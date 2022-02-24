#include <memory.h>
#include <assert.h> 
#include <vector>
#include <algorithm>
#include <numeric>
#include<iterator>


using namespace std;

template<typename T>
class Stack
{
    public:
        Stack(int size, int growBy = 1) : m_size(0),
            m_top(0), m_array(0), m_growSize(0)
        {
            if (size)
            {
                m_size = size;
                m_array.reserve(m_size);
                fill(m_array.begin(), m_array.end(), 5);

                m_growSize = ((growBy > 0) ? growBy: 0);
            }
        }

        ~Stack()
        {
            
        }

        void push(T val)
        {

            m_array[++m_top] = val;
        }

        void pop()
        {
            if(!isEmpty()){
                m_top--;
            }
        }

        const T& top()
        {
            assert(m_top >= 0);

            return m_array[m_top];
        }

        int GetSize() { return m_top; }
        int GetMaxSize() { return m_array.capacity(); }
        int isEmpty() { return m_top == -1; }
        int isFull() { return m_top == m_array.capacity() -1; }

    private:

        vector<T> m_array;
        int m_top;
        int m_size;
        int m_growSize;
};