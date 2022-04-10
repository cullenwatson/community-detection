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
#include "InputGraph.h"
using namespace boost;
using namespace std;
typedef bimap<string, int> Mappings;

typedef adjacency_list<setS, vecS, bidirectionalS,
        no_property,
        property<edge_weight_t, float>> Graph_type;

typedef adjacency_list<vecS, vecS, undirectedS> Graph;

typedef map<Graph_type::edge_descriptor, double> ECMap;
typedef ECMap::value_type ECEntry;

typedef typename graph_traits<Graph_type>::vertex_descriptor Vertex;
typedef pair<Vertex, Vertex> Edge;

class Algo {
private:
    Mappings mappings;
    Graph_type g;
    std::vector<std::reference_wrapper<ECEntry>> ranking;

    // x, y of current top centrality
    int topCentX, topCentY;
    float centrality_;
    void calcBetweenness();
public:

    Algo();


    void readGraph(std::string const& fname);


    // outputs
    void getTopEdge();
    void outputEdges();

    int getTopCentX(){ return topCentX; };
    int getTopCentY(){ return topCentY; };
    int getCentrality(){ return centrality_; };

};


#endif //INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_ALGO_H
