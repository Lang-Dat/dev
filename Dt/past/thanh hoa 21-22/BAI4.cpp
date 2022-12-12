/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 11:51:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

const int LIM = 1e3 + 6;
std::vector<bool> isPrime(LIM, true);
std::vector<int> primes = {2};

void sieve(int n) {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

int calc(int64_t r, int64_t l) {
    //  tính số số không phải là số nguyên tố nhưng có số ước là SNT
    db(r, l)
    int count = 0;
    for (int64_t i = 0; i < primes.size(); i++) {
        for (int64_t j = 1; j < primes.size(); j++) {
            int64_t power = (int64_t)(pow(primes[i], primes[j] - 1) + .1);
            // db(primes[i], primes[j], power, count)
            if (power > r) break;
            if (power >= l) {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    // freopen("./Test/BAI4/Test11/BAI4.INP", "r", stdin);
    // freopen("./BAI4.OUT", "w", stdout);
    #endif

    int64_t l, r;
    std::cin >> l >> r;
    sieve(LIM);
    std::vector<int64_t> ans;
    int end = 15; // log2(1e12)
    for (int i : primes) {
        for (int j = 1; j < end; j++) {
            int64_t power = (int64_t)(pow(i, primes[j] - 1) + .1);
            if (power > 1e12 || power < 0) {
                end = j;
                break;
            }
            ans.push_back(power);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i : ans)
        std::cout << i << " ";
    // cout << calc(r, l);
    return 0;
}