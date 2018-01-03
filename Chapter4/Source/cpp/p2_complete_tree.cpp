#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
typedef std::pair < int, int > ii;

void inorder(const std::vector < int > &tree, int idx){
    if (2 * idx < (int)tree.size())
        inorder(tree, 2 * idx);
    printf("%d ", tree[idx]);
    if (2 * idx + 1 < (int)tree.size())
        inorder(tree, 2 * idx + 1);
}

int main(void){
    int n, idx;
    int *a;
    scanf("%d", &n);
    a = new int[n + 1];
    for (int i = 1; i <= n; ++i)
        a[i] = i;

    std::queue < ii > q;
    std::vector < int > btree(1, 0);
    
    q.push(ii(1, n));
    while (!q.empty()){
        int start = q.front().first;
        int end = q.front().second;
        int k = (int)log2(end - start + 1) + 1;
        q.pop();
        if (k > 1){
            idx = (1 << (k - 2)) - 1 +
                std::min(
                    end - start + 2 - (1 << (k - 1)),
                    (1 << (k - 2))
                );
        }
        else
            idx = 0;
        btree.push_back(a[start + idx]);
        if(idx > 0)
            q.push(ii(start, start + idx - 1));
        if (start + idx < end)
            q.push(ii(start + idx + 1, end));
    }
    inorder(btree, 1);
    delete a;
    return 0;
}
