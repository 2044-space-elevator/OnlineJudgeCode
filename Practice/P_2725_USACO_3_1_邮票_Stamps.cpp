#include <iostream>
using namespace std;

bool candd[55];
int dp[(int)1e7];
int value[(int)1e2];

int main() {
    int n, k;
    cin >> k >> n;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    int res = 0;
    for (int i = 1; i <= 2e7; i++) {
        dp[i] = 1145141919;
        for (int j = 1; j <= n; j++) {
            if (i - value[j] >= 0) {
                dp[i] = min(dp[i], dp[i - value[j]] + 1);
            }
        }
            if (dp[i] == 1145141919 || dp[i] > k) {
                break;
            } else {
                res++;
            }
    }
    cout << res;
}