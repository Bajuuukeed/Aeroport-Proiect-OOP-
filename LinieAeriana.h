#ifndef OOP_AEROPORT_LINIEAERIANA_H
#define OOP_AEROPORT_LINIEAERIANA_H
#include <bits/stdc++.h>
#include "Client .h"
#include "CabinCrew.h"
using namespace std;
struct tarile {
    string UE[30] = {"Germania", "Franta", "Italia", "Spania", "Polonia", "Olanda", "Belgia", "Grecia", "Portugalia", "Suedia", "Austria", "Bulgaria", "Danemarca", "Finlanda", "Slovacia", "Irlanda", "Croatia", "Lituania", "Slovenia" };
    string Africa[30] = {"Egipt", "Africa de Sud", "Nigeria", "Kenya", "Maroc", "Algeria", "Tunisia", "Senegal", "Ghana", "Etiopia", "Tanzania", "Uganda", "Angola", "Mozambic", "Madagascar", "Camerun", "Coasta de Fildes", "Zimbabwe", "Zambia", "Sudan"};
    string Asia[30] = {"Japonia", "China", "India", "Coreea de Sud", "Thailanda", "Vietnam", "Indonezia", "Filipine", "Malaezia", "Singapore", "Turcia", "Arabia Saudita", "Emiratele Arabe Unite", "Israel", "Iran", "Irak", "Pakistan", "Bangladesh", "Sri Lanka", "Kazahstan" };
    string America[30] = {"Statele Unite", "Canada", "Mexic", "Brazilia", "Argentina", "Columbia", "Peru", "Chile", "Venezuela", "Ecuador", "Bolivia", "Paraguay", "Uruguay", "Cuba", "Costa Rica", "Panama", "Jamaica", "Haiti", "Honduras", "Guatemala"};
}tari;
inline bool sortare(Clienti *a , Clienti *b) {
    return a->getPrioritate() > b->getPrioritate();
}
inline bool sortarecabin(MembruEchipaj* a, MembruEchipaj* b) {
    return a->getPrioritate() > b->getPrioritate();
}
class Cursa {
private:
    int plane_nr;
    string numecompanie;
    int maxlimsits;
    string departure;
    string arrival;
    string hourofdepart;
    string hourofarrival;
    vector<MembruEchipaj*> cabincrew;
    vector<Clienti*>clienti;
public:
    Cursa():plane_nr(),maxlimsits(),departure(""),arrival(""), hourofdepart(""),hourofarrival(""){};
    Cursa(int plane_nr1 ,string numecompanie1, int maxlimsits1 , string departure1 , string arrival1, string hourofdepart1, string hourofarrival1):plane_nr(plane_nr1),numecompanie(numecompanie1),maxlimsits(maxlimsits1),departure(departure1),arrival(arrival1), hourofdepart(hourofdepart1),hourofarrival(hourofarrival1){};
    void addcabincrew();
    void showcabincrew();
    void addclient(Clienti* m);
    void showclient();
    string hourofdepartf();
    string hourofarrivalf();
    string getcompanyname() const;
     int getplane_nr() const;
    int getmaxlimsits() const;
    string getdeparture()const;
    string getarrival()const;
};
void Cursa::addclient(Clienti* m) {
    clienti.push_back(m);
}
void Cursa::showclient() {
    sort(clienti.begin(),clienti.end(),sortare);
    cout << "\nDin componenta acestui avion vor face parte\n";
    for ( auto x : clienti) {
        ClientiDiplomat* p = dynamic_cast<ClientiDiplomat*>(x);
        cout << x->getnume() << ' ' << x->getprenume() <<  ": " << x->gettaraorig();
        if (p!= nullptr) {
            cout << " [Client VIP]";
        }
        else {
            cout << " [Client Standard]";
        }
        cout << '\n';
    }
}
void Cursa::addcabincrew() {
     cout << "\nAdaugati pilotii echipajului\n";
    for (int i = 0 ; i< 2; i++) {
        string nume;
        cout << "Nume: ";
        cin >> nume;
        Pilot* p = new Pilot(nume,"Pilot");
        cabincrew.push_back(p);
        cout << '\n';
    }
    cout << "\nAdaugati steward-ul sef\n";
      string nume;
        cout << "Nume: ";
        cin >> nume;
    StewardSef* s = new StewardSef(nume,"StewardSef");
    cabincrew.push_back(s);
    cout << "\nAdaugati componenta de stewarzi\n";
    for (int i = 0 ; i<3;i++) {
        string nume;
        cout << "Nume: ";
        cin >> nume;
        Steward* p = new Steward(nume,"Pilot");
        cabincrew.push_back(p);
        cout << '\n';
    }
}
 void Cursa::showcabincrew() {
    if ( cabincrew.size() == 0) {
        cout << " Inca nu exista echipaj";
    }
    else {
        sort(cabincrew.begin(),cabincrew.end(),sortarecabin);
        for ( auto x : cabincrew){
            cout << x->getNume() << ' ';
            if ( x->getPrioritate() == 3) {
                cout << " [Pilot]";
            }
            else if ( x->getPrioritate() == 2) {
                cout << " [StewardSef]";
            }
            else {
                cout << " [Steward]";
            }
            cout << '\n';
        }
    }
}
 int Cursa::getplane_nr() const {
    return plane_nr;
}
int Cursa::getmaxlimsits() const {
    return maxlimsits;
}
string Cursa::getcompanyname() const {
     return numecompanie;
 }
 string Cursa::getdeparture() const{
    return departure;
}
string Cursa::hourofdepartf() {
     return hourofdepart;
 }
string Cursa::hourofarrivalf() {
     return hourofarrival;
 }
 string Cursa::getarrival() const{
    return arrival;
}
#endif