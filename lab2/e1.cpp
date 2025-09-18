#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> students;
    string prev = "";

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if (name != prev)
        {
            students.push_back(name);
        }
        prev = name;
    }

    cout << "All in all: " << students.size() << endl;
    cout << "Students:" << endl;
    for (int i = (int)students.size() - 1; i >= 0; --i)
    {
        cout << students[i] << endl;
    }

    return 0;
}