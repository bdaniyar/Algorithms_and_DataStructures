#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[100005];
    bool s = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        s=0;
        for(int j=i-1;j>=1;j--){ //traversing the left side of the array
            if(a[j] <= a[i]){
                s=1; //finding the closest smaller element in the left side
                cout << a[j] << " ";
                break;
            }
        }
        if(s==0) cout << -1 << " "; //if there is no smaller element in the left side
    }
    


    return 0;
}