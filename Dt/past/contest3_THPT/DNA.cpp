/**
 *	author: Lăng Trọng Đạt
 *	create: 27-11-2022 32:46:08
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(string str, string old) {
    if (str.size() != old.size()) return false;
    int diff = 0;
    for (int i = 0; i < str.size(); i++) {
        diff += str[i] != old[i];
    }
    return diff <= 2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DNA.INP", "r", stdin);
    freopen("./DNA.OUT", "w", stdout);
    #endif

    string undefine, old;
    bool isPrint = false;

    std::cin >> undefine;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> old;
        if (check(undefine, old)) {
            isPrint = true;
            std::cout << i << " ";
        }
    }
    
    if (!isPrint) cout << 0;
    return 0;
}