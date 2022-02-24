#include <iostream>
#include <assert.h> 

template<class T>
class UnorderedArray 
{
    public:
        UnorderedArray(int size, int growBy = 1) :
            m_array(NULL), m_maxSize(0),
            m_growSize(0), m_numElements(0)
        {
            if(size){
                m_maxSize = size;
                m_array = new T[m_maxSize];
                m_growSize = ((growBy > 0) ? growBy : 0);
            }
        }

        virtual ~UnorderedArray()
        {
            if(m_array != NULL){
                delete[] m_array;
                m_array = NULL;
             }
        }

        // linear search (O(n))
        virtual int search(T val)
        {
            assert(m_array != NULL);

            for(int i = 0; i < m_numElements; i++){
                if(m_array[i] == val)
                    return i;
            }

            return -1;
        }

        // bubble sort (O(n²))
        // compare every element to get max and store it at end of array
        // decrease upper bound by one and sort rest of array by storing max of n-1 at n-2
        // loop/recurse
        void BubbleSort()
        {
            assert(m_array != NULL);

            T temp;
            // decrease by one as end of array gets filled up with sorted max values
            for (int l = m_numElements -1; l > 0; l--){
                // compare with each value up to k, because k and above already sorted
                for (int k = 0; k < l; k++){
                    if(m_array[k] > m_array[k+1]){
                        // swap
                        temp = m_array[k + 1];
                        m_array[k + 1] = m_array[k];
                        m_array[k] = temp;
                    }
                }    
            }
        }

        // selection sort (O(n²)) but less swaps than bubble sort
        void SelectionSort()
        {
            assert(m_array != NULL);

            T temp;
            T min;

            for (int l = 0; l < m_numElements; l++){
                min = l;
                for (int k = l; k < m_numElements; k++){
                    // check if kth element is less than current min
                    // prevents swapping/ changing min if same value
                    if (m_array[k] < m_array[min]){          
                        min = k;
                    }
                }
                // after inner loop done, compare and swap min value to left
                if(m_array[min] < m_array[l]){
                    temp = m_array[l];
                    m_array[l] = m_array[min];
                    m_array[min] = temp;
                }
            }
        }

        // insertion sort (O(n²)) but faster than insertion and bubble usually (esp partially sorted lists)
        void InsertionSort()
        {
            assert(m_array != NULL);

            T temp;
            int k;

            for(int l = 1; l < m_numElements; l++ ){
                temp = m_array[l];
                for (k = l-1; k >= 0; k--){       
                    if (m_array[k] > temp){
                        m_array[k+1] = m_array[k]; //shift up the higher value
                    } else {
                        break;
                    }
                }
                m_array[k+1] = temp; // insert temp into it's sorted position

            }

        }


        virtual T& operator[](int index)
        {
            assert(m_array != NULL && index <= m_numElements);
            return m_array[index];
        }

        virtual void push(T val)
        {
            assert(m_array != NULL);
            if(m_numElements >= m_maxSize){
            Expand();
            }
            m_array[m_numElements] = val;
            m_numElements++;
        }

        void pop()
        {
            if(m_numElements > 0)
                m_numElements--;
        }

        void remove(int index)
        {
            assert(m_array != NULL);

            if(index >= m_maxSize){
                return;
            }
            
            for(int k = index; k < m_maxSize - 1; k++)
                m_array[k] = m_array[k + 1];
            
            m_maxSize--;

            if(m_numElements >= m_maxSize)
                m_numElements = m_maxSize - 1;    
        }

        void clear()      { m_numElements = 0; }
        int GetSize()     { return m_numElements; }
        int GetMaxSize()  { return m_maxSize; }
        int GetGrowSize() { return m_growSize; }

        void SetGrowSize(int val)
        {
            assert(val >= 0);
            m_growSize = val;
        }   

    private:
        T *m_array;
        int m_maxSize;
        int m_growSize;
        int m_numElements;

        bool Expand()
        {
            if(m_growSize <= 0)
                return false;

            T *temp = new T[m_maxSize + m_growSize];
            assert(temp != NULL);

            memcpy(temp, m_array, sizeof(T) * m_maxSize);

            delete[] m_array;
            m_array = temp;

            m_maxSize += m_growSize;

            return true;
        }

};