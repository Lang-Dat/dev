/**
 *	author: Lang Dat
 *	create: 31-10-2022 22:45:07
**/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int LIM = 1e6 + 6;
int SPF[LIM];

void sieve() {
    for (int i = 1; i < LIM; i++)
        SPF[i] = i;

    for (int i = 2; i * i <= LIM; i++) {
        if (SPF[i] == i) {
            for (int j = i * i; j < LIM; j += i) {
                if (SPF[j] == j) {
                    SPF[j] = i;
                }
            }
        }
    }
}

std::unordered_map<int, int> phanTichN(int n) {
    std::unordered_map<int, int> ans;
    while (n != 1) {
        ans[SPF[n]]++;
        n /= SPF[n];
    }
    return ans;
}

int numOfDivisor(int n) {
    std::unordered_map<int, int> freq_prime = phanTichN(n);
    int sum = 1;
    for (const auto &p : freq_prime) {
        sum *= (p.second + 1); 
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MATONG.INP", "r", stdin);
    freopen("./MATONG.OUT", "w", stdout);

    int n, ans = 0, tmp;
    sieve();
    std::cin >> n;
    while (std::cin >> tmp) {
        ans += tmp*numOfDivisor(tmp);
    }

    std::cout << ans << "";
    return 0;
}