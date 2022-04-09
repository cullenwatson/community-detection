#ifndef INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_MYGRAPH_H
#define INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_MYGRAPH_H

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/graphml.hpp"

using namespace boost;
using namespace std;
typedef adjacency_list<vecS, vecS, undirectedS> UndirectedGraph;
typedef graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

class MyGraph {
private:
    UndirectedGraph g;
public:
    // reads in graphml file
    MyGraph(string);

    void outputEdges();

};


#endif //INC_22S_PA03_GIRVAN_NEWMAN_CULLENWATSON_MYGRAPH_H
