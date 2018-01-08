#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

bool solve(const std::vector <int> &arr,
        int start, int end, int t){

    int mid = (start + end) / 2;
    if (start > end)
        return false;
    if (start == end){
        if (arr[start] == t)
            return true;
        else
            return false;
    }
    bool left = solve(arr, start, mid);
    bool right = solve(arr, mid + 1, end);
    bool flag = false;
    if (left || right)
        return true;
    else{
        std::map < int , int > hash;
        int sum = 0;
        for (int i = mid; i >= 0; --i){
            sum += arr[i];
            if (sum == t)
                flag = true;
            hash[sum] = 1;
        }
        for (int i = mid + 1; i <= end; ++i){
            if (hash[t - arr[i]])
                flag = true;
        }
    }
    return flag;
}

void dfs(TreeNode *node, std::vector < int > &arr, int t){
    if (node == NULL){
        solve(arr, 0, arr.size() - 1, t);
        return;
    }
    arr.push_back(node->data);
    dfs(node->left, arr, t);
    dfs(node->right, arr, t);
}

int main(void){

    return 0;
}
