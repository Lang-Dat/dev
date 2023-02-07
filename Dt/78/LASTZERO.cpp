/**
 *	author : Lăng Trọng Đạt
 *	creater: 05-02-2023 07:36:30
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

static const int LIM = 100 + 5;
static vector<vector<int>> phan_tich;
static bool is_use[LIM];
uint64_t n, tmp, k;

std::vector<int> phan_tich_thua_so(uint64_t n) {
    int base2 = 0, base5 = 0;
    while (n % 2 == 0) {
        base2++;
        n /= 2;
    }
    while (n % 5 == 0) {
        base5++;
        n /= 5;
    }
    return {base2, base5, min(base2, base5)};
}

int solve(int pos, int count, int cnt2, int cnt5) {
    if (count == k or pos == n)
        return min(cnt2, cnt5);
    return max(solve(pos + 1, count + 1, cnt2 + phan_tich[pos][0], cnt5 + phan_tich[pos][1]), 
               solve(pos + 1, count, cnt2, cnt5));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LASTZERO.INP", "r", stdin);
    freopen("./LASTZERO.OUT", "w", stdout);

    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        phan_tich.push_back(phan_tich_thua_so(tmp));
        phan_tich[i].push_back(i); // index
    }

     std::cout << solve(0, 0, 0, 0) << "";   
}