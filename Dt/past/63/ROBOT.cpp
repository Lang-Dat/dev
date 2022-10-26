/**
 *	author: Lang Dat
 *	create: 20-10-2022 04:17:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Time {
    int start = 0, end = 0;
};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ROBOT.INP", "r", stdin);
    freopen("./ROBOT.OUT", "w", stdout);

    int n;
    std::cin >> n;
    Time time[n];

    for (int i = 0; i < n; i++) {
        std::cin >> time[i].start >> time[i].end;
    }
    sort(time, time + n, [](Time &a, Time &b) -> bool {
        return a.end < b.end;
    });
    Time prev = time[0];
    int count = n > 0;
    for (int i = 1; i < n; i++) {
        if (time[i].start >= prev.end) {
            prev = time[i];
            count++;
        }
    }   
    std::cout << count;
    return 0;
}