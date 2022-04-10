//
// Created by pc on 4/10/22.
//

#ifndef INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_ALGO_H
#define INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_ALGO_H

#include <boost/bimap.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/betweenness_centrality.hpp>
#include "boost/graph/graphml.hpp"
#include <fstream>
#include <iostream>
using namespace boost;
using namespace std;
typedef bimap<string, int> Mappings;

typedef adjacency_list<setS, vecS, bidirectionalS,
        no_property,
        property<edge_weight_t, float>> Graph_type;

typedef typename graph_traits<Graph_type>::vertex_descriptor Vertex;
typedef pair<Vertex, Vertex> Edge;

class Algo {
public:

    Algo();

    Graph_type readGraph(std::string const& fname, Mappings& mappings);
    void outputBetweenness();
};


#endif //INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_ALGO_H
