#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

// O(n^3)
void floydWarshall(vector<vector<int>> &matrix){
    int m = (int)matrix.size(); // square matrix m x m
    
    for (int k=1;k<=m;k++){
        for (int i=0;i<m;i++){
            for (int j=0;j<m;j++){
                if (matrix[i][k-1] != inf && matrix[k-1][j] != inf && matrix[i][j] > matrix[i][k-1] + matrix[k-1][j]){
                    matrix[i][j] = matrix[i][k-1] + matrix[k-1][j];
                }
            }
        }
    }
}

void printMatrix(vector<vector<int>> &matrix){
    for (int i=0;i<matrix.size();i++){
        for (int j=0;j<matrix.size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    
    vector<vector<int>> matrix = {
        {0,5,inf,10},
        {inf,0,3,inf},
        {inf,inf,0,1},
        {inf,inf,inf,0}
    };
    floydWarshall(matrix);
    printMatrix(matrix);
}
