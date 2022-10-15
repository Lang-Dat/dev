/**
 *	author: Lang Dat
 *	create: 15.10.2022 41.33.15
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

std::vector<int> int_to_vi(int n, std::vector<int> v = {}) {
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}

int v_to_int(std::vector<int> number, int a, int b) {
    // convert vector contain single digit to integer
    int num = 0;
    for (int i : number) {
        if (i == a) num = num * 10 + b;
        else num = num * 10 + i;
    }
    return num;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NHAMSO.INP", "r", stdin);
    freopen("./NHAMSO.OUT", "w", stdout);

    int a, b;
    std::cin >> a >> b;
    std::vector<int> v_a = int_to_vi(a), v_b = int_to_vi(b);   

    std::cout << v_to_int(v_a, 6, 5) + v_to_int(v_b, 6, 5) << " " << v_to_int(v_a, 5, 6) + v_to_int(v_b, 5, 6);

    return 0;
}