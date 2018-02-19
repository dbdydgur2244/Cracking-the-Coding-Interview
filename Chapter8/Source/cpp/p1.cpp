#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000000;
int dp[N] = { 1, 1, 2 };

int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    printf("%d\n", dp[n]);
    return 0;
}
