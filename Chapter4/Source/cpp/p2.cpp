#include <cstdio>
#include <vector>
#include <cmath>
#include "Tree/BST.h"

void solve(
        class BinarySearchTree &bst,
        int start, int end
        )
{
    if (start > end)
        return;
    int mid = (start + end) / 2;
    bst.insert(mid);
    solve(bst, start, mid - 1);
    solve(bst, mid + 1, end);
}

int main(void){
    int n, idx;
    int *a;
    scanf("%d", &n);
    class BinarySearchTree bst;
    solve(bst, 0, n - 1);
    bst.print_inorder();
    return 0;
}
