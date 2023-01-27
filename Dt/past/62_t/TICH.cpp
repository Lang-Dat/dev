/**
 *	author : Lăng Trọng Đạt
 *	creater: 25-01-2023 16:19:50
**/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

std::vector<pair<int, int>> v;

int tich_chu_so(int n) {
    int tmp = n, res = 1;
    while (tmp > 0) {
        res *= tmp % 10;
        tmp /= 10;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TICH.INP", "r", stdin);
    freopen("./TICH.OUT", "w", stdout);
    #endif

    for (int i = 0; i < 1e4; i++) {
        if (tich_chu_so(i) != 0)
            v.push_back({tich_chu_so(i)*i, i});
            // std::cout << i << "\t" << setw(5) << tich_chu_so(i) << "\t" << tich_chu_so(i) * i << "\n";
    }  
    sort(v.begin(), v.end());
    
    for (auto &p : v)
        std::cout << p.second << "  " << p.first << "\n";
    return 0;
}