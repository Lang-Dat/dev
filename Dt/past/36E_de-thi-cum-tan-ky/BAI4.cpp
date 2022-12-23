#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>
#include <vector>
#define ull unsigned long long

const int LIM = 1e9 + 9;
// std::unordered_map<int, int> freq;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    // freopen("./Botest/Bai4/Test01/BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    ull n, d, tmp, prev_val = 0;
    ull ans = 0;

    std::cin >> d >> n;
    std::vector<int> freq(d, 0);
    // while(std::cin >> tmp) {
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        freq[(tmp + prev_val) % d]++;
        prev_val += tmp;
    }
    
    freq[0]++;
    for (int p : freq)
        ans += (ull)p*(ull)(p-1) / 2;

    std::cout << ans;
    return 0;
}