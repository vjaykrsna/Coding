#include <bits/stdc++.h>
using namespace std;

int main(){
    int adb1=266,adb2=289;
    vector<string> set1(adb1), set2(adb2), set3;
    string str;

    for (int i = 0; i < adb1; i++){ //adb shell pm list packages
        cin >> str;
        set1[i] = str.substr(8, str.size());
    }

    for (int i = 0; i < adb2; i++){ //adb shell pm list packages -u
        cin >> str;
        set2[i] = str.substr(8, str.size());
    }

    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    int i=0,j=0;
    while(j<adb2){//finding difference
        if(set1[i] == set2[j]){
            i++;
            j++;
        } else {
            str = "pm uninstall -k --user 0 " + set2[j];
            // str = "adb shell pm enable " + set2[j];
            set3.push_back(str);
            j++;
        }
    }
    for(auto i: set3) cout<<i<<endl;
}