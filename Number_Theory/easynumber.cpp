#include <iostream>

using namespace std;

const long m = 1 << 30;

int divCnt(long n)
{
    int cnt = 0, i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
            cnt += 2;
    }
    if (i * i == n)
        cnt++;
    return cnt;
}

int main()
{
    long long ans = 0;
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                ans += divCnt(i*j*k);
                ans %= m;
            }
        }
    }
    cout << ans << endl;
}