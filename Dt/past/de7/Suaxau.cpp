#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <cstring>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("Suaxau.INP", "r", stdin);
    freopen("Suaxau.OUT", "w", stdout);

    std::string str;
    std::getline(std::cin, str);
    std::vector<char> stack;
    for (char c : str)
    {
        if (c == '#' && stack.size() != 0)
            stack.pop_back();
        else if (c != '#')
            stack.push_back(c);
    }

    for (char c : stack)
        std::cout << c;

    return 0;
}