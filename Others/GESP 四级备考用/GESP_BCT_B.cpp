/*
10
00FFCFAB00FFAC09071B5CCFAB76
00AFCBAB11FFAB09981D34CFAF56
01BFCEAB00FFAC0907F25FCFBA65
10FBCBAB11FFAB09981DF4CFCA67
00FFCBFB00FFAC0907A25CCFFC76
00FFCBAB1CFFCB09FC1AC4CFCF67
01FCCBAB00FFAC0F071A54CFBA65
10EFCBAB11FFAB09981B34CFCF67
01FFCBAB00FFAC0F071054CFAC76
1000CBAB11FFAB0A981B84CFCF66
*/

#include <bits/stdc++.h>
using namespace std;

int color[16];
int image[20][20];
int cpimg[20][20];
int his[256];

int trans(char a) {
    if (a <= '9') {
        return a - '0';
    }
}

char itrans(int n) {
    if (n >= 10) {
        return (char)(n - 10 + 'A');
    }
    return (char)(n + '0');
}

int cmp(int c) {
    int distance = 256,res = -1;
    for (int i = 0; i <= 15; i++) {
        int d = c - color[i];
        if (d < 0) {
            d = abs(d);
        } 
        if (d < distance) {
            distance = d;
            res = i;
        }
    }
    return res;
}
int n, M;
int main() {
    cin >> n;
    for (int i = 0; i < 256; i++) {
        his[i] = -1;
    }    
    for (int i = 0; i < n; i++) {
        char line[50];
        cin >> line;
        M = strlen(line) / 2;
        for (int j = 0; j < M; j++) {
            int c = trans(line[j * 2]) * 16 + trans(line[j * 2 + 1]);
            image[i][j] = c;
            his[c]++;
        }
    }
    for (int c = 0; c < 16; c++) {
        int max = 0, max_id = -1;
        for (int i = 0; i < 256; i++) {
            if (his[i] > max) {
                max = his[i];
                max_id = i;
            } 
        }
        color[c] = max_id;
        his[max_id] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            cpimg[i][j] = cmp(image[i][j]);
        }
    }
    for (int c = 0; c < 16; c++) {
        cout << itrans(color[c] / 16) << itrans(color[c] % 16);
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            cout << itrans(cpimg[i][j]);
        }
        cout << endl;
    }
}