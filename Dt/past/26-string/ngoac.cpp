/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 12:08:21
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./ngoac.INP", "r", stdin);
    freopen("./ngoac.OUT", "w", stdout);
    #endif

    string str;
    int count = 0;
    std::cin >> str;
    for (char c : str) {
        if (c == '(') count++;
        else if (c == ')') {
            if (count == 0) {
                std::cout << "KHONG DUNG";
                return 0;
            }
            count--;   
        } else {
            std::cout << "KHONG HOP LE";
            return 0;
        }
    }

    cout << "DUNG"; 
    return 0;
}