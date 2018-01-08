#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> failure(const vector <int> &arr){
    int j = 0;
    
    vector <int> pi(arr.size(), 0);
    for(int i = 1; i < arr.size(); i++){
        while ( j > 0 && arr[i] != arr[j]){
            j = pi[j-1];
        }
        if(str[i] == str[j] ) {
            pi[i] = j + 1;
            j += 1;
        }
        else{
            pi[i] = 0;
        }
    }
}

bool kmp(const vector<int> &s,
        const vector<int> &p,
        const vector<int> &pi,
        ){
    int n = s.size();
    int m = p.size();
    int i = 0,j = 0;
    for(i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]){
            j = pi[j-1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                return true;    
            }

            else {
                j++;
            }
        }
    }
    return false;
}

bool solve(const vector <int> &s,
        const vector <int> &p
        ){
    vector <int> pi = failure(p);
    return kmp(s, p, pi);
}

void preorder(Treenode *node,
        vector <int> &preorder
        ){
    preorder.push_back(node->data);
    preorder(node->left);
    preorder(node->right);
}

int main(void){
    Treenode* T1;
    Treenode* T2;

    vector <int> preorder_T1;
    vector <int> preorder_T2;
    preorder(T1, preorder_T1);
    preorder(T2, preorder_T2);


    bool ans = solve(preorder_T1, preorder_T2);
    
    if (ans)
        printf("YES!\n");
    else
        printf("NO\n");
    return 0;
}
