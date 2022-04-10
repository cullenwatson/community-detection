#include "InputGraph.h"
#include <iostream>

using namespace std;

InputGraph::InputGraph(string file) {

    // read file
    ifstream inFile(file);
    dynamic_properties dp(ignore_other_properties);

    // add data to graph
    read_graphml(inFile, g, dp);

    // close file
    inFile.close();
}

void InputGraph::outputEdges() {

    cout << num_edges(g) << endl;
//    pair<edge_iterator, edge_iterator> ei = edges(g);
//    for (edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter)
//        cout << source(*edge_iter, g) << " - " << target(*edge_iter, g) << "\n";

}

void InputGraph::saveEdges() {
    ofstream file("../data/coords.txt");
    file << num_edges(g) << endl;
    pair<edge_iterator, edge_iterator> ei = edges(g);
    for (edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter)
        file << source(*edge_iter, g) << " - " << target(*edge_iter, g) << "\n";

    file.close();
}

void InputGraph::removeEdge(int a, int b) {
    remove_edge(a, b, g);
}

void InputGraph::saveToFile() {
    ofstream ouFile("../data/results.graphml");

    dynamic_properties dp(ignore_other_properties);
    write_graphml(ouFile, g, dp);

    ouFile.close();
}

