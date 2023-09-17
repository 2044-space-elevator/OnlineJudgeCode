/* ************************************************************************
> File Name:     Luogu_P1970.cpp
> Author:        2044_space_elevator
> Created Time:  Sun Sep 17 19:38:57 2023
> Description:   
 ************************************************************************/



#include <iostream>
using namespace std;

int n, arr[(int)1e5 + 5];
int dp[(int)1e5 + 5][2];;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] > arr[i - 1]) {
            dp[i][0] = dp[i - 1][1] + 1;;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
        if (arr[i] < arr[i - 1]) {
            dp[i][1] = dp[i - 1][0] +1;
        } else {

            dp[i][1] = dp[i - 1][1];;
        }
    }
    cout << max(dp[n][0], dp[n][1]);
}
