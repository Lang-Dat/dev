/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 31:12:14
**/
#include <iostream>
#include <algorithm>
using namespace std;

int num_of_change(string str) {
    int count = 0;
    for (int l = 0, r = str.size() - 1; l <= r; l++, r--)
        count += (str[l] != str[r]);
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SYMMETRY.INP", "r", stdin);
    freopen("./SYMMETRY.OUT", "w", stdout);
    #endif

    int n;
    string str;
    std::cin >> n;

    while (std::cin >> str) {
        std::cout << num_of_change(str) << "\n";
    }

    return 0;
}