#include <iostream>
#include "kdtree.h"
#include <vector>

using namespace std;

int main(int args, char **argc)
{
    cout << "KD Trees" << endl;
    KdTree<int> kdTree(3);

    for(int i = 0; i < 100; i++){
        vector<int> key(3);

        key[0] = rand() % 100;
        key[1] = rand() % 100;
        key[2] = rand() % 100;

        kdTree.push(key);
    }

    vector<int> low(3), high(3);
    low[0] = 20;
    low[1] = 30;
    low[2] = 25;
    high[0] = 90;
    high[1] = 70;
    high[2] = 80;

    cout << "Range (20, 30, 25) (90, 70, 80) Match:" << endl;

    kdTree.displayRange(low, high);

    cout << endl;

    cout << "Displaying Preorder:" << endl;
    
    kdTree.DisplayPreOrder();

    cout << endl;

    return 0;

}