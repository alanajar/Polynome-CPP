/*!
 * \file Polynome.hpp
 * \brief L'ensemble des éléments utiles à la classe
 * \author NAJAR A. & SAID C.
 * \date 04/2026
*/


#ifndef POLYNOME_HPP
    #define POLYNOME_HPP

    /* ---------------------------- */
    /* - BIBLIOTHÈQUE POUR LE C++ - */
    /* ---------------------------- */
    #include <iostream>

/*!
 * \class Polynome
 * \brief Classe permettant d'avoir une représentation d'un polynome
*/
class Polynome {
    private:
        size_t degree;
        double* coeffs;

    public:

        /******************************************/
        /* - Fonctions CONSTRUCTEUR/DESTRUCTEUR - */
        /******************************************/
        Polynome(const size_t& _degree, const double _arr[]);
        Polynome(const Polynome& polynome);
        Polynome() = delete;
        ~Polynome();


        /************************/
        /* - Fonctions MEMBRE - */
        /************************/
        Polynome deriver() const;
        double operator()(const double&) const;
        Polynome& operator=(const Polynome&);

        double* getCoeffs() const;
        double& operator[](size_t);
        double operator[](size_t) const;

        /*!
        * \brief Retourne le degré du polynome
        * \return Un entier non signé
        */
        inline size_t getDegree() const {
            return this->degree;
        };


        /****************************/
        /* - Fonctions NON-MEMBRE - */
        /****************************/
        friend bool operator==(const Polynome&) const;
        friend Polynome operator+(const Polynome&) const;
        friend Polynome operator-(const Polynome&) const;
        friend Polynome operator*(const double&) const;
        friend Polynome operator*(const Polynome&) const;
        friend std::ostream& operator<<(std::ostream&, const Polynome&);
};

#endif /* POLYNOME_HPP */
