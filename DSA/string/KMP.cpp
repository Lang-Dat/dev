#include <iostream>
#include <debug.h>
#include <algorithm>
#include <vector>
#include <cstring>

void build_LPS_table(const std::string &pattern, std::vector<int> &LPS) {
    // TC: O(m)
    // SP: O(m)
    int m = pattern.size();
    LPS.resize(m, 0);
    int i = 0;
    for (int j = 1; j < m; j++) {
        while (pattern[i] != pattern[j] && i > 0) {
            i = LPS[i-1];
        }
        if (pattern[j] == pattern[i]) {
            i++;
        }
        LPS[j] = i;
    }
}

std::vector<int> KMP(const std::string &haystack, const std::string &pattern) {
    std::vector<int> index_of_occu;
    std::vector<int> LPS;
    build_LPS_table(pattern, LPS);    
    int n = (int)haystack.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && pattern[j] != haystack[i]) {
            j = LPS[j-1];
        }
        if (pattern[j] == haystack[i]) {
            j++;
        }
        if (j == pattern.size()) {
            index_of_occu.push_back(i + 1 - j);
            j = LPS[j - 1];
        }
    }   
    return index_of_occu;
}

int main() {
    // std::string haystack = "aabcgdaaabcaabdaaabc";
    std::string haystack = std::string((int)1e7, 'aaaaaaaaaaabx') + "aaabc";
    std::string pattern = "aaabc";
    Timer t;
    std::cout << KMP(haystack, pattern);
    // std::cout << std::search(haystack.begin(), haystack.end(), pattern.begin(), pattern.end()) - haystack.begin() << " ";
        
}