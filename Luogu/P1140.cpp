// Problem: P1140 相似基因
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1140
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

int tables[200][200];

void init() {
	int* A = tables['A'], *C = tables['C'], *G = tables['G'], *T = tables['T'], *_ = tables['-'];
	A['A'] = 5, A['C'] = -1, A['G'] = -2, A['T'] = -1, A['-'] = -3;
	C['A'] = -1, C['C'] = 5, C['G'] = -3, C['T'] = -2, C['-'] = -4;
	G['A'] = -2, G['C'] = -3, G['G'] = 5, G['T'] = -2, G['-'] = -2;
	T['A'] = -1, T['C'] = -2, T['G'] = -2, T['T'] = 5, T['-'] = -1;
	_['A'] = -3, _['C'] = -4, _['G'] = -2, _['T'] = -1, _['-'] = 0;
}

int dp[105][105];

int main() {
	init();
	char m[] = "ACGT-";
//	int t; cin >> t; while (t--) solve();
	int n1, n2;
	stg str1, str2;
	cin >> n1 >> str1 >> n2 >> str2;
	str1 = " " + str1; str2 = " " + str2;
	rep(i, 1, n1) {
		dp[i][0] = dp[i - 1][0] + tables[str1[i]]['-'];
	}
	rep(j, 1, n2) {
		dp[0][j] = dp[0][j - 1] + tables['-'][str2[j]];
	}
	rep(i, 1, n1) {
		rep(j, 1, n2) {
			dp[i][j] = max({dp[i - 1][j] + tables[str1[i]]['-'],
			dp[i - 1][j - 1] + tables[str1[i]][str2[j]],
			dp[i][j - 1] + tables['-'][str2[j]]});	
			
		}
	}
	
	cout << dp[n1][n2];
	return 0;
}
