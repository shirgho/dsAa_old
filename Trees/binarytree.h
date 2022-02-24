#include <iostream>
#include <queue>

template <typename T>
class BinaryTree;

template <typename T>
class Node
{
    friend BinaryTree<T>;

    public:

        Node(T Key): m_key(Key), m_left(NULL),
                        m_right(NULL)
            {

            }

        ~Node()
        {
            if(m_left != NULL)
                delete m_left;
                m_left = NULL;

            if(m_right != NULL)
                delete m_right;
                m_right = NULL;
        }

        T GetKey()
        {
            return m_key;
        }

    private:
        T m_key;
        Node *m_left, *m_right;
};

template <typename T>
class BinaryTree
{
    public:
        BinaryTree() : m_root(NULL)
        {

        }
        ~BinaryTree()
        {
            if(m_root != NULL){
                delete m_root;
                m_root = NULL;
            }
        }

        void DisplayPreOrder()
        {
            DisplayPreOrder(m_root);
        }


        void DisplayPostOrder()
        {
            DisplayPostOrder(m_root);
        }


        void DisplayInOrder()
        {
            DisplayInOrder(m_root);
        }

/*         bool push(T key){
            Node<T> * newNode = new Node<T>(key);

            if(m_root == NULL){
                m_root = newNode;
            } else {
                Node<T> *parentNode = NULL;
                Node<T> *currentNode = m_root;

                parentNode = currentNode;

                if(key == currentNode->m_key){
                    delete newNode;
                    return false;
                }

                if(key < currentNode->m_key){
                    while(currentNode != NULL){
                        parentNode = currentNode;
                        currentNode = currentNode->m_left;
                    }
                    parentNode->m_left = newNode;
                    return true;
                }


                if(key > currentNode->m_key){
                    while(currentNode != NULL){
                        parentNode = currentNode;
                        currentNode = currentNode->m_right;
                    }
                    parentNode->m_right = newNode;
                    return true;
                }
            }

            return true;
        } */

        bool push(T key){
            Node<T> * newNode = new Node<T>(key);

            if(m_root == NULL){
                m_root = newNode;
            } else {
                Node<T> *parentNode = NULL;
                Node<T> *currentNode = m_root;

                while (1)
                {
                   
                    parentNode = currentNode;

                    if(key == currentNode->m_key){
                        delete newNode;
                        return false;
                    }

                    if(key < currentNode->m_key){
                        currentNode = currentNode->m_left;
                        if(currentNode == NULL){
                            parentNode->m_left = newNode;
                            return true;
                        }
                        
                    } else {
                        currentNode = currentNode->m_right;
                        if(currentNode == NULL){
                            parentNode->m_right = newNode;  
                            return true;
                        }  
                    }
                }
            }
            return true;
        }

        bool search(T key)
        {
            if(m_root == NULL)
                return false;

            Node<T> *currentNode = m_root;

            while(currentNode->m_key != key){
                if(key < currentNode->m_key)
                    currentNode = currentNode->m_left;
                else
                    currentNode = currentNode->m_right;
                
                if(currentNode == NULL)
                    return false;
            }
            return true;
        }

        int maxDepthRecursive(Node<T> *root)
        {
            //traverse tree recursively to left and right end leaf, and count back up to get the depth
            //on each call, return max of the left/right depths + 1 (to count the current level)
        
            if (root == NULL) return 0;
            
            int maxDepthLeft = maxDepthRecursive(root->m_left);
            int maxDepthRight = maxDepthRecursive(root->m_right);
            
            return std::max(maxDepthLeft, maxDepthRight) + 1;
        }

        int maxDepthIterative()
        {
            
        }

        int minDepthRecursive(Node <T> *root) 
        {
            if (root == NULL) 
                return 0;
            int leftMinDepth = 0, rightMinDepth = 0;
            
            if(root->m_left == NULL && root->m_right == NULL)
                return 1;
            else if(root->m_left != NULL && root->m_right == NULL){
                leftMinDepth = minDepthRecursive(root->m_left);
                return leftMinDepth + 1;
            } else if(root->m_right !=NULL && root->m_left == NULL){
                rightMinDepth = minDepthRecursive(root->m_right);
                return rightMinDepth + 1;
            } else {
                leftMinDepth = minDepthRecursive(root->m_left);
                rightMinDepth = minDepthRecursive(root->m_right);
                return std::min(leftMinDepth, rightMinDepth) + 1;
            }   
        }

