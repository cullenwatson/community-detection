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

void Algo::getTopEdge() {
    calcBetweenness();

    auto &edgenames = mappings.right;

    // output top centrality

    ECEntry const &entry = ranking[0];
    auto[edge, centrality] = entry;
    auto s = edgenames.at(source(edge, g));
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

