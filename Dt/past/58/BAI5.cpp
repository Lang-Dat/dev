/**
 *	author: Lang Dat
 *	create: 16.10.2022 04.21.08
 *	[16.10.2022 31.34.09] Bug 1: Đề nó yêu cầu in ra index chứ kh phải giá trị
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Value {
    int index = 0, val = 0, prevIndex = -1, count = 1;
};
const int LIM = 5005;
Value nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    freopen("./Test/Bai5/test2/BAI5.INP", "r", stdin);
    // freopen("./BAI5.OUT", "w", stdout);

    int n, tmp, end, max = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        nums[i].val = tmp;
        nums[i].index = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i - 1; j++) {
            if (nums[i].count < nums[j].count + 1 &&
                nums[i].val > nums[j].val) {
                nums[i].count = nums[j].count + 1;
                nums[i].prevIndex = j;
            }
        }
        if (nums[i].count > max) {
            end = i;
            max = nums[i].count;
        }
    }
    std::vector<int> ans;
    for (int i = end;i != -1;) {
        ans.push_back(i + 1);
        i = nums[i].prevIndex;
    }
    reverse(ans.begin(), ans.end());
    std::cout << ans.size() << "\n";
    for (int i : ans)
        std::cout << i << " ";
    return 0;
}