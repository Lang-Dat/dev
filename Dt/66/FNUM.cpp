/**
 *	author : Lăng Trọng Đạt
 *	creater: 28-01-2023 08:06:08
**/
#include <iostream>
#include <algorithm>
using namespace std;

int64_t l, r, sum = 0;

int tong_chu_so(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res % 9 + 9*(res % 9 == 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./FNUM.INP", "r", stdin);
    freopen("./Test/FNUM/test01/FNUM.INP", "r", stdin);
    // freopen("./FNUM.OUT", "w", stdout);
    #endif

    std::cin >> l >> r;
    db(l, r)
    if (r - l <= 9) {
        for (int i = l; i <= r; i++)
            sum += tong_chu_so(i);
        std::cout << sum << "";
        return 0;
    } 
    int first = (l / 9 + (l % 9 != 0)) * 9,
        last = (r/9) * 9; 
    db(first, last)
        
    sum += 45 * (last - first) / 9 + 45;

    // for (int i = l; i < first; i++) {
    //     sum += tong_chu_so(i);
    // }
    
    // for (int i = r; i > last; i--) {
    //     sum += tong_chu_so(i);
    // }

    std::cout << sum << "";
    return 0;
}