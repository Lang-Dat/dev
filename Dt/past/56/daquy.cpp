/**
 *	author : Lăng Trọng Đạt
 *	creater: 14-01-2023 19:43:09
**/
#include <iostream>
#include <algorithm>
using namespace std;

std::string operator*(string &str, int k) {
    string res = "";
    for (int i = 0; i < k; i++)
        res += str;
    return res;
}

string build() {
    int so_doan, m, k;
    string x, res = "";
    std::cin >> so_doan;
    for (int i = 0; i < so_doan; i++) {
        std::cin >> m >> x >> k;
        res += x * k;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./daquy.INP", "r", stdin);
    freopen("./daquy.OUT", "w ", stdout);
    #endif

    string s1 = build(), s2 = build();
    s1 = s1*2;
    string temp = s2;
    reverse(s2.begin(), s2.end());
    if (s2.size() == s1.size() / 2 and (s1.find(s2) != std::string::npos or s1.find(temp) != std::string::npos))
        std::cout << "CO\n";
    else std::cout << "KHONG\n";
    std::cout << s1.size() / 2 << " " << s2.size();
    return 0;
}