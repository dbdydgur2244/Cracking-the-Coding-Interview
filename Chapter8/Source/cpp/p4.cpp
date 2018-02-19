#include <cstdio>
#include <vector>
using namespace std;
const int N = 30;

int a[N];
vector<int>res[N];

// using bit version
void solveByBit(int *a, int n, vector<vector<int>>&res){
    for (int i = 0; i < (1 << n); ++i){
        res[i].clear();
        for (int j = 0; (1 << j) < i; ++j){
            if (i & (1 << j))
                res[i].push_back(a[j]);
        }
    }
}
// using recursive
void solve(int x, int n, bool bits[]){
    static int idx = 0;
    if (x == n){
        for (int i = 0; i < n; ++i){
            if (bits[i])
                res[idx].push_back(a[i]);
        }
        idx++;
        return;
    }
    bits[x] = true;
    solve(x + 1, n, bits);
    bits[x] = false;
    solve(x + 1, n, bits);
}

int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    return 0;
}
