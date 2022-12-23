#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstring>

class KMP {
    const std::string &pattern;
    int m;
    std::vector<int> table;
public:
    KMP(const std::string &pattern)
        : pattern(pattern), table(pattern.size()), m(pattern.size()) {
        int i = 0;
        for (int j = 1; j < m; j++) {
            while (i > 0 && pattern[i] != pattern[j])
                i = table[i-1];
            if (pattern[i] == pattern[j])
                i += 1;
            table[j] = i;
        }
    }  
    std::unordered_set<int> find_in(const std::string &haystack) {
        std::unordered_set<int> index_of_occu;
        for (int i = 0, j = 0; j < (int)haystack.size(); j++) {
            while (i > 0 && pattern[i] != haystack[j])
                i = table[i-1];
            if (pattern[i] == haystack[j])
                i += 1;
            if (i == m) {
                index_of_occu.insert(j + 1 - m);
                i = table[i-1];
            }
        }
        return index_of_occu;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./THAYTHE.INP", "r", stdin);
    freopen("./THAYTHE.OUT", "w", stdout);

    std::string haystack, pattern, replace;
    std::getline(std::cin, haystack);
    std::cin >> pattern >> replace;
    KMP needle(pattern);
    std::unordered_set<int> index_of_occu = needle.find_in(haystack);
    for (int i = 0; i < (int)haystack.size();) {
        if (index_of_occu.count(i)) {
            std::cout << replace << "";
            i += (int)pattern.size();
        } else {
            std::cout << haystack[i] << "";
            i += 1;
        }
    }
    return 0;
}