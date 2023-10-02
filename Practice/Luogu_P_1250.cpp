#include <algorithm>
#include <iostream>
using namespace std;

struct trees {
    int left, right, numberTree;
}arr[114514];
bool vis[50005];
int n, h;

bool cmp(trees a, trees b) {
    return a.right < b.right;
}

int main() {
    cin >> h >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].left >> arr[i].right >> arr[i].numberTree;
    }
    sort(arr + 1, arr + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = arr[i].left; j <= arr[i].right; j++) {
            if (vis[j]) {
                cnt++;
            }
        }
        for (int j = arr[i].right; cnt < arr[i].numberTree && j >= arr[i].left; j--) {
            if (!vis[j]) {
                vis[j] = 1;
                ans++, cnt++;
            }
        }
    }
    cout << ans;
}