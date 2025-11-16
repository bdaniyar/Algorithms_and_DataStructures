#include <iostream>
#include <vector>

using namespace std;

vector<int> build_lps(const string &s){
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;
    for(int i=1;i<n;i++){
        while(len>0 && s[i]!=s[len])
            len = lps[len-1];
        if(s[i]==s[len])
            len++;
        lps[i]=len;
    }
    return lps;
}

int main(){
    string s = "ababcabab";
    vector<int> lps = build_lps(s);

    int len = lps.back(); // длина наибольшего суффикс-префикса
    cout << "Длина: " << len << "\n";
    cout << "Суффикс-префикс: " << s.substr(0,len) << "\n";
}