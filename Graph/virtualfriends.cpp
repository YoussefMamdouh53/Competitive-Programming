#include <iostream>
#include <list>
#include <map>

const int N = 1e5 + 5;

int parent[N], sz[N], t, cnt = 1, n;
std::map<std::string, int> m;
std::string x, y;

void init()
{
    cnt = 1;
    m.clear();
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
    std::cin >> t; //scanf("%d", &t);
    while (t--)
    {
        init();
        std::cin >> n; //scanf("%d", &n);
        while (n--)
        {
            std::cin >> x >> y; //scanf("%s %s", &x, &y);
            if (m[x] == 0)
                m[x] = cnt++;
            if (m[y] == 0)
                m[y] = cnt++;
            makefriend(m[x], m[y]);
            printf("%d\n", sz[getleader(m[x])]);
        }
    }
}