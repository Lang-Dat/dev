/**
 *	author: Lang Dat
 *	create: 23-10-2022 33:38:08
**/
#include <iostream>
#include <set>
using namespace std;

string str;
int n, best = 0, ans = 0;

int vaildCount(int start) {
    std::set<string> prev_vaild;
    int open = 0;
    for (int i = start; i < str.size(); i++) {
        if (str[i] == '(') open++;
        else if (str[i] == ')' && open > 0) open--;
        else break;
        if (open == 0) {
            string sub_vaild = str.substr(start, i - start + 1);
            prev_vaild.insert(sub_vaild);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    for (int _ = 0; _ < n; _++) {
        std::cin >> str;
        int ans = 0;
        std::set<string> prev_vaild;
        for (int start = 0; start < str.size(); start++) {
                int open = 0;
                for (int i = start; i < str.size(); i++) {
                    if (str[i] == '(') open++;
                    else if (str[i] == ')' && open > 0) open--;
                    else break;
                    if (open == 0) {
                        string sub_vaild = str.substr(start, i - start + 1);
                        prev_vaild.insert(sub_vaild);
                    }
                }
        }
        std::cout << prev_vaild.size() << "\n";
    }
    return 0;
}