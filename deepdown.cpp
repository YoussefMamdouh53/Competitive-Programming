#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> a[N]; 
int n, k, x;

bool isvalid(int c, int p){
    for (int i = 0; i < a[c].size(); i++){
        if (a[c][i] < p) p++;
        else return false;
    }
    return true;
}

int bs(int c) {
    long long lo = 1, hi = 1e12, mid;
    while (lo < hi){
        mid = (hi + lo) / 2;
        if (isvalid(c, mid)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return hi;
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            a[i].clear();
            for (int j = 0;j<k;j++){
                scanf("%d", &x);
                a[i].push_back(x);
            }
        }
        vector<pair<int,int>> v;
        for (int i = 0;i<n;i++){
            int k = bs(i);
            v.push_back({k, -a[i].size()});
        }
        sort(v.begin(), v.end());
        // puts("DEBUG");
        // for (auto i : v){
        //     cerr << i.first << " " << -i.second << endl;
        // }
        // puts("END");
        int ans = v[0].first, p;
        p = -v[0].second + v[0].first;
        for (int i = 0;i < v.size() - 1;i++){
            if (p < v[i+1].first) {
                ans += abs(p - v[i+1].first);
                p += abs(p - v[i+1].first);
            }
            p += -v[i+1].second;
            //cerr << "ANS: " << ans << " " << p <<  endl;
        }
        printf("%d\n", ans);
    }
}
/*
8
6 22 11 16 12 12 16
1 6
4 19 1 15 22
10 24 11 6 7 11 15 20 22 2 6
10 5 3 6 1 12 24 20 4 1 23
6 10 3 24 1 24 8
1 19
7 8 23 4 5 7 20 18

7 8    -> 1
20 30  -> 10
20 24  -> 4
20 21  -> 1
23 30  -> 7
23 29  -> 6
23 29  -> 6
25 35  -> 10

19 20    -> 1
20 30  -> 10
20 24  -> 4
20 21  -> 1
23 30  -> 7
23 29  -> 6
23 29  -> 6
25 35  -> 10
*/