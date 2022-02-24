#include <iostream>
#include "queue.h"

using namespace std;

int main (int args, char ** argc)
{
    std::cout << "Queues innit" << std::endl;

    
    Queue<int> qList(5);

    qList.push(191);
    qList.push(291);
    qList.push(391);
    qList.push(491);
    qList.push(591);

    qList.pop();

    qList.push(621);

    cout << "Size of the Queue: " << qList.GetSize() << " ." << endl;

    cout << "Contents of the Queue:";

    while(qList.isEmpty() == false){
        cout << " " << qList.front();
        qList.pop();
    }

    cout << "." << endl;

    if(qList.isEmpty() == true)
        cout << "The int queue is empty." << endl;
    else
        cout << "The int queue is NOT empty." << endl;

    int size = 5;
    Dequeue<int> dqList(size);
    for(int i = 0; i < size; i++){
        dqList.push_front(10 + i);
    }

    cout << "Size of the Queue: " << dqList.GetSize() << " ." << endl;

    cout << "Contents of the Queue:";

    while(dqList.isEmpty() == false){
        cout << " Front: " << dqList.front();
        cout << " Back: " << dqList.back();
        cout << endl;
        dqList.pop_front();
    }

    cout << "." << endl;

    if(dqList.isEmpty() == true)
        cout << "The int queue is empty." << endl;
    else
        cout << "The int queue is NOT empty." << endl;

    return 1;


}