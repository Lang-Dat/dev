/**
 *	author: Lang Dat
 *	create: 23-10-2022 33:38:08
**/
#include <iostream>
using namespace std;

string str;
int n, best = 0, ans = 0;

bool isLongestVaild(int start) {
    int open = 0, currMax = 0;
    for (int i = start; i < str.size(); i++) {
        if (str[i] == '(') open++;
        else if (str[i] == ')' && open > 0) open--;
        else break;
        if (open == 0 && i - start + 1 > currMax) {
            currMax = i - start + 1;
        }
    }
    if (currMax == best) {
        return true;
    } else if (currMax > best) {
        ans = 0;
        best = currMax;
        return true;
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NGOAC.INP", "r", stdin);
    freopen("./NGOAC.OUT", "w", stdout);

    std::cin >> str;
    for (int i = 0; i < str.size(); i++) {
        ans += isLongestVaild(i);
    }

    if (best == 0) {
        std::cout << 0 << " " << 1;
        return 0;
    } else {
        std::cout << best << " " << ans;
    }
    return 0;
}