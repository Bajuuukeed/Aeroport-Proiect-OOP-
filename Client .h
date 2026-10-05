#ifndef OOP_AEROPORT_CLIENT_H
#define OOP_AEROPORT_CLIENT_H
#include <cstring>
using namespace std;
class Clienti {
private:
    string nume;
    string prenume;
    string CNP;
    string taraorigine;
    string datanastere;
public:
    Clienti() : nume(""), prenume(""), CNP(""), taraorigine(""),datanastere(""){};
    Clienti(string nume1, string prenume1 , string CNP1 , string taraorigine1,  string datanastere1): nume(nume1),prenume(prenume1),CNP(CNP1),taraorigine(taraorigine1),datanastere(datanastere1){};
    string getnume() const;
    string getprenume() const;
    string getCNP() const;
    virtual int getPrioritate()const;
    string getdatanastere() const;
    string gettaraorig() const;
};
class ClientiDiplomat:public Clienti {
private:
      string taraundemergeti;
public:
    ClientiDiplomat() : Clienti("",  "" ,  "" ,  "",  ""),taraundemergeti(""){};
    ClientiDiplomat(string nume1, string prenume1 , string CNP1 , string taraorigine1,  string datanastere1, string taraundemergeti1):Clienti(nume1,  prenume1 ,  CNP1 ,  taraorigine1,  datanastere1),taraundemergeti(taraundemergeti1){};
    virtual int getPrioritate()const override;
    string gettara()const;
};
string ClientiDiplomat::gettara() const {
    return taraundemergeti;
}
int Clienti::getPrioritate() const {
    return 2;
}
int ClientiDiplomat::getPrioritate() const {
    return 1;
}
string Clienti::gettaraorig()const {
    return taraorigine;
}
string Clienti::getnume() const {
    return nume;
}
string Clienti::getprenume() const {
    return prenume;
}

string Clienti::getCNP() const {
    return CNP;
}
string Clienti::getdatanastere() const {
    return datanastere;
}

#endif //OOP_AEROPORT_CLIENT_H