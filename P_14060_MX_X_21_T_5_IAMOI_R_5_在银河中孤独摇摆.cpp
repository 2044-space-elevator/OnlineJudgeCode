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
int n, arr[N];
void solve() {
    n = 0;
    stg s;
    cin >> s; 
    char tmp = '#';
    repq(i, 0, s.size()) {
        if (s[i] != tmp) {
            tmp = s[i];
            n++;
            arr[n] = 1;
        }
        else arr[n]++;
    }
    stack<int> st;
    int len = s.size();
    ll ans = len * (len + 1) / 2;
    rrep(i, 1, n) {
        while (st.size() && arr[st.top()] > arr[i]) {
            ans = ans - arr[i] * arr[st.top()];
            st.pop();
        }
        st.push(i);
    }
    cout << ans << endl;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
