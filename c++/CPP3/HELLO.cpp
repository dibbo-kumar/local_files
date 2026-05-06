#include <iostream>
#include <ctime>

using namespace std;
void delay(double seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}
int main()
{
    string s = "MY NAME IS DIBRO KUMAR BISWASH";
    string p = "                                     ";
    for (int i = 0; i < 30; i++)
    {
        char c = 'A';
        while (s[i] + 1 > c)
        {
            p[i] = c;
            cout << p << endl;
           delay(0.05);
            c++;
        }
    }
    return 0;
}
