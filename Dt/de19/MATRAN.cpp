#pragma GCC optimize("O2")
#include <iostream>

const int LIM = 150;
int matrix[LIM][LIM], freqDoc[LIM][LIM], freqNgang[LIM][LIM];
int x, y;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MATRAN.INP", "r", stdin);
    freopen("./MATRAN.OUT", "w", stdout);

    std::cin >> x >> y;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++) {
            std::cin >> matrix[i][j];
            if (j > 0) freqNgang[i][j] = freqNgang[i][j - 1] + matrix[i][j];
            else if (j == 0) freqNgang[i][j] = matrix[i][j];
        }
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            if (j > 0) freqDoc[j][i] = freqDoc[j - 1][i] + matrix[j][i];
            else if (j == 0) freqDoc[j][i] = matrix[j][i];

    // for (int i = 0; i < x; i++) {
    //     for (int j = 0; j < y; j++)
    //         std::cout << freqDoc[i][j] << " ";
    //     std::cout << "\n";  
    // }
    // logm("Ngang\n")
    // for (int i = 0; i < x; i++) {
    //     for (int j = 0; j < y; j++)
    //         std::cout << freqNgang[i][j] << " ";
    //     std::cout << "\n";  
    // }
    
    return 0;
}