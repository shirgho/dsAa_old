#include <vector>
#include <assert.h>

template<class TYPE>
class KdTree;

template<class TYPE>
class KdNode
{
    friend KdTree<TYPE>;

    public:

        KdNode(std::vector<TYPE> &key): m_key(key), m_left(NULL),
                        m_right(NULL)
            {

            }

        ~KdNode()
        {
            if(m_left != NULL)
                delete m_left;
                m_left = NULL;

            if(m_right != NULL)
                delete m_right;
                m_right = NULL;
        }

    private:
        std::vector<TYPE> m_key;
        KdNode *m_left, *m_right;
};

template<typename TYPE>
class KdTree
{
    public:
        KdTree(int depth) : m_root(0), m_depth(depth)
        {
            assert(depth > 0);
        }

        ~KdTree()
        {
            if(m_root != NULL){
                delete m_root;
                m_root = NULL;
            }
        }

        void push(std::vector<TYPE> &key)
        {
            KdNode<TYPE> *newNode = new KdNode<TYPE> (key);

            if(m_root == NULL){
                m_root = newNode;
                return;
            }

            KdNode<TYPE> *parentNode = m_root;
            KdNode<TYPE> *currentNode = m_root;
            int level = 0;

            while (1)
            {
                
                parentNode = currentNode;

                if(key[level] < currentNode->m_key[level]){
                    currentNode = currentNode->m_left;
                    if(currentNode == NULL){
                        parentNode->m_left = newNode;
                        return;
                    }
                    
                } else {
                    currentNode = currentNode->m_right;
                    if(currentNode == NULL){
                        parentNode->m_right = newNode;  
                        return;
                    }  
                }

                level++;
                if(level >= m_depth)
                    level = 0;
            }
        }

        void displayRange(const std::vector<TYPE> &low, const std::vector<TYPE> &high)
        {
            displayRange(0, low, high, m_root);
        }
        void DisplayPreOrder()
        {
            DisplayPreOrder(m_root);
        }

    private:
        KdNode<TYPE> *m_root;
        int m_depth;

        void displayRange(int level, const std::vector<TYPE> &low, const std::vector<TYPE> &high, KdNode<TYPE> *node)
        {
            if(node != NULL){
                int i;
                for(i = 0; i < m_depth; i++){
                    if(low[i] > node->m_key[i] || high[i] < node->m_key[i])
                        break;
                }

                if(i == m_depth){
                    std::cout << "(";

                    for(int j = 0; j < m_depth; j++){
                        std::cout << node->m_key[j];
                        if( j != m_depth - 1)
                            std::cout << ", ";
                    }

                    std::cout << ")" << std::endl;
                }
                level++;

                if(level >= m_depth)
                    level = 0;
                
                if(low[level] <= node->m_key[level])
                    displayRange(level, low, high, node->m_left);
                
                if(high[level] >= node->m_key[level])
                    displayRange(level, low, high, node->m_right);
            }
        }

        void DisplayPreOrder(KdNode<TYPE> *node)
        {
            if(node != NULL){
                std::cout << "(";

                for(int i = 0; i < m_depth; i++)
                    std::cout << node->m_key[i] << ", ";

                std::cout << ")" << std::endl;
                
                DisplayPreOrder(node->m_left);
                DisplayPreOrder(node->m_right);

                
            }

        }
};