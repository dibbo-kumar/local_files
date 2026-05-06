#include <iostream>
using namespace std;
int main()
{
    int d, m, y;
    int d1, m1, y1;

    cout << "Enter first date (dd/mm/yyyy): ";
    cin >> d >> m >> y;

    cout << "Enter second date (dd/mm/yyyy): ";
    cin >> d1 >> m1 >> y1;
    int total_date = 0;
    // if (d > d1)
    // {
    //     int df = (30 - d) + d1;
    //     total_date = total_date + df;
    // }
    // else
    // {
    //     total_date = total_date + (d1 - d);
    // }
    // if (m > d1)
    // {
    //     int mf = (12 - m) + m1;
    //     total_date = total_date + mf * 30;
    // }
    // else
    // {
    //     total_date = total_date + (m1 - m) * 30;
    // }
    total_date += (d1 - d) + (m1 - m) * 30;

    total_date = total_date + (y1 - y) * 365;

    int tm = total_date / 30;
cout << tm << endl;
    int td = total_date % 30;
    int ty = tm / 12;
    tm = tm % 12;
    cout << "The difference between the two dates is: " << td << " days, " << tm << " months, and " << ty << " years.";
    cout << total_date << endl;

    return 0;
}
