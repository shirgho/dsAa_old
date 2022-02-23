#include <iostream>
#include <list>
#include <iterator>
#include "graph.h"

using namespace std;

int main(int args, char **argc)
{
    cout << "Graphs" << endl;

    Graph<char> demoGraph(6);

    demoGraph.push('A'); 
    demoGraph.push('B');
    demoGraph.push('C');
    demoGraph.push('D');
    demoGraph.push('E');
    demoGraph.push('F');

    // Attach A:B A:C B:D C:E D:E E:F

    demoGraph.attachDirectedEdge(0,1);
    demoGraph.attachDirectedEdge(0,2);
    demoGraph.attachDirectedEdge(1,3);
    demoGraph.attachDirectedEdge(2,4);
    demoGraph.attachDirectedEdge(3,4);
    demoGraph.attachDirectedEdge(4,5);

    // Perform depth first search for a path from A to D
    cout << "Depth First Search Nodes visited: " << endl;

    int result = demoGraph.DepthFirstSearch(0, 3);

    cout << endl;

    if(result == 1)
        cout << "Path from A to D found!" << endl;
    else
        cout << "Path from A to D NOT found!" << endl;

    cout << endl ;

    // Perform breadth first search for a path from A to D
    cout << "Breadth First Search Nodes visited: " << endl;

    result = demoGraph.BreadthFirstSearch(0, 3);
 
    cout << endl;

    if(result == 1)
        cout << "Path from A to D found!";

    else
        cout << "Path from A to D NOT found!";

    cout << endl << endl;

    cout << "Minimum Spanning Tree: ";
    demoGraph.DisplayMST();
    cout << endl << endl;

    list<char> tsResult;
    cout << "Topological Sort: " << endl;
    if(demoGraph.topologicalSort(tsResult) == true){
        ostream_iterator<char> output(cout, " ");
        copy(tsResult.begin(), tsResult.end(), output);
    } else {
        cout << "There are cycles in the graph!";
    }

    cout << endl; 

    return 0;
 

}