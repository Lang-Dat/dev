#include <iostream>
#include <vector>
#include <algorithm>

#define log(x) std::cout << x << " ";
#define logl(x) std::cout << x << std::endl;
#define matrix std::vector<std::vector<int>>

bool compare(const std::vector<int> &box1, const std::vector<int> &box2)
{return box1[0] < box2[0];}

int maxHeightPrev(matrix &boxs, int height[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < height[i] && boxs[n][1] > boxs[i][1] && boxs[n][0] > boxs[i][0]) max = height[i];
    }
    return max;
}

int tallestStack(matrix &boxs)
{
    std::sort(boxs.begin(), boxs.end(), compare);
    
    int n = boxs.size();
    int height[n];
    height[0] = boxs[0][2]; 

    for (int i = 1; i < n; i++)
    {
        height[i] = boxs[i][2] + maxHeightPrev(boxs, height, i);
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << boxs[i][j] << " ";
        logl("");
    }
    int max = 0;
    for (int h : height)
        // if (max < h) max = h;
        log(h);
    return max;
}

int main()
{
    matrix boxs = {
                {4, 5, 3},
                {2, 3, 2},
                {3, 6, 2},
                {1, 5, 4},
                {2, 4, 1},
                {1, 2, 2}
    };

    logl(tallestStack(boxs));
}

/*
In:
6
4 5 3
2 3 2
3 6 2
1 5 4
2 4 1
1 2 2
out: 7
*/