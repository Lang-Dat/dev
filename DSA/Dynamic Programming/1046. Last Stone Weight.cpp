#include <iostream>
#include <vector>
#include <queue>
using std::vector;

int lastStoneWeight(vector<int>& stones) {
    std::priority_queue<int> maxh(stones.begin(), stones.end());
    while (maxh.size() > 1)
    {
        int first = maxh.top(); maxh.pop();
        int second = maxh.top(); maxh.pop();

        if (first != second)
            maxh.push(first - second);
    }
    return (!maxh.empty()) ? maxh.top() : 0;    
}

int main() {
    vector<int> nums = {2,7,4,1,8,1};
    std::cout << lastStoneWeight(nums) << " ";
}