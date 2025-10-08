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


int n, m;
int arr[(int)3e5 + 5], lst[(int)3e5 + 5], sum[(int)3e5 + 5];
main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            char ch;
            cin >> ch;
            if (ch == '0') {
                arr[j] = 0;
            } else {
                arr[j]++;
            }
        }
        stack<int> st;
        rep(j, 1, m) {
            while (st.size() && arr[st.top()] > arr[j]) {
                lst[st.top()] = j; 
                st.pop();
            }
            st.push(j);
        }
        while (st.size()) {
            lst[st.top()] = m + 1;
            st.pop();
        }
        rrep(j, 1, m) {
            sum[j] = sum[lst[j]] + (lst[j] - j) * arr[j];
            ans = max(ans, sum[j]);
        }
    }
    cout << ans;
	return 0;
}
