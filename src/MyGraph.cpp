#include "MyGraph.h"

 MyGraph::MyGraph(string file){

    // read file
     ifstream inFile(file);
    dynamic_properties dp(ignore_other_properties);

    // add data to graph
    read_graphml(inFile,g, dp);

    inFile.close();
}
void MyGraph::outputEdges(){
    pair<edge_iterator, edge_iterator> ei = edges(g);
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter)
        cout << "(" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ")\n";
}