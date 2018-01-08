#include <cstdio>
#include <vector>

void inorder_travel(const Tree *node,
        std::vector < int > &order,
        ){
    if (node == NULL)
        return;
    inorder_travel(node->left, order);
    order.push_back(node->val);
    inorder_travel(node->right, order);
}

bool check_bst(Tree *node){
    if (node == NULL)
        return true;
    if (node->left && node->left->val >= node->val)
        return false;
    if (node->right && node->right->val <= node->val)
        return false;
    return check_bst(node->left) && check_bst(node->right);
}

int main(void){
    /*
     *  assume already input
     */
   
    // check inorder travelsal result is increasing
    bool flag = true;
    for (int i =  1; i < order.size(); ++i)
        if (order[i - 1] > order[i]){
            flag = false; break;
        }

    // check left subtree is smaller than right subtree recursively
    flag = check_bst(root);
    return 0;
}
