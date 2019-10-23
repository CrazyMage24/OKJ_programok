#include <string>
#include <vector>

using namespace std;

class targy
{
protected:
    string nev;
    int mennyiseg;
public:
    targy(string nev, int mennyiseg);
    void setNev(string nev);
    void setMennyiseg(int mennyiseg);
    string getNev();
    int getMennyiseg();
    virtual string mindenAdat() {}; // virtuálissá teszi az osztályt, ne példányosítsd!
};

class kincs : public targy
{
private:
    int ertek;
public:
    kincs(string nev, int mennyiseg, int ertek);
    void setErtek(int ertek);
    int getErtek();
    string mindenAdat();

};

class lom : public targy
{
protected:
    bool joE;
public:
    lom(string nev, int mennyiseg, bool joE);
    void setJoE(bool joE);
    bool getJoE();
    string mindenAdat();

};

class garazs
{
private:
    vector<targy*> targyak;
    int bevetel;
public:
    garazs();
    void targyBerak(targy& t);
    void targyKidob(string nev);
    string mindenKincs();
    string mindenLom();
    string kerekparVasarlas();
    int kincsOsszErtek();
    double lomArany();
    string legertekesebbKincs();
    void lomtalanitas();
    int eladas(string termek, int mennyiseg);
    void setBevetel(int bevetel);
    int getBevetel();
};
