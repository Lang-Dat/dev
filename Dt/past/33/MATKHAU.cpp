/**
 *	author: Lăng Trọng Đạt
 *	create: 22-12-2022 00:34:07
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int best = 2;

static const int LIM = 1e6 + 5;
uint64_t ONES[64]; // 1 << i
uint64_t sieve_mark[LIM / 64 + 11];

inline void mark(int &bit) { sieve_mark[bit / 64] |= ONES[bit & 63]; }
inline bool is_prime(int &bit) { return (bit != 1 and bit % 2 != 0) and (sieve_mark[bit / 64] & ONES[bit & 63]) == 0 or bit == 2; }

void sieve(int n) {
    for (int i = 0; i < 64; i++) ONES[i] = 1ULL << i; // turn bit i on

    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime(i)) {
            for (int j = i * i; j < n; j += i + i)
                mark(j);
        }
    }
}


void find_largest(std::string num) {
    for (int i = 0; i < num.size(); i++) {
        for (int j = i, curr = 0; j < num.size() and curr < 1e6; j++)  {
            curr = curr * 10 + (num[j] - '0');
            if (curr < 1e6 and is_prime(curr))
                best = max(best, curr);
        }
    }
}  

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MATKHAU.INP", "r", stdin);
    freopen("./MATKHAU.OUT", "w", stdout);
    #endif

    sieve(LIM);

    string tmp = "";
    std::vector<string> nums;

    char c;
    while (std::cin >> c) {
        if ((c > '9' or c < '0') and tmp != "") {
            nums.push_back(tmp);
            tmp = "";
        } else if (c >= '0' and c <= '9') {
            tmp += c;
        }
    }

    if (!tmp.empty()) nums.push_back(tmp);
    for (string num : nums)
        find_largest(num);

    std::cout << best << "";
    return 0;
}