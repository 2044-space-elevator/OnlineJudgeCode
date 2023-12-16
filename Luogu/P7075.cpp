// Problem: P7075 [CSP-S2020] 儒略日
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7075
// Memory Limit: 256 MB
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

#define int ll

namespace Date {
	int calc(int x) {
		int startDay = -4712;
		if (x < startDay) {
			return 0;
		}
		int ans = (x - startDay) * 365 + 365;
		if (x >= 1582) {
			ans = ans - 10;
			ans += (1581 - startDay) >> 2 + 1;
			ans += (x - 1580) >> 2 - (x - 1500) / (int)1e2 + (x - 1200) / (int)4e2;
		} else {
			ans += (x - startDay) >> 2 + 1;
		}
		return ans;
	}
	bool isodd(int ye);
	int TypeMonth(int n, int year) {
		if (n == 10) {
			return year == 1582 ? 21 : 31;
		}
		if (n == 4 || n == 6 || n == 9 || n == 11) {
			return 30;
		} else if (n == 2) {
			return 28 + isodd(year);
		} 
		return 31;
	}
	
	bool isodd(int ye) {
		if (ye <= 1582) {
			return !(ye % 4);
		}
		if (ye % 100) {
			return !(ye % 4);
		} else {
			return !(ye % 400);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	n++;
	int left = -4712, right = 1e9 + 10, mid, month;
	while (left < right) {
		mid = left + right >> 1;
		if (Date::calc(mid) >= n) {
			right = mid;
		} else {
			left = mid + 1;
		}
		n = n - Date::calc(left - 1);
		month;
		rep(i, 1, 12) {
			if (n <= Date::TypeMonth(i, left)) {
				month = i;
				break;
			} else {
				n = n - Date::TypeMonth(i, left);
			}
		}
		
	}
	if (left == 1582 && month == 10) {
		n += (n >= 5 ? 10 :false);
		cout << n << ' ' << month << ' ' << left << endl;
	} else { if (left > 0) {
		cout << n << ' ' << month << ' ' << left << endl;
	} else {
		cout << n << ' ' << month << ' ' << -left + 1 << " BC\n";
	} }
}




signed main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
