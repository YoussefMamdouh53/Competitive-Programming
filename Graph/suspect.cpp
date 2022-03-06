#include <iostream>

using namespace std;

const int N = 3e4 + 5;

int parent[N], sz[N];

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

void merge(int x, int y)
{
    x = getleader(x);
    y = getleader(y);

    if (x == y)
        return;

    parent[x] = y;
    sz[y] += sz[x];
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2){
        if (n == 0 && m == 0) break;
        init();
        while (m--) {
            int k, x, y;
            scanf("%d %d", &k, &x);
            k--;
            while (k--){
                scanf("%d", &y);
                merge(x,y);
                x = y;
            }
        }
        printf("%d\n", sz[getleader(0)]);
    }
}