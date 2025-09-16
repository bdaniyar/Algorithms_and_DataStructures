#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long k;
    if (!(cin >> n >> k))
        return 0;

    if (n == 0)
    {
        cout << endl;
        return 0;
    }

    vector<string> words(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];

    k %= n; // нормализуем k
    // Сдвиг влево на k позиций (как в примерах):
    rotate(words.begin(), words.begin() + k, words.end());

    for (int i = 0; i < n; ++i)
        cout << words[i] << ' ';
    cout << '\n';
    return 0;
}