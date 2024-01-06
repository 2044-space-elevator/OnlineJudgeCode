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
#define int long long

const int N = 1e6 + 5;
int n, t, arr[N], tag[N], ope[N];

typedef long long ll;
typedef unsigned long long ull;

namespace LinkTree {
    void build(int now, int left, int right) {
        if (left == right) {
            ope[now] = arr[left];
            return;
        }
        int mid = (left + right) >> 1;
        build(now * 2, left, mid);
        build(now * 2 + 1, mid + 1, right);
        ope[now] = ope[now * 2] + ope[now * 2 + 1];
    }
    void update(
        int begin, int end, int left, 
        int right, int now, int gs
    ) {
        if (begin >= left && right >= end){
            ope[now] += gs * (end - begin + 1);
            tag[now] += gs;
            return;
        }
        int mid = (begin + end) >> 1;
        tag[now * 2] += tag[now];
        ope[now * 2] += tag[now] * (mid - begin + 1);
        tag[now * 2 + 1] += tag[now];
        ope[now * 2 + 1] += tag[now] * (end - mid);
        tag[now] = 0;  
        if (left <= mid) {
            update(begin, mid, left, right, now * 2, gs);
        }
        if (right > mid) {
            update(mid + 1, end, left, right, now * 2 + 1, gs);
        }
        ope[now] = ope[now * 2] + ope[now * 2 + 1];
    }
    int query(
        int begin, int end, int left,
        int right, int now
    ) {
        int res = 0;
        if (left >= begin && right <= end) {
            return ope[now];
        }
        int mid = (left + right) >> 1;
        tag[now * 2] += tag[now];
        ope[now * 2] += tag[now] * (mid - left + 1);
        tag[now * 2 + 1] += tag[now];
        ope[now * 2 + 1] += tag[now] * (right - mid);
        tag[now] = 0;  
        int sum = 0;
        if (begin <= mid) {
            sum += query(begin, end, left, mid, now * 2);
        }
        if (end > mid) {
            sum += query(begin, end, mid + 1, right, now * 2 + 1);
        }
        return sum;
    }

};

using namespace LinkTree;

void solve() {
    int typ;
    cin >> typ;
    if (typ == 1) {
        int x, y, k;
        cin >> x >> y >> k;
        update(1, n, x, y, 1, k);
    } else {
        int x, y;
        cin >> x >> y;
        cout << query(x, y, 1, n, 1) << endl;
    }
}


main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> t;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (t--) solve();
	return 0;
}
