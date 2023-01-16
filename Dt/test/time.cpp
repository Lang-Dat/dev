/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 12:48:19
**/
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;

static const int LIM = 1e8;
template<typename F>
void benchmark(F func, const string& name) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;

    auto t1 = high_resolution_clock::now();
    func();
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    cout << name << "\t\t: " << ms_double.count() << endl;
}

void not_unsign() {
    for (int _ = 0; _ < 5; _++) {
        int64_t i = 1;
        for (int64_t j = 0; j <= LIM; j++)
        i += j;
    }
}
void unsign() {
    for (int _ = 0; _ < 5; _++) {
        uint64_t i = 1;
        for (uint64_t j = 0; j <= LIM; j++)
            i += j;
    }
}
int main()
{

    benchmark(unsign, "dung unsign");
    benchmark(not_unsign, "kh dung unsign");

        
    return 0;
}