#include <iostream>
#include <vector>
using std::vector;

int n, res = 0, sumEnergy = 0;

int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
    n = energy.size();
    for (int i = 0; i < n; i++)
    {
        sumEnergy += energy[i];
        int hours = 0;
        if (experience[i] >= initialExperience)
            hours += experience[i] - initialExperience + 1;
        res += hours;
        initialExperience += experience[i] + hours;
    }    

    if (sumEnergy >= initialEnergy)
        res += sumEnergy - initialEnergy + 1;

    return res;
}

int main()
{
    // Input: initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
    // Output: 8
    int initialEnergy = 2, initialExperience = 4;
    vector<int> energy = {1}, experience = {3};
    int ans = minNumberOfHours(initialEnergy, initialExperience, energy, experience);
    log(ans);
}