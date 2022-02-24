#include "../gamedev/array.h"

template<typename T>
class Stack
{
    public:
        Stack(int size, int growBy = 1)
        {
            if (size)
            {
                m_container = new UnorderedArray<T>(size, growBy);
                assert(m_container != NULL);
            
            }
        }

        ~Stack()
        {
            if(m_container != NULL)
            {
                delete m_container;
                m_container = NULL;
            }
        }

        void push(T val)
        {
            assert(m_container != NULL);
            m_container->push(val);
        }

        void pop()
        {
            assert(m_container != NULL);
            m_container->pop();
        }

        const T& top()
        {
            assert(m_container != NULL);
            return (*m_container)[m_container->GetSize() -1];
        }

        int GetSize() { 
            assert(m_container != NULL);
            return m_container->GetSize(); 
        }
        int GetMaxSize()  { 
            assert(m_container != NULL);
            return m_container->GetMaxSize(); 
        }
        int isEmpty() { 
            assert(m_container != NULL);
            return (m_container->GetSize() == 0); 
        }
        int isFull() { 
            assert(m_container != NULL);
            return (m_container->GetSize() == GetMaxSize() - 1); 
        }

    private:

        UnorderedArray<T> *m_container;

};