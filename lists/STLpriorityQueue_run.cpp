#include <iostream>
#include <queue>
#include <vector>

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
        NetworkMessage(int data) : m_data(data) { }
        ~NetworkMessage() { } 

        int GetData() { return m_data; }

        bool operator<(NetworkMessage &obj)
        {
            return (m_data < obj.GetData());
        } 

        bool operator>(NetworkMessage &obj)
        {
            return !(m_data < obj.GetData());
        }

    private:
        int m_data;
};

int main (int args, char ** argc)
{
    std::cout << "Priority Queues innit" << std::endl;

    priority_queue<NetworkMessage, vector<NetworkMessage>,
     less_cmp<NetworkMessage>> que;

    priority_queue<NetworkMessage*, vector<NetworkMessage*>,
     greater_cmp_ptr<NetworkMessage*>> ptrque;
    
    que.push(NetworkMessage(200));
    que.push(NetworkMessage(286));
    que.push(NetworkMessage(362));
    que.push(NetworkMessage(435));
    que.push(NetworkMessage(121));

    ptrque.push(new NetworkMessage(20));
    ptrque.push(new NetworkMessage(28));
    ptrque.push(new NetworkMessage(36));
    ptrque.push(new NetworkMessage(43));
    ptrque.push(new NetworkMessage(12));

    int size = (int)que.size();

    cout << "Size of the Queue: " << size << " ." << endl;

    cout << "Contents of the Queue:";

    for(int i=0; i < size; i++){
        NetworkMessage message = que.top();
        cout << " " << message.GetData();
        cout << endl;

        que.pop();
    }

    for(int i=0; i < size; i++){
        NetworkMessage *message = ptrque.top();
        if(message != NULL){
            cout << " " << message->GetData();
            delete message;
            cout << "(deleted)" << endl;
        }

        ptrque.pop();
        cout << endl;
    }

    cout << "." << endl;

    if(que.empty() == true)
        cout << "The normal queue is empty." << endl;
    else
        cout << "The normal queue is NOT empty." << endl;

    if(ptrque.empty() == true)
        cout << "The ptr queue is empty." << endl;
    else
        cout << "The ptr queue is NOT empty." << endl;

    return 1;


}