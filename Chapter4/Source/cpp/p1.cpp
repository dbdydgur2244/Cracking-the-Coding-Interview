#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

bool dfs(
        const std::vector < std::vector < int > >&g,
        int src, int dest,
        int x)
{
    visited[x] = true;
    if (x == dest)
        return true;
    bool visit = false;
    for (const auto &next: g[x]){
        if (!visited[next])
            visit = visit || dfs(g, src, dest, next);
    }
    return visit;
}

bool bfs(
        const std::vector < std::vetor < int > > &g,
        int src, int dest)
{
    queue < int > q;
    q.push(src);
    visited[src] = true;
    bool visit = false;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(const auto &next: g[now]){
            if (!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    q.clear();
    return visit;
}

int main(void){
     
    return 0;
}
