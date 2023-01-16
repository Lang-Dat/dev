/**
 *	author: Lang Dat
 *	create: 13-11-2022 09:33:18
**/
#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

static const int LIM = 1e6 + 3;
int SPF[LIM];
void sieve() {
    for (int i = 0; i < LIM; i++)
        SPF[i] = i;
    for (int i = 2; i * i < LIM; i++)
        if (SPF[i] == i)
            for (int j = i * i; j <= LIM; j += i)
                if (SPF[j] == j)
                    SPF[j] = i;
}

std::unordered_map<int, int> phanTich(int n) {
    std::unordered_map<int, int> freq_prime;
    while (n != 1) {
        freq_prime[SPF[n]]++;
        n /= SPF[n];
    }
    return freq_prime;
}
int sumOfFactor(int n) {
    std::unordered_map<int, int> freq_prime = phanTich(n);
    double sum = 1;
    for (const auto &p : freq_prime) {
        // fix std::pow'bug by + 0.1
        sum *= ((int)(std::pow(p.first, p.second + 1) + 0.1) - 1) / (double)(p.first - 1); 
    }
    return sum;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GHH.INP", "r", stdin);
    freopen("./GHH.OUT", "w", stdout);
    #endif

    sieve();
    int n, tmp;    
    std::cin >> n;
    while (std::cin >> tmp) {
        if (2*tmp <= sumOfFactor(tmp))
            std::cout << 1 << "\n";
        else 
            std::cout << 0 << "\n";
    }
    return 0;
}