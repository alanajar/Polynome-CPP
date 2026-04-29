#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestsUnitaires
#include <boost/test/unit_test.hpp>
#include "../src/Polynome.hpp"

BOOST_AUTO_TEST_CASE(Construction)
{
    static const double coef_p1[] = {3, -1.414, 3, 6, 0, 1};
    static size_t degree = 5;
    static Polynome p1(degree, coef_p1);

    BOOST_REQUIRE(p1.getDegree() == degree);
    BOOST_WARN_MESSAGE([]() -> bool {
        for (size_t currDeg = 0; currDeg < degree; currDeg++) {
            if (p1[currDeg] != coef_p1[currDeg]) return false;
        }

        return true;
    }, "La construction d'un polynome via coéfficients ne donne pas le résultat attendu !");

    static Polynome p2(p1);
    BOOST_REQUIRE(p2.getDegree() == p1.getDegree());
    BOOST_WARN_MESSAGE([]() -> bool {
        for (size_t currDeg = 0; currDeg < degree; currDeg++) {
            if (p2[currDeg] != p1[currDeg]) return false;
        }

        return true;
    }, "La construction d'un polynome par copie ne donne pas le résultat attendu !");
}

BOOST_AUTO_TEST_CASE(AffectationEtComparaison)
{
    static const double coef_p1[] = {3, -1.414, 3, 6, 0, 1};
    static size_t degree = 5;
    static Polynome p1(degree, coef_p1);
    static Polynome p2(p1);

    BOOST_REQUIRE_MESSAGE(p1[0] == coef_p1[0], "L'opérateur d'indéxation ne donne pas le résultat attendu !");
    BOOST_CHECK_EQUAL(p1 == p1, p2 == p1);

    static const double coef_p3[] = {15, -1.414, 3, 6, 0, 1};
    static Polynome p3(degree, coef_p3);
    static const double coef_p4[] = {3, -1.414, 3, 6, 0, 4};
    static Polynome p4(degree, coef_p4);
    BOOST_CHECK_EQUAL((p1 == p3) == false, (p1 == p4) == false);

    BOOST_REQUIRE_MESSAGE([]() -> bool {
        for (size_t curr = 0; curr < degree + 1; curr++) {
            static double testValue = 8.457;
            double oldValue = p1[curr];

            p1[curr] = testValue;
            if (p1[curr] != testValue)
                return false;

            p1[curr] = oldValue;
            if (p1[curr] != oldValue)
                return false;
        }

        return true;
    }, "L'affectation d'un coéfficient du Polynome ne donne pas le résultat attendu !");
}

BOOST_AUTO_TEST_CASE(Operateurs)
{
    static const double coef_p1[] = {3, -1.414, 3, 6, 0, 1};
    static size_t degree = 5;
    static Polynome p1(degree, coef_p1);

    BOOST_CHECK_MESSAGE(p1(0) == coef_p1[0], "L'opérateur d'appel de fonction ne donne pas le résultat attendu pour x=0 !");
    BOOST_CHECK_MESSAGE([]() -> bool {
        double sum = 0.0;
        for (size_t curr = 0; curr < degree + 1; curr++)
            sum += p1[curr];

        return p1(1) == sum;
    }, "L'opérateur d'appel de fonction ne donne pas le résultat attendu pour x=1 !");

    static const double coef_p2[] = {4, -2, 3, 1, -2, -1};
    static Polynome p2(degree, coef_p2);
    static Polynome temp(0, new double[1]{0});

    BOOST_CHECK_NO_THROW(temp = (p1 + p2));
    BOOST_CHECK_MESSAGE([]() -> bool {
        for (size_t currDeg = 0; currDeg < degree; currDeg++) {
            double supposedResult = p1[currDeg] + p2[currDeg];
            if (temp[currDeg] != supposedResult) return false;
        }

        return true;
    }, "L'addition de deux polynomes ne donne pas le résultat attendu !");
}

BOOST_AUTO_TEST_CASE(integration)
{
    double c[] = {2.0, 6.0, 12.0};
    double ci[] = {0.0, 2.0, 3.0, 4.0};

    Polynome p(2, c);
    Polynome attendu(3, ci);

    Polynome primitive = p.integrer();
    BOOST_CHECK_MESSAGE(primitive == attendu, "l'integrale marche bien");
}