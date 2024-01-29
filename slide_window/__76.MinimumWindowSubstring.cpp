// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

string minWindow(string s, string t) {

    // create mapT for element count table for 't'
    vector<int> mapT(128);
    for (char c : t) {
        ++mapT[c];
    }

    int spliding_windows_begin = 0;
    int spliding_windows_end = 0;
    int find_t_count = 0;
    string min_substr = "";
    vector<int> mapS(128);
    for (char c : s) {

        if (mapT[c] > 0) {
            ++mapS[c];
            if (mapS[c] <= mapT[c]) {
                ++find_t_count;
            }
        }

        if (find_t_count == t.length()) {       // find all elements blonging to 't'
            while(mapT[s[spliding_windows_begin]] < mapS[s[spliding_windows_begin]] 
                        || mapT[s[spliding_windows_begin]] == 0) 
            {
                // Move the spliding windows, and when the next element blonging to 't' is found
                if (mapT[s[spliding_windows_begin]] < mapS[s[spliding_windows_begin]]) {
                    --mapS[s[spliding_windows_begin]];
                }
                ++spliding_windows_begin;
            } // while finish

            if (min_substr == "" 
                || spliding_windows_begin -  spliding_windows_begin + 1 < min_substr.length())
            {
                min_substr = s.substr(spliding_windows_begin, spliding_windows_end + 1);
            }
        } // if (find_t_count == t.length()) finish

        ++spliding_windows_end;
    } // for (char c : s) finish
    spliding_windows_begin = 0;
    spliding_windows_end = 0;
    find_t_count = 0;
    string min_substr_chk = "";
    vector<int> mapMinSubstr(128);
    for(char c : min_substr) {

        if (mapT[c] > 0) {
            ++mapMinSubstr[c];
            if (mapMinSubstr[c] <= mapT[c]) {
                ++find_t_count;
            }
        }
        if (find_t_count == t.length()) {
            if (min_substr_chk == "" 
                || spliding_windows_end - spliding_windows_begin + 1 < min_substr_chk.size())
                min_substr_chk = min_substr.substr(spliding_windows_begin, spliding_windows_end + 1);
        }
        ++spliding_windows_end;
    }
    return min_substr_chk;
}



int main() {
    string ss = "ADOBECODEBANC";
    string t = "ABC";
    // string ss = "abc";
    // string t = "b";
    string res;

    cout << "min_substr: " << minWindow(ss, t) << endl;
    cout << "min windows size: " << minWindow(ss, t).size() << endl;

    return 0;
}


/*
int minWindow(string s, string t) {
    // create mapT
    vector<int> mapT(128);
    for(char c : t) {
        ++mapT[c]; // mapT[c] = mapT[c] + 1;
    }

    string result = "";
    int count = 0; 
    int start = 0; int i = 0;
    vector<int> mapS(128);
    for(char c : s) {
        if (mapT[c] > 0) {
            ++mapS[c];
            if (mapT[c] >= mapS[c]) {
                ++count;
            }
        }
        if (count == t.length()) {
            while (mapT[s[start]] < mapS[s[start]] || mapT[s[start]] == 0) {
                if (mapT[s[start]] < mapS[s[start]]) {
                    --mapS[s[start]];
                }
                ++start;
            }
            if (result ==  "" || i - start + 1 < result.length()) {
                result = s.substr(start, i + 1);
            }
        }
        ++i;
    }
    cout << result << endl;
    int min_size = result.size();
    return min_size;
}*/