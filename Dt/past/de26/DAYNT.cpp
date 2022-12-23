#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <vector>

const int LIM = 32000 + 5;
std::vector<short> primes(LIM, true); 
void sieve() {
    for (int i = 2; i * i < LIM; i++)
        if (primes[i])
            for (int j = i * i; j < LIM; j += i)
                primes[j] = false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAYNT.INP", "r", stdin);
    freopen("./DAYNT.OUT", "w", stdout);

    sieve();
    int k, tmp;
    std::cin >> k;
    std::vector<int> ans;
    ans.reserve((int)1e4);
    while (std::cin >> tmp)
        if (tmp > 1 && primes[tmp]) {
            ans.push_back(tmp);
            primes[tmp] = false; // Trach lap so
        }

    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++)
        std::cout << ans[i] << " ";
    return 0;
}