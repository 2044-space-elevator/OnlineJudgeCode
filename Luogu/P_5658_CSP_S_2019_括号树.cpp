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

const int N = 5E5 + 5;
int lst[N], fa[N], dp[N];
vct<int> E[N];
int n, top;
stg str;
ll st[N];

void dfs(int u) {
    bool flg = 0;
    int tmp = 0;
    if (str[u] == ')' ){
        if (top) {
            tmp = st[top];
            lst[u] = lst[fa[tmp]] + 1;
            top--;
        }
    } else if (str[u] == '(') st[++top] = u;
    dp[u] = dp[fa[u]] + lst[u];
    for (int v : E[u]) {
        dfs(v);
    }
    if (tmp) st[++top] = tmp; 
    else if (top) top--;
}

main() {
    cin >> n;
    cin >> str;
    str = " " + str;
    rep(i, 2, n) {
        cin >> fa[i];
        E[fa[i]].push_back(i);
    } 
    dfs(1);
    ll ans = 0;
    rep(i, 1, n) {
        ans ^= (i * dp[i]);
    }
    cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
