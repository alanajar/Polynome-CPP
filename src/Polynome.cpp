#include "Polynome.hpp"

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