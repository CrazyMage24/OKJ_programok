#include <iostream>
#include <dirent.h>
#include <windows.h>
#include "osztaly.h"

using namespace std;

void fajlLista()
{
    // mappa név elkérése HA VAN ÉKEZET A MAPPA NEVÉBEN AZ GÁZ!
    cout << "Mappa neve: " << endl;
    string dirname;
    cin.get();
    getline(cin,dirname);

    // Stringből char[] csinálása
    char mappa[dirname.length() + 1];
    strcpy(mappa, dirname.c_str());

    // kiíratás
    DIR *dir;
    struct dirent *ent;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if ((dir = opendir (mappa)) != NULL)
    {
      cout << "Fajlok listaja:" << endl;

      // színezés
      SetConsoleTextAttribute(hConsole, 10);

      /* Mappán belül minden fájl kiírása */
      while ((ent = readdir (dir)) != NULL)
        {
        printf ("%s\n", ent->d_name);
        }
      closedir (dir);
    }
    else
    {
      /* Mappa nem nyitható meg hibaüzenet */
      SetConsoleTextAttribute(hConsole, 12);
      perror ("");
    }

    // szín vissza alapra
    SetConsoleTextAttribute(hConsole, 7);
}

void fajlLetrehoz()
{
    string fajlnev;
    int sz;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Letrehozok egy fajlt" << endl;
    cout << "Fajl neve: " << endl;
    cin.get();
    getline(cin,fajlnev);
    fajl f(fajlnev);
    f.open("ios::out");

    cout << "Irsz bele szoveget?[1/0]" << endl;
    cin >> sz;

    if(sz==1)
    {
        string szoveg;
        cout << "Szoveg bele: " << endl;
        cin.get();
        getline(cin,szoveg);
        f.write(szoveg);
    }
    SetConsoleTextAttribute(hConsole, 10);
    cout << "Fajl kesz" << endl;
    SetConsoleTextAttribute(hConsole, 7);
    f.close();
}

void fajlModosit()
{
    string fajlnev;
    cout << "Fajl neve: " << endl;
    cin.get();
    getline(cin,fajlnev);
    fajl f(fajlnev);

}

void fajlTorol()
{

}

int main()
{
    // magyar billentyűzet beállítása
    setlocale(LC_ALL, "hu_HU.ISO88592");

    int response;
    do
    {
        // menü parancssor
        cout << "Fajl kezelo: " <<endl;
        cout << endl;
        cout << "1 -- Fajl letrehozasa" << endl;
        cout << "2 -- Fajl modositasa" << endl;
        cout << "3 -- Fajl torlese" << endl;
        cout << "4 -- Fajlok listaja" << endl;
        cout << "0 -- Kilepes" << endl;
        cin >> response;
        // válasz feldolgozása
        switch(response)
        {
        case 1:
            {
                // ha 1-et írt be, akkor létrehozol egy fájlt, nevet adsz neki, szöveget illeszthetsz bele
                fajlLetrehoz();
            }
            break;
        case 2:
            {
                // ha 2-őt írt be, akkor megkeres egy fájlt, és átírhatja az egész szövegét, vagy folytathatja a végéről
                fajlModosit();
            }
            break;
        case 3:
            {
                // ha 3-at írt be, akkor megkeres egy fájlt és törli a tartalmát vagy az egész fájlt
                fajlTorol();
            }
            break;
        case 4:
            {
                // ha 4-et írt be, akkor bekér egy mappanevet és kiírja a benne lévő fájlok neveit és kiterjesztéseit
                fajlLista();
            }
            break;
        default:
            {
                // ha 0-t vagy valami hülyeséget írt be, akkor kilép a program
                response=0;
            }
            break;
        }
    }
    while(response!=0);
    cout << "Quit" <<endl;
    cout << endl;
    return 0;
}
