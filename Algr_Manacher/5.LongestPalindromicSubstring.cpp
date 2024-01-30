#include <iostream>
using namespace std;


int start = 0;
int maxL = 0;
int n = 0;

void search(const string& s, int left, int right) {
    while(left >= 0 && right < n && s[left] == s[right]) --left, ++right;
    if(right-left-1 > maxL) {
        maxL = right-left-1;
        start = left+1;
    }
}


string longestPalindrome(string s) {
    n = s.size();
    if(n == 1) return s;
    for(int i = 0; i < n-1; ++i) {
        search(s, i, i);
        search(s, i, i+1);
    }
    return s.substr(start, maxL);
}

int main(void) {
    //string s = "cbbd";
    string s = "baba";
    string res = longestPalindrome(s);
    cout << "res: " << res << endl;
    s = "cbbd";
    res = longestPalindrome(s);
    cout << "res: " << res << endl;

    return 0;
}