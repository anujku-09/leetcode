class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty() || matrix[0].empty()) return ans;

        int top = 0;
        int btm = matrix.size() - 1;
        int lft = 0;
        int rgt = matrix[0].size() - 1;
        while (top <= btm && lft <= rgt){
            for(int j = lft; j <= rgt; j++){
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int i = top; i <= btm; i++){
                ans.push_back(matrix[i][rgt]);
            }
            rgt--;

            if(top <= btm){
                for(int j = rgt; j >= lft; j--) {
                    ans.push_back(matrix[btm][j]);
                }
                btm--;
            }
            if(lft <= rgt){
                for(int i = btm; i >= top; i--){
                    ans.push_back(matrix[i][lft]);
                }
                lft++;
            }
        }
        return ans;
    }
};