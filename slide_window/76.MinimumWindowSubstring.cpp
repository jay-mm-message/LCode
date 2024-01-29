// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

#include <iostream>
using namespace std;


void show_t_map(vector<int> t_map, string tags) {
    cout << tags << "," <<"++t_map[s[spliding_windows_left]];" << endl;
    for(int i = 0 ; i < 128 ; ++i) {
        if (t_map[i]> 0)
            cout << static_cast<char>(i) << ' ';
    }
    cout << endl;
}
string minWindow(string s, string t) {

    int min_left = -1, minLen = INT_MAX;
    int t_cnt = 0, spliding_windows_left = 0;

    vector<int> t_map(128);

    // create map of all elements blonging to 't'
    for (int i = 0 ; i < t.size() ; ++i) {
        ++t_map[t[i]]; //t_map[t[i]] = t_map[t[i]] + 1;
    }
    // scanf string of s
    for (int i = 0 ; i < s.size() ; ++i) {
        // if ++, are when both element are the same, 't' and s[i]
        --t_map[s[i]]; //t_map[s[i]] = t_map[s[i]] - 1;
        // if ++, are when both element are the same, 't' and s[i]
        if (t_map[s[i]] >= 0) { 
            ++t_cnt; }

        // spliding windows move
        while(t_cnt == t.size()) {
            // first, minLen = INT_MAX, and then next min of length
            if (minLen > i - spliding_windows_left + 1) {
                // update min of length(), and then keep spliding_windows_left
                minLen = i - spliding_windows_left + 1;
                min_left = spliding_windows_left;
            }

            //show_t_map(t_map, "before");
            // spliding windows left keep move next
            ++t_map[s[spliding_windows_left]];
            //show_t_map(t_map, "after");
            //t_map[s[spliding_windows_left]] = t_map[s[spliding_windows_left]] + 1;
            // find new same element bloning to 'a'
            if (t_map[s[spliding_windows_left]] > 0) {
                // Exit the while loop and go back to finding the next 's[i]' belonging to 't' 
                --t_cnt;
            }
            // spliding windows left keep move next
            ++spliding_windows_left; 
        }
    }

    string res;
    (min_left == -1)? res = "": res = s.substr(min_left, minLen);
    return res;
}

void show(string ss, string t, string minWindows) {
    cout << "ss: " << ss << endl;
    cout << "t: " << t << endl;
    cout << "res: " << minWindows << endl;
}
int main() {

    string ss = "ADOBECODEBANC";
    string t = "ABC";
    show(ss, t, minWindow(ss, t));

    ss = "abc";
    t = 'b';
    show(ss, t, minWindow(ss, t));

    ss = "ADOBECODEBANC";
    t = 'b';

    cout << endl;
    return 0;
}