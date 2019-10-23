#include <iostream>

using namespace std;

class bankautomata
{
private:
    int huszezres;
    int tizezres;
    int otezres;
    int ketezres;
    int ezres;
    int maxpenz;
public:
    bankautomata();
    string penzKiVetel(int osszeg);
    string penzBefizetes(int kivantosszeg, int befizetettosszeg);
    string getPenz();
    long int osszesPenz();
    int karbantartas();

    int getHuszezres();
    int getTizezres();
    int getOtezres();
    int getKetezres();
    int getEzres();
};
