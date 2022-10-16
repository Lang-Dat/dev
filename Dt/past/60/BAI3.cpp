/**
 *	author: Lang Dat
 *	create: 16.10.2022 01.48.10
 *	[16-10-2022 06:50:21] Bug 1: trước khi dùng sàng phải đánh dấu các snt > sqrt(lim) là chính nó vì trong vòng lặp ta sẽ không lặp đến các số lớn hơn căn n
**/
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

#define ull unsigned long long

const int LIM = 1e6 + 6;
int SPF[LIM]; // smallest prime factor
void sieve() {
    for (int i = 2; i < LIM; i++)
        SPF[i] = i; // making prime number larger than sqrt(LIM) to be iself
    for (int i = 3; i * i <= LIM; i++)
        if (SPF[i] == i) {
            SPF[i] = i;
            for (int j = i * i; j <= LIM; j += i)
                if (SPF[j] == j)
                    SPF[j] = i;
        }
}
// Phân tích n ra thừa số nguyên tố và trả về umpii
std::unordered_map<int, int> phanTichNWithSPF(int n, std::unordered_map<int, int> freq_prime = {}) {
    while (n != 1) {
        freq_prime[SPF[n]]++;
        n /= SPF[n];
    }
    return freq_prime;
}
ull numOfDivisor(ull n) {
    std::unordered_map<int, int> freq_prime = phanTichNWithSPF(n);
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
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    sieve();
    ull n, tmp, ans = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        ans += tmp*numOfDivisor(tmp);
    }
    std::cout << ans;

    return 0;
}