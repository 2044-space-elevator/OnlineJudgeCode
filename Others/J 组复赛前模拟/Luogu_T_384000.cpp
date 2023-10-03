// Written by 2044_space_elevator.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // For many testcases
}

int arr[25], n, shelf, ans = 1145141919;
bool vis[25];

void dfs(int sum) {
    if (sum >= shelf) {
        ans = min(ans, sum - shelf);
        return;     
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(sum + arr[i]);
            vis[i] = 0;
        }
    } 
}

int main() {
    // freopen("Sample1.in", "r", stdin);
    // freopen("Sample2.in", "r", stdout);
    
    cin >> n >> shelf;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dfs(0);
    cout << ans;
    // fclose(stdin);
    // fclose(stdout);    
    return 0;
}