/**
 *	author: Lang Dat
 *	create: 06-11-2022 48:15:19
**/
#include <iostream>
using namespace std;

int freq1[129], freq2[129];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./XAU.INP", "r", stdin);
    freopen("./XAU.OUT", "w", stdout);
    #endif

    string s1, s2;
    int count = 0;
    std::cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        freq1[s1[i]]++;
        freq2[s2[i]]++;
    }
    freq2[s2[s1.size()-1]]--;

    for (int i = s1.size() - 1; i < s2.size(); i++) {
        freq2[s2[i]]++;
        for (int i = 0; i <= 128; i++)
            if (freq1[i] != freq2[i])
                goto cnt;
        count++;
        cnt:;
        freq2[s2[i - s1.size() + 1]]--;
    }
    std::cout << count << "";
    return 0;
}