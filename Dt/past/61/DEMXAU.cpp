/**
 *	author: Lang Dat
 *	create: 18-10-2022 01:48:14
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEMXAU.INP", "r", stdin);
    freopen("./DEMXAU.OUT", "w", stdout);

    string str;
    std::cin >> str;
    int count = 0, n = str.size();

    for (int i = 0; i < n; i++) {
        for (int j = i, num_of_char = 0, num_of_digit = 0; j < n; j++) {
            if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) {
                num_of_char++;
            } else {
                num_of_digit++;
            }
            count += num_of_char > num_of_digit;
        }
    }
    std::cout << count;
    return 0;
}