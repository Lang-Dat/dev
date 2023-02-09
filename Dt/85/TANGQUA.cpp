#include <iostream>

int main() {
    freopen("TANGQUA.INP", "r", stdin);
    freopen("TANGQUA.OUT", "w", stdout);
    int n, tmp, maximum = 0, cnt = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        if (tmp == maximum) cnt++;
        else if (tmp > maximum) {
            maximum = tmp;
            cnt = 1;
        }
    }

    std::cout << cnt;
}
