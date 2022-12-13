#include <bits/stdc++.h>

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
    std::vector<int> find_in(const std::string &haystack) {
        std::vector<int> index_of_occu;
        for (int i = 0, j = 0; j < (int)haystack.size(); j++) {
            while (i > 0 && pattern[i] != haystack[j])
                i = table[i-1];
            if (pattern[i] == haystack[j])
                i += 1;
            if (i == m) {
                index_of_occu.push_back(j + 1 - m);
                i = table[i-1];
            }
        }
        return index_of_occu;
    }
};

bool isPalindrome(int l, int r, std::string &str) {
    // TC: O(r - l)
    for (; l <= r; l++, r--)
        if (str[l] != str[r])
            return false;
    return true;
}

int explane_around(int l, int r, std::string &str) {
    while (l >= 0 && r <= str.size() && str[l] == str[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}
int longest_palindrome_substring(std::string &str) {
    // TC: O(n^2)
    // nhận thấy rằng là một palindrome sẽ đối xứng quanh tâm của nó
    // và sẽ có tất cả là 2n - 1 tâm
    int best = 1;
    for (int i = 0; i < str.size(); i++)
        best = std::max(best, std::max(explane_around(i, i, str), explane_around(i, i + 1, str)));
    return best;
}