/**
 *	author: Lang Dat
 *	create: 08-11-2022 05:12:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 1e3 + 5;
int nums[LIM][LIM], freq[LIM];
inline bool isVaild(int x, int y) {
    return nums[x][y] == nums[x+1][y] && 
           nums[x][y] == nums[x][y+1] &&
           nums[x][y] == nums[x+1][y+1]; 
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./dem.INP", "r", stdin);
    freopen("./dem.OUT", "w", stdout);
    #endif

    int n, ans = 0, best = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> nums[i][j];
    
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1; j++)
            if (isVaild(i, j)) {
                freq[nums[i][j]]++;
                best = max(best, freq[nums[i][j]]);
            }
    std::cout << best << "";
    return 0;
}