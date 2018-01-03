#include <cstdio>
#include <list>
#include <vector>
using namespace std;

void travel(const std::vector < std::vector < int > > &tree,
        std::vector < std::list < int > > &dtree,
        int x, int depth){
    for (int i = 0; i < tree[depth].size(); ++i){
        dtree[depth].push(tree[depth][i]);
        travel(tree, dtree, i, depth + 1);
    }
}

//assume that already has tree
int main(void){
    std::vector < std::list < int > > depth_tree;
    std::vector < std::vector < int >  > tree;
    int n;
    /*
     * input n, tree, height
     */
    depth_tree.resize(height);

    depth_tree[0].push(dtree[0][0]);
    travel(tree, depth_tree, 1);
    return 0;
}
