#include <cstdio>
#include <vector>
#include <algorithm>

int check_leaf(Tree* node, int height){
    int left_h, right_h;
    if (node == NULL)
        return height - 1;
    left_h = check_leaf(node->left,height + 1);
    right_h = check_left(node->right, height + 1);
    if (left_h == -1 || left_h != right_h)
        return -1;
    return height;
}

int main(void){
    /*
     * input setting ......
     */
   
    int flag = check_leaft(root, 1);
    if (flag != -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
