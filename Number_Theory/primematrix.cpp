// Incomplete

#include <iostream>

using namespace std;

int row[500], col[500];

bool isPrime(int n)
{
    if (n < 2 || (n % 2 == 0 && n != 2))
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n, m, x;
    cin >> n >> m;
    fill(row, row + 500, 0);
    fill(col, col + 500, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            if (isPrime(x))
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    int diff = 1000, best = 1000;
    for (int i = 0; i < n; i++)
    {
        diff = min(diff, m - row[i]);
    }
    for (int i = 0; i < m; i++)
    {
        diff = min(diff, n - col[i]);
    }
    cout << diff << endl;
}