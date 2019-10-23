#include "osztaly.h"
#include <iostream>
using namespace std;

fajl::fajl(string nev, char elvalaszto)
{
    this->nev=nev;
    this->elvalaszto=elvalaszto;
}
fajl::fajl(string nev)
{
    this->nev=nev;
    this->elvalaszto=' ';
}
void fajl::open(string kapcsolo)
{
    if(kapcsolo=="ios::in")
    {
        this->f.open(nev.c_str(),ios::in);
    }
    else if(kapcsolo=="ios::out")
    {
        this->f.open(nev.c_str(),ios::out);
    }
    else
    {
        cout << "Hibas kapcsolo!" <<endl;
    }
}
void fajl::close()
{
    this->f.close();
}
void fajl::write(string szoveg)
{
    if(f.is_open())
    {
        f << szoveg;
    }
    else
    {
        cout << "Fajl nincs megnyitva" <<endl;
    }
}
string fajl::getAdat()
{
    stringstream ki;
    ki << nev << " " << elvalaszto << " " << mentes;
    return ki.str();
}
