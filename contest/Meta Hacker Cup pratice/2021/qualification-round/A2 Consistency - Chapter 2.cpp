#include <iostream>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <additionPrint.h>

int solve(std::string str)
{
    std::map<char, int> countChar;
    for (auto c : str) countChar[c]++;

    int v_max = 0, v_count = 0;
    int c_max = 0, c_count = 0;
    
    for (auto c : countChar)
    {
        if (VOWELS.count(c.first)) {
            if (c.second > v_max) v_max = c.second;
            v_count += c.second;
        }
        else {
            if (c.second > c_max) c_max = c.second;
            c_count += c.second;
        }
    }

    int c = (c_count - c_max) * 2 + v_count; 
    int v = (v_count - v_max) * 2 + c_count; 

    return std::min(c, v);
}

int main()
{
    // freopen("./Input/consistency_chapter_2_input.txt", "r", stdin);
    // freopen("./Output/ans_consistency_chapter_2_input.txt", "w", stdout);
    freopen("./Input/temp.txt", "r", stdin);
    
    int T, k;
    std::string str;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
    {
        std::cin >> str >> k;
        for (int i = 1; i <= T; i++)
{}
        int res = solve(str);
        std::cout << "Case #" << i << ": "
                  << res << std::endl;
    }
}