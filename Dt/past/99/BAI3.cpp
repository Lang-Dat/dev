/**
 *	author: Lang Dat
 *	create: 20-11-2022 54:15:11
**/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
static const int LIM = 1e5 + 5;
int nums[LIM];
ll n, total = 0;
std::vector<ll> uocs;

bool isVaild(ll uoc) {
    std::vector<int> split_points;
    for (ll i = 1, curr = 0, prev = 1; i <= n; i++) {
        curr += nums[i];
        if (curr == uoc) {
            split_points.push_back(prev);
            prev = i + 1;
            curr = 0;
        } else if (curr > uoc || i == n) return false;
    }
    std::cout << split_points.size() << "\n";
    for (int i : split_points)
        std::cout << i << " ";
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        total += (ll)nums[i];
    }
    
    for (ll i = 1; i * i <= total; i++) {
        if (total % i == 0) {
            uocs.push_back(i);
            if (i * i != total) uocs.push_back(total / i);
        }
    }
    sort(uocs.begin(), uocs.end());
    for (int uoc : uocs) {
        if (isVaild(uoc)) break;
    }
    return 0;
}