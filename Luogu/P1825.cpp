// Problem: P1825 [USACO11OPEN] Corn Maze S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1825
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Coding by 2044_space_elevator

#include <bits/stdc++.h>
using namespace std;

char _map[305][305];
bool vis[305][305];
pair<pair<int, int>, pair<int, int> > CY[26];
int n, m;
int startX, startY;

struct point {
	int x, y, step;
};

bool _isalpha(char c) {
	return (c >= 'A' &&  c <= 'Z');
}

queue<point> q;

void bfs() {
	q.push({startX, startY, 0});
	vis[startX][startY] = 1;
	while (q.size()) {
		point data = q.front();
		q.pop();
		// cout << data.x <<' ' <<data.y << ' ' << data.step << endl;
		if (_map[data.x][data.y] == '=') {
			cout << data.step << endl;
			return;
		}
		int dxy[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
		for (int i = 0; i < 4; i++) {
			int dx = data.x + dxy[i][0], dy = data.y + dxy[i][1];
			if (dx > n || dy > m || dx < 0 || dy < 0 || vis[dx][dy]) {
				continue;
			}
			vis[dx][dy] = 1;
			if (_isalpha(_map[dx][dy])) {
				pair<int, int> tmp = {dx, dy};
				pair<pair<int, int>, pair<int, int> > tmp2 = CY[_map[dx][dy]];
				if (tmp2.first == tmp) {
					tmp = tmp2.second;
				} else {
					tmp = tmp2.first;
				}
				dx = tmp.first;
				dy = tmp.second;
			}
			q.push({dx, dy, data.step + 1});
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> _map[i][j];
			vis[i][j] = (_map[i][j] == '#');
			if (_map[i][j] == '@') {
				startX = i;
				startY = j;
			} else if (_map[i][j] >= 'A' && _map[i][j] <= 'Z') {
				auto& tmp = CY[_map[i][j]];
				if (tmp.first.first) {
					tmp.second = {i, j};
				} else {
					tmp.first = {i, j};
				}
			}
		}
	}
	bfs();
	
}