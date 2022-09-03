#include <cmath>
#include <iostream>
#include <algorithm>

int main()
{
    Timer time;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);

    int n;
    std::cin >> n;
    short nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    int tu = 0, nhon = 0, vuong = 0, temp;
    double pythago;

    std::sort(nums, nums + n);
    for (int a = 0; a < n; a++)
        for (int b = a + 1; b < n; b++) {
            temp = nums[a] + nums[b];
            pythago = sqrt(nums[a]*nums[a] + nums[b]*nums[b]);
            // a + c > b > c - a
            for (int c = b + 1; temp > nums[c] && c < n; c++) {
                if (nums[c] < pythago) nhon++;
                else if (nums[c] == pythago) vuong++;
                else tu++;
            }
        }

    std::cout << nhon << " " << vuong << " " << tu;
    return 0;
}