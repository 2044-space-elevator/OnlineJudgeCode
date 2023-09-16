#include <iostream>
using namespace std;

int arr[4] = {10, 20, 50, 100};
int dp[1005];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = arr[i]; j <= n; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
}