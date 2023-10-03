#include <iostream>
using namespace std;

int n, k, p;
int stirling[10005][1005];

int main() {
    cin >> n >> k >> p;
    stirling[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            stirling[i][j] = stirling[i - 1][j - 1] + j * stirling[i - 1][j];
            stirling[i][j] %= p;
        }
    } 
    cout << stirling[n][k];

}