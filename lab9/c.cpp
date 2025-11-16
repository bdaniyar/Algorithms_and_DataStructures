#include <iostream>
#include <vector>

using namespace std;

vector<int> build_lps(const string&pat){
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0;
    int i = 1;
    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0 ){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


int kmp_search(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = build_lps(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) return i - j;; // нашли подстроку
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}


int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    string s = s1+s1;
    int cnt = kmp_search(s,s2);
    if(cnt < 0) cout << -1;
    else cout << (int(s1.size()) - cnt) % int(s1.size());

    return 0;
}