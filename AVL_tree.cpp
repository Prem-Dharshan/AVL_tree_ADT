#include "AVL_tree.h"
#include <iostream>
#include <stack>
#include <queue>

//----INSERTION----//

template <typename T>
void AVLSearchTree<T>::ins_elt(T elt)
{
    if (root == nullptr)
    {
        root = createNode<T>(elt);
    }
    else
    {
        root = insertElement(root, elt);
    }
}

template <typename T>
Node<T> *AVLSearchTree<T>::insertElement(Node<T> *nd, T elt)
{
    if (!nd)
    {
        return createNode<T>(elt);
    }
    if (elt < nd->data)
    {
        nd->lchild = insertElement(nd->lchild, elt);
    }
    else if (elt > nd->data)
    {
        nd->rchild = insertElement(nd->rchild, elt);
    }
    else
    {
        return nd;
    }

    nd->height = 1 + max_val(height(nd->lchild), height(nd->rchild));

    int balance = bal_factor(nd);

    if (balance > 1 && elt < nd->lchild->data)
    {
        return LL_rot(nd);
    }

    if (balance < -1 && elt > nd->rchild->data)
    {
        return RR_rot(nd);
    }

    if (balance > 1 && elt > nd->lchild->data)
    {
        return LR_rot(nd);
    }

    if (balance < -1 && elt < nd->rchild->data)
    {
        return RL_rot(nd);
    }

    return nd;
}

//----ROTATIONS----//
template <typename T>
Node<T> *AVLSearchTree<T>::LL_rot(Node<T> *nd)
{
    Node<T> *k = nd->lchild;
    nd->lchild = k->rchild;
    k->rchild = nd;

    nd->height = max_val(height(nd->lchild), height(nd->rchild)) + 1;
    k->height = max_val(height(k->lchild), height(k->rchild)) + 1;

    return k;
}

template <typename T>
Node<T> *AVLSearchTree<T>::RR_rot(Node<T> *nd)
{
    Node<T> *k = nd->rchild;
    nd->rchild = k->lchild;
    k->lchild = nd;

    nd->height = max_val(height(nd->lchild), height(nd->rchild)) + 1;
    k->height = max_val(height(k->lchild), height(k->rchild)) + 1;

    return k;
}

template <typename T>
Node<T> *AVLSearchTree<T>::LR_rot(Node<T> *nd)
{
    nd->lchild = RR_rot(nd->lchild);

    return LL_rot(nd);
}

template <typename T>
Node<T> *AVLSearchTree<T>::RL_rot(Node<T> *nd)
{
    nd->rchild = LL_rot(nd->rchild);

    return RR_rot(nd);
}

//----INSTANTIATION----//
template <typename T>
Node<T> *createNode()
{
    Node<T> *nd = new Node<T>;
    nd->lchild = nullptr;
    nd->rchild = nullptr;
    nd->height = 1;

    return nd;
}

template <typename T>
Node<T> *createNode(T elt)
{
    Node<T> *nd = new Node<T>;
    nd->data = elt;
    nd->lchild = nullptr;
    nd->rchild = nullptr;
    nd->height = 1;

    return nd;
}

template <typename T>
AVLSearchTree<T>::AVLSearchTree()
{
    root = nullptr;
}

template <typename T>
AVLSearchTree<T>::AVLSearchTree(T elt)
{
    root = createNode<T>(elt);
}

//----UTILITY FNS----//
template <typename T>
int max_val(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
int bal_factor(Node<T> *nd)
{
    if (nd == nullptr)
    {
        return 0;
    }
    return height(nd->lchild) - height(nd->rchild);
}

template <typename T>
int height(Node<T> *nd)
{
    if (nd == nullptr)
    {
        return 0;
    }
    return nd->height;
}

//----TRAVERSAL FNS----//
template <typename T>
void inorder(Node<T> *nd)
{
    if (nd)
    {
        inorder(nd->lchild);
        std::cout << nd->data << ' ';
        inorder(nd->rchild);
    }
}

template <typename T>
void preorder(Node<T> *nd)
{
    if (nd)
    {
        std::cout << nd->data << ' ';
        preorder(nd->lchild);
        preorder(nd->rchild);
    }
}


template <typename T>
void lvl_order_traversal(Node<T> *&nd)
{
        if (nd == nullptr)
        {
                return;
        }

        std::queue<Node<T>*> q;

        q.push(nd);


        while (!q.empty())
        {
                Node<T>* curr = q.front();
                q.pop();

                std::cout << curr->data << ' ';

                if (curr->lchild != nullptr) q.push(curr->lchild);
                if (curr->rchild != nullptr) q.push(curr->rchild);
        }

        return;
}

template <typename T>
void depth_first_traversal(Node<T> *&nd)
{
        if (nd == nullptr)
        {
                return;
        }

        std::stack<Node<T>*> st;
        st.push(nd);

        while (!st.empty())
        {
                Node<T>* curr = st.top();
                st.pop();

                std::cout << curr->data << ' ';

                if (curr->rchild != nullptr) st.push(curr->rchild);
                if (curr->lchild != nullptr) st.push(curr->lchild);
        }

        return;
}

template <typename T>
Node<T>* AVLSearchTree<T>::min_val(Node<T>* nd)
{
    Node<T>* pptr = nd;
    while (pptr->lchild)
    {
        pptr = pptr->lchild;
    }

    return pptr;
}

template <typename T>
void postorder(Node<T> * nd)
{
    if (nd)
    {
        postorder(nd->lchild);
        postorder(nd->rchild);
        std::cout << nd->data << ' ';
    }
}

template <typename T>
void AVLSearchTree<T>::del_elt(T elt)
{
    root = deleteElement(root, elt);
}

template <typename T>
Node<T>* AVLSearchTree<T>::deleteElement(Node<T>* nd, T elt)
{
    if (nd == nullptr)
    {
        return nd;
    }
    if (elt < nd->data)
    {
        nd->lchild = deleteElement(nd->lchild, elt);
    }
    else if (elt > nd->data)
    {
        nd->rchild = deleteElement(nd->rchild, elt);
    }
    else
    {
         if (nd->lchild == nullptr or nd->rchild == nullptr)
        {
            Node<T> *temp = (nd->lchild) ? nd->lchild : nd->rchild;

            if (temp == nullptr)
            {
                temp = nd;
                nd = nullptr;
            }
            else
            {
                *nd = *temp;
            }

            delete temp;
        }
        else
        {
            Node<T>* pptr = min_val(nd->rchild);
            nd->data = pptr->data;
            nd->rchild = deleteElement(nd->rchild, pptr->data);
	}
    }

    if (nd == nullptr)
        return nd;

    nd->height = 1 + max_val(height(nd->lchild), height(nd->rchild));

    int balance = bal_factor(nd);

    if (balance > 1 && bal_factor(nd->lchild) >= 0)
        return LL_rot(nd);

    if (balance < -1 && bal_factor(nd->rchild) <= 0)
        return RR_rot(nd);

    if (balance > 1 && bal_factor(nd->lchild) < 0)
    {
        return LR_rot(nd);
    }

    if (balance < -1 && bal_factor(nd->rchild) > 0)
    {
        return RL_rot(nd);
    }

    return nd;
}

