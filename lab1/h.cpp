#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool isPrime = true;
    if (n < 2)
        isPrime = false;
    for (int j = 2; j * j <= n; ++j){
        if (n % j == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
