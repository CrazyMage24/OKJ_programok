#include <iostream>
#include <sstream>
#include "osztaly.h"

using namespace std;

bankautomata::bankautomata()
{
    this->huszezres=5;
    this->tizezres=10;
    this->otezres=20;
    this->ketezres=50;
    this->ezres=100;
    this->maxpenz = osszesPenz();
}
string bankautomata::penzKiVetel(int osszeg)
{
    if(osszeg>osszesPenz())
    {
        return "Tul keves rendelkezesre allo penz!";
    }
    else
    {
        while(osszeg>=20000 && huszezres>0)
        {
            osszeg-=20000;
            huszezres--;
        }
        while(osszeg>=10000 && tizezres>0)
        {
            osszeg-=10000;
            tizezres--;
        }
        while(osszeg>=5000 && otezres>0)
        {
            osszeg-=5000;
            otezres--;
        }
        while(osszeg>=2000 && ketezres>0)
        {
            osszeg-=2000;
            ketezres--;
        }
        while(osszeg>=1000 && ezres>0)
        {
            osszeg-=1000;
            ezres--;
        }
        stringstream v;
        v << "Sikeres tranzakcio, visszajaro: " << osszeg;
        return v.str();
    }
}
string bankautomata::penzBefizetes(int kivantosszeg, int befizetettosszeg)
{
    if(kivantosszeg>befizetettosszeg)
    {
        return "Keves befizetes!";
    }
    else
    {
        while(befizetettosszeg>=20000)
        {
            befizetettosszeg-=20000;
            huszezres++;
        }
        while(befizetettosszeg>=10000)
        {
            befizetettosszeg-=10000;
            tizezres++;
        }
        while(befizetettosszeg>=5000)
        {
            befizetettosszeg-=5000;
            otezres++;
        }
        while(befizetettosszeg>=2000)
        {
            befizetettosszeg-=2000;
            ketezres++;
        }
        while(befizetettosszeg>=1000)
        {
            befizetettosszeg-=1000;
            ezres++;
        }
        stringstream v;
        v << "Sikeres befizetes, visszajaro: " << befizetettosszeg;
        return v.str();
    }
}
string bankautomata::getPenz()
{
    stringstream ki;
    ki << "Huszezres: " << getHuszezres() << "\n" << "Tizezres: " << getTizezres() << "\n" << "Otezres: " << getOtezres() << "\n" << "Ketezres: " << getKetezres() << "\n" << "Ezres: " << getEzres() << endl;
    return ki.str();
}
long int bankautomata::osszesPenz()
{
    return (getHuszezres()*20000)+(getTizezres()*10000)+(getOtezres()*5000)+(getKetezres()*2000)+(getEzres()*1000);
}
int bankautomata::karbantartas()
{
    int voltpenz = osszesPenz();
    this->huszezres=5;
    this->tizezres=10;
    this->otezres=20;
    this->ketezres=50;
    this->ezres=100;
    return maxpenz-voltpenz;
}

int bankautomata::getHuszezres()
{
    return huszezres;
}
int bankautomata::getTizezres()
{
    return tizezres;
}
int bankautomata::getOtezres()
{
    return otezres;
}
int bankautomata::getKetezres()
{
    return ketezres;
}
int bankautomata::getEzres()
{
    return ezres;
}
