/**
 *	author: Lang Dat
 *	create: 29-10-2022 25:28:20
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./tom.INP", "r", stdin);
    // freopen("./tom.OUT", "w", stdout);

    int n, k;
    string str;
    std::cin >> str >> n >> k;
    int time = 0, trong_bung = 0, pho_mai = 0, can = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '*') {
            pho_mai++;
            can = 0;
            trong_bung++;
        }
        else {
            if (trong_bung > 0) trong_bung--;
            can++;
            pho_mai = 0;
        }
        if (pho_mai > k || can > k) {
            std::cout  << "FAIL";
            return 0;
        }
        time++;
        if (trong_bung == n && i != str.size() - 1) {
            trong_bung = 0;

            time += n;
        }
    } 
    std::cout << time << "";
    return 0;
}