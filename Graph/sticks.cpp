#define LOCAL

#include <iostream>
#include <list>

using namespace std;

const int N = 1e6 + 5;
const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;

int n, m, u, v;
list<int> a[N], ans;
int visited[N];

bool DFS(int u)
{
    visited[u] = IN_PROGRESS;
    for (int v : a[u])
    {
        if (visited[v] == IN_PROGRESS){
            return true;
        }
        else if (visited[v] == NOT_VISITED){
            if (DFS(v)) return true;
        }
    }
    visited[u] = VISITED;
    ans.push_back(u);
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
START:
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) return 0;
        for (int i = 1;i<=n;i++){
            a[i].clear();
            visited[i]=0;
        }
        ans.clear();
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++){
            if (visited[i] == NOT_VISITED)
            {
                if (DFS(i)) {
                    puts("IMPOSSIBLE");
                    goto START;
                }
            }
        }
        for (int i : ans) printf("%d\n", i);
    }
}