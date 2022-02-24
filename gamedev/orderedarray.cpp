/* Ordered array/sequence
    - insertion is O(n)
    - searching is O(log n) through Binary search

When insertions are rare but searches are frequent, better than unordered sequence

*/

#include <iostream>
#include <assert.h> 

template <class T>
class OrderedArray
{
    public:
        OrderedArray(int size, int growBy = 1) :
            m_array(NULL), m_maxSize(0),
            m_growSize(0), m_numElements(0)
        {
            if(size){
                m_maxSize = size;
                m_array = new T[m_maxSize];
                memset(m_array, 0, sizeof(T) * m_maxSize);


                m_growSize = ((growBy > 0) ? growBy : 0);
            }
        }

        virtual ~OrderedArray()
        {
            if(m_array != NULL){
                delete[] m_array;
                m_array = NULL;
             }
        }

        // Binary Search
        int search (T searchKey)
        {
            assert(m_array != NULL);

            if (!m_array) return -1;

            int lowerBound = 0;
            int upperBound = m_numElements - 1;
            
            while (lowerBound <= upperBound){
                // bug when ints are too large and cause overflow
                //int index = (lowerBound + upperBound) / 2;
                // better: ((unsigned int)lowerBound + (unsigned int)upperBound)) >> 1;
                // but this below is also clear enough for me without conversion, but mb slower
                int index = lowerBound + ((upperBound - lowerBound) / 2);
                if (m_array[index] == searchKey){
                    return index;
                }
                else if (m_array[index] > searchKey){
                    upperBound = index - 1;
                } else {
                    lowerBound = index + 1;

                }
            }
             
            return -1;
            
        }

        // Recursive Binary Search
        int recursiveSearch( T searchKey)
        {
            return find(searchKey, 0, m_numElements -1);
        }

        int find(T searchKey, int lowerBound, int upperBound)
        {
            assert(m_array != NULL);
            assert(lowerBound >= 0);
            assert(upperBound < m_numElements);

            int index = lowerBound + ((upperBound - lowerBound) / 2);
            // index = lower + upper, simple version but int can overflow

            if (m_array[index] == searchKey){
                std::cout << "found!" << std::endl;
                return index;
            } else if (lowerBound > upperBound){
                // valid not found, end condition for the recursion
                return -1;
            } else if (m_array[index] > searchKey){
                upperBound = index - 1;
                return find(searchKey, lowerBound, upperBound);
            } else {
                lowerBound = index + 1;
                return find(searchKey, lowerBound, upperBound);
            }

            /*
            Have to return the find funciton so that the recursive functions return the
            value from the call stack. Otherwise, even if found, going back to the prev
            find call will result in it going out of the loop and returning -1
            */

            return -1;
        }

        int push(T val)
        {
            assert(m_array != NULL);
            if(m_numElements >= m_maxSize){
                Expand();
            }
        
            int i = 0;
            // find the first value that is greater than the inserting value
            for(i = 0; i < m_numElements; i++){
                if(m_array[i] > val)
                break;
            }
            
            for(int k = m_numElements; k > i; k--){
                m_array[k] = m_array[k - 1];
            }
            
            m_array[i] = val;
            m_numElements++;
            return i;
            
        }

        // use binary search to push value
        int binaryInsert(T val)
        {
            assert(m_array != NULL);
            if(m_numElements >= m_maxSize){
                Expand();
            }

            // find the first value that is greater than inserting value
            int pos = 0;

            if(m_numElements == 0){
                pos = 0;
            } else {
                pos = findPos(val, 0, m_numElements - 1);
            }

            if (pos >= 0){
                // shift everything starting from pos up, to make room at pos for new element
                std::cout << "valid value of pos: " << pos << std::endl;
                for(int k = m_numElements; k >= pos; k--){
                    m_array[k+1] = m_array[k];
                }
            } else {
                std::cout << "invalid value of pos: " << pos << std::endl;
                return pos;
            }
      
            
            
            m_array[pos] = val;
            m_numElements++;
            std::cout << "number of elements: " << m_numElements << std::endl;
            
            return pos;

        }

        int findPos(T searchKey, int lowerBound, int upperBound)
        {
            assert(m_array != NULL);
            assert(lowerBound >= 0);
            assert(upperBound < m_numElements);

            int index = lowerBound + ((upperBound - lowerBound) / 2);

            if (lowerBound > upperBound){
                std::cout << "Valid position is after all current items" << std::endl;
                std::cout << "Inserting new item in expanded array" << std::endl;
                return lowerBound;
            } else if (m_array[index] == searchKey){
                std::cout << "No duplicates allowed!" << std::endl;
                std::cout << index << std::endl;
                std::cout << m_array[index] << std::endl;
                std::cout << searchKey << std::endl;
                return -1;
            } else if (m_array[index] > searchKey){
                if (m_array[index - 1] < searchKey){
                    std::cout << "found pos at " << index << std::endl;
                    return index;
                } else {
                    upperBound = index - 1;
                    std::cout << "going to upper case find " << index << std::endl;
                    return findPos(searchKey, lowerBound, upperBound);
                }              
            } else if (m_array[index] < searchKey){
                if (m_array[index + 1] > searchKey){
                    std::cout << "found pos at " << index << std::endl;
                    return (index + 1);
                } else {
                    lowerBound = index + 1;
                    std::cout << "going to lower case find " << index << std::endl;
                    return findPos(searchKey, lowerBound, upperBound);
                }
                
                
            }

            /*
            Have to return the find funciton so that the recursive functions return the
            value from the call stack. Otherwise, even if found, going back to the prev
            find call will result in it going out of the loop and returning -1
            */
            std::cout << "went out of recursion without pos" << std::endl;

            return -1;
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

        // Making this const allows for reading but not writing.
        virtual const T& operator[](int index)
        {
            assert(m_array != NULL && index <= m_numElements);
            return m_array[index];
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