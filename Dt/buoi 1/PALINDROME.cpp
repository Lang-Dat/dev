#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <cstring>

inline short getLength(int n) {
    return std::to_string(n).size();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("PALINDROME.INP", "r", stdin);
    freopen("PALINDROME.OUT", "w", stdout);

    std::string str;
    long long count = 0, L, R;
    std::cin >> L >> R;

    if (R < 1e4) {
        for (int i = L; i <= R; i++)
        {
            str = std::to_string(i);
            if (str[0] == str[str.size() - 1])
                count++;
        }
    }
    else {
        if (L < 10) {
            count += 10 - L;
            L = 10;
        }
        short r = getLength(R);
        for (short i = 0; i < r; i++)
            count += std::pow(10, i)*9;
    }
    
    
    std::cout << count;

    return 0;
}