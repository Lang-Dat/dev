/**
 *	author: Lăng Trọng Đạt
 *	create: 27-11-2022 39:02:09
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Val {
    int num, two = 0, five = 0;
    Val(int n, std::vector<int> fac)
        : num(n) {
            two = fac[0];
            five = fac[1];
        }
};
std::vector<int> factorazing(int num) {
    int tmp, f = 0, t = 0;
    tmp = num;
    while (tmp % 5 == 0) {
        tmp /= 5;
        f++;
    }
    tmp = num;
    while (tmp % 2 == 0) {
        tmp /= 2;
        t++;
    }
    return {t, f};
}
static const int LIM = 1e5 + 5;
std::vector<Val> nums;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DIV10X.INP", "r", stdin);
    freopen("./DIV10X.OUT", "w", stdout);
    #endif

    int n, x, num;
    std::cin >> n >> x;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (num % 2 != 0 and num % 5 != 0) continue;

        nums.push_back(Val(num, factorazing(num)));
    }
    
    Val target(x, factorazing(x));
    return 0;
}