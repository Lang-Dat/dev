/**
 *	author: Lang Dat
 *	create: 20-11-2022 42:42:11
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Shape
{
    int index;
    double area;
};

static const int LIM = 1e4 + 5;
int ans[LIM], X[LIM], Y[LIM];
Shape shapes[LIM];

double calcArea(int numOfVertex) {
// The area is then given by the formula
// |(x1.y2 − y1.x2) + (x2.y3 − y2.x3) + .... +  (xn.y1 − yn.x1)| / 2
    double sum = 0;
    for (int i = 0; i < numOfVertex - 1; i++) {
        // db(X[i], Y[i])
        sum += X[i]*Y[i+1] - Y[i]*X[i+1];
    }
    sum += X[numOfVertex-1]*Y[0] - Y[numOfVertex-1]*X[0];
    sum = std::abs(sum) / 2;
    // db(sum)
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);
    #endif

    int n, soDinh;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> soDinh;
        for (int j = 0; j < soDinh; j++) {
            std::cin >> X[j] >> Y[j];
        }
        shapes[i].index = i;
        shapes[i].area = calcArea(soDinh);
    }

    sort(shapes, shapes + n, [](Shape &a, Shape &b) -> bool {
        return a.area > b.area;
    });
    for (int i = 0; i < n; i++) {
        ans[shapes[i].index] = i;
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << "\n";
    }   
    return 0;
}