#include <iostream>
#include "AVL_tree.h"
#include "AVL_tree.cpp"
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7};

    AVLT<int> tree(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        tree.ins_elt(arr[i]);
        preorder(tree.root);
        cout << endl;
    }

    cout << "Deleting in the inserted order:" << endl;

    for (auto val : arr)
    {
         tree.del_elt(val);
         preorder(tree.root);
         cout << endl;
    }

    return 0;
}
