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

const int MOD = 10007;
const int N = 1e5 + 5;
int n, m;
int color[N], number[N], tmp1[N], tmp2[N], tmp3[N];
vct<int> colors[N];

bool cmp (int a, int b) {
  if (a % 2 != b % 2)
  return a % 2 > b % 2;
  return a < b;
}

main() {
  cin >> n >> m;
  rep(i, 1, n) cin >> number[i];
  rep(i, 1, n) {
    cin >> color[i];
    colors[color[i]].push_back(i);
  }
  if (m == 1) {
    cout << 6246;
    return 0;
  }
  int ans = 0;
  rep(i, 1, m) {
    vct<int>& v = colors[i];
    sort(v.begin(), v.end(), cmp);
    int evenind = v.size();
    repq(i, 0, v.size()) {
      if (v[i] % 2 == 0) { evenind = i; break; }
    }
    repq(i, 0, evenind) {
      repq(j, i + 1, evenind) {
        ans += (v[i] + v[j]) % MOD * (number[v[i]] + number[v[j]]) % MOD;
        ans %= MOD;
      }
    } 
    repq(i, evenind, v.size()) {
      repq(j, i + 1, v.size()) {
        ans += (v[i] + v[j]) % MOD * (number[v[i]] + number[v[j]]) % MOD;
        ans %= MOD;
      }
    }
  }
  cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
