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

int n, k, arr[1000006];
int ffmax[1000006][32], ffmin[1000006][32];

int rmqmax(int l, int r) {
    int k = log2(r - l + 1);
    return max(ffmax[l][k], ffmax[r - (1 << k) + 1][k]);
}

int rmqmin(int l, int r) {
    int k = log2(r - l + 1);
    return min(ffmin[l][k], ffmin[r - (1 << k) + 1][k]);
}

main() {
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> arr[i]; ffmax[i][0] = ffmin[i][0] = arr[i];
    }
    for (int j = 1; 1 << j <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            ffmax[i][j] = max(ffmax[i][j - 1], ffmax[i + (1 << j - 1)][j - 1]);
            ffmin[i][j] = min(ffmin[i][j - 1], ffmin[i + (1 << j - 1)][j - 1]);
        }
    }
    rep(l, 1, n - k + 1) {
        int r = l + k - 1;
        cout << rmqmin(l, r) << ' ';
    }
    cout << endl;
    rep(l, 1, n - k + 1) {
        int r = l + k - 1;
        cout << rmqmax(l, r) << ' ';
    }
//	int t; cin >> t; while (t--) solve();
	return 0;
}
