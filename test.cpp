#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        int i = 0, j = 1, temp = 0, mx = 0;
        int idx = 0, jdx = -1;

        //check for even size
        while (j < s.size()) {
            if (s[i] == s[j]) {
                temp++;
                if (temp > mx) {
                    mx = temp;
                    idx = i;
                    jdx = j;
                }
                j++;
                if (i == 0) {
                    i = j - 1;
                    temp = 0;
                } else {
                    i--;
                }

            } else {
                temp = 0;
                j++;
                i = j - 1;
            }
        }
        mx--;

        //check for odd size
        i = 0, j = 2, temp = 0;
        while (j < s.size()) {
            if (s[i] == s[j]) {
                temp++;
                if (temp > mx) {
                    mx = temp;
                    idx = i;
                    jdx = j;
                }
                if (i == 0) {
                    j++;
                    i = j - 2;
                    temp = 0;
                } else {
                    i--;
                    j++;
                }
            } else { // incorrect block of code for updation
                temp = 0;
                j++;
                i = j - 2;
            }
        }

        string str;
        if (mx <= -1) {
            str.push_back(s[0]);
            return str;
        }

        return s.substr(idx, jdx - idx + 1);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("banana") << endl;
    return 0;
}
