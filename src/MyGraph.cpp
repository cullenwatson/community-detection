#include "MyGraph.h"
#include <iostream>
 using namespace std;
 MyGraph::MyGraph(string file){

    // read file
    ifstream inFile(file);
    dynamic_properties dp(ignore_other_properties);

    // add data to graph
    read_graphml(inFile,g, dp);

    inFile.close();
}
void MyGraph::outputEdges(){
     ofstream file("../data/people.txt");
     file<<num_edges(g)<<endl;
    pair<edge_iterator, edge_iterator> ei = edges(g);
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter)
        file << source(*edge_iter, g) << " - " << target(*edge_iter, g) << "\n";

    file.close();
}

