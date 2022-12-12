/**
 *	author: Lăng Trọng Đạt
 *	create: 27-11-2022 00:29:09
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void decresingN(int &n, int i, std::unordered_map<int, int> &freq_prime) {
    int tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    if (tmp > 0) {
        freq_prime[i] += tmp;
    }
}
// Phân tích n ra thừa số nguyên tố và trả về umpii
std::unordered_map<int, int> phanTichN(int n, std::unordered_map<int, int> freq_prime = {}) {
    decresingN(n, 2, freq_prime);
    decresingN(n, 3, freq_prime);
    for (int i = 5; i * i <= n; i += 6) {
        decresingN(n, i, freq_prime);
        decresingN(n, i+2, freq_prime);
    }
    if (n > 1) freq_prime[n] += 1;
    return freq_prime;
}

int n, m, c;
std::vector<int> ans;
std::unordered_map<int, int> freq, target;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BACTERIA.INP", "r", stdin);
    freopen("./BACTERIA.OUT", "w", stdout);
    #endif

    std::cin >> n >> m >> c;

    freq = phanTichN(n);
    target = phanTichN(m);
    for (auto &p : freq) {
        if (!target.count(p.first)) {
            while (freq[p.first]) {
                freq[p.first]--;
                ans.push_back(p.first);
                n /= p.first;
            }
        }
        while (p.second > target[p.first]) {
            ans.push_back(p.first);
            freq[p.first]--;
        }
    }

    for (auto &p : target) {
        if (!freq.count(p.first)) {
            cout << "Impossible";
            return 0;
        }
    }

    int times = 1;
    for (auto &p : freq) {
        freq[p.first] *= times;
        while (p.second < target[p.first]) {
            times *= 2;
            freq[p.first] *= 2;
            ans.push_back(0);
        }
        while (p.second > target[p.first]) {
            ans.push_back(p.first);
            freq[p.first]--;
        }
    }
    std::cout << ans.size() << "\n";
    for (int i : ans)
        std::cout << i << " ";
    return 0;
}