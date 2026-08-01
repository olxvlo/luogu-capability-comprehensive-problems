/*猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 10 种配料（芥末、孜然等），
每种配料可以放 1 到 3 克，任意烤鸡的美味程度为所有配料质量之和。

现在， Hanke 想要知道，如果给你一个美味程度 n ，请输出这 10 种配料的所有搭配方案。

输入格式
一个正整数 n，表示美味程度。

输出格式
第一行，方案总数。

第二行至结束，10 个数，表示每种配料所放的质量，按字典序排列。

如果没有符合要求的方法，就只要在第一行输出一个 0。*/
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    //枚举可能;
    vector <vector<int>> num;
    for (int i=0; i<10; i++) {
        for (int j=0; j<=10-i; j++) {
            int k = 10-i-j;
            if (i + 2*j + 3*k == n) {
                vector <int> temp;
                for (int x=0; x<i; x++)
                    temp.push_back(1);
                for (int x=0; x<j; x++)
                    temp.push_back(2);   
                for (int x=0; x<k; x++)
                    temp.push_back(3);

                do {
                    num.push_back(temp);
                } while (next_permutation(temp.begin(), temp.end()));

            }
        }
    }

    sort (num.begin(), num.end());

    if (num.size() == 0)
        cout << 0 << endl;
    else {
        cout << num.size() << endl;
        for (auto &vec:num) {
            for (int i=0; i<10; i++) {
                cout << vec[i] << (i==9? '\n':' ');
            }
        }
    }

    return 0;
}