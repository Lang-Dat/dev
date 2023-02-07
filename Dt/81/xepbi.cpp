#include <iostream>
#include <cmath>

bool check(int64_t n) {
    // kiểm tra một số có thể viết dưới dạng tích của hai số liên tiếp không
    int sq = std::sqrt(n);
    return sq * (sq + 1) == n;
}
int main() {
    freopen("xepbi.inp", "r", stdin);
    freopen("xepbi.out", "w", stdout);
    int64_t n, temp, ans = 0;
    std::cin >> n;
    while (std::cin >> temp) {
        ans += check(2*temp);
    }

    std::cout << ans;
}
