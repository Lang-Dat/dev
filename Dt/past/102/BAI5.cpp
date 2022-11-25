/**
 *	author: Lang Dat
 *	create: 21-11-2022 26:01:08
**/
#include <iostream>
using namespace std;

#define ull unsigned long long

static const int LIM = 4*1e5 + 5;
int nums[LIM];
int freq[(int)1e8 + 5];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);
    #endif

    int n, k;
    ull count = 0;
    std::cin >> n >> k;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (ull l = 0, r = 0; r < n; r++) {
        freq[nums[r]]++;  
        while (freq[nums[r]] >= k) {
            count += n - r;
            freq[nums[l++]]--;
        }
    }
    cout << count;
    return 0;
}