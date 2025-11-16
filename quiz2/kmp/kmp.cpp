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

bool kmp_search(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = build_lps(pattern);
    int i = 0, j = 0;
    while(i < n){
        if(text[i] == pattern[j]){
            i++; j++;
            if(j == m) return true;
        } else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return false;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> build_lps(const string&pat){
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0;
    int i = 1;
    while(i < m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
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


bool kmp_search(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = build_lps(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) return true; // нашли подстроку
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return false;
}

bool kmp(const string&text, const string&pattern){
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = build_lps(pattern);
    int i=0, j=0;
    while(i<n){
        if(text[i] == pattern[j]){
            i++, j++;
            if(j==m) return true;
        }
        else{
            if(j!=0) j = lps[j-1];
            else{
                i++;
            }
        }
    }
    
}