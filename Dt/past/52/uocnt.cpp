/**
 *	author : Lăng Trọng Đạt
 *	creater: 07-01-2023 09:37:20
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

std::unordered_map<int64_t, int> prime_freq;
void decre(int64_t &n, int64_t p) {
    int count = 0;
    while (n % p == 0) {
        count++;
        n /= p;
    }
    if (count)
        prime_freq[p] = count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./uocnt.INP", "r", stdin);
    freopen("./uocnt.OUT", "w", stdout);
    #endif

    int64_t n;
    std::cin >> n;

    decre(n, 2);
    decre(n, 3);

    for (int64_t i = 5; i * i <= n; i += 6) {
        decre(n, i);
        decre(n, i + 2);
    }
    if (n > 1)
        prime_freq[n]++;

    std::cout << prime_freq.size() << "";
    return 0;
}