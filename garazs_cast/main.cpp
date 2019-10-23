#include <iostream>
#include "osztaly.h"

using namespace std;

int main()
{
    string valasz;
    int mennyit;
    garazs g;

    kincs k1("toronyora lanccal",1,5000);
    g.targyBerak(k1);

    kincs k2("kerekpar",2,12000);
    g.targyBerak(k2);

    lom l1("szakadt befottesgumi",1000, false);
    g.targyBerak(l1);

    kincs k3("porcelan etkeszlet",5,15000);
    g.targyBerak(k3);

    lom l2("lyukas fuggony",3, false);
    g.targyBerak(l2);

    kincs k4("belyeggyujtemeny",1,25000);
    g.targyBerak(k4);

    kincs k5("hintalo",3,5000);
    g.targyBerak(k5);

    lom l3("rossz funyiro",2, true);
    g.targyBerak(l3);

    lom l4("koteg ujsagpapir", 1, true);
    g.targyBerak(l4);

    cout<<"Kincsek: "<<endl<<g.mindenKincs()<<endl;
    cout<<"Lomok: "<<endl<<g.mindenLom()<<endl;

    cout<<"F1 - kerekpar vasarlas: "<<endl<<g.kerekparVasarlas()<<endl;

    cout<<"F2 - kincsek osszerteke: "<<endl<<g.kincsOsszErtek()<<endl;

    cout<<"F3 - jolomok aranya: "<<endl<<g.lomArany()<<"%"<<endl;

    cout<<"F4 - legertekesebb kincs: "<<endl<<g.legertekesebbKincs()<<endl;

    cout<<"F5 - lomtalanitas: "<<endl;
    g.lomtalanitas();
    cout<<g.mindenLom()<<endl;

    cout<<"F6 - garazsvasar: "<<endl;

    do{
        cout<<"Elado targyak: "<<g.mindenKincs()<<endl;
        cin.get();
        cout<<"Mit szeretne? ";
        getline(cin,valasz);
        if (valasz!="Viszlat")
        {
            cout<<"Mennyit szeretne? ";
            cin>>mennyit;
            int b=g.eladas(valasz,mennyit);
            g.setBevetel(b);
        }


    }while (valasz!="Viszlat");

    cout<<"Osszes bevetel: "<<g.getBevetel();

    cout << endl;
    return 0;
}
