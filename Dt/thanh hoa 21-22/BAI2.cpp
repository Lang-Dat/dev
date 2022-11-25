/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 09:26:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ull unsigned long long

bool isCorrect(string w, string c) {
    int freq[129];
    for (int i = 0, j = 0; i < c.size(); i++) {
        if (c[i] != w[j]) return false;
        while (c[i] == w[j]) j++;
        if (i == c.size() - 1 && j <= w.size() - 1) return false;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    #endif

    string word;
    int count = 0;
    std::vector<string> words;
    while (std::cin >> word)
        words.push_back(word);
    for (int i = 0, j = words.size() / 2; i < words.size() / 2; i++, j++) {
        count += isCorrect(words[i], words[j]);
    }
    std::cout << count << "";
    return 0;
}