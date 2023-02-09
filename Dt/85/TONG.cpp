#include <iostream>
#include <unordered_map>

std::unordered_map<int64_t, int> freq = {{0, 1}}; // freq[i]: number of prefix have sum equal to i

int main() {
    freopen("TONG.INP", "r", stdin);
    freopen("TONG.OUT", "w", stdout);

    int64_t n, sum = 0, tmp, cnt = 0;
    std::cin >> n;
    freq.reserve(2*n);
    while (std::cin >> tmp) {
        sum += tmp;
        cnt += freq[sum];
        freq[sum]++;
    }

    std::cout << cnt;
}
