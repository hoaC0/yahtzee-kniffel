#ifndef PUNKTEKARTE_H
#define PUNKTEKARTE_H

#include <array>

class Punktekarte {
private:
    std::array<int, 13> punkte;
    std::array<bool, 13> verwendet;
    int bonus;

public:
    Punktekarte();
    void eintragen(int kategorie, int punkte);
    bool istVerwendet(int kategorie) const;
    int getPunkte(int kategorie) const;
    int getBonus() const;
    int getZwischenSummeOben() const;
    int getEndSummeOben() const;
    int getGesamtPunkte() const;
    bool istVoll() const;
    void anzeigen() const;
};

#endif