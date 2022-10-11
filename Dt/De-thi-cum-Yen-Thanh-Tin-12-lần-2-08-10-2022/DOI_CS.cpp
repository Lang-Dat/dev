#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <map>

#define ull unsigned long long
std::map<char, char> hang_chuc_theo_don_vi = {{'0', '0'}, {'2', '1'}, {'4', '2'}, {'6', '1'}, {'8', '0'}};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOI_CS.INP", "r", stdin);
    freopen("./DOI_CS.OUT", "w", stdout);

    std::string num;
    std::cin >> num;
    ull n = num.size();
    if (n <= 2) {
        std::cout << "12";
        return 0;
    } else if (num.front() == '1') {
        num[n - 1] = '0';
        num[n - 2] = '0';
    } else {
        num[0] = '1';
        if (num[n-2] == '0') {
            num[n-1] = '0';
        } else if (hang_chuc_theo_don_vi.count(num.back())) {
            num[n-2] = hang_chuc_theo_don_vi[num.back()];
        } else if ((int)(num[n-2] - '0') % 2 == 0){
            num[n-1] = '0';
        } else {
            num[n-1] = 2;
        }
    }
    std::cout << num;

    return 0;
}