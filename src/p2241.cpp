/*题目描述
有一个 n×m 方格的棋盘，求其方格包含多少正方形、长方形（不包含正方形）。

输入格式
一行，两个正整数 n,m（n≤5000,m≤5000）。

输出格式
一行，两个正整数，分别表示方格包含多少正方形、长方形（不包含正方形）。*/

#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    long long count1 = 0, count2 = 0;

    for (long long i=1; i<=n; i++) {
        for (long long j=1; j<=m; j++) {
            long long tem = (n-(i-1)) * (m-(j-1));
            if (i == j)
                count1 += tem;
            else
                count2 += tem;
        }
    }

    cout << count1 << ' ' << count2 << endl;

    return 0;
}