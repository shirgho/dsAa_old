#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <assert.h>

template<typename T> class LinkList;
template<typename T> class LinkIterator;

template<typename T>
class LinkNode
{
    friend class LinkIterator<T>;
    friend class LinkList<T>;

    private:
        LinkNode() : m_next(0), m_prev(0)
        {
            
        }
        T m_data;
        LinkNode *m_next;
        LinkNode *m_prev;
};

template<typename T>
class LinkIterator
{
    friend class LinkList<T>;

    public:
        LinkIterator()
        {
            m_node = NULL;
        }

        ~LinkIterator()
        {

        }

        bool isValid()
        {
            if(m_node == nullptr){
                return false;
            } else {
                return true;
            }

            // or just write
            //return (m_node != NULL);
        }

        void operator=(LinkNode<T> *node)
        {
            m_node = node;
        }

        T &operator*()
        {
            assert(m_node != NULL);

            return m_node->m_data;
        }

        void operator++()
        {
            assert(m_node != NULL);
            
            m_node = m_node->m_next;
        }

        void operator++(int)
        {
            assert(m_node != NULL);
            
            m_node = m_node->m_next;
        }

        void operator--()
        {
            assert(m_node != NULL);
            
            m_node = m_node->m_prev;
        }

        void operator--(int)
        {
            assert(m_node != NULL);
            
            m_node = m_node->m_prev;
        }

        bool operator!=(LinkNode<T> *node)
        {

            return (m_node != node); 
        }

        bool operator==(LinkNode<T> *node)
        {
            return (m_node == node); 
        }

    private:
        LinkNode<T> *m_node;

};

template<typename T>
class LinkList
{
    public:
        LinkList() : m_size(0), m_root(0), m_lastNode(0)
        {

        }

        ~LinkList()
        {
            while(m_root != NULL) Pop_Back();
        }

        LinkNode<T> *Begin()
        {
            assert(m_root != NULL);

            return m_root;
        }

        LinkNode<T> *End()
        {
            assert(m_lastNode != NULL);

            return m_lastNode;
        }

        void Push_Back(T newData)
        {
            LinkNode<T> *node = new LinkNode<T>;

            assert(node != NULL);

            node->m_data = newData;
            node->m_next = NULL;
            node->m_prev = NULL;

            if (m_lastNode != NULL){
                m_lastNode->m_next = node;
                node->m_prev = m_lastNode;
            } else { // if empty list
                m_root = node;   
            }

            m_lastNode = node;

            m_size++;
        }

        void Push_Front(T newData)
        {
            LinkNode<T> * node = new LinkNode<T>;

            assert (node != NULL);

            node->m_data = newData;
            node->m_next = NULL;
            node->m_prev = NULL;

            if (m_root != NULL){
                node->m_next = m_root;
                m_root->m_prev = node;
                m_root = node;
            } else { // if empty list               
                m_root = node;
                m_lastNode = node;
            }

            m_size++;
            
        }

        void Insert_Before(LinkIterator<T> *it, T newData)
        {
            assert(it->m_node != NULL);

            LinkNode<T> *newNode = new LinkNode<T>;
            assert(&newNode != NULL);
            newNode->m_data = newData;

            newNode->m_prev = it->m_node->m_prev;
            newNode->m_next = it->m_node;

            if(it->m_node->m_prev != NULL)
                it->m_node->m_prev->m_next = newNode;

            it->m_node->m_prev = newNode;

            if(it->m_node == m_root)
                m_root = newNode;

            m_size++;
            
        } 

        /* void Insert_Before(LinkIterator<T> &it, T newData)
        {
            assert(it.m_node != NULL);

            LinkNode<T> *newNode = new LinkNode<T>;
            newNode->m_data = newData;

            newNode->m_prev = it.m_node->m_prev;
            newNode->m_next = it.m_node;

            if(it.m_node->m_prev != NULL)
                it.m_node->m_prev->m_next = newNode;

            it.m_node->m_prev = newNode;

            if(it.m_node == m_root)
                m_root = newNode;

            m_size++;
            
        } */

        void Insert_After(LinkIterator<T> &it, T newData)
        {
            assert(it.m_node != NULL);

            LinkNode<T> *newNode = new LinkNode<T>;
            assert(newNode != NULL);

            newNode->m_data = newData;

            newNode->m_prev = it.m_node;
            newNode->m_next = it.m_node->m_next;
            
            if (it.m_node->m_next != NULL)
                it.m_node->m_next->m_prev = newNode;
            
            it.m_node->m_next = newNode;

            if(it.m_node == m_lastNode)
                m_lastNode = newNode;

            m_size++;
            
        }

        void Pop_Back()
        {
            assert(m_root != NULL);

            // so only one item in list, the root
            if (m_root->m_next == NULL && m_lastNode->m_prev == NULL){
                delete m_root;
                m_root = NULL;
                //delete m_lastNode;
                m_lastNode = NULL;
            } else {
                /* 
                //For singly linked lists
                LinkNode<T> *prevNode = m_root;
                while (prevNode->m_next != NULL &&
                       prevNode->m_next != m_lastNode){
                    prevNode = prevNode->m_next;
                }
                delete m_lastNode;
                prevNode->m_next = NULL;
                m_lastNode = prevNode;
                */

                LinkNode<T> *prevNode = m_lastNode->m_prev;

                prevNode->m_next = NULL;
                delete m_lastNode;
                m_lastNode = prevNode;

            }

            m_size = (m_size == 0 ? m_size : m_size - 1);
        }

        void Pop_Front()
        {
            assert(m_root != NULL);

            LinkNode<T> *temp = m_root;
            m_root = m_root->m_next;

            if (m_root != NULL){
                m_root->m_prev = NULL;;
            } 

            delete temp;
            
            m_size = m_size == 0 ? m_size : m_size - 1;
         
        }

        int GetSize()
        {
            return m_size;
        }


    public:
        int m_size;
        LinkNode<T> *m_root;
        LinkNode<T> *m_lastNode;

};







#endif /*LINKEDLISTS_H*/