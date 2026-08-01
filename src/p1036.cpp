/*已知 n 个整数 x ,以及 1 个整数 k（k<n）。从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。

现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：3+7+19=29。

输入格式
第一行两个空格隔开的整数 n,k（1≤n≤20，k<n）。第二行 n 个整数

输出格式
输出一个整数，表示种类数。*/

#include <bits/stdc++.h>
using namespace std;
int irp[10005];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //创建素数数组;
    for (int i=2; i<10005; i++) 
        irp[i] = 1;
    for (int i=2; i<10005; i++) {
        if (irp[i])
            for (int j=2*i; j<10005; j+=i) 
                irp[j] = 0;
    }

    int n, k;
    cin >> n >> k;
    vector <int> num(n);
    for (int i=0; i<n; i++) 
        cin >> num[i];
    //枚举可能的组合;

    int count = 0; 
    for (int mask=0; mask<(1<<n); mask++) 
        if (__builtin_popcount(mask) == k) {  //两个下划线
            int temp = 0;
            for (int i=0; i<n; i++)
                if (mask & (1<<i)) 
                    temp += num[i];
            
            if (temp <10005 && irp[temp])
                count ++;
            else {
                if (temp % 2) {
                    bool check = 1;
                    //for (int i=3; irp[i] && i*i<=temp; i+=2)一旦遇到irp[i]==0会提前终止
                    for (int i=3; i*i<=temp; i+=2)
                        if (irp[i] && temp % i == 0)
                            check = 0;

                    if (check)
                        count ++;
                }
            }
        
        }
    
    cout << count << endl;
    
    return 0;

}