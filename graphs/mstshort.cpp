#include <iostream>
#include <list>
#include <iterator>
#include "graph.h"

using namespace std;

int main(int args, char **argc)
{
    cout << "MSP short" << endl;

    Graph<char> demoGraph(5);
    string output;

    demoGraph.push('A'); 
    demoGraph.push('B');
    demoGraph.push('C');
    demoGraph.push('D');
    demoGraph.push('E');

    demoGraph.attachEdge(0, 1);
    demoGraph.attachEdge(0, 2);
    demoGraph.attachEdge(0, 3);
    demoGraph.attachEdge(0, 4);

    demoGraph.attachEdge(1, 2);
    demoGraph.attachEdge(1, 3);
    demoGraph.attachEdge(1, 4);

    demoGraph.attachEdge(2, 3);
    demoGraph.attachEdge(2, 4);

    demoGraph.attachEdge(3, 4);

    cout << "Minimum Spanning Tree: ";
    demoGraph.DisplayMSTShortest(output);
    cout << endl << endl;

    cout << endl; 

    return 0;
 

}