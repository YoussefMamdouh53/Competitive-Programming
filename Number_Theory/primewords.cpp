#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n == 2 || n == 1)
        return true;
    if (!(n & 1))
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    string word;
    int sum;
    while (cin >> word)
    {
        sum = 0;
        for (char c : word)
        {
            if (c >= 'a' && c <= 'z')
                sum += c - 'a' + 1;
            else
                sum += c - 'A' + 27;
        }
        //cerr << sum << endl;
        puts(isPrime(sum) ? "It is a prime word." : "It is not a prime word.");
    }
}