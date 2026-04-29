#include "Polynome.hpp"

Polynome::~Polynome() {
    delete[] this->coeffs;
}

Polynome::Polynome(const Polynome& polynome) : Polynome(polynome.degree, polynome.coeffs) {}

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

const double& Polynome::operator[](size_t i) const
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

Polynome &Polynome::operator=(const Polynome &p2)
{
    delete[] this->coeffs;

    this->degree = p2.degree;
    this->coeffs = new double[this->degree + 1];

    for (size_t i = 0; i <= degree; i++)
        this->coeffs[i] = p2.coeffs[i];
    return *this;
}

double Polynome::operator()(const double& x) const  
{
    double res = 0.0;
    double x_puissance = 1.0;
    for (size_t i=0; i<=degree; i++) {
        res += coeffs[i] * x_puissance;
        x_puissance *= x;
    }
    return res;
}

Polynome Polynome::deriver() const
{
    if (degree == 0)
    {
        double *c = new double[1]{0};
        Polynome p(0, c);
        
        delete[] c;
        return p;
    }

    size_t newDegree = this->degree - 1;
    double *_coeffs = new double[newDegree + 1];

    for (size_t i = this->degree; i > 0; i--)
        _coeffs[i - 1] = i * this->coeffs[i];

    Polynome newPolynome(newDegree, _coeffs);

    delete[] _coeffs;

    return newPolynome;
}

Polynome Polynome::operator+(const Polynome &p2) const
{
    size_t maxDegree = this->degree > p2.degree ? this->degree : p2.degree;
    double *_coeffs = new double[maxDegree + 1];

    for (size_t i = 0; i <= maxDegree; i++)
        _coeffs[i] = ((this->degree >= i ? this->coeffs[i] : 0.0) + (p2.degree >= i ? p2.coeffs[i] : 0.0));

    Polynome newPolynome(maxDegree, _coeffs);

    delete[] _coeffs;

    return newPolynome;
};

Polynome Polynome::integrer() const {
    double* tmp = new double[degree+2];
    tmp[0] = 0.0;
    for(size_t i=0; i<=degree; i++) {
        tmp[i+1] = coeffs[i]/(i+1);
    }
    Polynome p_tmp(degree+1, tmp);
    delete[] tmp;
    return p_tmp;
}