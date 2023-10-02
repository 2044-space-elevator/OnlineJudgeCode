#include <iostream>
#define int long long
#define MOD 20123 
using namespace std;

int n, m;
pair<int,int> arr[10005][105];
int quan[10005];
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j].first >> arr[i][j].second;
            quan[i] += arr[i][j].first;
        }
    }
    int res = 0;
    int enter_kase; cin >> enter_kase;
    for (int i = 1; i <= n; i++) {
        res += arr[i][enter_kase].second;
        int cnt = arr[i][enter_kase].first;
        int x = arr[i][enter_kase].second;
        int j = enter_kase;
        int lm = x;
        lm %= quan[i], lm += quan[i];
        lm -= arr[i][j].first; 
        while (lm) {
            j++;
            j %= m;
            lm -= arr[i][j].first;
        }
        res %= MOD;
        enter_kase = j;
    }
    cout << res;
}