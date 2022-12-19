/**
 *	author: Lăng Trọng Đạt
 *	create: 16-12-2022 04:45:19
**/
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

std::unordered_set<uint64_t> perfect_num = {6, 28, 496, 8128, 33550336};

int tong_chu_so(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BHHAO.INP", "r", stdin);
    freopen("./BHHAO.OUT", "w", stdout);
    #endif

    int n, tmp, count = 0;    
    std::cin >> n;
    while (std::cin >> tmp)
        count += perfect_num.count(tong_chu_so(tmp));

    std::cout << count << "";
    return 0;
}