        int minDepthIterative() 
        {  
            int l=1;

            std::queue<Node<T> *> q;

            Node<T> *startRoot = m_root;

            if(startRoot==NULL)
            {
                return 0;
            }
            q.push(startRoot);
            while(!q.empty())
            {
                int n=q.size();
                while(n--)
                {
                    Node<T> *temp = q.front();
            
                    q.pop();
                    // leaf found
                    if(temp->m_left == NULL && temp->m_right == NULL)
                    {
                    return l;
                    }
                    
                    if(temp->m_left == NULL)
                    {
                        q.push(temp->m_right);
                    }
                    if(temp->m_right == NULL)
                    {
                        q.push(temp->m_left);
                    }
                    if(temp->m_left !=NULL && temp->m_right != NULL)
                    {
                        q.push(temp->m_left);
                        q.push(temp->m_right);
                    }      
                }
                l++;
            }
            return 0;    
        }

        void remove(T key)
        {
            if(m_root == NULL)
                return;
            
            Node<T> *parent = m_root;
            Node<T> *node = m_root;
            bool isLeftNode = false;

            while(node->m_key != key){
                parent = node;

                if(key < node->m_key){
                    node = node->m_left;
                    isLeftNode = true;
                } else {
                    node = node->m_right;
                    isLeftNode = false;
                }

                if(node == NULL)
                    return;
            }

            //if node has no children
            if(node->m_left == NULL && node->m_right == NULL){
                if(node == m_root)
                    m_root == NULL;
                else if(isLeftNode == true)
                    parent->m_left = NULL;
                else
                    parent->m_right = NULL;
            // if node has right child
            } else if(node->m_left == NULL){
                if(node == m_root)
                    m_root == node->m_right;
                else if(isLeftNode == true)
                    parent->m_left = node->m_right;
                else
                    parent->m_right = node->m_right;
            // if node has left child
            } else if(node->m_right == NULL){
                if(node == m_root)
                    m_root == node->m_left;
                else if(isLeftNode == true)
                    parent->m_left = node->m_left;
                else
                    parent->m_right = node->m_left;
            // if node has both right and left child
            } else {
                Node<T> *tempNode = node->m_right;
                Node<T> *successor = node;
                Node<T> *successorParent = node;

                while(tempNode != NULL){
                    successorParent = successor;
                    successor = tempNode;
                    tempNode = tempNode->m_left;
                }

                // if first right child not taken
                if(successor != node->m_right){
                    successorParent->m_left = successor->m_right;
                    successor->m_right = node->m_right;
                }
                if(node == m_root){
                    m_root = successor;
                } else if (isLeftNode){
                    node = parent->m_left;
                    parent->m_left = successor;
                } else {
                    node = parent->m_right;
                    parent->m_right = successor;
                }
                successor->m_left = node->m_left;
            }

            //Nullify so destructor does not delete any nodes they might point to still
            node->m_left = NULL;
            node->m_right = NULL;
            delete node;
        }

        Node<T>* GetRoot()
        {
            return m_root;
        } 
    
    private:
        Node<T> *m_root;

        void DisplayPreOrder(Node<T> *node)
        {
            if(node != NULL){
                std::cout << node->m_key << " ";

                DisplayPreOrder(node->m_left);
                DisplayPreOrder(node->m_right);
            }

        }

        void DisplayPostOrder(Node<T> *node)
        {
            if(node != NULL){
                DisplayPostOrder(node->m_left);
                DisplayPostOrder(node->m_right);
            
                std::cout << node->m_key << " ";
            }
            
        }

        void DisplayInOrder(Node<T> *node)
        {
            if(node != NULL){
                DisplayInOrder(node->m_left);
                std::cout << node->m_key << " ";
                DisplayInOrder(node->m_right);         
            }
            
        }
};
