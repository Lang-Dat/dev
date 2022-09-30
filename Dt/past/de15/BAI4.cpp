#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

void find(std::string str) {
    int index, sum = 0; 
    //  S(M)=1a1+2a2+3a3+…+10a10 
    for (int i = 1; i <= 10; i++) {
        if (str[i-1] != '?')    
            sum += i * (int)(str[i-1]-'0');
        else if (str[i-1] == '?') index = i;
    }
    int next = sum / 11 * 11;
    if (next < sum) next += 11;
    for (int i = next - sum;; i += 11)
        if (i % index == 0) {
            if (i / index != 10)
                std::cout << i / index << " \n";
            return;
        }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    std::string str;
    while(std::cin >> str)
        find(str);
    return 0;
}