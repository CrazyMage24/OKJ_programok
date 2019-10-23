#include <iostream>
#include <sstream>
#include "osztaly.h"

using namespace std;

targy::targy(string nev, int mennyiseg)
{
    this->nev=nev;
    this->mennyiseg=mennyiseg;
}
void targy::setNev(string nev)
{
    this->nev=nev;
}
void targy::setMennyiseg(int mennyiseg)
{
    this->mennyiseg=mennyiseg;
}
string targy::getNev()
{
    return nev;
}
int targy::getMennyiseg()
{
    return mennyiseg;
}

/* --- */

kincs::kincs(string nev, int mennyiseg, int ertek) : targy(nev,mennyiseg)
{
    this->ertek=ertek;
}
void kincs::setErtek(int ertek)
{
    this->ertek=ertek;
}
int kincs::getErtek()
{
    return ertek;
}
string kincs::mindenAdat()
{
    stringstream ki;
    ki << "Nev: " << nev << " Mennyiseg: " << mennyiseg << " Ertek: " << ertek << "\n";
    return ki.str();
}

/* --- */

lom::lom(string nev, int mennyiseg, bool joE): targy(nev,mennyiseg)
{
    this->joE=joE;
}
void lom::setJoE(bool joE)
{
    this->joE=joE;
}
bool lom::getJoE()
{
    return joE;
}
string lom::mindenAdat()
{
    stringstream ki;
    ki << "Nev: " << nev << " Mennyiseg: " << mennyiseg << " Jo-e: " << joE << "\n";
    return ki.str();
}

/* --- */

garazs::garazs()
{
    this->bevetel=0;
}
void garazs::targyBerak(targy& t)
{
    int i = 0;
    while(i<targyak.size() && targyak[i]->getNev()!=t.getNev())
    {
        i++;
    }
    if(i<targyak.size())
    {
        int db=targyak[i]->getMennyiseg();
        db+=t.getMennyiseg();
        targyak[i]->setMennyiseg(db);
    }
    else
    {
        targyak.push_back(&t);
    }
}
void garazs::targyKidob(string nev)
{
    int i = 0;
    while(i<targyak.size() && targyak[i]->getNev()!=nev)
    {
        i++;
    }
    if(i<targyak.size())
    {
        targyak.erase(targyak.begin() + i);
    }
    else
    {
        cout << "Targy nem talalhato" << endl;
    }

}
string garazs::mindenKincs()
{
    string ki;
    for(int i = 0; i < targyak.size(); i++)
    {
        kincs* Ezkincs = dynamic_cast<kincs*>(targyak[i]);
        if(Ezkincs!=NULL)
        {
            ki=ki+targyak[i]->mindenAdat() + "\n";
        }
    }
    return ki;
}
string garazs::mindenLom()
{
    string ki;
    for(int i = 0; i < targyak.size(); i++)
    {
        lom* Ezlom = dynamic_cast<lom*>(targyak[i]);
        if(Ezlom!=NULL)
        {
            ki=ki+targyak[i]->mindenAdat() + "\n";
        }
    }
    return ki;
}
string garazs::kerekparVasarlas()
{

    int i = 0;
    while(i<targyak.size() && targyak[i]->getNev()!="kerekpar")
    {
        i++;
    }
    if(i<targyak.size())
    {
        return targyak[i]->mindenAdat();
    }
    else
    {
        return "Nincs kerekpar";
    }
}
int garazs::kincsOsszErtek()
{
    int szum = 0;
    for(int i = 0; i <targyak.size();i++)
    {
        kincs* Ezkincs = dynamic_cast<kincs*>(targyak[i]);
        if(Ezkincs!=NULL)
        {
            szum+=Ezkincs->getErtek()*Ezkincs->getMennyiseg();
        }
    }
    return szum;
}
double garazs::lomArany()
{
    int lomdb = 0;
    int jolom = 0;
    for(int i = 0; i < targyak.size(); i++)
    {
        lom* Ezlom = dynamic_cast<lom*>(targyak[i]);
        if(Ezlom!=NULL)
        {
            lomdb+=Ezlom->getMennyiseg();
            if(Ezlom->getJoE())
            {
                jolom+=Ezlom->getMennyiseg();
            }
        }
    }
    return jolom*100.00/lomdb;
}
string garazs::legertekesebbKincs()
{
    int maxi = 0;
    int maxe = 0;
    for(int i = 1; i<targyak.size(); i++)
    {
        kincs* Ezkincs = dynamic_cast<kincs*>(targyak[i]);
        if(Ezkincs!=NULL)
        {
            if(Ezkincs->getErtek()>maxe)
            {
                maxi = i;
                maxe = Ezkincs->getErtek();
            }
        }
    }
    kincs* maxkincs = dynamic_cast<kincs*>(targyak[maxi]);
    if  (maxkincs!=NULL)
    {
        return targyak[maxi]->mindenAdat();
    }
    else
    {
        return "Kincs, ami nincs";
    }
}
void garazs::lomtalanitas()
{
    for (int i=0;i<targyak.size();i++)
    {
        lom* ezLom=dynamic_cast<lom*>(targyak[i]);
        if (ezLom!=NULL)
        {
            if (!ezLom->getJoE())
            {
                targyKidob(ezLom->getNev());
            }
        }
    }
}
int garazs::eladas(string termek, int mennyiseg)
{
    int i = 0;
    while(i<targyak.size() && targyak[i]->getNev()!=termek)
    {
        i++;
    }
    if(targyak[i]->getMennyiseg()>=mennyiseg)
    {
        kincs* eladando = dynamic_cast<kincs*>(targyak[i]);
        if(eladando!=NULL)
        {
            int maradek=targyak[i]->getMennyiseg()-mennyiseg;
            targyak[i]->setMennyiseg(maradek);
        }
        return mennyiseg*eladando->getErtek();
    }
    else
    {
        return 0;
    }
}
void garazs::setBevetel(int bevetel)
{
    this->bevetel+=bevetel;
}
int garazs::getBevetel()
{
    return bevetel;
}
