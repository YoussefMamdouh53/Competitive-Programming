#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int rad[N], n ,f;
double hi = 0;

bool isvalid(double p){
    int cnt = 0;
    for (int i = 0;i<n;i++){
        cnt += (M_PI * rad[i] * rad[i]) / p;
    }
    return cnt > f;
}

double solve() {
    double lo = 0;
    hi *= 0.5;
    while (hi > 1e-9){
        if (isvalid(hi + lo)) lo += hi;
        hi *= 0.5;
    }
    return lo;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &f);
        for (int i = 0;i<n;i++) {
            scanf("%d", rad + i);
            hi = max(hi, M_PI * rad[i] * rad[i]);
        }
        printf("%.4f\n", solve());
        hi = 0;
    }
}