#include <cstdio>

int main(void){
    for (int i = 1; i <= 32; ++i){
        printf("%d\n", (i & (i - 1)) == 0);
    }
    return 0;
}
