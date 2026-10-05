#include <iostream>
#include "LinieAeriana.h"
#include "Aeroport.h"
#include "Client .h"
using namespace std;

int main() {
    PanouAeroport aer;
    int optiune = -1;
    do {
        cout << "1.Afisare zboruri \n";
        cout << "2.Adaugare zboruri \n";
        cout << "3.Adaugare clienti \n";
        cout << "4.Cautare zbor \n";
        cout << "5.Iesire \n";
        cin >> optiune;
        if (optiune == 1) {
            aer.aratazborurile();
        }
        else if ( optiune == 2) {
            aer.adaugazbor();
        }
        else if ( optiune == 3) {
            aer.adaugaclienti();
        }
        else if ( optiune == 4) {
              aer.cautarezbor();
        }
    }
    while (optiune!=5);
}
