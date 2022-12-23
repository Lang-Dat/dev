/**
 *	author: Lang Dat
 *	create: 23-10-2022 50:14:10
**/
#include <iostream>
using namespace std;

int best = 0;

void longestEqualSubseq(string str) {
    for (int i = 1, count = 1; i < str.size(); i++) {
        if (str[i] == str[i-1]) count++;
        else count = 1;
        if (count > best) best = count;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Xanhdep.INP", "r", stdin);
    freopen("./Xanhdep.OUT", "w", stdout);

    int n;
    std::cin >> n;
    string str;
    while (std::cin >> str) {
        longestEqualSubseq(str);
    }
    std::cout << best;

    return 0;
}