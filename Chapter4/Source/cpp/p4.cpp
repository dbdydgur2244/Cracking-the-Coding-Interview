#include <cstdio>
#include <vector>
#include <algorithm>

void check_leaf(const std::vector < std::vector < int > > &tree,
        std::vector < int > &leaf_node,
        int x, int h){
    if (tree[x].size() == 0)
        leaf_node.push_back(h);
    for (int i = 0; i < tree[x].size(); ++i){
        check_leaf(tree, leaf_node, tree[x][i], h + 1);
    }
}

int main(void){
    /*
     * input setting ......
     */
    std::vector < std::vector < int >> tree;
    std::vector < int > leaf_node;
    check_leaf(tree, leaf_node, 0, 0);
    std::sort(leaf_node);

    bool flag = true;
    if (leaf_node[leaf_node.size() - 1] - leaf_node[0] > 1)
        flag = false;
    flag ? printf("True\n") : printf("False\n");

    return 0;
}
