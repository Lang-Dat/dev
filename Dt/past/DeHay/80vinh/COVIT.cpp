// https://leetcode.com/discuss/interview-question/758045/
/**
 *	author: Lang Dat
 *	create: 27-10-2022 40:39:07
 * This is hard problem
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int LIM = 1e6 + 6;
int best = 0;
int nums[LIM], cumm_neg_sum[LIM];

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
    for (int i = n - 1, curr = 0; i >= 0; i--) {
        cumm_neg_sum[i] = curr;
        curr = min(0, curr + nums[i]);
    }

    for (int currSum = 0, l = 0, r = 0; r < n; r++) {
        currSum += nums[r];
        while (currSum +  cumm_neg_sum[r] > s && l < r) {
            currSum -= nums[l++];
        }
        if (currSum <= s && r - l > best) {
            best = r - l;
        }
        // db(r, l, currSum, nums[r], cumm_neg_sum[r])
    }
    std::cout << best + 1<< "";
    return 0;
}