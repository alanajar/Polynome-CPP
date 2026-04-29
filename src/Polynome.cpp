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

Polynome::Polynome(const size_t& _degree, const double _arr[]) : degree(_degree), coeffs(new double[_degree + 1])
{
    for (size_t i = 0; i <= degree; i++)
        this->coeffs[i] = _arr[i];
}

double &Polynome::operator[](size_t i)
{
    if (i > degree + 1) throw std::out_of_range("Index out of range");

    return coeffs[i];
}

double Polynome::operator[](size_t i) const
{
    if (i > degree + 1) throw std::out_of_range("Index out of range");

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


bool operator==(const Polynome& p1, const Polynome& p2){
    if (p1.degree != p2.degree){
        return false;
    }
    for (size_t i=0; i<=p1.degree; i++){
        if (p1.coeffs[i] != p2.coeffs[i]){
            return false;
        }
    }
    return true;
}