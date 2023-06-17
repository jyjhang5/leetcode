#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int count[255] = {0};

        for (int startPos = 0; startPos < s.length(); startPos++) {
            for (int endPos = startPos; endPos < s.length(); endPos++) {
                int index = s[endPos] - 0;
                count[index]++;
                if (count[index] > 1) {
                    if (maxLength < (endPos - startPos)) {
                        maxLength = endPos - startPos;
                    }
                    fill_n(count, 255, 0);
                    break;
                }
                else if (endPos == s.length() - 1){
                    if (maxLength < (endPos - startPos + 1)) {
                        maxLength = endPos - startPos + 1;
                    }
                }
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution s;
    string str1;
    str1 = "abcabcbb"; // ans ＝ 3
    // str1 = "bbbbb"; // ans ＝ 1
    // str1 = "pwwkew"; // ans ＝ 3
    // str1 = " 1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*()_+{}:<>?\\";
    // str1 = "$?"; // ans = 1
    int result = s.lengthOfLongestSubstring(str1);
    cout << result << endl;
}