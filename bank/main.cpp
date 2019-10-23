#include <iostream>
#include "osztaly.h"

using namespace std;

int main()
{
    int valasz;
    int osszeg;
    bankautomata a;
    do
    {
        cout << "1 -- Penz felvetel" <<endl;
        cout << "2 -- Penz osszege" <<endl;
        cout << "3 -- Osszes penz" <<endl;
        cout << "4 -- Karbantartas" <<endl;
        cout << "5 -- Befizetes" <<endl;
        cout << "6 -- Kilepes" <<endl;
        cin >> valasz;
        if(valasz==1)
        {
            cout << "Osszeg: ";
            cin >> osszeg;
            cout << a.penzKiVetel(osszeg) << endl;
        }
        if(valasz==2)
        {
            cout << a.getPenz() << endl;
        }
        if(valasz==3)
        {
            cout << a.osszesPenz() << endl;
        }
        if(valasz==4)
        {
            cout << a.karbantartas() << endl;
        }
        if(valasz==5)
        {
            int kivantosszeg;
            int befizetettosszeg;
            cout << "Befizetni kivant osszeg: ";
            cin >> kivantosszeg;
            cout << endl;
            cout << "Befizetett osszeg: ";
            cin >> befizetettosszeg;
            cout << endl;
            cout << a.penzBefizetes(kivantosszeg, befizetettosszeg) << endl;
        }
    }
    while(valasz!=6);
    cout << endl;
    return 0;
}
