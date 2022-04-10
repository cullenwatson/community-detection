#include <iostream>
#include "MyGraph.h"
#include "Algo.h"

using namespace std;

int main(int argc, char *argv[]) {

    MyGraph myGraph("../data/people.graphml");
//    myGraph.outputEdges();

    myGraph.saveEdges();
    Algo algo;
    algo.calcBetweenness();
    algo.outputRanking();



    return 0;
}