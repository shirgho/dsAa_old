#include <iostream>

template<typename T>
class VerySimpleList
{
    public:
        VerySimpleList(): m_data(0) { }
        T m_data;
        VerySimpleList * next;
};

int main(int arg, char **argc)
{
    VerySimpleList<int> intListNode;
    intListNode.m_data = 1;
    intListNode.next = nullptr;

    VerySimpleList<int> intListNode2;
    intListNode2.m_data = 2;
    intListNode2.next = nullptr;
    intListNode.next = &intListNode2;

    VerySimpleList<int> *it = &intListNode;
    while(it != nullptr){
        std::cout << "node contains: " << it->m_data << "." << std::endl;
        it = it->next;
    }

    return 1;
}