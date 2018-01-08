#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    vector < vector < int > > g;
    vector < int > in;

    int n = 6;
    g.resize(7); in.resize(7);
    g[1].push_back(4); in[4]++;
    g[6].push_back(2); in[2]++;
    g[2].push_back(4); in[4]++;
    g[6].push_back(1); in[1]++;
    g[4].push_back(3); in[3]++;
    
    priority_queue < int > pq;
    vector < int > ans;

    for (int i = 1; i <= n; i++) {
        if (!in[i])
            pq.push(-i);
    }

    while (!pq.empty()) {
        int here = -pq.top();
        pq.pop();
        ans.push_back(here);
        for (int there : g[here]) {
            in[there]--;
            if (!in[there])
                pq.push(-there);
        }
    }
    if (ans.size() < n){
        printf("Impossible");
    }
    else
        for(auto idx: ans)
            printf("%c ", idx - 1 + 'a');
    puts("");
    return 0;
}
