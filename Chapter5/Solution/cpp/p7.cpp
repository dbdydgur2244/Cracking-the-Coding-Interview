#include <cstdio>

void getBits(char bits[], int n){
    for (int i = 0; i < 32; ++i){
        if (n < (1 << i))
            return;
        bits[i] = 
            (n & (1 << i)) == 0 ? '0' : '1';
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    
    int swaped;
    char bits[33] = { 0, };

    swaped = ((n << 1) & 0xAAAAAAAA);
    swaped = swaped | ((n >> 1) & 0x55555555);
    getBits(bits, swaped);
    printf("%s\n", bits);
    return 0;
}
