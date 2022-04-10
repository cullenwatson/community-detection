//
// Created by pc on 4/10/22.
//

#include "Algo.h"
Algo::Algo(){

}
Graph_type Algo::readGraph(std::string const& fname, Mappings& mappings){
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
    return Graph_type(edge_array.data(), edge_array.data() + edge_array.size(),
                 transmission_delay.data(), numVertices);
}
void Algo::calcBetweenness(){

    g = readGraph("../data/people.txt", mappings);

    ECMap ecm;
    brandes_betweenness_centrality(
            g, boost::edge_centrality_map(boost::make_assoc_property_map(ecm)));

    //std::vector<std::reference_wrapper<ECEntry>> ranking(ecm.begin(), ecm.end());
    auto it = ranking.begin();
    ranking.insert(it, ecm.begin(), ecm.end());
    {
        // top-n
        auto n = std::min(30ul, ranking.size());

        auto first = ranking.begin(), middle = first + n, last = ranking.end();
        std::partial_sort(
                first, middle, last,
                [](ECEntry const& a, ECEntry const& b) { return a.second > b.second; });

        ranking.erase(middle, last);
    }

}

void Algo::outputRanking() {
    auto& edgenames = mappings.right;


    for (ECEntry const& entry : ranking) {
        //cout<<entry.first<<endl;
        //cout<<entry.second<<endl;
        auto [edge, centrality] = entry;
        auto s = edgenames.at(source(edge, g));
        auto t = edgenames.at(target(edge, g));
        std::cout << s << "-" << t << " centrality " << centrality << "\n";
    }
}
