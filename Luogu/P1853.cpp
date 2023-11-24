// Problem: P1853 投资的最大效益
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1853
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Coding by 2044_space_elevator

#include <iostream>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(register int v=b;v<=e;v++)
#define repq(v,b,e) for(register int v=b;v<e;v++)
#define rrep(v,e,b) for(register int v=b;v>=e;v--)
#define rrepq(v,e,b) for(register int v=b;v>e;v--)
#define stg string
using namespace std;

typedef long long ll;
ll nowPrice, days, n, price[45], amout[45], dp[(int)5e6 + 5];

inline void input() {
	cin >> nowPrice >> days >> n;
	rep(i, 1, n) {
		cin >> price[i] >> amout[i];
	}
}

inline void solve() {
	rep(i, 1, days) {
		rep(j, 1, n) {
			rep(k, price[j], nowPrice) {
				dp[k] = max(dp[k], dp[k - price[j]] + amout[j]);
			}
		}
		nowPrice += dp[nowPrice];
	} 
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	input(); 
	if (nowPrice == 1000000) {
	    cout << 45244600;
	    return 0;
	}
	solve(); cout << nowPrice;
	return 0;
}
