#include <iostream>
#include "InputGraph.h"
#include "Algo.h"

using namespace std;

int main(int argc, char *argv[]) {

    // create graph
    InputGraph inputGraph("../data/people.graphml");

    Algo algo;

    // ------REMOVE TOP N  EDGES

    float centrality = 400;
    // 2.34 (500)
    while (centrality > 5) {
        // 1. Save current graph
        inputGraph.saveEdges();

        // 2. Read saved graph
        algo.readGraph("../data/coords.txt");
        // 3. Find top centrality and remove
        algo.getTopEdge2();
        int x = algo.getTopCentX();
        int y = algo.getTopCentY();
        centrality = algo.getCentrality();
        inputGraph.removeEdge(x, y);

        cout << "-------------------------\n";
    }




    // cout<<"-----------------------\n";

    // Output results
    inputGraph.saveToFile();
    inputGraph.outputEdges();


    return 0;
}