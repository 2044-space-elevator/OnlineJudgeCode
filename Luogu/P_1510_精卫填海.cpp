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

const int N = 1e4 + 5;
int v, n, c, dp[N];

struct tmp {
    int k, m;
}rock[N];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> v >> n >> c;
    int sum = 0;
    rep(i, 1, n) {
        cin >> rock[i].k >> rock[i].m;
        sum += rock[i].k;
    }
    rep(i, 1, n) {
        rrep(j, rock[i].m, c) {
            dp[j] = 
            max(dp[j],
            dp[j - rock[i].m] + rock[i].k);
        } 
    }
    rep(i, 1, c) {
        if (dp[i] >= v) {
            cout << c - i;
            return 0;
        }
    } 
    cout << "Impossible\n";
    return 0;
}
