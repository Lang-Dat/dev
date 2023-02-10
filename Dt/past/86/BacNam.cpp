#include <iostream>
#include <unordered_set>

int main() {
    freopen("BACNAM.INP", "r", stdin);
    freopen("BACNAM.OUT", "w", stdout);

    int n, tmp, le = 0, chan = 0;
    std::cin >> n;
    std::unordered_set<int> is_appear;
    is_appear.reserve(2 * n);
    while (std::cin >> tmp) {
        if (tmp & 1) {
            le += !is_appear.count(tmp - 2);
        } else {
            chan += !is_appear.count(tmp - 2);
        }
        is_appear.insert(tmp);
    }

    std::cout << le << "\n" << chan;
}
