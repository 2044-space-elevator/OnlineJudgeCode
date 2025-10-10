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

const int N = 1E6 + 5;
int arr[N], la[N], ra[N];

main() {
//	int t; cin >> t; while (t--) solve();
    stack<int> st;
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> arr[i];
        while (st.size() && arr[st.top()] > arr[i]) {
            ra[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        ra[st.top()] = n + 1;
        st.pop();
    }
    rrep(i, 1, n) {
        while (st.size() && arr[st.top()] > arr[i]) {
            la[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        la[st.top()] = 0;
        st.pop();
    }
    ll ans = 0;
    rep(i, 1, n) {
        ll tmp = arr[i] * (ra[i] - la[i] - 1);
        ans = max(ans, tmp);
    }
    cout << ans;
	return 0;
}
