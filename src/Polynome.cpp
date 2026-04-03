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

Polynome& Polynome::operator=(const Polynome& p){
    if (this != &p) {
        delete[] coef;
        degree = p.degree;
        coef = new double[degree+1];
        for (size_t i=0; i<=degree; i++){
            coef[i] = p.coef[i];
        }
    }
    return *this;
}

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