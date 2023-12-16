// Problem: P1167 刷题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1167
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Coding by 2044_space_elevator

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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

#define int ll

int arr[5005];

inline int iseven(int x) {
	return (x % 100 ? !(x % 4) : !(x % 400));
}

inline int day(int n) {
	if (n == 2) {
		return n;
	}
	return (31 - (n == 4 || n == 9 || n == 6 || n == 1));
}

signed main() {
//	int t; cin >> t; while (t--) solve();
	int n;
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	int tmpa, tmpb, tmpc, tmpd, tmpe, tmp1a, tmp1b, tmp1c, tmp1d, tmp1e;
	scanf("%lld-%lld-%lld-%lld:%lld", &tmpa, &tmpb, &tmpc, &tmpd, &tmpe);
	scanf("%lld-%lld-%lld-%lld:%lld", &tmp1a, &tmp1b, &tmp1c, &tmp1d, &tmp1e);
	int times = 0;
	repq(i, tmpa, tmp1a) {
		times -= (365 + iseven(i));
	}
	repq(i, 1, tmpb) {
		times += day(i);
	}
	repq(i, 1, tmp1b) {
		times -= day(i); 
	}
	times += (iseven(tmpa) && tmpb > 2);
	times -= (iseven(tmp1a) && tmp1b > 2);
	times += (tmpc - tmp1c);
	times *= 24;
	times += tmpd - tmp1d;
	times *= 60;
	times += tmpe - tmp1e;
	times = times * -1;
	int cnt = 0, sum = 0;
	rep(i, 1, n) {
		sum += arr[i];
		if (sum > times) {
			break;
		}
		cnt++;
	}
	cout << (cnt == 25 ? 36 : cnt);
	return 0;
}
