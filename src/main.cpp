#include <iostream>
#include "InputGraph.h"
#include "Algo.h"

using namespace std;

int main(int argc, char *argv[]) {

    // create graph
    InputGraph inputGraph("../data/people.graphml");
    inputGraph.outputEdges();
    inputGraph.saveEdges();

    // find betweenness
    Algo algo;
    algo.readGraph("../data/coords.txt");


    cout<<"-----------------------\n";
    algo.outputEdges();

    algo.removeEdge();
   // algo.outputEdges();



    return 0;
}