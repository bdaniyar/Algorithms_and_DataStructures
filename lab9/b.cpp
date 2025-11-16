#include <iostream>
#include <vector>
using namespace std;

vector<int> build_lps(const string &pat){
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while(i < m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0) len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmp_count(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();
    if(m == 0) return 0;
    vector<int> lps = build_lps(pattern);
    int i = 0, j = 0;
    int cnt = 0;
    while(i < n){
        if(text[i] == pattern[j]){
            i++; j++;
            if(j == m){
                cnt++;
                j = lps[j-1];
            }
        } else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return cnt;
}

int main(){
    string a; int k;
    string b;
    cin >> a >> k >> b;
    int cnt = kmp_count(b, a);
    if(cnt >= k) cout << "YES";
    else cout << "NO";
}