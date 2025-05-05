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

struct person {
    bool status;
    stg job;
}crowd[(int)1e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    cin >> n >> m;
    repq(i, 0, n ){
        cin >> crowd[i].status >> crowd[i].job;
    }
    int pt = 0;
    //cout << crowd[5].status << ' ' << crowd[5].job;
    while (m--) {
        int sta, num;
        cin >> sta >> num;
        if (sta == crowd[pt].status)num *= - 1;
        pt = (pt + n + num) % n;
        //cout << pt << endl;
    }
    cout << crowd[pt].job;
	return 0;
}
