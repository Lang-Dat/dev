/**
 *	author: Lăng Trọng Đạt
 *	create: 06-12-2022 03:02:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

bool isPrime_(uint64_t n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (uint64_t i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    #endif

    string num;
    std::set<int> appeared;
    bool isPrinted = false;
    std::cin >> num;

    for (char c : num) {
        int tmp = c - '0';
        if (isPrime_(tmp)) {
            if (!appeared.count(tmp))
                std::cout << tmp << " ";
            appeared.insert(tmp);
            isPrinted = true;
        }
    }

    if (!isPrinted) std::cout << 0 << "";
    return 0;
}