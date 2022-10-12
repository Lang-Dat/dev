/**
 *	author: Lang Dat
 *	create: 12.10.2022 44.29.19
**/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long

const int LIM = 1e5;
bool isNotPrime[LIM];
void sieve(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}

std::vector<int> num_to_v(int n, std::vector<int> v = {}) {
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}

bool isPrime(ull n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MPRIME.INP", "r", stdin);
    freopen("./MPRIME.OUT", "w", stdout);

    ull tmp; // n < 500
    int n;
    std::vector<int> prev = {2}, curr;
    std::cin >> n;
    sieve(LIM);
    for (int i = 3; n > 0; i += 2) {
        if (!isNotPrime[i]) {
            curr.clear();
            curr = num_to_v(i);
            tmp = 0;
            for (int i : prev) tmp = tmp * 10 + i;
            prev.clear();
            for (int i : curr) {
                tmp = tmp * 10 + i;
                prev.push_back(i);
            }
            if (isPrime(tmp)) n--;
        }
    } 
    std::cout << tmp;
    return 0;
}