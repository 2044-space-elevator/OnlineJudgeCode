#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

const int N = 2E5 + 5;
const ll mod = 998244353;
int arr[N], brr[N], cnt[N];

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) { cin >> arr[i]; brr[i] = arr[i]; }
    sort(brr + 1, brr + n + 1);
    int m = unique(brr + 1, brr + n + 1) - (brr + 1);
    rep(i, 1, n) {
        arr[i] = lower_bound(brr + 1, brr + m + 1, arr[i]) - (brr + 1);
    }
    int minx = 1e9;
    rep(i, 1, n) {
        if (arr[i] > minx) {
            cnt[arr[i]]++;
        } else {
            minx = arr[i];
        }
    }
    ll ans = 1;
    rep(i, 1, n) {
        ans *= (cnt[i] + 1);
        ans %= mod;
    }
    cout << ans;
	return 0;
}
