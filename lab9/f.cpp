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

void kmp_find_positions(const string &text, const string &pattern, vector<int> &vect){
    int n = text.size();
    int m = pattern.size();
    if(m == 0) return;

    vector<int> lps = build_lps(pattern);
    int i = 0, j = 0;

    while(i < n){
        if(text[i] == pattern[j]){
            i++; j++;
            if(j == m){
                vect.push_back(i - j); // сохраняем индекс начала совпадения
                j = lps[j-1]; // продолжаем искать другие вхождения
            }
        } else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
}

int main(){
    string a;
    string b;
    vector<int> vect;
    cin >> a >> b;
    kmp_find_positions(a,b,vect);
    cout << vect.size() << endl;
    for(int x: vect){
        cout << x +1 << " ";
   }
}