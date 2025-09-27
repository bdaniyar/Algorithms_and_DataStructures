#include <iostream>
#include <vector>

using namespace std;

int count(const vector<int>& a, int L, int R){
    int cnt= 0;
    for(int x: a){
        if (L<= x && x <=R) cnt++;
    }
    return cnt;
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    for(int i=0;i<q;i++){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int c1 = count(vect, l1 ,r1);
        int c2 = count(vect, l2, r2);
        int c12 = count(vect, max(l1,l2), min(r1,r2));

        cout << c1 + c2 - c12 << endl;
    }
}