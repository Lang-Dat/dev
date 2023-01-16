/**
 *	author : Lăng Trọng Đạt
 *	creater: 15-01-2023 08:10:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

string str;
bool solve() {
    int al = 0, bl = 0, ar = 0, br = 0;
    for (char c : str) {
        (c == 'a')  ? ar++ : br++;
    }
    for (char c : str) {
        (c == 'a') ? ar-- : br--;
        (c == 'a') ? al++ : bl++;
        if (al == bl and ar == br)
            return true;
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./Nicestr.INP", "r", stdin);
    freopen("./Nicestr.OUT", "w", stdout);
    #endif

    int q;
    std::cin >> q;
    while (std::cin >> str) {
        std::cout << (solve() ? 2 : 1) << "\n";
    }

    return 0;
}