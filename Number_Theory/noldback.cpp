#include <iostream>
#include <set>

using namespace std;

const int N = 1005;

bool prime[N];

void sieve()
{
    fill(prime, prime + N, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    sieve();
    int n, k, cnt = 0;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (prime[j])
                {
                    if ((i + j + 1 <= n) && prime[i + j + 1])
                    {
                        cnt++;
                    }
                    break;
                }
            }
        }
    }
    cout << (cnt >= k ? "YES" : "NO") << endl;
}