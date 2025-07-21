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

struct node {
    int a, b, ind;
}arr[(int)2e5 + 5];
int order[(int)2e5 + 5];
bool cmp1(node a, node b) {
    return a.a > b.a;
}
bool cmp2(node a, node b) {
    return a.b < b.b;
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n; cin >> n;
    rep(i, 1, n) cin >> arr[i].a >> arr[i].b; 
    rep(i, 1, n) arr[i].ind = i;
    sort(arr + 1, arr + n + 1, cmp2);
    rep(i, 1, n) {
        order[arr[i].ind] = i;
    }
	return 0;
}
