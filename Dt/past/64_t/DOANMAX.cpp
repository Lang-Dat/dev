/**
 *	author : Lăng Trọng Đạt
 *	creater: 26-01-2023 08:36:13
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DOANMAX.INP", "r", stdin);
    freopen("./DOANMAX.OUT", "w", stdout);
    #endif

    string str;
    std::getline(cin, str);

    int best_length = 1, pos = 1;
    std::unordered_map<char, int> freq;

    for (int l = 0, r = 0; r < str.size(); r++) {
        freq[str[r]]++;
        while (freq[str[r]] > 1) {
            freq[str[l++]]--;
        }
        if (r - l + 1 > best_length) {
            best_length = r - l + 1;
            pos = l + 1;
        }
    }

    std::cout << pos << " " << best_length;
    
    return 0;
}