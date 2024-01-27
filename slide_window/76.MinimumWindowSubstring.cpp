// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

#include <iostream>
using namespace std;

string minWindow(string s, string t) {

    int minLeft = -1, minLen = INT_MAX;
    int t_cnt = 0, left = 0;

    vector<int> letterCnt(128);

    for (int i = 0 ; i < t.size() ; ++i) {
        letterCnt[t[i]] = letterCnt[t[i]] + 1;
    }

    for (int i = 0 ; i < s.size() ; ++i) {
        letterCnt[s[i]] = letterCnt[s[i]] - 1;
        if (letterCnt[s[i]] >= 0) { 
            ++t_cnt; }

        while(t_cnt == t.size()) {
            if (minLen > i - left + 1) {
                minLen = i - left + 1;
                minLeft = left;
            }
            letterCnt[s[left]] = letterCnt[s[left]] + 1;
            if (letterCnt[s[left]] > 0) {
                --t_cnt;
            }
            ++left;
        }
    }

    string res;
    (minLeft == -1)? res = "": res = s.substr(minLeft, minLen);
    return res;
}

int main() {
    string ss = "ADOBECODEBANC";
    string t = "ABC";
    string res;

    res = minWindow(ss, t);

    cout << "ss: " << ss << endl;
    cout << "t: " << t << endl;
    cout << "res: " << res << endl;
    return 0;
}