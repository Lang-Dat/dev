#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <unordered_map>

typedef std::unordered_map<char, int> umap;

bool cmp(umap str, umap pattern) {
    // O (|pattern|)
    for (auto &p : pattern) {
        if (str[p.first] != pattern[p.first])
            return false;
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("XAU.INP", "r", stdin);
    freopen("XAU.OUT", "w", stdout);

    std::string str, pattern;
    std::cin >> pattern >> str;
    umap patternLetterCount;
    umap letterCount;

    for (char c : pattern)
        patternLetterCount[c]++;

    int length = pattern.size(), count = 0;
    
    // O (|str|)
    for (int i = 0; i < length - 1; i++)
        letterCount[str[i]]++;
    
    for (int i = length - 1; i < str.size(); i++) {
        letterCount[str[i]]++;
        if (cmp(letterCount, patternLetterCount))
            count++;
        letterCount[str[i+1-length]]--;
    }

    std::cout << count;
    return 0;
}