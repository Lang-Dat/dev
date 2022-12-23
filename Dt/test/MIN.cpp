/**
 *	author: Lang Dat
 *	create: 02-11-2022 32:06:09
**/
#include <iostream>
#include <math.h>
using namespace std;

#define ull unsigned long long

int numOfDigit(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./MIN.INP", "r", stdin);
    // freopen("./MIN.OUT", "w", stdout);

    string str;
    int k;
    std::cin >> str >> k;
    if (k > str.size()) {
        std::cout << string(k, '5') << "";
    } else {
        int count = 0;
        for (char &c : str)
            count += c == '5';
        
        if (count < k) {
            int remain = k - count;
            for (char &c : str) {
                if (c < '5') c = '5';
                goto cnt;
            }
            std::cout << string(str.size() + 1, 5) << "";
            return 0;
            cnt:;
            remain--;
            for (int i = str.size() - 1; i >= 0; i--) {
                if (str[i] != '5') {
                    str[i] = '5';
                    remain--;
                }
                if (remain == 0) {
                    std::cout << str << "";
                    return 0;
                }
            }
            std::cout << string(str.size() + 1, '5') << "";
        } else {
            // for (int i = 0; i < str.size(); i++) {
            //     if (str[i] < '5') {
            //         str[i] = '5';
            //         count++;
            //         for (int i = str.size() - 1; i >= 0 && count > k; i--) {
            //             if (str[i] == '5') {
            //                 str[i] = '0';
            //                 count--;
            //             }
            //         }
            //         std::cout << str << "";
            //         return 0;
            //     }
            // }
        }
    }
    return 0;
} 