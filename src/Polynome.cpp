#include "Polynome.hpp"

Polynome::~Polynome() {
    delete[] this->coeffs;
}