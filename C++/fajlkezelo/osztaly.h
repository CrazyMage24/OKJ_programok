#include <string>
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

class fajl
{
private:
    string nev;
    char elvalaszto;
    time_t mentes;
    fstream f;
public:
    fajl(string nev, char elvalaszto);
    fajl(string nev);

    void open(string kapcsolo);
    void close();

    void write(string szoveg);
    string getAdat();
};
