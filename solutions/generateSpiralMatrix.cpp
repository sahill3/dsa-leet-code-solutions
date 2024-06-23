class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0)) ;

        int eCol = n-1;
        int eRow = n-1;
        int sRow = 0, sCol = 0;
        int num = 1;
        int count = 0;
        int total = n*n;

        while(count < total){
            for(int i = sCol; count < total && i <= eCol; i++){
                matrix[sRow][i] = num++;
                count++;
            }
            sRow++;

            for(int i = sRow; count < total && i <= eRow; i++){
                matrix[i][eCol] = num++;
                count++;
            }
            eCol--;

            for(int i = eCol; count < total && i >= sCol; i--){
                matrix[eRow][i] = num++;
                count++;
            }
            eRow--;

            for(int i = eRow; count < total && i >= sRow; i--){
                matrix[i][sCol] = num++;
                count++;
            }
            sCol++;
        }
        return matrix;
    }
};
