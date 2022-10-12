#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>
#include <map>

#define ull unsigned long long
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Dao_CS.INP", "r", stdin);
    freopen("./Dao_CS.OUT", "w", stdout);

    std::string num;
    std::cin >> num;
    ull n = num.size();
    if (n <= 2) {
        std::cout << "12";
        return 0;
    }
    int isSwap = 0;
    int last = (num[n-1] - '0') + (num[n-2] - '0') * 10;
    if (num.front() > '1') {
        num[0] = '1';
        isSwap++;
    }
    for (int i = 1; i < num.size() - 2 && (isSwap < 1 || 
                  (last % 4 == 0 && isSwap < 2)); i++) {
        if (num[i] > '0') {
            num[i] = '0';
            isSwap++;
        }
    }
    if (isSwap == 0) {
        num[n - 1] = '0';
        num[n - 2] = '0';
    } else if (isSwap == 1) {
        if (num[n-2] == '0') {
            num[n-1] = '0';
        } else if ((int)(num[n-1] - '0') % 4 == 0) {
            num[n-2] = '0';
        } else if ((int)(num[n-1] - '0') % 2 == 0){
            num[n-2] = '1';
        } else if ((int)(num[n-2] - '0') % 2 == 0){
            num[n-1] = '0';
        } else {
            num[n-1] = '2';
        }
    }

    std::cout << num;

    return 0;
}