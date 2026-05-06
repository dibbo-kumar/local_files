#include <iostream>
using namespace std;
int main()
{
    int x, y, i = 3, m;
    cout << " p1 pick a number" << endl;
    cin >> x;
    cout << "p2 guess the number" << endl;
    cin >> y;
    if (x != y)
    {
        cout << "sorry wrong guess  " << i - 1 << " chances left" << endl;
        i--;
    }
    else
    {
        cout << "congrats, you've guessed correctly" << endl;
         m = 1;
    }
    if (m != 1 && i > 0)
    {
        cout << "p2 guess the number again" << endl;
        cin >> y;

        if (x != y)
        {
            cout << "sorry wrong guess  " << i - 1 << " chances left" << endl;
            i--;
        }
        else
        {
            cout << "congrats, you've guessed correctly" << endl;
            m = 1;
        }
    }
    
    if (m != 1 && i > 0)
    {
        cout << "p2 guess the number again" << endl;
        cin >> y;

        if (x != y)
            cout << "player 1 wins" << endl;
        else
        {
            cout << "congrats, you've guessed correctly" << endl;
             m = 1;
        }
    }

    return 0;
}