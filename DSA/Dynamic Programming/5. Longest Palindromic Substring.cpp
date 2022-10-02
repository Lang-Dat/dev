#include <iostream>
using std::string;

bool is_palindrome(string &str) {
    for (int i = 0; i < str.size() / 2; i++)
        if (str[i] != str[str.size() - 1 - i])
            return false;
    return true;
}

string longestPalindrome(string s) {
    int best = 0, n = s.size();
    string best_substr, subs;

    for (int l = 0; l < n; l++) {
        subs = s.substr(l);
        for (;subs.size() > best; subs.pop_back()) {
            if (is_palindrome(subs)) {
                best = subs.size();
                best_substr = subs;
            } 
        }
    }
    return best_substr;
}

int main() {
    string str = ""; 
    Timer time;
    std::cout << longestPalindrome(str) << "\n";
}