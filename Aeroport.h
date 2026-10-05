#ifndef OOP_AEROPORT_AEROPORT_H
#define OOP_AEROPORT_AEROPORT_H
#include "Client .h"
#include "LinieAeriana.h"
class PanouAeroport{
private:
   vector<Cursa>displaycurse;
public:
   PanouAeroport(){};
   void aratazborurile();
    void adaugaclienti();
    void adaugazbor();
    void cautarezbor();
};
void PanouAeroport::cautarezbor() {
    cout << "\nSpuneti-ne numarul zborului\n";
    int nr;
    cin >> nr;
    for (auto x : displaycurse) {
        if ( x.getplane_nr() == nr){
            cout << "\nZborul cu numarul: " << x.getplane_nr() << "\nCompania aeriana : " << x.getcompanyname() << "\nCe pleaca din: "  << x.getdeparture() << "\nCu destinatia: " << x.getarrival() << "\nOra de plecare: " << x.hourofdepartf() << "\nOra de sosire: " << x.hourofarrivalf() << '\n';
            cout << "\n----Veti fi insotiti de urmatorul staff----";
            x.showcabincrew();
            cout << '\nClientii zborului acestuia sunt:\n';
            x.showclient();
            break;
        }
    }
}
void PanouAeroport::aratazborurile() {
    for (auto x: displaycurse) {
        cout << "\nZborul cu numarul: " << x.getplane_nr() << "\nCompania aeriana : " << x.getcompanyname() << "\nCe pleaca din: "  << x.getdeparture() << "\nCu destinatia: " << x.getarrival() << "\nOra de plecare: " << x.hourofdepartf() << "\nOra de sosire: " << x.hourofarrivalf() << '\n';
        cout << '\n';
    }
}
void PanouAeroport::adaugaclienti() {
     cout << "Introduceti prenumele clientului: \n";
    string prenume;
    cin >> prenume;
    cout << "Introduceti numele clientului: \n";
    string nume;
    cin >> nume;
    cout << "Introduceti CNP-ul clientului: \n";
    string CNP;
    cin >> CNP;
    cout << "Introduceti tara de origine a clientului\n";
    string taraorigine;
    cin >> taraorigine;
    cout << "Introduceti data de nastere a clientului: \n";
    string datanas;
    cin >> datanas;
    cout << "Sunteti client diplomat?(da/nu)\n";
    string raspuns;
    cin >> raspuns;
    string taradip;
    if ( raspuns == "da") {
        cout << "In ce tara doriti sa mergeti in functia de diplomat\n";
        cin >> taradip;
    }
    else {
        bool arenevviza = true;
        for (auto x: tari.UE) {
            if ( x == taraorigine) {
                arenevviza = false;
            }
        }
        if ( arenevviza == true) {
            cout << "Circulati in afara UE:Pentru a circula din aceasta tara dvs aveti nevoie de viza la plecare.Aveti?(da/nu): ";
            string raspuns;
            cin >> raspuns;
            if ( raspuns == "Da") {
                cout << "Acces perm;is!\n";
            }
            else {
                cout << "Acces restrictionat\n";
                return;
            }
        }
    }
    if ( displaycurse.empty()) {
        cout <<"Nu exista curse valabile \n";
    }
    else {
        cout << "Selectati cursa dorita \n";
        for (auto x = displaycurse.begin(); x != displaycurse.end(); x++) {
            size_t index = x - displaycurse.begin();
            cout << "Zborul cu nr " << index+1 << " pe lista noastra" ;
            cout << "\n";
            cout << "\nZborul cu numarul: " << displaycurse[index].getplane_nr() << "\nCompania aeriana : " << displaycurse[index].getcompanyname() << "\nCe pleaca din: "  << displaycurse[index].getdeparture() << "\nCu destinatia: " << displaycurse[index].getarrival() << "\nOra de plecare: " << displaycurse[index].hourofdepartf() << "\nOra de sosire: " << displaycurse[index].hourofarrivalf() << '\n';
            cout << '\n';
        }
        cout << "Selectati optiunea dumneavoastra: ";
        int optiune;
        cin >> optiune;
        for (auto x = displaycurse.begin(); x != displaycurse.end(); x++) {
            size_t index = x - displaycurse.begin();
            if ( index+1 == optiune) {
                if ( raspuns == "da") {
                    ClientiDiplomat* l = new ClientiDiplomat(nume,prenume,CNP,taraorigine,datanas,taradip);
                    displaycurse[index].addclient(l);
                }
                    else {
                        Clienti* l = new Clienti(nume,prenume,CNP,taraorigine,datanas);
                        displaycurse[index].addclient(l);
                    }
                 cout << "\nAti ales sa folositi zborul cu nr: " << index+1;
                 cout << "\n----Veti fi insotiti de urmatorul staff----\n";
                 displaycurse[index].showcabincrew();
            }
        }
    }
}
void PanouAeroport::adaugazbor() {
    cout << "Introduceti numarul avionului : \n";
    int plane_nr;
    cin >> plane_nr;
    cout << "Introduceti numele companiei : \n";
    string companie;
    cin >> companie;
    cout << "Introduceti limita avionului : \n";
    int maxlimsits ;
    cin >> maxlimsits;
    cout << "Introduceti orasul de plecare a avionului: \n";
    string departure;
    cin >> departure;
    cout << "Introduceti orasul unde se va ajunge avionul: \n";
    string arrival;
    cin >> arrival;
    cout << "Introduceti ora de plecare  a avionului: \n";
    string hourofdepart;
    cin >> hourofdepart;
    cout << "Introduceti ora de ajungere a avionului: \n";
    string hourofarrival;
    cin >> hourofarrival;
    Cursa m(plane_nr,companie,maxlimsits,departure,arrival,hourofdepart,hourofarrival);
    m.addcabincrew();
    displaycurse.push_back(m);
}
#endif