/* C++ program to construct tree using
inorder and postorder traversals 

This code was taken from https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/?ref=lbp
written by rathbhupendra. And then adapted to use post instead of preorder traversal. 

Is good. But why not use Node constructor instead of seperate helper function?

Will select last value in post array as root. Decrement index here for next call.
Then find the value in inArray and split into two ranges, left and right tree
Recursively call to create right tree from above two steps, then left tree.
Return both and then the function returns the root as the complete tree.
*/
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
    public:
        int data;
        node* left;
        node* right;
};
 
/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);
node* newNode(int data);
 
/* Recursive function to construct binary
of size len from Inorder traversal in[]
and Postorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking
for cases where inorder and preorder do not
form a tree */
node* buildTree(int in[], int post[], int inStrt, int inEnd)
{
    static int postIndex = inEnd;
 
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from postorder
    traversal using postIndex
    and increment postIndex */
    node* tNode = newNode(post[postIndex--]);
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);
 
    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->right = buildTree(in, post, inIndex + 1, inEnd);
    tNode->left = buildTree(in, post, inStrt, inIndex - 1);
    
 
    return tNode;
}
 
/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}
 
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}
 
/* This function is here just to test buildTree() */
void printInorder(node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout<<node->data<<" ";
 
    /* now recur on right child */
    printInorder(node->right);
}

void printPreorder(node* node)
{
    if (node == NULL)
        return;
 
    /* print the data of node */
    cout<<node->data<<" ";
    /* then recur on left child */
    printPreorder(node->left);
    /* now recur on right child */
    printPreorder(node->right);
}
 
/* Driver code */
int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int len = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, post, 0, len - 1);
 
    /* Let us test the built tree by
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
    cout << endl;

    cout << "Preorder traversal of the constructed tree is \n";
    printPreorder(root);
     cout << endl;
}