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

int maxfood, maxmass, weight[405], mass[405], value[405], n, dp[405][405];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> maxfood >> maxmass >> n;
    rep(i, 1, n) {
        cin >> weight[i] >> mass[i] >> value[i];
    } 
    rep(i, 1, n) {
        rrep(j, weight[i], maxfood) {
            rrep(k, mass[i], maxmass) {
                dp[j][k] = max(dp[j][k], dp[j - weight[i]][k - mass[i]] + value[i]);
            }
        }
    }
    cout << dp[maxfood][maxmass];
	return 0;
}
