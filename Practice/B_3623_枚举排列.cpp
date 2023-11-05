#include <vector>
#include <iostream>
using namespace std;

int n, k;
vector<int> arr;
bool vis[15];

void dfs(int step) {
    if (step == k) {
        for (auto u : arr) {
            cout << u << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            arr.push_back(i);
            dfs(step + 1);
            arr.pop_back();
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    dfs(0);
}