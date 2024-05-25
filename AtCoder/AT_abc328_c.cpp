// LUOGU_RID: 134656492
// Problem: [ABC328C] Consecutive
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc328_c
// Memory Limit: 1 MB
// Time Limit: 2000 ms
// 
// Coding by 2044_space_elevator

#include <bits/stdc++.h>
using namespace std;

int tmp, Q, l, r, arr[(int)3e5 + 5];
string s;

int main() {
	cin >> tmp >> Q >> s;
	while (Q--) {
		cin >> l >> r;
		int ans = 0;
		for (int i = l; i < r; i++) {
			if (s[i - 1] == s[i]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}