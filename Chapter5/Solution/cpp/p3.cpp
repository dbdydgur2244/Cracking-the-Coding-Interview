#include <cstdio>
#include <algorithm>
#include <cstring>

int solve(char bits[]){
    int ans = 0, len = strlen(bits), bef;
    int dp[32][2] = {0, };
    
    bef = -1;

    dp[0][0] = (bits[0] == '1') ? 1 : 0;
    dp[0][1] = 0;
    if (bits[0] == '0'){
        dp[0][1] = 1;
        bef = 0;
    }

    for (int i = 1; i < len; ++i){
        if (bits[i] == '0'){
            dp[i][1] = dp[i -1][0] + 1;
            if (bef != -1)
                dp[i][1] -= dp[bef][1];
            bef = i;
            dp[i][0] = 0;
        }
        else{
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]) + 1;
        }
        ans = std::max({ ans, dp[i][0], dp[i][1] });
    }
    return ans;
}

int main(void){
    int n;
    scanf("%d", &n);

    char bits[33] = { 0, };
    for (int i = 0; i < 32; ++i){
        char bit = (n & (1 << i))  > 0 ? '1' : '0';
        bits[i] = bit; 
    }

    printf("%d\n", solve(bits));
    return 0;
}
