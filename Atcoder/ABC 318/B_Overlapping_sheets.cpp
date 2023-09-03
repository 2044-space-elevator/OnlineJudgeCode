#include <iostream>
#define MAX_RANGE 105
using namespace std;

bool vis[MAX_RANGE][MAX_RANGE];
int n, A[MAX_RANGE], B[MAX_RANGE], C[MAX_RANGE], D[MAX_RANGE];
int ans = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    for (int i = 1; i <= n; i++)
    {
        for (int x = A[i]; x < B[i]; x++)
        {
            for (int y = C[i]; y < D[i]; y++)
            {
                vis[x][y] = 1;
            }
        }
    }
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            // cout << vis[i][j] << ' ';
            ans += vis[i][j];
        }
        // cout << endl;
    }
    cout << ans;
}