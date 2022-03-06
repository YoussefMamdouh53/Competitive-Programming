#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int parent[N], sz[N], n, m, t = 1;

int getleader(int a) {
    if (a == parent[a]) return a;
    return parent[a] = getleader(parent[a]);
}
void merge(int a, int b) {
    a = getleader(a);
    b = getleader(b);

    if (a==b) return;
    parent[a] = b;
    sz[b] += sz[a];
}
void init() {
    for (int i = 0;i < N;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int main() {
    while (cin >> n >> m, n | m) {
        init();
        while (m--){
            int x,y;
            cin >> x >> y;
            merge(x,y);
        }
        set<int> s;
        for (int i = 1;i <= n;i++){
            s.insert(getleader(i));
        }
        cout << "Case " << t++ << ": " << s.size() << endl;
    }
}