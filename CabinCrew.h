#ifndef OOP_AEROPORT_CABINCREW_H
#define OOP_AEROPORT_CABINCREW_H
#include <string>
using namespace std;
class MembruEchipaj {
protected:
     string nume;
     string rank;
public:
     MembruEchipaj() : nume(""), rank("") {}
     MembruEchipaj(string nume1, string rank1) : nume(nume1), rank(rank1) {}
     virtual ~MembruEchipaj() {}
     string getNume() const { return nume; }
     virtual int getPrioritate() const = 0;
};
class Pilot : public MembruEchipaj {
public:
     Pilot() : MembruEchipaj() {}
     Pilot(string nume1, string rank1) : MembruEchipaj(nume1, rank1) {}
     string getNume() const { return nume; }
     int getPrioritate() const override {
          return 3;
     }
};
class StewardSef : public MembruEchipaj {
public:
     StewardSef() : MembruEchipaj() {}
     StewardSef(string nume1, string rank1) : MembruEchipaj(nume1, rank1) {}
     string getNume() const { return nume; }
     int getPrioritate() const override {
          return 2;
     }
};

class Steward : public MembruEchipaj {
public:
     Steward() : MembruEchipaj() {}
     string getNume() const { return nume; }
     Steward(string nume1, string rank1) : MembruEchipaj(nume1, rank1) {}
     int getPrioritate() const override {
          return 1;
     }
};
#endif //OOP_AEROPORT_CABINCREW_H