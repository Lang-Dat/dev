/**
 *	author: Lang Dat
 *	create: 16-10-2022 47:43:20
**/
#include <iostream>
#include <vector>
using namespace std;

const double eps = 1e-9;

class KMP {
    const std::string &pattern;
    int m;
    std::vector<int> table;
public:
    KMP(const std::string &pattern)
        : pattern(pattern), table(pattern.size()), m(pattern.size()) {
        int i = 0;
        for (int j = 1; j < m; j++) {
            while (i > 0 && pattern[i] != pattern[j])
                i = table[i-1];
            if (pattern[i] == pattern[j])
                i += 1;
            table[j] = i;
        }
    }  
    std::vector<int> find_in(const std::string &haystack) {
        std::vector<int> index_of_occu;
        for (int i = 0, j = 0; j < (int)haystack.size(); j++) {
            while (i > 0 && pattern[i] != haystack[j])
                i = table[i-1];
            if (pattern[i] == haystack[j])
                i += 1;
            if (i == m) {
                index_of_occu.push_back(j + 1 - m);
                i = table[i-1];
            }
        }
        return index_of_occu;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("A.INP", "r", stdin);
    string str, prev = "", now;
    int n, l;
    double best = 0;
    std::cin >> n >> str;
    KMP needle("aba");
    std::vector<int> occus = needle.find_in(str);
    for (int i = 0; i < occus.size(); i++) {
        // db(occus[i])
        for (double j = i, count = 1; j < occus.size(); j++, count++) {
            double l = (occus[j] + 3 - occus[i]);
            double curr = count / l;
            if (curr - best >= eps) {
                // db(curr, occus[j], count, l, prev)
                best = curr;
                prev = str.substr(occus[i], (int)l);
            }
        }
    }
    std::cout << prev;
    return 0;
}