#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
bool vis[20];
int n;

bool isprime(int n) {
    if (n == 2) {
        return true;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int step) {
    if (step == n) {
        for (int i = 0; i < arr.size(); i++) {
            if (!isprime(arr[i] + arr[(i + 1) % (arr.size())])) {
                return;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!isprime(i + arr.back())) {
                continue;
            }
            vis[i] = 1;
            arr.push_back(i);
            dfs(step + 1);
            vis[i] = 0;
            arr.pop_back();
        }
    }
}

int main() {
    cin >> n;
    arr.push_back(1);
    vis[1] = 1;
    dfs(1);

}
