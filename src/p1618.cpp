/*将 1,2,…,9 共 9 个数分成三组，分别组成三个三位数，且使这三个三位数的比例是 A:B:C，试求出所有满足条件的三个三位数，
若无解，输出 No!!!。

输入格式
三个数，A,B,C。

输出格式
若干行，每行 3 个数字。按照每行第一个数字升序排列。*/

#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B, C;
    cin >> A >> B >> C;

    //枚举三位数,验证比例
    vector<int> st;
    for (int i=1; i<10; i++)
        st.push_back(i);
    int check = 1;
    do {
        int a = st[0]*100 + st[1]*10 + st[2];
        int b = st[3]*100 + st[4]*10 + st[5];
        int c = st[6]*100 + st[7]*10 + st[8];
        if (a*B == b*A && a*C == c*A) {
            cout << a << " " << b << " " << c << endl;
            check = 0;
        }
    } while (next_permutation (st.begin(), st.end()));

    if (check)
        cout << "No!!!" << endl;

    return 0;
}