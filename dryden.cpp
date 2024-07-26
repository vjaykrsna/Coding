string longestPalindrome(string s){
    if (s.size() <= 1)
        return s;
    int i = 0, j = 1, temp = 0, mx = 0;
    int idx = 0, jdx = -1;

    while (j < s.size()){
        if (s[i] == s[j]){
            temp++;
            if (temp > mx){
                mx = temp;
                idx = i;
                jdx = j;
            }
            if (i == 0){
                j++;
                i = j - 1;
                temp = 0;
            }
            else{
                i--;
                j++;
            }
        }
        else{
            temp = 0;
            i++;
            j++;
        }
    }

    string str;
    if (mx <= -1)
    {
        str.push_back(s[0]);
        return str;
    }

    return s.substr(idx, jdx - idx + 1);
}