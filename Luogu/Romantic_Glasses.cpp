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

map<int, bool> mark;

void solve() {
    int n;
    mark.clear();
    // 您猜猜不 clear 会发生什么……
    mark[0] = 1;
    cin >> n;
    int x = 0;
    bool flag = 0;
    rep(i, 1, n) {
        int p;
        cin >> p;
        if (flag) {
            continue;
        }
        if (i % 2) {
            p = -p;
        }
        x += p;
        if (mark[x]) {
            RTY
            flag = 1; // 一个坑点，不要遇到 YES 直接 return 了，后面的数没读入到这样 cin 会把数组的数当 n 读进去
        }
        mark[x] = 1;
    }
    if (!flag)
        RTN
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
