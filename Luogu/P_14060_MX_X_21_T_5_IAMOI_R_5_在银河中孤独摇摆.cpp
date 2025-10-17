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

const int N = 1E7 + 5;
int arr[N], sum[N], ra[N];
int n;
ll ans = 0;
stack<int> st;

void sol() {
    rep(i, 1, n + 1) {
        while (st.size() && sum[st.top()] < sum[i]) {
            ra[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        ra[st.top()] = n + 2;
        st.pop();
    }
    rep(i, 1, n) {
        ans += ra[i] - i - 1;
    }
}

void solve() {
    stg s;
    cin >> s;
    n = s.size();
    repq(i, 0, s.size()) {
        arr[i + 1] = s[i] - '0';
    }
    sum[n + 1] = 0;
    rrep(i, 1, n) {
        sum[i] = sum[i + 1] + (arr[i] ? 1 : -1);
    }
    ans = 0;
    sol();
    rrep(i, 1, n) {
        sum[i] = sum[i + 1] + (arr[i] ? -1 : 1);
    }
    sol();
    cout << ans << '\n';
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
