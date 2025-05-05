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

int hf[40][40];
pair<int, int> dy[1600];

main() {
    int n;
    cin >> n;
    hf[1][n / 2 + 1] = 1;
    dy[1] = {1, n / 2 + 1};
    rep(k, 2, n * n) {
        int ox = dy[k - 1].first, oy = dy[k - 1].second;
        int nowx, nowy;
        if (ox == 1 && oy != n) nowx = n, nowy = oy + 1;
        if (ox != 1 && oy == n) nowx = ox - 1, nowy = 1;
        if (ox == 1 && oy == n) nowx = 2, nowy = n;
        if (ox != 1 && oy != n) {
            if (!hf[ox - 1][oy + 1]) {
                nowx = ox - 1, nowy = oy + 1;
            } else nowx = ox + 1, nowy = oy;
        }
        hf[nowx][nowy] = k;
        dy[k] = {nowx, nowy};
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            cout << hf[i][j] << ' ';
        }
        cout << endl;
    }
//	int t; cin >> t; while (t--) solve();
	return 0;
}
