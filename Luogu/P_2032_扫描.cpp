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

deque<int> q;
int arr[(int)2e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) {
        int x;
        cin >> x;
        arr[i] = x;
        while (q.size() && q.front() + k - 1 < i) {
            q.pop_front();
        }
        while (q.size() && arr[q.back()] <= arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k) {
            cout << arr[q.front()] << endl;
        }
    }
	return 0;
}
