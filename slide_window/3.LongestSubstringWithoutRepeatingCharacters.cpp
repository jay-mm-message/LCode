#include <iostream>
#include <set>

using namespace std;


void show(set<char> st) {
    for (char c : st) {
        cout << c;
    }
    cout << endl;
}

// int lengthOfLongestSubstring(string s) {
//     int n = s.size();
//     set<char> st;

//     int spliding_windows_begin = 0;
//     int spliding_windows_end = 0;
//     int maxLen = 0;

//     while(spliding_windows_end < n) {
//         if (st.find(s[spliding_windows_end]) == st.end()) {
//             st.insert(s[spliding_windows_end]);
//             maxLen = max(maxLen, spliding_windows_end - spliding_windows_begin + 1);
//             ++spliding_windows_end;
//         }
//         else
//         {
//             //erase before store of st
//             st.erase(st.find(s[spliding_windows_begin]));
//             // shift
//             ++spliding_windows_begin;
//         }
//     }
//     show(st);
//     return maxLen;
// }

  int lengthOfLongestSubstring(string s) {
    
    int maxLen = 0;
    int right_w = 0, left_w = 0;
    set<char> st;
    while (right_w < s.length()) {
        if (st.find(s[right_w]) == st.end()) {
            // right_w
            st.insert(s[right_w]);
            if (maxLen < right_w - left_w + 1) {
                maxLen = right_w - left_w + 1;
            }
            ++right_w;
        } else {
            // left_w
            st.erase(st.find(s[left_w]));
            ++left_w;
        }
    }
    show(st);
    return maxLen;
  }

int main(void) {
    //string s = "abcabcbb";
    //string s = "bbbbb";
    //string s = "pwwkew";
    //string s = "c"
    string s = "loddktdji";
    lengthOfLongestSubstring(s);
    return 0;
}