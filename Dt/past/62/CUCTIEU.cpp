/**
 *	author: Lang Dat
 *	create: 18-10-2022 56:19:15
**/
#include <iostream>
using namespace std;

const int LIM = 32005;
int nums[LIM];
int n, count = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CUCTIEU.INP", "r", stdin);
    freopen("./CUCTIEU.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1 && nums[1] < nums[2]) count++;
        else if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) count++;
        else if (i == n && nums[n] < nums[n-1]) count++;
    }

    std::cout << count;
    return 0;
}