#include "list.h" 

template<typename T>
class Stack
{
    public:
        Stack() 
        {
            //m_size = size;
        }

        ~Stack() {}

        void push(T val)
        {
            m_container.Push_Back(val);
        }

        void pop()
        {
            m_container.Pop_Back();
        }

        const T& top()
        {
           LinkIterator<T> it;
           it = m_container.End();
           return *it;
        }

        int GetSize() { return m_container.GetSize(); }
        bool isEmpty() { return m_container.GetSize() == 0; }


    private:
    
        LinkList<T> m_container;
        //int m_size;
       
};