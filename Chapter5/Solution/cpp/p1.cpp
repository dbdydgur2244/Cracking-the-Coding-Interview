#include <cstdio>
#include <cstring>

const int bits = 32;

void updateBit(char n[], char m[], int &i, int &j){
    int len_n = strlen(n), len_m = strlen(m), cnt = 1;
    
    for (int idx = 1; idx <= j - i + 1; ++idx){
        n[len_n - idx -i] = m[len_m - cnt++];
    }
}

int main(void){
    char n[bits], m[bits];
    int i, j;
    scanf("%s %s", n, m);
    scanf("%d %d", &i, &j);

    updateBit(n, m, i, j);
    printf("%s\n", n);
    return 0;
}
