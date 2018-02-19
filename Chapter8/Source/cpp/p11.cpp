#include <cstdio>
/* Use Dynamic programming
 * Space Complexity : O(n)
 * Time Complexitiy : O(n)
 */
const int N = 1000000;

int main(void){
    int n;
    int dp[N];
    int coin[] = { 1, 5, 10, 25};
    scanf("%d", &n);
    

    for (int i = 0; i < 4; ++i){
        int co = coin[i];
        dp[co]++;
        for (int i = co + 1; i <= n; ++i){
            dp[i]++;
        }   
    }

    printf("%d\n", dp[n]);

    return 0;
}
