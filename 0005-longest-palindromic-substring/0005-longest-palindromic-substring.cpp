class Solution {
public:
    int expand(string& s, int l, int r){
        while (l >= 0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int st=0, maxLen=0;
        for(int i = 0; i < s.length(); i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int currmax = max(len1, len2);
            if(currmax > maxLen){
                maxLen = currmax;
                st = i - (currmax -1)/2;
            }
        }
        return s.substr(st,maxLen);
    }
};