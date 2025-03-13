#ifndef WUERFEL_H
#define WUERFEL_H

class Wuerfel {
private:
    int wert;     // aktueller wert des wuerfels (1-6)
    bool behalten; // flag, ob der wuerfel beim naechsten wurf behalten wird

public:
    Wuerfel();     // konstruktor - initialisiert wuerfel
    void werfen(); // wirft den wuerfel neu (wenn nicht behalten)
    int getWert() const;  // gibt aktuellen wurfwert zurueck
    void setBehalten(bool behalten);  // setzt behalten-status
    bool istBehalten() const;         // gibt behalten-status zurueck
    void reset();                     // setzt behalten-status zurueck
};

#endif