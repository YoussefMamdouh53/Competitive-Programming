#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int stalls[N], n, c;

bool isvalid(int d){
    int j = c;
    int last = -1e6;
    for (int i = 0; i < n; i++){
        if (stalls[i] >= last + d){
            last = stalls[i];
            j--;
        }
        if (j == 0) return true;
    }
    return false;
}

int solve() {
    int lo = 1, hi = stalls[n-1] - stalls[0], mid;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (isvalid(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return hi;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &c);
        for (int i = 0; i < n; i++)
            scanf("%d", stalls + i);

        sort(stalls, stalls + n);

        printf("%d\n", solve());
    }
}