/**
 *	author : Lăng Trọng Đạt
 *	creater: 05-02-2023 07:16:05
**/
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int64_t tong_uoc(int n) {
    int64_t sum = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            sum += i;
            if (i * i != n)
                sum += n / i;
        }
    return sum;
}

pair<int64_t, int64_t> get_abundancy(int64_t n) {
    int64_t tong_cac_uoc = tong_uoc(n);
    int temp = n;
    for (int i = 2; i * i <= temp; i++) {
        while (n % i == 0 and tong_cac_uoc % i == 0) {
            n /= i;
            tong_cac_uoc /= i;
        }
    }
    if (n > 1 and tong_cac_uoc % n == 0) {
        n = 1;
        tong_cac_uoc /= n;
    } 
    return {tong_cac_uoc, n};
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SOTT.INP", "r", stdin);
    freopen("./SOTT.OUT", "w", stdout);

    int64_t a, b;
    std::cin >> a >> b;
    
    pair<int64_t, int64_t> a_abun = get_abundancy(a), b_abun = get_abundancy(b);
    if (a_abun.first == b_abun.first and a_abun.second == b_abun.second)
        std::cout << a_abun.first << "\n" << a_abun.second;
    else 
        std::cout << -1 << "";
}