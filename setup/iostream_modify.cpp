#define dbm(mess) std::cout << mess;
#define db1(a) std::cout << #a << " = " << a << "\n";
#define db2(a, b) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << "\n";
#define db3(a, b, c) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " " \
                             << #c << " = " << c << "\n";
#define db4(a, b, c, d) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " " \
                             << #c << " = " << c << " " \
                             << #d << " = " << d << "\n";
#define db5(a, b, c, d, e) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " " \
                             << #c << " = " << c << " " \
                             << #d << " = " << d << " " \
                             << #e << " = " << e << "\n";

#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define db(...) GET_MACRO(__VA_ARGS__, db5, db4, db3, db2, db1)(__VA_ARGS__)
