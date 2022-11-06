/**
 *	author: Lang Dat
 *	create: 03-11-2022 09:36:20
**/
#include <iostream>
#include <algorithm>

using namespace std;

struct Shape {
    int a, b, h;
    int count = 1, best = 0;
    void rerange() {
        int tmp = h;
        h = min({a, b, h});
        if (h == a) a = tmp;
        else if (h == b) b = tmp;
        best = h;
    }
};

const int LIM = 5005;
Shape s[LIM]; // shapes

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TOWER.INP", "r", stdin);
    freopen("./TOWER.OUT", "w", stdout);

    int n, best_h = 0, so_hop = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> s[i].a >> s[i].b >> s[i].h;
        s[i].rerange();
    }
    
    sort(s, s + n, [](Shape &a, Shape &b) -> bool {
        if (a.a == b.a) return a.b < b.b;
        return a.a < b.a;
    });

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i].b >= s[j].b && s[i].best < s[j].best + s[i].h) {
                s[i].best = s[j].best + s[i].h;
                s[i].count = s[j].count + 1;
            }
        }
        if (s[i].best > best_h) {
            so_hop = s[i].count;
            best_h = s[i].best;
        }
    }
    std::cout << so_hop << " " << best_h;
    return 0;
}