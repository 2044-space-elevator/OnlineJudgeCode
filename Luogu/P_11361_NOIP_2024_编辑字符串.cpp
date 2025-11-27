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

const int N = 1E5 + 5;
int cnta[N][2], posa[N], posb[N], cntb[N][2];
stg a, b, ta, tb;

void solve() {
	int n, tota = 0, totb = 0;
	cin >> n;	
	memset(cnta, 0, sizeof cnta);
	memset(cntb, 0, sizeof cntb);
	cin >> a >> b >> ta >> tb;
	a = " " + a, b = " " + b, ta = " " + ta, tb = " " + tb;
	rep(i, 1, n) {
		if (ta[i] == ta[i - 1]) posa[i] = posa[i - 1];
		else posa[i] = ++tota;
		cnta[posa[i]][a[i] - '0']++;
		if (tb[i] == tb[i - 1]) posb[i] = posb[i - 1];
		else posb[i] = ++totb;
		cntb[posb[i]][b[i] - '0']++;
	}
	int ans = 0;
	rep(i, 1, n) {
		if (ta[i] == '0' && tb[i] == '0') {
			ans = ans + (a[i] == b[i]);
		} else if (ta[i] == '0') {
			if (cntb[posb[i]][a[i] - '0']) {
				cntb[posb[i]][a[i] - '0']--;
				ans++;
			}
		} else if (tb[i] == '0') {
			if (cnta[posa[i]][b[i] - '0']) {
				cnta[posa[i]][b[i] - '0']--;
				ans++;
			}
		} 
	}
	rep(i, 1, n) {
		if (ta[i] != '1' || tb[i] != '1') continue;
		if (cnta[posa[i]][0] && cntb[posb[i]][0]) {
			cnta[posa[i]][0]--; cntb[posb[i]][0]--;
			ans++;
		} else if (cnta[posa[i]][1] && cntb[posb[i]][1]) {
			cnta[posa[i]][1]--; cntb[posb[i]][1]--;
			ans++;
		}
	}
	cout << ans << '\n';
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
