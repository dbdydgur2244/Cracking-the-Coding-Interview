#include <cstdio>
#include <algorithm>
using namespace std;
const int R = 1000, C = 1000;
int grid[R][C], dp[R][C];

void dfs(int x, int y){
    int &res = dp[x][y];
    if (res != -1)
        return;
    if (y - 1 >= 0 && grid[x][y - 1]){
        dfs(x, y - 1);
        res += dp[x][y - 1];
    }
    if (x - 1 >= 0 && grid[x - 1][y]){
        dfs(x - 1, y);
        res += dp[x - 1][y];
    }
}

int main(void){
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j){
        scanf("%d", &grid[i][j]);
        dp[i][j] = -1;
    }
    dp[0][0] = 1;
    dfs(r - 1, c - 1);
    printf("%d\n", dp[r - 1][c - 1]);
    return 0;
}
