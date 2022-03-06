#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 5e5 + 5;
int t, n, m, x, y;

int parent[N];

void init() {
    for (int i = 0;i<N;i++) parent[i] = i;
}

int getleader(int a){
    if (a == parent[a]) return a;
    return parent[a] = getleader(parent[a]);
}

void merge(int a, int b) {
    a = getleader(a);
    b = getleader(b);

    if (a == b) return;

    parent[a] = b;
}

bool same(int a, int b) {
    return getleader(a) == getleader(b);
}

int main() {
    freopen("meciul.in", "r", stdin);
    freopen("meciul.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d %d", &n, &m);
        for (int i = 0;i < m;i++) {
            scanf("%d %d", &x, &y);
            if (!same(x,y)){
                puts("YES");
                merge(x, y);
            }
            else {
                puts("NO");
            }
        }
        
    }
}