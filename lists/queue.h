#include "list.h" 
#include <iostream>

template<typename T>
class Queue
{
    public:
        Queue(int size) 
        {
            assert(size > 0);
            m_size = size;
        }

        ~Queue() {}

        void push(T val)
        {
            if(m_container.GetSize() < m_size){
                m_container.Push_Back(val);
            }
            
        }

        void pop()
        {
            m_container.Pop_Front();
        }

        const T& front()
        {
           LinkIterator<T> it;
           it = m_container.Begin();
           return *it;
        }

        int GetSize() { return m_container.GetSize(); }
        int GetMaxSize() { return m_size; } 
        bool isEmpty() { return m_container.GetSize() == 0; }
        void Resize(int size ) { assert(size > 0); m_size = size; }


    private:
    
        LinkList<T> m_container;
        int m_size;
       
};

template<typename T>
class Dequeue
{
    public:
        Dequeue(int size) 
        {
            assert(size > 0);
            m_size = size;
        }

        ~Dequeue() {}

        void push_front(T val)
        {
            if(m_container.GetSize() < m_size){
                m_container.Push_Front(val);
            }
            
        }

        void push_back(T val)
        {
            if(m_container.GetSize() < m_size){
                m_container.Push_Back(val);
            }
            
        }

        // just the convention used here... Can mix/decide to use push 
        // front with pop_front etc.. don't really agree with this one here
        void pop_front()
        {
            m_container.Pop_Back();
        }

        void pop_back()
        {
            m_container.Pop_Front();
        }

        const T& front()
        {
           LinkIterator<T> it;
           it = m_container.End();
           return *it; // custom * operator to give back it->m_node->m_data
        }

        const T& back()
        {
           LinkIterator<T> it;
           it = m_container.Begin(); // custom = to assign it.m_node = m_root 
           return *it; //custom * operator to give back it.m_node->m_data
        }

        int GetSize() { return m_container.GetSize(); }
        int GetMaxSize() { return m_size; } 
        bool isEmpty() { return m_container.GetSize() == 0; }
        void Resize(int size ) { assert(size > 0); m_size = size; }


    private:
    
        LinkList<T> m_container;
        int m_size;
       
};

template<typename T, typename CMP>
class PriorityQueue
{
    public:
        PriorityQueue(int size)
        {
            assert(size > 0);
            m_size = size;
        }

        ~PriorityQueue()
        {

        }

        void push(T val)
        {
            assert(m_container.GetSize() < m_size);

            if(m_container.GetSize() == 0){
                m_container.Push_Back(val);
            } else {
                LinkIterator<T> it;
                it = m_container.Begin();

                CMP cmp;

                while(it.isValid()){
                    if(cmp(val, *it))
                        break;
                    std::cout << "value of it " << &it << std::endl;
                    it++;

                }

                if(it.isValid())
                    m_container.Insert_Before(&it, val);
                else
                    m_container.Push_Back(val); //append to end
            }

        }

        void pop()
        {
            m_container.Pop_Front();
        }

        const T& front()
        {
           LinkIterator<T> it;
           it = m_container.Begin();
           return *it;
        }

        const T& back()
        {
           LinkIterator<T> it;
           it = m_container.End();
           return *it;
        }

        int GetSize() { return m_container.GetSize(); }
        int GetMaxSize() { return m_size; } 
        bool isEmpty() { return m_container.GetSize() == 0; }
        void Resize(int size ) { assert(size > 0); m_size = size; }

    private:
    
        LinkList<T> m_container;
        int m_size;
};