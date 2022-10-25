/**
 *	author: Lang Dat
 *	create: 23-10-2022 33:38:08
**/
#include <iostream>
using namespace std;

string str;
int n, best = 0, ans = 0;
const int LIM = 1e6;
int dp[LIM]; // dp[i] = longest vaild length end in str[i]
bool isLongestVaild(int &start, int currMax = 0) {
    int open = 0, i;

    for (i = start; i < str.size(); i++) {
        if (str[i] == '(') open++;
        else if (str[i] == ')' && open > 0) open--;
        else {
            start = i;
            break;
        }
        if (open == 0 && i - start + 1 > currMax) {
            currMax = i - start + 1;
        }
        // if (i == str.size() - 1) {
        //     start = str.size();
        // }
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
    str.insert(str.begin(), ' ');
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == '(') dp[i] = 0;
        else if (str[i] == ')') {
            if (str[i-1] == '(')
                dp[i] = dp[i-2] + 2;
            else if (str[i-1] == ')' && str[i-dp[i-1]-1] == '(')
                dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2;
        }
        if (dp[i] == best) {
            ans++;
        } else if (dp[i] > best) {
            ans = 1;
            best = dp[i];
        }
    }

    if (best == 0) {
        std::cout << 0 << " " << 1;
        return 0;
    } else {
        std::cout << best << " " << ans;
    }
    return 0;
}