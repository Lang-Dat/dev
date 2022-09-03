#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

std::map<int, int> solve(std::vector<int> &rating, int n)
{
    std::map<int, int> ans;
    std::vector<int> cpy_rating = rating;
    std::sort(cpy_rating.begin(), cpy_rating.end());
    
    for (int i = 0; i < n; i++)
    {
        int du_r = cpy_rating[i] * 2; // mentee
        for (int j = n - 1; j >= 0; j--)
        {
            if (cpy_rating[j] /* mentor */ <= du_r && i != j) {
                ans[cpy_rating[i]] = cpy_rating[j];
                goto cnt;
            }
        }   
        ans[cpy_rating[i]] = -1;
        cnt:;
    }
    // log(ans);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("in.inp", "r", stdin);
    // freopen("in.out", "w", stdout);

    int T, n;
    std::vector<int> rating;
    std::cin >> T;
    
    for (int i = 1; i <= T; i++)
    {
        std::cin >> n;
        rating.resize(n);
        for (int j = 0; j < n; j++)
            std::cin >> rating[j];
        
        std::map<int, int> ans = solve(rating, n);
        std::cout << "Case #" << i << ": ";
        for (int num : rating)
            std::cout << ans[num] << " ";
        
        std::cout << "\n";
    }

    return 0;
}