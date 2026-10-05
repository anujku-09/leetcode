class Solution {
public:
    int scoreOfParentheses(string s) {
        int sc = 0;
        int dep = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                dep++;
            } else{
                dep--;
                if(s[i - 1] == '('){
                    sc += (1 << dep);
                }
            }
        }
        return sc;
    }
};