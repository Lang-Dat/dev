
// Addition modify
#include <set>
#include <memory>
#include <chrono>
#include <vector>
#include <map>


#define log1(a) std::cout << #a << " = " << a << "\n";
#define log2(a, b) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << "\n";
#define log3(a, b, c) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " " \
                             << #c << " = " << c << "\n";
#define log4(a, b, c, d) std::cout << #a << " = " << a << " " \
                             << #b << " = " << b << " " \
                             << #c << " = " << c << " " \
                             << #d << " = " << d << "\n";

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define log(...) GET_MACRO(__VA_ARGS__, log4, log3, log2, log1)(__VA_ARGS__)

struct Timer
{
    // dependents header: chrono
public:
    bool inSecond;
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000;
        std::cout << "Running time: " << ms << "ms ~ " 
                  << duration.count() << "s\n";
    }
};

// Print set with cout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s)
{
    os << "{ ";
    for (auto &i : s) 
        os << i << " ";
    os << "}\t";
    return os;
}
// Print vector with cout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto &i : v) 
        os << i << " ";
    os << "}\t";
    return os;
}
// Print 2D vector with cout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v)
{
    os << "\n  ";
    for (auto &temp : v) 
    {
        for (auto &i : temp)
                os << i << " ";
        os << "\n  ";
    }
    return os;
}
// Print map with cout
template<typename T>
std::ostream &operator<<(std::ostream &os, const std::map<T, T> &mp)
{
    os << "{ ";
    for (auto &i : mp)
        os << i.first << " : " << i.second << "; ";
    os << "}\t";
    return os;
}