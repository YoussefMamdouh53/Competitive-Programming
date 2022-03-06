#include <iostream>
#include <algorithm>

const int N = 3e4 + 5;

int parent[N], sz[N], t, n, m, x, y;

void init()
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int getleader(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getleader(parent[x]);
}

void makefriend(int x, int y)
{
    x = getleader(x);
    y = getleader(y);

    if (x == y)
        return;

    parent[x] = y;
    sz[y] += sz[x];
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        init();
        scanf("%d %d", &n, &m);
        while (m--)
        {
            scanf("%d %d", &x, &y);
            makefriend(x, y);
        }
        printf("%d\n", *std::max_element(sz + 1, sz + n + 1));
    }
}