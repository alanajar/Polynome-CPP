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