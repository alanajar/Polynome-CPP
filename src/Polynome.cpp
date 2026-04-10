/*!
 * \file Polynome.cpp
 * \brief Fonctions permettant l'utilisation d'un polynome
 * \date 04/2026
*/

#include "Polynome.hpp"

/*!
 * \brief Destructeur de la classe
*/
Polynome::~Polynome() {
    delete[] this->coeffs;
}

Polynome::Polynome(const Polynome& src) : Polynome(src.degree, src.coeffs) {}

double &Polynome::operator[](size_t i)
{
    if (i > degree) throw std::out_of_range("Index out of range");

    return coeffs[i];
}

double Polynome::operator[](size_t i) const
{
    if (i > degree) throw std::out_of_range("Index out of range");

    return coeffs[i];
}
std::ostream& operator<<(std::ostream& os, const Polynome& p)
{
    bool premierecoeff = false;
    for (int i = p.getDegree(); i >= 0; i--) {
        double c = p.coeffs[i];
        if (c == 0.0) 
        continue;
        if (premierecoeff) {
            os << (c > 0 ? "+" : "");
        }
        if (i == 0) {
            os << c;
        } else {
            if (c == 1.0)       {}
            else if (c == -1.0) { os << "-"; }
            else                { os << c; }
            if (i == 1)  os << "x";
            else         os << "x^" << i;
        }
        premierecoeff = true;
    }
    if (!premierecoeff) os << "0";
    return os;
}