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

#define int ll
vct<int> zm[411];
int sum[411][(int)2e5 + 5];



main() {
//	int t; cin >> t; while (t--) solve();
    stg s;
    cin >> s;
    repq(i, 0, s.size()) {
        zm[s[i]].push_back(i);
    }
    rep(i, 'A', 'Z') {
        repq(j, 0, zm[i].size()) {
            if (j)
            sum[i][j] = sum[i][j - 1] + zm[i][j];
            else sum[i][j] = zm[i][j];
        }
    }
    int ans = 0;
    rep(i, 'A', 'Z') {
        repq(j, 0, zm[i].size()) {
            ans += (sum[i][zm[i].size() - 1] - sum[i][j]);
            ans -= (zm[i].size() - 1 - j) * (zm[i][j] + 1);

        }
    }
    cout << ans;
	return 0;
}
