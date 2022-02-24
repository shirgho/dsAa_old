#include <string>
#include <list>
#include <iterator>

template<typename T>
class HashItem
{
    public:
        HashItem() : m_key(0) {}
        ~HashItem() {}

        int GetKey() { return m_key; }
        void SetKey(int k) { m_key = k; }

        T GetObject() { return m_obj; }
        void SetObj(T obj) {m_obj = obj; }

        bool operator==(HashItem &item)
        {
            if(m_key == item.GetKey())
                return true;
            
            return false;
        }

        bool operator=(HashItem item)
        {
            m_key = item.GetKey();
            m_obj = item.GetObject();

        }

    private:
        int m_key;
        T m_obj;

};

// Seperate Chaining
// Array of link lists
template<typename T>
class HashTable
{
    public:
        HashTable(int size) : m_size(0)
        {
            if(size > 0){
                m_size = GetNextPrimeNum(size);
                m_table = new std::list<HashItem<T>>[m_size];
            }
        }

        ~HashTable()
        {
            if(m_table != NULL){
                delete[] m_table;
                m_table = NULL;
            }
        }

        int HashFunction(int key)
        {
            return key % m_size;

        }

        int HashFunction(std::string &str)
        {
            int hash = 0;

            for(int i=0; i < (int)str.size(); i++){
                int val = (int(str[i]));
                hash = (hash * 256 + val) % m_size;
            }

            return hash;
        }

        int GetSize()
        {
            return m_size;
        }

        void Insert(int key, T &obj)
        {
            HashItem<T> item;
            item.SetKey(key);
            item.SetObj(obj);
            
            int hash = HashFunction(key);
            m_table[hash].push_back(item);

        }

        void Delete(int key)
        {
            int hash = HashFunction(key);
            
            std::list<HashItem<T>> *ptr = &m_table[hash];
            typename std::list<HashItem<T>>::iterator it;

            for(it = ptr->begin(); it!= ptr->end(); it++){
                if(it->GetKey() == key){
                    ptr->erase(it);
                    break;
                }
            }
        }

        bool Find(int key, T* obj)
        {
            int hash = HashFunction(key);

            std::list<HashItem<T>> *ptr = &m_table[hash];
            typename std::list<HashItem<T>>::iterator it;

            for(it = ptr->begin(); it != ptr->end(); it++){
                if((*it).GetKey() == key){
                    if(obj != NULL)
                        *obj = (*it).GetObject();

                    return true;
                }
            }

            return false;
        }

        bool isNumPrime(int val){
            for(int i=2; (i * i) <= val; i++){
                if((val % i) == 0)
                    return false;
            }

            return true;
        }

        int GetNextPrimeNum(int val){
            for(int i = val + 1; ; i++){
                if(isNumPrime(i))
                    break;
            
                return i;
            }
        }
        
        private:
            std::list<HashItem<T>> *m_table;
            int m_size;

};