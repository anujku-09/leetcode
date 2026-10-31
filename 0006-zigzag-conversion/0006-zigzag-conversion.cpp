class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || s.length() <= numRows) {
            return s;
        }
        vector<string> rows(numRows);

        int currRow = 0;
        bool goDown = false;

        for(char c : s) {
            rows[currRow] += c;

            if (currRow == 0 || currRow == numRows - 1) {
                goDown = !goDown;
            }

            currRow += goDown ? 1 : -1;
        }
        string res = "";
        for(const string& row : rows) {
            res += row;
        }
        return res;
    }
};