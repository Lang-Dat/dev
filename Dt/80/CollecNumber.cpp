#include <iostream>
#include <unordered_set>

std::unordered_set<int> s;

int main() {
    freopen("CollecNumber.INP", "r", stdin);
    freopen("CollecNumber.OUT", "w", stdout);
    int n, tmp, ans = 0;
    std::cin >> n;
    s.reserve(2*n);
    while (std::cin >> tmp) {
        ans += (!s.count(tmp - 1));
        s.insert(tmp);
    }

    std::cout << ans;
}
