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

int status[10][7];
int tmp[7];

bool check(int x) {
	rep(i, 1, 5) {
		if ((tmp[i] + 20) % 10 != (20 + status[x][i]) % 10) {
			return 0;
		}
	}
	return 1;
}

main() {
	int n;
	cin >> n;
	rep(i, 1, n) {
		rep(j ,1, 5) {
			cin >> status[i][j];
		}
	}
	int cnt = 0;
	rep(a, 0, 9) {
	rep(b, 0, 9) {
	rep(c, 0, 9) {
	rep(d, 0, 9) {
	rep(e, 0, 9) {
		bool ans = 1;
		rep(i, 1, n) {
			bool flg = 0;
			tmp[1] = a, tmp[2] = b, tmp[3] = c, tmp[4] = d, tmp[5] = e;
			rep(j, 1, 5) {
				rep(k, -9, 9) {
					if (k == 0) continue;
					tmp[j] += k;
					flg |= check(i);
					tmp[j] -= k;
				}
			}
			rep(j, 1, 4) {
				rep(k, -9, 9) {
					if (k == 0) continue;
					tmp[j] += k, tmp[j + 1] += k;
					flg |= check(i);
					tmp[j] -= k, tmp[j + 1] -= k;
				}
			}
			ans &= flg;
		}
		cnt += ans;
	}}}}}
	cout << cnt;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
