#ifndef INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_INPUTGRAPH_H
#define INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_INPUTGRAPH_H

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/graphml.hpp"
#include "boost/graph/betweenness_centrality.hpp"

#include <boost/random/uniform_01.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/bimap.hpp>

using namespace boost;
using namespace std;

typedef adjacency_list<vecS, vecS, undirectedS> Graph;
typedef graph_traits<Graph>::edge_iterator edge_iterator;

class InputGraph {
private:
    Graph g;
public:
    // reads in graphml file
    InputGraph(string);

    void outputEdges();
    void saveEdges();
    void removeEdge(int, int);

    void saveToFile();
};


#endif //INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_INPUTGRAPH_H
