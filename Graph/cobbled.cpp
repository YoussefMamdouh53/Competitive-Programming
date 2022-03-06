#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, M = 3e5 + 5;
int t, p, n, m, x, y , z;
#define U second.first
#define V second.second

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
    pair<int , pair<int,int>> edge[M];
    cin >> t;
    while (t--) {
        init();
        long long cost = 0;
        cin >> p >> n >> m;
        for (int i = 0;i < m;i++) {
            cin >> x >> y >> z;
            edge[i] = {z , {x,y}};
        }
        sort(edge,edge+m);
        for (int i = 0;i<m;i++){
            if (!same(edge[i].U, edge[i].V)) {
                merge(edge[i].U, edge[i].V);
                cost += edge[i].first;
            }
        }
        cout << cost * p << endl;
    }
}