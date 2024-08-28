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

typedef unsigned long long ull;

void solve() {
	
}

int arr[20][10], brr[10][10][10][10][10];

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    brr[a][b][c][d][e]++;
    rep(j, 0, 9) {
      brr[j][b][c][d][e]++;
      brr[a][j][c][d][e]++;
      brr[a][b][j][d][e]++;
      brr[a][b][c][j][e]++;
      brr[a][b][c][d][j]++;
    }
    rep(j, 1, 9) {
      brr[(a + j) % 10][(b + j) % 10][c][d][e]++;
      brr[a][(b + j) % 10][(c + j) % 10][d][e]++;
      brr[a][b][(c + j) % 10][(d + j) % 10][e]++;
      brr[a][b][c][(d + j) % 10][(e + j) % 10]++;

    }
  }
  int ans = 0;
  rep(i, 0, 9) rep(j, 0, 9) rep(k, 0, 9) rep(l, 0, 9) rep(m, 0, 9)
    ans += brr[i][j][k][l][m] == n;
  cout << ans;
	return 0;
}
