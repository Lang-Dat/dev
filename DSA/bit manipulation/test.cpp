#include <iostream>
#include <bitset>

#define log1(a) std::cout << #a << " = " << a << "\n";
#define log2(a, b) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " ";
#define log3(a, b, c) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " " \
                             << #c << " = " << c << " ";
#define log4(a, b, c, d) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " " \
                             << #c << " = " << c << " " \
                             << #d << " = " << d << " ";

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define log(...) std::cout << ##__VA_ARGS__; //GET_MACRO(__VA_ARGS__, log4, log3, log2, log1)(__VA_ARGS__)

int main()
{
    int a = 2, b = 3, c = 4, z = 5;
    int t = 0;
    log(a, b, c);    // (output)  $ ./"test.exe"
                        //              a = 2 b = 3 c = 4 z = 5
    return 0;
}