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

    /**
     * @brief Lecture des coefficients du Polynome
     *
     * @return Pointeur sur le premier coefficient du Polynome
     */
    double *getCoeffs() const;

    /**
     * @brief Dérive le polynome
     *
     * @return Une nouvelle instance de Polynome équivalante à la dérivée du Polynome courant
     */
    Polynome deriver() const;
};

#endif