/**
 *	author: Lang Dat
 *	create: 27-10-2022 40:39:07
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int LIM = 1e6 + 6;
int best = 0;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./COVIT.INP", "r", stdin);
    freopen("./COVIT.OUT", "w", stdout);

    int n, s;
    std::cin >> n >> s;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int l = 0, r = 0, currSum = 0;;) {
        if (currSum + nums[r] <)
    }
    return 0;
}