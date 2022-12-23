/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 09:15:16
**/
#include <iostream>
#include <algorithm>
using namespace std;

bool is_flip = false;
int n;
string str;
char curr(int i) {
    if (str[i] == 'A') {
        return ((is_flip) ? 'B' : 'A');
    } else
        return ((is_flip) ? 'A' : 'B');
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DNA.INP", "r", stdin);
    freopen("./DNA.OUT", "w", stdout);
    #endif

    std::cin >> n >> str;

    int a = 0, b = 0;
    
    for (char c : str)
        (c == 'A') ? a++ : b++;

    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        // db(curr(i), i)
        if (curr(i) == 'B') {
            if (i > 0 and curr(i-1) == 'A') {
                if (b >= a) {
                    is_flip = !is_flip;
                    // db(i, "xxx")
                }
            } else is_flip = !is_flip;
            while (i >= 0 and curr(i) == 'B') {
                i--;
                // db(i, curr(i))
            }
            i++;

            count++;
        }
        (curr(i) == 'A') ? a-- : b--;
    }
    std::cout << count << "";
    return 0;
}