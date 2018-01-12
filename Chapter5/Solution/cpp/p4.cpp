#include <cstdio>
#include <algorithm>

std::vector <int> getBit(int n){
    std::vector < int > v;
    for (int i = 0; i < 32; ++i){
        if (n < (1 << i))
            break;
        v.push_back( (n & (1 << i)) == 0 ? 0 : 1);
    }
    return v;
}

int main(void){
    int n;
    scanf("%d", &n);
    
    std::vector <int> small = getBit(n), large = getBit(n);
    std::vector <int> orig = getBit(n);

    std::reverse(orig.begin(), orig.end());
    std::reverse(small.begin(), small.end());
    std::reverse(large.begin(), small.end());

    std::prev_permutation(small.begin(), small.end());
    std::next_permutation(large.begin(), large.end());

    for (auto &i: orig)
        printf("%d", i);
    puts("");
    for (auto &i: small)
        printf("%d", i);
    puts("");
    for (auto &i: large)
        printf("%d", i);
    puts("");
    return 0;
}
