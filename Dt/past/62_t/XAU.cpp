/**
 *	author : Lăng Trọng Đạt
 *	creater: 25-01-2023 09:02:04
 **/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

static const int base = 31;
static const int MOD = 1e9 + 9;

bool rabin_karp(int l, string &s)
{
    // Kiểm tra xem có tồn tại hai chuỗi con nào giống nhau có độ dài là l
    uint64_t curr = 0, h = 1;
    std::unordered_map<uint64_t, vector<int>> seen; // <value, index>
    // calc first hash
    for (int i = 0; i < l; i++) {
        curr = (curr*base + s[i]);
        if (i) h *= base;
    }

    seen[curr] = {0};

    for (int i = 0; i + l <= s.size(); i++)
    {
        curr = ((curr - (s[i] * h)) * base + s[i + l]);
        if (seen.count(curr)) {
            string temp = s.substr(i + 1, l);
            for (int start : seen[curr]) {
                if (temp == s.substr(start, l))
                    return true;
            }
        }
        seen[curr].push_back(i + 1);
    }

    return false;
}

int longestDupSubstring(string s)
{
    // TC: O(nLog(n)) n is |s|
    int n = s.size();

    int lo = 0, hi = n;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        if (!rabin_karp(mid, s))
            hi = mid - 1;
        else
        {
            ans = mid;
            lo = mid + 1;
        }
    }

    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./XAU.INP", "r", stdin);
    // freopen("./Test/XAU/test16/XAU.INP", "r", stdin);
    freopen("./XAU.OUT", "w", stdout);
#endif

    int n;
    string str;
    std::cin >> n >> str;
    cout << longestDupSubstring(str);
    return 0;
}
