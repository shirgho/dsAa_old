#include <string>

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

template<typename T>
class HashTable
{
    public:
        HashTable(int size) : m_size(0), m_totalItems(0)
        {
            if(size > 0){
                m_size = GetNextPrimeNum(size);
                m_table = new HashItem<T>[m_size];
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

        int HashFunction2(int key)
        {
            return 3 - key % 3;
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

        int GetTotalItems()
        {
            return m_totalItems;
        }

        bool Insert(int key, T &obj)
        {
            if(m_totalItems == m_size)
                return false;
            
            int hash = HashFunction(key);
            int step = HashFunction2(key);

            while(m_table[hash].GetKey() > 0){

                std::cout << m_table[hash].GetKey() <<" staying";
                //hash++; //for linear probing
                hash += step;
                hash %= m_size;
            }

            m_table[hash].SetKey(key);
            m_table[hash].SetObj(obj);

            m_totalItems++;

            return true;
        }

        void Delete(int key)
        {
            int hash = HashFunction(key);
            int originalHash = hash;
            int step = HashFunction2(key);

            while(m_table[hash].GetKey() != -1){
                if(m_table[hash].GetKey() == key){
                    m_table[hash].SetKey(-1);
                    m_totalItems--;

                    return;
                }

                //hash++; // for linear probing
                hash+= step; 
                hash %= m_size;

                if(originalHash == hash)
                    return;
            }
        }

        bool Find(int key, T *obj)
        {
            int hash = HashFunction(key);
            int originalHash = hash;
            int step = HashFunction2(key);

            while(m_table[hash].GetKey() != -1){
                if(m_table[hash].GetKey() == key){
                    if(obj != NULL)
                        *obj = m_table[hash].GetObject();

                    return true; 
                }

                //hash++;
                hash += step;
                hash %= m_size;

                if(originalHash == hash)
                    return false;
            }

            return false;
        }

        private:
            HashItem<T> *m_table;
            int m_size, m_totalItems;

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
};