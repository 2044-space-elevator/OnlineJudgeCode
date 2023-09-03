#include <algorithm>
#include <iostream>
using namespace std;

int n, m, arr[55], dp[(int)1e7];

int main() {
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];    
    }
    sum -= m;
    if (sum < 0) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int V = sum; V >= arr[i]; V--) {
            dp[V] = max(dp[V], dp[V - arr[i]] + arr[i]);
        }
    }
    cout << sum - dp[sum] + m;
}