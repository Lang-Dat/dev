/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 15:25:19
**/
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool cmp(std::vector<int> a, std::vector<int> b) {
    for (int i = 0; i < std::min(a.size(), b.size()); i++)
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;

    return true;
}

std::set<std::vector<int>> ans;
std::vector<std::vector<int>> final_ans; // to easy sort

// biểu diễn một số dưới dạng tổng của các số tự nhiên
void solve(int curr, std::vector<int> curr_ans, int& target) {
    if (curr == target) {
        sort(curr_ans.begin(), curr_ans.end(), greater<int>());
        if (!ans.count(curr_ans)) {
            ans.insert(curr_ans);
            final_ans.push_back(curr_ans);
        }
        return;
    } else if (curr > target) return;

    for (int i = 1; i <= target - curr; i++) {
        curr_ans.push_back(i);
        solve(curr + i, curr_ans, target);
        curr_ans.pop_back();
    }    
}

void print() {
    sort(final_ans.begin(), final_ans.end(), cmp);
    
    for (auto &s : final_ans) {
        for (int num : s)
            std::cout << num << " ";
        std::cout << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./PTT.INP", "r", stdin);
    freopen("./PTT.OUT", "w", stdout);
    #endif

    int target;
    std::cin >> target;

    solve(0, {}, target);

    print();
    return 0;
}