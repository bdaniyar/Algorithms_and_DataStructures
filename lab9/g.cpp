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

int main(){
    string s;
    cin >> s;
    vector<int> lps = build_lps(s);
    int val = lps[lps.size()-1];
    int n = s.size();
    cout << n - val << endl;
}