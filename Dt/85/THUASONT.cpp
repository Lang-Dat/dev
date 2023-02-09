#include <iostream>
#include <map>

std::map<int64_t, int> freq;
int64_t n;

void decre(int i) {
    while (n % i == 0) {
        freq[i]++;
        n /= i;
    }
}

int main() {
    freopen("THUASONT.INP", "r", stdin);
    freopen("THUASONT.OUT", "w", stdout);

    std::cin >> n;

    decre(2);
    decre(3);
    for (int64_t i = 5; i * i <= n; i++) {
        decre(i);
        decre(i + 2);
    }
    if (n > 1) freq[n]++;
    std::cout << freq.size() << "\n";
    for (auto &p : freq) {
        if (p.second != 0) {
            std::cout << p.first << " " << p.second << "\n";
        }
    }
}
