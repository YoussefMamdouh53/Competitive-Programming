#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[100][100];

int ks(const vector<int> &weights, const vector<int> &costs, int capacity) {
    memset(dp, 0, sizeof dp);
    int sz = weights.size();
    for (int i = 1;i <= sz; i++){
        for (int j = 1;j <= capacity; j++){
            if (j >= weights[i - 1])
                dp[i][j] = max(dp[i - 1][j], costs[i-1] + dp[i-1][j - weights[i-1]]);
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for (int i = 1;i<=sz;i++){
        for (int j = 1;j<=capacity;j++){
            printf("%-5d", dp[i][j]);
        }
        cout << endl;
    }
    return dp[sz][capacity];
}

int main() {
    vector<int> cost, weight;
    cost.push_back(10);
    cost.push_back(3);
    cost.push_back(9);
    cost.push_back(5);
    cost.push_back(6);
    weight.push_back(3);
    weight.push_back(1);
    weight.push_back(2);
    weight.push_back(2);
    weight.push_back(1);

    cout << ks(weight, cost, 6) << endl;
}