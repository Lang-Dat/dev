/**
 *	author: Lang Dat
 *	create: 18-10-2022 09:27:16
**/
#include <iostream>
using namespace std;

int process(string str) {
    char min_ = '9'; 
    for (int i = 1; i < str.size(); i++)
        if (str[i] < min_)
            min_ = str[i];
    std::cout << str.front() << min_ << "\n";
    return min_ - '0';
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./KhaoSatGia.INP", "r", stdin);
    freopen("./KhaoSatGia.OUT", "w", stdout);

    string str;
    int min_cost = 0, n;
    std::cin >> n;
    while (std::cin >> str) {
        min_cost += process(str);
    }
    std::cout << min_cost;
    return 0;
}