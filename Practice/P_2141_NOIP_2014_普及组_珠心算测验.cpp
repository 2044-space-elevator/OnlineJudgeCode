#include <bits/stdc++.h>
using namespace std;

int n;
int arr[114514];
int flag[114514];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            flag[arr[i] + arr[j]] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += flag[arr[i]];
    }
    cout << ans;
}