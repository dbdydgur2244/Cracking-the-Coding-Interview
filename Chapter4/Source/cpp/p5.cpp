#include <cstdio>
#include <vector>

void inorder_travel(const std::vector < int > &tree,
        std::vector < int > &order,
        int n){
    order.push_back(tree[n]);
    if (tree.size() > 2 * n + 1)
        inorder_travel(2 * n  + 1);
    if (tree.size() > 2 * n + 2)
        inorder_travel(2 * n  + 2);
}

int main(void){
    /*
     *  assume already input
     */
    
    bool flag = true;
    for (int i =  1; i < order.size(); ++i)
        if (order[i - 1] > order[i]){
            flag = false; break;
        }
    return 0;
}
