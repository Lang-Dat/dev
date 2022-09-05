#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using std::vector;

// Chuyen tu danh sach canh sang ma tran ke (Do thi vo huong)
vector<vector<int>> listEdgeToMatrixUndirected() {
    int n, m, start, end;
    std::cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        std::cin >> start >> end;
        matrix[start - 1][end - 1] = 1;
        matrix[end - 1][start - 1] = 1;
    }
    return matrix;
}

// Chuyen tu danh sach canh sang ma tran ke (Do thi co huong)
vector<vector<int>> listEdgeToMatrixDirected() {
    int n, m, start, end;
    std::cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        std::cin >> start >> end;
        matrix[start - 1][end - 1] = 1;
    }
    return matrix;
}

// Chuyen tu danh sach canh sang danh sach ke (Do thi vo huong)
std::map<int, std::unordered_set<int>> listEdgeToAdjacencyList() {
    int n, m, start, end;
    std::cin >> n >> m;
    std::map<int, std::unordered_set<int>> adjacencyList;

    for (int i = 0; i < m; i++) {
        std::cin >> start >> end;
        adjacencyList[start].insert(end);
        adjacencyList[end].insert(start);
    }
    return adjacencyList;
}

int main()
{
    freopen("graph input.txt","r", stdin);
    // auto matrix = listEdgeToMatrixDirected();

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //         std::cout << matrix[i][j] << " ";
    //     std::cout << "\n";
    // }
    
    auto adjacencyList = listEdgeToAdjacencyList();
    for (auto const &[start, end] : adjacencyList) {
        std::cout << start << " : ";
        for (auto &i : end) 
            std::cout << i << " ";
        std::cout << "\n";
    }
    return 0;
}