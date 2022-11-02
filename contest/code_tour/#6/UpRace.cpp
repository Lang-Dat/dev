/**
 *	author: Lang Dat
 *	create: 29-10-2022 47:51:20
**/
#include <iostream>
using namespace std;

const int LIM = 1e5 + 5;
int moi_nhom[LIM], freq[LIM];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./UpRace.INP", "r", stdin);
    // freopen("./UpRace.OUT", "w", stdout);

    int n, tmp, ans = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        moi_nhom[tmp]++;
    }
    for (int i : moi_nhom)
        freq[i]++;
    for (int i = 1; i < LIM; i++) {
        while (freq[i] > 1) {
            for (int j = i - 1; j >= 0; j--) {
                if (j == 0) {
                    freq[i]--;
                    ans += i;
                } else {
                    if (freq[j] == 0) {
                        freq[j] = 1;
                        freq[i]--;
                        ans += i - j;
                        break;
                    }
                }
            }           
        }
    }
    std::cout << ans << "";
    return 0;
}