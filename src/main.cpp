#include "MyGraph.h"
#include <iostream>
#include "Algo.h"
using namespace std;
int main(int argc, char *argv[]){

    MyGraph myGraph("../data/people.graphml");
    myGraph.outputEdges();

    Algo algo;
    algo.outputBetweenness();



    return 0;
}