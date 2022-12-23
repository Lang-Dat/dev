/**
 *	author: Lang Dat
 *	create: 12.10.2022 44.46.21
**/
#include <iostream>
#include <vector>
using namespace std;

string pattern, str;

class KMP {
    const string &needle;
    std::vector<int> table;
public:
    KMP(const string &needle) :
        needle(needle), table(needle.size()) {
        for (int i = 0, j = 1; j < needle.size(); j++) {
            while (needle[i] != needle[j] && i > 0) {
                i = table[i-1];
            }
            if (needle[i] == needle[j])
                i += 1;
            table[j] = i;
        }
    }
    std::vector<int> find_in(const string &hay_stack) {
        std::vector<int> index_of_occu;
        for (int i = 0, j = 0; j < hay_stack.size(); j++) {
            while (needle[i] != hay_stack[j] && i > 0) {
                i = table[i-1];
            }
            if (needle[i] == hay_stack[j])
                i += 1;
            if (i == needle.size()) {
                index_of_occu.push_back(j + 1 - needle.size());
                i = 0; // reset
            }
        }
        return index_of_occu;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CENSOR.INP", "r", stdin);
    freopen("./TEST/censor/test10/CENSOR.INP", "r", stdin);
    freopen("./CENSOR.OUT", "w", stdout);

    std::cin >> str >> pattern;
    KMP needle(pattern);
    std::vector<int> index_of_occu = needle.find_in(str);
    while (!index_of_occu.empty()) {
        for (int i = index_of_occu.size() - 1; i >= 0; i--) {
            str.erase(index_of_occu[i], pattern.size());
        }
        index_of_occu = needle.find_in(str);
    }
    std::cout << str;
    return 0;
}