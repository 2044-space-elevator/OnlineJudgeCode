#include <bits/stdc++.h>
using namespace std;

int arr[95], h, w;
int tab[10][10];

int main() {
    int n;
    cin >> h >> w >> n;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> tab[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= w; j++) {
            bool flg = 0;
            for (int k = 1; k <= n; k++) flg |= (tab[i][j] == arr[k]);
            tmp += flg;
        }
        ans = max(tmp, ans);
    }
    cout << ans << '\n';
}