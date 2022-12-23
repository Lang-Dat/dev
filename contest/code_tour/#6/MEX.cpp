/**
 *	author: Lang Dat
 *	create: 29-10-2022 35:06:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 1000000 + 5;
bool isMark_b[LIM];
int isMark_org[LIM];
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./MEX.INP", "r", stdin);
    // freopen("./MEX.OUT", "w", stdout);

    int n;
    std::cin >> n;
    int mex = 0;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        isMark_org[nums[i]]++;
        while (isMark_org[mex] > 0) 
            mex++;
    }
    

    int mex_b = 0;
    for (int i : nums) {
        int tmp = min(i, mex);
        if (isMark_org[tmp] > 1) 
            isMark_b[mex] = true;
        else 
            isMark_b[tmp] = true;
        // db(min(i, mex))
        while (isMark_b[mex_b] == true) {
            mex_b++;
        }
    }
    

    std::cout << mex_b << "";
    return 0;
}