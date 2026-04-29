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
        
        /**
        * @brief Accès en lecture seule au coefficient de degré i
        *
        * Permet de lire le coefficient 
        *
        * @param i L'indice du coefficient
        * @return Une référence constante vers le coefficient de degré i
        */
        const double& operator[](size_t i) const;

        /**
        * @brief Accès en écriture au coefficient de degré i
        *
        * Permet de modifier le coefficient 
        *
        * @param i L'indice du coefficient
        * @return Une référence modifiable vers le coefficient de degré i
        */
        double& operator[](size_t);

        /**
        * @brief lecture du degré du polynome.
        * @return Le degré du polynome.
        */
        inline size_t getDegree() const {
            return this->degree;
        };

        double* getCoeffs() const;

        Polynome deriver() const;
};

#endif