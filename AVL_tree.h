#pragma once

template <typename T>
struct Node
{
    T data;
    Node<T> *lchild;
    Node<T> *rchild;
    int height;
};

template <typename T>
using Node = Node<T>;

template <typename T>
int bal_factor(Node<T> *);

template <typename T>
int height(Node<T> *);

template <typename T>
int max_val(T a, T b);

template <typename T>
Node<T> *createNode();

template <typename T>
Node<T> *createNode(T);

template <typename T>
class AVLSearchTree
{
public:
    // DATA MEMEBERS
    Node<T> *root;
    Node<T> *ptr;

    // FUNCTIONS FOR CREATION
    AVLSearchTree();
    AVLSearchTree(T);

    // FUNCTIONS FOR INSERTION
    Node<T> *insertElement(Node<T> *nd, T elt);
    void ins_elt(T);

    Node<T> *LL_rot(Node<T> *nd);
    Node<T> *RR_rot(Node<T> *nd);
    Node<T> *LR_rot(Node<T> *nd);
    Node<T> *RL_rot(Node<T> *nd);

    //FUNCTIONS FOR DELETIONS
    Node<T>* min_val(Node<T>*);
    Node<T>* deleteElement(Node<T>*, T);
    void del_elt(T);

};

template <typename T>
using AVLT = AVLSearchTree<T>;

// DISPLAY FUNCTIONS
template <typename T>
void inorder(Node<T> *nd);

template <typename T>
void preorder(Node<T> *nd);

template <typename T>
void postorder(Node<T> *nd);

template <typename T>
void depth_first_traversal(Node<T>*&);

template <typename T>
void lvl_order_traversal(Node<T>*&);

