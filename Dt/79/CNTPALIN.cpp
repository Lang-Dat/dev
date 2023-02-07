#include <iostream>
#include <cstring>
#include <unordered_map>

#define db(x) std::cout << #x << ": " << x << "\n";
static const int MOD = 1e9 + 7;
std::unordered_map<char, int> freq;
std::string str;

uint64_t tu = 1, mau = 1;
uint64_t count_factorize(int n) {
    uint64_t res = 1;
    for (uint64_t i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main() {
    freopen("CNTPALIN.INP", "r", stdin);
//    freopen("./TEST/CNTPALIN/2/CNTPALIN.INP", "r", stdin);
    freopen("CNTPALIN.OUT", "w", stdout);

//    std::getline(std::cin, str);
    std::cin >> str;
    for (char& c : str)
        freq[c]++;
    int count = 0;
    bool is_have_odd = false;
    for (auto& p : freq) {
        if (p.second & 1) {
            if (is_have_odd) {
                std::cout << 0;
                return 0;
            } else is_have_odd = true;
        }
        mau *= count_factorize(p.second / 2);
        count += p.second;
//        db(p.second); db(count_factorize(p.second / 2))
    }

    std::cout << count_factorize(count / 2) / mau;
}
