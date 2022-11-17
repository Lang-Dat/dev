/**
 *	author: Lang Dat
 *	create: 06-11-2022 25:07:19
**/
#include <iostream>
using namespace std;

#define ull unsigned long long
int freq[11];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./THONGKE.INP", "r", stdin);
    freopen("./THONGKE.OUT", "w", stdout);
    #endif
    
    ull n, tmp;
    std::cin >> n;
    while (std::cin >> tmp)
        freq[tmp]++;
    for (int i = 0; i < 11; i++)
        if (freq[i] > 0)
            std::cout << i << " " << freq[i] << "\n";

    return 0;
}