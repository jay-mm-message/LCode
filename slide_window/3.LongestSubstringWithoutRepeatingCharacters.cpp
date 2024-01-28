#include <iostream>
using namespace std;

string sliding_windows(string s,
                        int sliding_begin,
                        int sliding_len) 
{
    
    string words;
    for(int i = sliding_begin ; i < sliding_len ; ++i) {
        words += s[i];
    }
    //cout << words << ", size: " << words.size() << endl;

    return words;
}

string sliding_windows_discard_some_letter(string s,
                        int sliding_begin,
                        int sliding_len) 
{
    
    string words;

    vector<int> letterCnt(128);
    for(int i = sliding_begin ; i < sliding_len ; ++i) {
        if (++letterCnt[s[i]] > 1) {
            return "";
        } else {
            words += s[i];
        }
    }
    //cout << words << ", size: " << words.size() << endl;

    return words;
}

void sliding_windows_move(string s,
                            int sliding_begin,
                            int sliding_len) 
{
    string words;
    while(sliding_begin + sliding_len < s.size() + 1) {
        //words = sliding_windows(s, sliding_begin, sliding_len + sliding_begin);
        words = sliding_windows_discard_some_letter(
                s, sliding_begin, sliding_len + sliding_begin);
        ++sliding_begin;
        if (!words.empty())
            cout << words << endl;
    }
}

string sliding_windows_move_find_max_substr(string s,
                            int sliding_begin,
                            int sliding_len) 
{
    string words, max_words = "";
    while(sliding_begin + sliding_len < s.size() + 1) {
        //words = sliding_windows(s, sliding_begin, sliding_len + sliding_begin);
        words = sliding_windows_discard_some_letter(
                s, sliding_begin, sliding_len + sliding_begin);
        ++sliding_begin;
        if (!words.empty()) {
            //cout << words << ", " << words.size() << endl;
            if (max_words.size() == 0 || max_words.size() < words.size()) {
                max_words = words;
            }
        }
    }
    //cout << "max_words:" << max_words << endl;
    return max_words;
}

int lengthOfLongestSubstring(string s) {

    int maxLen = 0;
    string substr = "", max_substr = "";
    for (size_t i = s.size() ; i > 0; --i)
    {
        /* code */
        int sliding_begin = 0;
        int sliding_len = i;
        //sliding_windows_move(s, sliding_begin, sliding_len);
        substr = sliding_windows_move_find_max_substr(s, sliding_begin, sliding_len);
        if (max_substr.size() < substr.size()) {
            max_substr = substr;
        }
    }
    maxLen = max_substr.size();
    cout << "substr: " << max_substr << ", size: " << maxLen << endl;
    return maxLen;
}

int main(void) {
    //string s = "abcabcbb";
    //string s = "bbbbb";
    //string s = "pwwkew";
    //string s = "c";
    //string s = "loddktdji";
    lengthOfLongestSubstring(s);
    return 0;
}