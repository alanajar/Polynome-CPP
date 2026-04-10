#ifndef POLYNOME_HPP
#define POLYNOME_HPP

#include <iostream>

class Polynome {
    private:
        size_t degree;
        double* coeffs;

    public:
        Polynome(const size_t& _degree, const double _arr[]);
        Polynome(const Polynome& polynome);
        Polynome() = delete;

        ~Polynome();

        double operator()(const double&) const;

        friend bool operator==(const Polynome&, const Polynome&);

        friend std::ostream& operator<<(std::ostream&, const Polynome&);
        Polynome operator+(const Polynome&) const;
        Polynome operator-(const Polynome&) const;
        Polynome operator*(const double&) const;
        Polynome operator*(const Polynome&) const;

        Polynome& operator=(const Polynome&);

        double operator[](size_t) const;
        double& operator[](size_t);

        inline size_t getDegree() const {
            return this->degree;
        };

        double* getCoeffs() const;

        Polynome deriver() const;
};

#endif