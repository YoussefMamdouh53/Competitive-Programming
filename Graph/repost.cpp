#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

const int N = 205;

int n, id = 1, ans = 0;
list<int> edges[N];
unordered_map<string, int> m;
string a,b;
bool visited[N];

void DFS(int u, int depth) {
    visited[u] = true;
    ans = max(ans, depth);
    for (int v : edges[u]){
        if (!visited[v] )DFS(v, depth + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 0;i<n;i++){
        cin >> a >> b >> b;
        transform(a.begin(), a.end(),a.begin(), ::toupper);
        transform(b.begin(), b.end(),b.begin(), ::toupper);
        if (m.count(a) == 0) m[a] = id++;
        if (m.count(b) == 0) m[b] = id++;
        edges[m[a]].push_back(m[b]);
        edges[m[b]].push_back(m[a]);
    }
    DFS(m["POLYCARP"], 1);
    cout << ans << endl;
}