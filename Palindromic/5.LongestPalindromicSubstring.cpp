#include <iostream>
using namespace std;


string palindrome(string s, int a, int b) {
    string res = "";
    while (s[a] == s[b]) {
        if (a < 0 || b == s.length()) {
            break;
        } else {
            res = s.substr(a, b - a + 1);
        }
        --a;
        ++b;
    }
    return res;
}

string longestPalindrome(string s) {
    string res_max = "", res = "";

    // abba
    // bab

    for (int i = 0 ; i < s.length() ; ++i) 
    {
        res = palindrome(s, i, i);
        if (res_max.size() < res.size()) {
            res_max = res;
        }
        res = palindrome(s, i, i + 1);
        if (res_max.size() < res.size()) {
            res_max = res;
        }
        //res = s.substr(s[ii], s[jj] - s[ii] + 1);
        //cout << res << endl;
    }

    cout << res_max << endl;
    return res_max;    
}

int main(void) {
    //string s = "cbbd";
    string s = "baba";
    string res = longestPalindrome(s);
    s = "cbbd";
    res = longestPalindrome(s);
    
    return 0;
}