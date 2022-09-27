#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
struct Activity {
    int start = 0, end = 0;
};
//Function to find the maximum number of activities that can
//be performed by a single person.
int activitySelection(vector<int> start, vector<int> end, int n)
{
    Activity lich[n];
    for (int i = 0; i < n; i++) {
        lich[i].start = start[i];
        lich[i].end = end[i];
    }
    std::sort(lich, lich + n, [](Activity a1, Activity a2) -> bool {return a1.end < a2.end;});
    for (int i = 0; i < n; i++) {
        std::cout << lich[i].start << " " << 
        lich[i].end << "\n";
    }
 
}

int main() {
    // Input:
    // N = 4
    // start[] = {1, 3, 2, 5}
    // end[] = {2, 4, 3, 6}
    // Output: 
    // 3
    // Explanation:
    // A person can perform activities 1, 2
    // and 4.
    vector<int> start = {1, 3, 2, 5};
    vector<int> end = {2, 4, 3, 6};
    std::cout << activitySelection(start, end, 4) << " ";
}