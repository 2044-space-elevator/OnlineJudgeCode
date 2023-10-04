// Writen by 2044_space_elevator
#include <bits/stdc++.h>
using namespace std;
    
void solve() {
    
    // For many test cases
    
}

int vis[(int)(2 * 1e5 + 5)];
int arr[(int)(2 * 1e5 + 5)];
bool mapVis[(int)(2 * 1e5 + 5)];

int main() {
    int n, m;    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
        mapVis[arr[i]] = 1;
    } 
    for (int i = n; i; i--) {
        if (!mapVis[i]) {
            vis[i] = vis[i + 1] + 1;
        } else {
            vis[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << endl;
    }
    return 0;
}