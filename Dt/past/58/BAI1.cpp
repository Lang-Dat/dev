/**
 *	author: Lang Dat
 *	create: 16.10.2022 00.48.07
**/
#include <iostream>
#include <vector>
using namespace std;

const int LIM = 1e6 + 6;
std::vector<bool> isPrime(LIM, true);

int sieve(int l, int r, int count = 0) {
    for (int i = 2; i * i <= r; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= r; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = l; i <= r; i++)
        count += isPrime[i];
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    int n, l = INT32_MAX, r = 0, tmp, ans;
    std::cin >> n;
    while(std::cin >> tmp) {
        l = min(l, tmp);
        r = max(r, tmp);
    }
    ans = sieve(l, r);
    std::cout << ans - n;
    return 0;
}