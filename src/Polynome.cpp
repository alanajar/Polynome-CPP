#include "Polynome.hpp"

Polynome::~Polynome() {
    delete[] this->coeffs;
}

Polynome::Polynome(unsigned int _degree, double* _coefs) : degree(_degree), coef(nullptr)
{
    coef = new double[degree+1];
    for (size_t i=0; i<= degree; i++){
        coef[i]=_coefs[i];
    }
}