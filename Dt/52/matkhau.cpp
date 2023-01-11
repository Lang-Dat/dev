/**
 *	author : Lăng Trọng Đạt
 *	creater: 07-01-2023 18:42:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char find_disticst(string &str) {
    std::vector<int> freq(129, 0);
    for (char c : str) {
        freq[c]++;
    }
    for (int i = 0; i < 129; i++)
        if (freq[i] == 1)
            return (char)(i);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./matkhau.INP", "r", stdin);
    freopen("./matkhau.OUT", "w", stdout);
    #endif

    string str;
    int n;
    std::cin >> n;
    while (std::cin >> str) {
        std::cout << find_disticst(str) << "";
    }

    return 0;
}