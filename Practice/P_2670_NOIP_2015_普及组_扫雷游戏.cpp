#include <iostream>
using namespace std;

char map[105][105];
int di[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

int main() {
    int n, m;
    cin >> n >> m;  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == '?') {
                int cnt = '0';
                for (int k = 0; k < 8; k++) {
                    int dx = di[k][0] + i;
                    int dy = di[k][1] + j;
                    if (dx < 1 || dx > n || dy < 1 || dy > m) {
                        continue; //
                    }
                    if (map[dx][dy] == '*') {
                        cnt++;
                    }
                }
                map[i][j] = cnt; 
            }
            cout << map[i][j];
        }
        cout << endl;
    }
}