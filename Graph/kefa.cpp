#define LOCAL

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 1e5 + 5;

int n, m, u, v, ans = 0, hasCat[N];
vector<int> a[N];
bitset<N> visited;

void DFS(int u, int nOfCat)
{
    visited[u] = 1;
    if (hasCat[u])
        nOfCat++;
    else
        nOfCat = 0;
    if (nOfCat > m)
        return;
    if (a[u].size() == 1 && u != 1)
        ans++;
    else
    {
        for (int v : a[u])
        {
            if (!visited[v])
            {
                DFS(v, nOfCat);
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &hasCat[i]);
    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1, 0);
    printf("%d\n", ans);
}