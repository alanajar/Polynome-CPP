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