#ifndef WUERFEL_H
#define WUERFEL_H

class Wuerfel {
private:
    int wert;
    bool behalten;

public:
    Wuerfel();
    void werfen();
    int getWert() const;
    void setBehalten(bool behalten);
    bool istBehalten() const;
    void reset();
};

#endif