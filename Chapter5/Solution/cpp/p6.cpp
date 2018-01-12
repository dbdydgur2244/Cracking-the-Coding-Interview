#include <cstdio>
#include <cstring>

void getBits(int n, char bits[]){
    for (int i = 0; i < 32; ++i){
        int bit = n & (1 << i);
        bits[i] = (bit == 0 ? '0' : '1');
    }
}

int main(void){
    int n, m;
    char n_bits[33] = {0, }, m_bits[33] = {0, };
    scanf("%d %d", &n, &m);

    getBits(n, n_bits); getBits(m, m_bits);
    
    int len = strlen(n_bits), cnt = 0;
    for (int i = 0; i < len; ++i){
        if (n_bits[i] != m_bits[i])
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
