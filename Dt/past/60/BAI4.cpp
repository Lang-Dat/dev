/**
 *	author: Lang Dat
 *	create: 16.10.2022 57.54.11
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    string str;
    int n;
    std::cin >> n >> str;

    for (int length = 1; length <= str.size(); length++)
    {
        for (int start = 0; start + length < str.size(); start++)
        {
            if (search(str.begin() + start + 1, str.end(), 
                       str.begin() + start, str.begin() + start + length) != str.end())
                goto cnt;
        }
        std::cout << length;
        return 0;
        cnt:;
    }
    std::cout << str.size();
 
    return 0;
}