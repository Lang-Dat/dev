#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_set>

int tongChuSo(int n, int sum = 0) {
    while(n > 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHuuHan(int tmp) {
    std::unordered_set<int> s = {tmp};
    while (tmp != 1) {
        tmp = tongChuSo(tmp);
        if (s.count(tmp)) return false;
        s.insert(tmp);
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LIMITED.INP", "r", stdin);
    freopen("./LIMITED.OUT", "w", stdout);

    int tmp;
    while(std::cin >> tmp) {
        for (int i = tmp + 1;; i++) {
            if (isHuuHan(i)) {
                std::cout << i << "\n";
                goto cnt;
            }
        }
        cnt:;
    }

    return 0;
}