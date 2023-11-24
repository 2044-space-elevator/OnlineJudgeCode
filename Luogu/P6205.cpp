// Problem: P6205 [USACO06JAN] Dollar Dayz S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6205
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Coding by 2044_space_elevator

#include <iostream>
using namespace std;

int dp[10005];

int main() {
	int n, k;
	cin >> n >> k;	
	dp[0] =1;
	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			if (j >= i) {
				dp[j] = max(dp[j], dp[j - i] + dp[j]);
			}
		}
	}
	cout << dp[n];
}