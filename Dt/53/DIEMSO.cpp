/**
 *	author : Lăng Trọng Đạt
 *	creater: 08-01-2023 28:46:14
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    int tong;
    int ind, rank;
    string name;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DIEMSO.INP", "r", stdin);
    freopen("./DIEMSO.OUT", "w", stdout);
    #endif

    int n, a, b;
    std::cin >> n;
    Student nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i].name >> a >> b;
        nums[i].tong = a + b;
        nums[i].ind = i;
    }
    
    sort(nums, nums + n, [](Student &a, Student &b) -> bool {
        return a.tong > b.tong;
    });

    nums[0].rank = 1;
    for (int i = 1, count = 2; i < n; i++, count++) {
        if (nums[i].tong < nums[i-1].tong)
            nums[i].rank = count;
        else nums[i].rank = nums[i-1].rank;
    }   

    sort(nums, nums + n, [](Student &a, Student &b) -> bool {
        return a.ind < b.ind;
    });
    for (int i = 0; i < n; i++) {
        std::cout << nums[i].name << " " << nums[i].rank << "\n";
    }

    return 0;
}