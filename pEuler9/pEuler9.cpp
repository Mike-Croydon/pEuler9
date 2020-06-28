// This program solves Project Euler problem 9: Special Pythagorean Triplet
// There is one Pythagorean Triplet (a^2 + b^2 = c^2) whose sum equals 1000 (a+b+c=1000)
//Find (a*b*c)

#include "pch.h"
#include <iostream>

using namespace std;

//This class 
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
int main()
{
	//Brute force solution. Takes advantage of fact that a < b < c and that a and b have to be relatively small for the sum == 1000
	long int  c = 0;
	long int product = 0;
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
	cout << "The solution is: " << product;
}

