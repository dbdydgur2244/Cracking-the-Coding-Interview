#include <cstdio>
#include <cstring>
typedef long long ll;

bool solve(char bits[], unsigned long long n){

    for (int i = 0; i < 32; ++i){
        int bit = n & (1 << i);
        if (bit != 0)
            return false;
    }

    for (int i = 32; i < 64; ++i){
        unsigned long long bit = n & (1ll << i);
        printf("%d %d\n", i, bit != 0);
        bits[64 - i - 1] = 
            (bit != 0 ? '1' : '0');
    }
    return true;
}

int main(void){
    char bits[33] = {0, };
    union{
        double dn;
        unsigned long long un;
    } n;
    scanf("%lf", &n.dn);
    solve(bits, n.un) ? printf("%s\n", bits) : printf("ERROR\n");
    return 0;
}
