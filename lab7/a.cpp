#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> words;
        string w;
        while(ss>>w){
            words.push_back(w);
        }
        stable_sort(words.begin(), words.end(), 
        [](const string&a, const string&b){
            return a.size() < b.size();
        });
        for(auto&x : words){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}