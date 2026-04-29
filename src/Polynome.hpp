#ifndef POLYNOME_HPP
#define POLYNOME_HPP

/*!
 * \file Polynome.cpp
 * \brief Fonctions permettant l'utilisation d'un polynome
 * \date 04/2026
 */
#include <iostream>

class Polynome
{
private:
    size_t degree;
    double *coeffs;

public:
    /**
     * @brief Constructeur à deux paramètres.
     *
     * Crée une instance de la classe Polynome
     *
     * @param _degree Le degré du polynome.
     * @param _arr Le tableau de coefficients
     */
    Polynome(const size_t &_degree, const double _arr[]);

    /**
     * @brief Constructeur de copie.
     *
     * Effectue une copie du polynôme source
     *
     * @param polynome Le polynôme à copier.
     */
    Polynome(const Polynome &polynome);
    Polynome() = delete;

    /*!
     * \brief Destructeur de la classe
     */
    ~Polynome();

    /**
     * @brief calculer la valeur du polynome pour une valeur de x donnée
     *
     * @param x La valeur de x le polynome
     * @return La valeur P(x)
     */
    double operator()(const double &) const;

    friend bool operator==(const Polynome &, const Polynome &);

    /**
     * @brief Affichage d'un polynôme 
     *
     * Les coefficients nuls ne sont pas affichés
     * les coefficients égaux à 1 ou -1 sont simplifiés
     *
     * @param os Le flux de sortie
     * @param p Le polynome à afficher
     * @return Une référence vers le flux de sortie
     */
    friend std::ostream &operator<<(std::ostream &, const Polynome &);
    Polynome operator+(const Polynome &) const;
    Polynome operator-(const Polynome &) const;
    Polynome operator*(const double &) const;
    Polynome operator*(const Polynome &) const;

    Polynome &operator=(const Polynome &);

    const double &operator[](size_t i) const;
    double &operator[](size_t);

    /**
     * @brief lecture du degré du polynome.
     * @return Le degré du polynome.
     */
    inline size_t getDegree() const
    {
        return this->degree;
    };

    double *getCoeffs() const;

    Polynome deriver() const;
};

#endif