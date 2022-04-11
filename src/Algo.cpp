//
// Created by pc on 4/10/22.
//

#include "Algo.h"

Algo::Algo() {

}

void Algo::readGraph(std::string const &fname) {
    std::ifstream myFile(fname);

    // gets first line and turns it to int
    unsigned numEdges = 0;
    myFile >> numEdges;

    vector<Edge> edge_array;

    for (string src, hyphen, tgt;
         edge_array.size() < numEdges && myFile >> src >> hyphen >> tgt;) {
        // combined lookup/insert:
        auto s = mappings.insert(Mappings::value_type(src, mappings.size()))
                .first->get_right();
        auto t = mappings.insert(Mappings::value_type(tgt, mappings.size()))
                .first->get_right();

        // now that all the names are collected we can read in the edge array
        // and store it as the integer mapped to that name in the map
        edge_array.emplace_back(s, t);
    }

    std::vector<float> transmission_delay(edge_array.size(),
                                          1.f); // no edge weights

    int const numVertices = mappings.size();
    g = Graph_type(edge_array.data(), edge_array.data() + edge_array.size(),
                   transmission_delay.data(), numVertices);
}

void Algo::calcBetweenness() {

    ECMap ecm;
    brandes_betweenness_centrality(
            g, edge_centrality_map(make_assoc_property_map(ecm)));

    // output map
//    for (auto& it = ecm.begin();
//         it != ecm.end(); ++it) {
//        std::cout << "hi"<<endl;
//    }

    auto it = ranking.begin();
    ranking.insert(it, ecm.begin(), ecm.end());
    {
        // top-n
        auto n = std::min(10ul, ranking.size());

        auto first = ranking.begin(), middle = first + n, last = ranking.end();
        std::partial_sort(
                first, middle, last,
                [](ECEntry const &a, ECEntry const &b) { return a.second > b.second; });

        ranking.erase(middle, last);
    }

}
void Algo::getTopEdge2() {
    using G = boost::adjacency_list<boost::setS, boost::vecS, boost::bidirectionalS,
            boost::no_property,
            boost::property<boost::edge_weight_t, float>>;
    using V = G::vertex_descriptor;

    set<MyEdge> myEdges;

    for(int i=0; i<num_vertices(g); i++){
        auto s = vertex(i, g);
        assert(s == i);

        std::vector<size_t> distances(num_vertices(g));
        std::vector<V>      predecessors(num_vertices(g));

        dijkstra_shortest_paths(g, s,
                                boost::distance_map(distances.data())
                                        .predecessor_map(predecessors.data()));

        for (auto v : boost::make_iterator_range(vertices(g))) {
            //std::cout << "distance ("<<i<<" to " << v << "): ";

            for (V curr = v, pred = curr; (pred = predecessors.at(curr)) != curr;
                 curr = predecessors.at(curr)) {
                //std::cout << " (" << pred << ", "<<curr <<")";

                // add edge
                MyEdge myEdge(curr, pred);

                auto iter = myEdges.find(myEdge);
                // if found, inc qty
                if (iter != myEdges.end()) {
                    (*iter).incQty();
                } else {
                    myEdges.insert(myEdge);
                }
            }
            std::cout << "\n";
        }
    }
    // iter through set and find edge with highest betweenness
    set<MyEdge>::iterator itr;
    MyEdge maxEdge(0,0);
    int maxQty = 0;
    for (itr = myEdges.begin(); itr != myEdges.end(); itr++) {
        int edgeQty = (*itr).getQty();
        if(edgeQty > maxQty){
            maxQty = edgeQty;

            maxEdge.setX((*itr).getX());
            maxEdge.setY((*itr).getY());
        }
    }
    //cout<<maxEdge.getX()<< ", "<<maxEdge.getY()<<endl;

    auto &edgenames = mappings.right;

    // output top centrality

    auto s = edgenames.at(maxEdge.getX());
    auto t = edgenames.at(maxEdge.getY());
    centrality_ = maxQty;

    std::cout << s << "-" << t <<" CENTRALITY: "<<centrality_<< "\n";
    topCentX = stoi(s);
    topCentY = stoi(t);

}
void Algo::getTopEdge() {
    calcBetweenness();

    auto &edgenames = mappings.right;

    // output top centrality

    ECEntry const &entry = ranking[0];
    auto[edge, centrality] = entry;
    auto s = edgenames.at(entry.first.m_source);
    auto t = edgenames.at(target(edge, g));
    std::cout << s << "-" << t << " centrality " << centrality << "\n";
    topCentX = stoi(s);
    topCentY = stoi(t);
    centrality_ = centrality;

    //cout<<topCentX<<" "<<topCentY;





    // output all centralities
//    for (ECEntry const& entry : ranking) {
//        auto [edge, centrality] = entry;
//        auto s = edgenames.at(source(edge, g));
//        auto t = edgenames.at(target(edge, g));
//        std::cout << s << "-" << t << " centrality " << centrality << "\n";
//    }
}

void Algo::outputEdges() {
    typedef graph_traits<Graph_type>::edge_iterator edge_iterator;

    cout << "-----------" << num_edges(g) << "-----------" << endl;
    pair<edge_iterator, edge_iterator> ei = edges(g);
    for (edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter)
        cout << source(*edge_iter, g) << " - " << target(*edge_iter, g) << "\n";
}

