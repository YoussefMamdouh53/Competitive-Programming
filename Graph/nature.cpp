#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 5;

int n, m, mx;
int leader[N], sz[N];
unordered_map<string, int> mp;

int getleader(int x) {
    if (leader[x] == x) return x;
    return leader[x] = getleader(leader[x]);
}
void merge(int x, int y) {
    x = getleader(x);
    y = getleader(y);
    if (x == y) return;
    leader[x] = y;
    sz[y] += sz[x];
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
            return 0;
        string s,k;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            mp[s] = i;
            leader[i] = i;
            sz[i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> s >> k;
            merge(mp[s], mp[k]);
        }
        cout << *max_element(sz, sz + n) << endl;
    }
}