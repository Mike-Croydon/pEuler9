// This program solves Project Euler problem 9: Special Pythagorean Triplet
// There is one Pythagorean Triplet (a^2 + b^2 = c^2) whose sum equals 1000 (a+b+c=1000)
//Find (a*b*c)

#include "pch.h"
#include <iostream>

using namespace std;

class triplet {
private:
	int side[2];
	int hypotenuse;
public:
	int * getABC()
	{
		int temp[3];
		temp[0] = side[0];
		temp[1] = side[1];
		temp[2] = hypotenuse;
		return temp;
	}

	bool isPythTriple()
	{
		if (((side[0] ^ 2) + (side[1] ^ 2)) == hypotenuse ^ 2)
		{
			return true;
		}
		else { return false; }
	}

};
int main()
{
    std::cout << "Hello World!\n"; 
}

