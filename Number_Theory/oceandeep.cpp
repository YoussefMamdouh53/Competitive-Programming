#include <iostream>

using namespace std;

const long MOD = 131071;

long a[10005];

long solve(long n)
{
    if (a[n] != 0)
        return a[n];
    if (n < 20)
        return a[n] = (1 << n) % MOD;
    else if (n & 1)
        return a[n] = (solve(n >> 1) % MOD * solve((n >> 1) + 1) % MOD) % MOD;
    else
        return a[n] = (solve(n >> 1) % MOD * solve(n >> 1) % MOD) % MOD;
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    string s;
    while (cin >> s)
    {
        long ans = 0;
        for (int i = s.size() - 2, j = 0; i >= 0; i--, j++)
        {
            if (s[i] == '1')
                ans += solve(j);
            ans %= MOD;
        }
        if (ans % MOD == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}