class Solution {
public:
    vector<string> ans;
    bool isValid(const string& s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')') {
                cnt--;
                if (cnt < 0)
                    return false;
            }
        }
        return cnt == 0;
    }

    void dfs(string& s, int idx, int rem_l, int rem_r) {
        if (rem_l == 0 && rem_r == 0) {
            if (isValid(s))
                ans.push_back(s);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (i > idx && s[i] == s[i - 1])
                continue;
            if (s[i] == '(' && rem_l > 0) {
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, i, rem_l - 1, rem_r);
            } else if (s[i] == ')' && rem_r > 0) {
                string next = s.substr(0, i) + s.substr(i + 1);
                dfs(next, i, rem_l, rem_r - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int rem_l = 0, rem_r = 0;
        for (char& c : s) {
            if (c == '(') {
                rem_l++;
            } else if (c == ')') {
                if (rem_l > 0)
                    rem_l--;
                else {
                    rem_r++;
                }
            }
        }
        dfs(s, 0, rem_l, rem_r);
        return ans;
    }
};