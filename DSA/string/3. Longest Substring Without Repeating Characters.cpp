#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using std::string;

std::vector<int> freq(256, -1);

int lengthOfLongestSubstring(string s) {
    int len = 0, left = 0;
    for (int right = 0; right < s.size(); right++)
    {
        if (freq[s[right] != -1] && freq[s[right]] + 1 > left)
            left = freq[s[right]] + 1;
        freq[s[right]] = right;
        if (right - left - 1 > len)
            len = right - left + 1; 
    }
    return len;
}

int main() {
    string str = "abcabcbb";
    std::cout << lengthOfLongestSubstring(str) << " ";
}