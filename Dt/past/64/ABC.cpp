/**
 *	author: Lang Dat
 *	create: 21-10-2022 12:14:19
**/
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ABC.INP", "r", stdin);
    freopen("./ABC.OUT", "w", stdout);

    string str;
    int count = 0;
    std::cin >> str;

    for (int i = 0; i < str.size(); i++) {
        std::unordered_map<char, int> freq = {{'A', 0}, {'B', 0}, {'C', 0}};
        for (int j = i; j < str.size(); j++) {
            if (!freq.count(str[j])) {
                break;
            }
            freq[str[j]]++;
            count += freq['A'] == freq['B'] && freq['A'] == freq['C'];
        }
    }
    std::cout << count;
    return 0;
}