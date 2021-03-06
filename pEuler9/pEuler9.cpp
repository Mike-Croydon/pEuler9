// This program solves Project Euler problem 9: Special Pythagorean Triplet
// There is one Pythagorean Triplet (a^2 + b^2 = c^2) whose sum equals 1000 (a+b+c=1000)
//Find (a*b*c)

#include "pch.h"
#include <iostream>
#include "EulerLib.h"

using namespace std;

/*
//This class is used to store a triple and has some useful functions to perform necessary calculations.
class Triple {
private:
	long int side[2];
	long int hypotenuse;
public:
	Triple(long int a, long int b, long int c)
	{
		side[0] = a;
		side[1] = b;
		hypotenuse = c;
	}
	long int * getABC()
	{
		long int temp[3];
		temp[0] = side[0];
		temp[1] = side[1];
		temp[2] = hypotenuse;
		return temp;
	}

	bool isPythTriple()
	{
		if (((side[0] * side[0]) + (side[1] * side[1])) == (hypotenuse * hypotenuse))
		{
			return true;
		}
		else { return false; }
	}

	int getSum()
	{
		long int sum = side[0] + side[1] + hypotenuse;
		return sum;
	}

	long int getProduct()
	{
		long int product = side[0] * side[1] * hypotenuse;
		return product;
	}

};
*/

int main()
{
	long int product = 0;
	long int a, b, c;
	
	//This loops takes advantage of  a way to construct triples where a=m^2-n^2, b=2mn, and c = m^2+n^2, where m > n;
	for (int m = 2; m < 100; m++)
	{
		for (int n = 1; n < m; n++)
		{
			a = (m*m) - (n*n);
			b = (2 * m*n);
			c = (m*m) + (n*n);
			EulerLib::PythTriple triple = EulerLib::PythTriple(a, b, c);
			if ((triple.isPythTriple()) && (triple.getSum() == 1000))
			{
				product = triple.getProduct();
				break;	//break once we find the correct triple so we don't keep iterating
			}
		}
	}

	/*Brute force solution. Takes advantage of fact that a < b < c and that a and b have to be relatively small for the sum == 1000
	long int  c = 0;
	
	for (int a = 1; a < 333; a++)
	{
		for (int b = a; b < 500; b++)
		{
			for (int c = b; c < 1000; c++)
			{
				Triple triple(a, b, c);
				if ((triple.isPythTriple()) && (triple.getSum() == 1000)) 
				{
					product = triple.getProduct();
				}
			}

		}
	}
	*/
	cout << "The solution is: " << product;
}

