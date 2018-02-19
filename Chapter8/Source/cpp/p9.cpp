#include <cstdio>
const int N = 1000;
int n, ans;

void print(int x, int n, int parent[]){
    for (int i = 0; i < x; ++i){
        parent[i] ? printf(")") : printf("(");
    }
    for (int i = x; i < 2 * n; ++i)
        printf(")");
    puts("");
}

void solve(int left, int right, int x, int parent[]){
    if (left == 0){
        print(x, n, parent);
        ans++;
        return;
    }

    if (left > 0){
        parent[x] = 0;
        solve(left - 1, right, x + 1, parent);
    }
    if (left < right){
        parent[x] = 1;
        solve(left, right - 1, x + 1, parent);
    }
}

int main(void){
    int parent[N];
    scanf("%d", &n);
    solve(n, n, 0, parent);
    printf("%d\n", ans);
    return 0;
}
