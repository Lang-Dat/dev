#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

const int LIM = 1e5 + 5;
std::vector<int> nums;

static const int LIM_SIEVE = 1e4 + 5;
uint64_t ONES[64]; // 1 << i
uint64_t sieve_mark[LIM_SIEVE / 64 + 11];

inline void mark(int &bit) { sieve_mark[bit / 64] |= ONES[bit & 63]; }
inline bool is_prime(int bit) { return (bit > 1 and bit % 2 != 0) and (sieve_mark[bit / 64] & ONES[bit & 63]) == 0 or bit == 2; }

void sieve(int n) {
    for (int i = 0; i < 64; i++) ONES[i] = 1ULL << i; // turn bit i on

    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime(i)) {
            for (int j = i * i; j < n; j += i + i)
                mark(j);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NUMBER.INP", "r", stdin);
    freopen("./NUMBER.OUT", "w", stdout);

    sieve(LIM_SIEVE);
    
    nums.reserve(LIM);
    int tmp;
    while (std::cin >> tmp)
        nums.push_back(tmp);
        
    int n = nums.size();

    int ans = -1;
    for (int i = n - 2; i > 0; i--)
        if (is_prime(nums[i+1]) and is_prime(nums[i-1])) {
            ans = i;
            break;
        }
    std::cout << ans + 1;
    return 0;
}