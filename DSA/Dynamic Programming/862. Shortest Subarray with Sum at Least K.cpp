/**
 *	author: Lang Dat
 *	create: 16.10.2022 56.39.06
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Value {
    int val = 0, index = 0;
};

int find_ind(std::vector<Value> &prefix_sum, int value, int start, int end) {
    // find the last element smaller or equal to value
    end--;
    int ans = -1, mid;
    while (start <= end) {
        mid = (end - start) / 2;
        if (prefix_sum[mid].val <= value) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<Value> prefix_sum(n);
    int sum = 0, shortest = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        prefix_sum[i].val = sum;
        prefix_sum[i].index = i;
    }    
    sort(prefix_sum.begin(), prefix_sum.end(), [](const Value &a, const Value &b) -> bool {
        if (a.val == b.val) {
            return a.index < b.index;
        }
        return a.val < b.val;
    });
    int maxInd[n];
    maxInd[0] = prefix_sum[0].index;
    for (int i = 1; i < n; i++) {
        maxInd[i] = max(maxInd[i - 1], prefix_sum[i].index);
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // if (sum >= k) {

        // }
        int x = sum - k;
        int ind = find_ind(prefix_sum, x, 0, n);
        db(ind, prefix_sum[ind].val, prefix_sum[ind].index, x, sum)
        if (ind != -1 && sum >= k) {
            shortest = min(shortest, i + 1);
        } else {
            for (int j = ind; j >= 0; j--) {
                if (maxInd[j] <= i) {
                    dbm("fuck")
                    shortest = min(shortest, i - j + 1);
                    break;
                }
            }
        }
        // db(ind, sum, i, prefix_sum[i].val, prefix_sum[i].index)
    }
    return shortest;
}

int main()
{
    std::vector<int> nums = {2, -1, 2};
    std::cout << shortestSubarray(nums, 3);

    return 0;
}