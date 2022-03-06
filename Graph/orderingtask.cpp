
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100 + 5;

int n, m, u, v;
vector<int> a[N];
bool visited[N];

void DFS(int u, vector<int> &ans)
{
    visited[u] = 1;
    for (int v : a[u])
    {
        if (!visited[v])
        {
            DFS(v, ans);
        }
    }
    ans.push_back(u);
}

int main()
{
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) return 0;
        // Reset loop
        for (int i = 1;i<=n;i++){
            a[i].clear();
            visited[i]=0;
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
        }
        for (int i = 1; i <= n; i++){
            if (!visited[i])
            {
                DFS(i, ans);
            }
        }
        reverse(ans.begin(),ans.end());
        for (int i : ans) printf("%d ", i);
        printf("\n");
    }
}