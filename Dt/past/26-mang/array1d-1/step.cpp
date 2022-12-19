/**
 *	author: Lăng Trọng Đạt
 *	create: 16-12-2022 22:41:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int n) {
    int prev = n % 10, curr;
    bool isLoop = false;
    n /= 10;
    while (n > 0) {
        curr = n % 10;
        n /= 10;
        if (prev < curr) 
            return false;
        prev = curr;
        isLoop = true;
    }

    if (!isLoop)
        return false;

    return true;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./step.INP", "r", stdin);
    freopen("./step.OUT", "w", stdout);
    #endif

    int n, tmp, count = 0;
    std::cin >> n;

    while (std::cin >> tmp) {
        count += check(tmp);
    }

    std::cout << count << "";
    return 0;
}