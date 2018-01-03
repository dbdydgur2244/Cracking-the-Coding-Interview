#include <cstdio>
#include <vector>
#include <cmath>

void inorder(const std::vector < std::vector < int > > &tree, int idx){
    printf("%d ", tree[idx]);
}

int main(void){
    int n, idx;
    int *a;
    scanf("%d", &n);
    a = new int[n];
    for (int i = 0; i < n; ++i)
        a[i] = i;

    std::vector < int > btree(1, 0);
    

    inorder(btree, 0);
    delete a;
    return 0;
}
