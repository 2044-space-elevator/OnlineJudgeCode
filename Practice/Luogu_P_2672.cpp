#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int, int> arr[114514];
int sumbe[114514], sumaf[114514], sum[114514];

int main() {
    cin >>n;
    for (int i= 1; i <= n; i++) {
        cin >> arr[i].second;
    }
    for (int i= 1; i <= n; i++) {
        cin >> arr[i].first;
    }
    sort(arr + 1, arr + n + 1, greater<pair<int, int> >());
    for (int i = 1;i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i].first;
    }
    for (int i = 1; i <= n; i++) {
        sumbe[i] = max(sumbe[i - 1], 2 * arr[i].second);
    }
    for (int i = n; i; i--) {
        sumaf[i] = max(sumaf[i + 1], 2 * arr[i].second + arr[i].first);
    }
    for (int i = 1; i <= n; i++) {
        cout << max(sumbe[i] + sum[i], sum[i - 1] + sumaf[i]) << endl;
    }
}