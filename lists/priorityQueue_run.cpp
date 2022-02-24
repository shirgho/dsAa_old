#include <iostream>
#include "queue.h"

using namespace std;

template<typename T>
class less_cmp
{
    public:
        inline bool operator()(T lVal, T rVal)
        { return (lVal < rVal); }
};

template<typename T>
class less_cmp_ptr
{
    public:
        inline bool operator()(T lVal, T rVal)
        { return (*lVal < *rVal); }
};

template<typename T>
class greater_cmp
{
    public:
        inline bool operator()(T lVal, T rVal)
        { return (lVal > rVal); }
};

template<typename T>
class greater_cmp_ptr
{
    public:
        inline bool operator()(T lVal, T rVal)
        { return (*lVal > *rVal); }
};


class NetworkMessage
{
    public:
        NetworkMessage() : m_priority(0), m_id(0) { }
        NetworkMessage(int p, int id) : m_priority(p), m_id(id) { }
        ~NetworkMessage() { } 

        int GetPriority() { return m_priority; }
        int GetID()       { return m_id; }

        bool operator<(NetworkMessage &m)
        {
            if(m_priority < m.GetPriority())
                return true;
            else if(m_id < m.GetID())
                return true;

            return false;

        } 

        bool operator>(NetworkMessage &m)
        {
            return !(*this < m);
        }

    private:
        int m_priority, m_id;
};

int main (int args, char ** argc)
{
    std::cout << "Priority Queues innit" << std::endl;

    int size = 5;

    PriorityQueue< NetworkMessage, less_cmp<NetworkMessage> > que(size);
    
    que.push(NetworkMessage(3, 200));
    que.push(NetworkMessage(2, 286));
    que.push(NetworkMessage(1, 362));
    que.push(NetworkMessage(3, 435));
    que.push(NetworkMessage(1, 121));

    cout << "Size of the Queue: " << que.GetSize() << " ." << endl;

    cout << "Contents of the Queue:";

    while(que.isEmpty() == false){
        NetworkMessage message = que.front();
        cout << " Priority: " << message.GetPriority();
        cout << " ID: " << message.GetID();
        cout << endl;

        que.pop();
    }

    cout << "." << endl;

    if(que.isEmpty() == true)
        cout << "The int queue is empty." << endl;
    else
        cout << "The int queue is NOT empty." << endl;

    return 1;


}