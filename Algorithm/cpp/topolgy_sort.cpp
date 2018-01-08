#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

bool topology_sort(
        vector<vector<int>> g,
        vector<int> ans
        ){
    vector < int > in(g.size(), 0);
    for (int i = 0; i < g.size(); ++i){
        for(int j = 0; j < g[j].size(); ++j){
            in[g[i][j]]++;
        }
    }

    priority_queue < int > pq;

    for (int i = 0; i < n; ++i){
        if(!in[i])
            pq.push(-i);
    }
    
    while(!pq.empty()){
        int here = -pq.top();
        pq.pop();
        ans.push_back(here);
        for (int next:g[here]){
            in[next]--;
            if (!in[next])
                pq.push(-next);
        }
    }

    if (ans.size() < n)
        return false;
    return true;
}

