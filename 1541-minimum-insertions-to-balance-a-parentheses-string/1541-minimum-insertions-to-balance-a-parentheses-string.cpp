class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int o = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                o++;
            }
            else {
                if(i + 1 < n && s[i + 1] == ')') {
                    i++;
                }
                else{
                    ans++;
                }
                if(o > 0){
                    o--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans + o * 2;
    }
};