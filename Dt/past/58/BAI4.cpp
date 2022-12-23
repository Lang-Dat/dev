/**
 *	author: Lang Dat
 *	create: 16.10.2022 38.07.08
 *	[16.10.2022 53.34.09] Bug 1: String nó cho trên nhiều dòng, nếu dùng getline thì nó tính cả kí tự '\n' nên không thể sử dụng trong trường hợp này
**/
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> prevOccu(128, -1);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    string str = "", tmp;
    while (std::cin >> tmp)
        str += tmp;
    int now = 0, best = 0, index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (prevOccu[str[i]] >= now) {
            now = prevOccu[str[i]] + 1;
        }
        prevOccu[str[i]] = i;
        if (i - now + 1 > best) {
            best = i - now + 1;
            index = now;
        }
    }
    std::cout << index + 1 << " " << best << "\n";
    return 0;
}