// Problem: P1833 樱花
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1833
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Coding by 2044_space_elevator

#include <bits/stdc++.h>
using namespace std;

int T, flowers;

struct flower {
	int t, c, p;
}arr[(int)1e4 + 5];

int dp[(int)1e4 + 5];

void input() {
	int startH, startM, endH, endM;
	scanf("%d:%d %d:%d", &startH, &startM, &endH, &endM);
	T = (endH - startH) * 60 + endM - startM;
	cin >> flowers;
	for (int i = 1; i <= flowers; i++) {
		cin >> arr[i].t >> arr[i].c >> arr[i].p;
		if (arr[i].p == 0) {
			arr[i].p = T / arr[i].t;
		}
	}
	
	
}

int main() {
	input();
	for (int i = 1; i <= flowers; i++) {
		for (int j = T; j >= arr[i].t; j--) {
			for (int k = arr[i].p; k >= 0; k--) {
				if (j >= k * arr[i].t) {
					dp[j] = max(dp[j - k * arr[i].t] + k * arr[i].c, dp[j]);
				}
			}
		} 
	}
	cout << dp[T];
}