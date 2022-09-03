#include <iostream>
#include <string.h>

int L, min, remain;
std::string str, curr = "";

int bruceForce(int L, std::string str)
{
    if (L == 1)
        return 1;

    for (min = 1; min <= L; min++)
    {
        curr += str[min - 1];
        for (int i = 0; i < L - min; i += min) {
            if (str.substr(i, min) != curr)
                    goto cnt;
        }

        remain = L % min;
        if ((remain == 0 && str.substr(L - min) == curr) || 
            (remain && str.substr(L - remain) == curr.substr(0, remain)))
            return min;
        cnt:;
    }
    return 0;
}

int main()
{
    Timer time;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("a.inp", "r", stdin);
    freopen("a.out", "a", stdout);

    std::cin >> L;
    std::cin >> str;

    int ans = bruceForce(L, str);
    std::cout << ans;
}