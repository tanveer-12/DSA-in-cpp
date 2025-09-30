#include <vector>
#include <iostream>

std::vector<std::vector<int>> rotateMat(std::vector<std::vector<int>> matrix){
    int m = matrix.size();  ///rows
    int n = matrix[0].size();       // cols
    std::vector<std::vector<int>> rotated(m, std::vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            rotated[j][m - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}

int main(){
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto resulted = rotateMat(matrix);
    for(auto itr: resulted){
        for(auto val: itr){
            std::cout<< val<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}