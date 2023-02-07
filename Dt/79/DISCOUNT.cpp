#include <iostream>
#include <algorithm>

static const int LIM = 1e7 + 5;
static int freq[LIM];
int n, maximum_val = 0, tmp;

int main() {
    freopen("DISCOUNT.INP", "r", stdin);
    freopen("DISCOUNT.OUT", "w", stdout);

    std::cin >> n;
    while (std::cin >> tmp) {
        freq[tmp]++;
        maximum_val = std::max(maximum_val, tmp);
    }
    for (int i = maximum_val; i >= 1; i--) {
        for (int j = i, count = 0; j <= maximum_val; j += i) {
            count += freq[j];
            if (count > 1) {
                std::cout << i;
                return 0;
            }
        }
    }
}
