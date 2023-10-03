// Written by 2044_space_elevator.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    // For many testcases
}

int vis[105][105];

int main() {
    // freopen("Sample1.in", "r", stdin);
    // freopen("Sample2.in", "r", stdout);
    int n, k;
    int ri, ci;
    cin >> n >>k;
    for (int i = 1; i <= k; i++) {
        cin >> ri >> ci;
        for (int j = 1; j <= n; j++) {
            vis[ri][j]++;
            vis[j][ci]++;
        }
        for (int j = 1; j <= n; j++) {
            if (ri + j > n || ci + j > n) {
                break;
            }
            vis[ri + j][ci + j]++;
        }
        for (int j = 1; j <= n; j++) {
            if (ri - j <= 0 || ci + j > n) {
                break;
            }
            vis[ri - j][ci + j]++;
        }
        for (int j = 1; j <= n; j++) {
            if (ri - j <= 0 || ci - j <= 0) {
                break;
            }
            vis[ri - j][ci - j]++;
        }
        for (int j = 1; j <= n; j++) {
            if (ri + j > n || ci - j <= 0) {
                break;
            }
            vis[ri + j][ci - j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] >= k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    // fclose(stdin);
    // fclose(stdout);    
    return 0;
}