/*
 * Polynomial.h
 * @author <a href="mailto: m.hassanpour@mrl-spl.ir">Mostafa Hassanpour</a>
 *
 */
#include <vector>

class Polynomial {

private:


public:

    std::vector<float> a;  // f(x) = a*x^3 + b * x^2 + c * x + d

    Polynomial(){}
	Polynomial(double pointInit, double pointFinal, double slopeInit, double slopeFinal, double time)
	{

        a.resize(4);
		a.at(0) = pointInit;
        a.at(1) = slopeInit;
		a.at(2) = -(3 * pointInit - 3 * pointFinal + 2 * time * slopeInit + time * slopeFinal ) / ( time * time );
		a.at(3) = ( 2 * pointInit - 2 * pointFinal + time * slopeInit + time * slopeFinal ) / ( time * time * time);


	}

	float operator()(float t)
	{
		return a.at(0) + a.at(1) * t + a.at(2) * t * t + a.at(3) * t * t * t;

	}
};

