#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date {
    int day, month, year;
};

int main() {
    int n;
    cin >> n;

    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        char def; 
        cin >> dates[i].day >> def >> dates[i].month >> def >> dates[i].year;
    }

    
    sort(dates.begin(), dates.end(), [](const Date &a, const Date &b) {
        if (a.year != b.year) return a.year < b.year;
        if (a.month != b.month) return a.month < b.month;
        return a.day < b.day;
    });

  
    for (const auto &d : dates) {
        printf("%02d-%02d-%04d\n", d.day, d.month, d.year);
    }

    return 0;
}