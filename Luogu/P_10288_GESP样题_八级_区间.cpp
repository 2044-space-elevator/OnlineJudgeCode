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

vct<int> na[(int)1e5 + 5];
int arr[(int)1e5 + 5], brr[(int)1e5 + 5];
void solve() {
    int n;
    cin >> n; 
    rep(i, 1, n) {cin >> arr[i]; brr[i] = arr[i]; }
    sort(brr + 1, brr + n + 1);
    int k = unique(brr + 1, brr + n + 1) - (brr + 1);
    rep(i, 1, n) na[i].clear();
    rep(i, 1, n) {
        arr[i] = lower_bound(brr + 1, brr + k + 1, arr[i]) - brr;
        na[arr[i]].push_back(i);
    }   
    int t;
    cin >> t;
    while (t--) {
        int l, r, x;
        cin >> l >> r >> x;
        int ox = x;
        x = lower_bound(brr + 1, brr + k + 1, x) - brr;
        if (brr[x] != ox) { cout << 0 << endl; continue; }
        auto ll = lower_bound(na[x].begin(), na[x].end(), l);
        auto rr = --(upper_bound(na[x].begin(), na[x].end(), r));
        cout << rr - ll + 1 << endl;
    }
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
