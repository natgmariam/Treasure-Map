/*

Description: <a file that contains the overload code all the 
operators, in order to calculate movment>
Input: File name of the map to read and use
Output: Steps of the map to reach the treasure
*/
#include "ComplexNumber.h"
#include <cmath>

//----------------- Operator overload implementations -----------------
//TODO: Implement ComplexNumber operator overloads

/**/
ComplexNumber operator + (ComplexNumber left, ComplexNumber right)
{
	//Create a resulting ComplexNumber and assign the correct answer to it. You can change 
	//this to be one line if you know how
	ComplexNumber result;
	
	result.real=left.real + right.real; 
	result.imaginary=left.imaginary + right.imaginary; 
	return result;
}

/**/
ComplexNumber operator * (ComplexNumber left, ComplexNumber right)
{
	ComplexNumber result;
			//	a           c            b               d 
	result.real=(left.real * right.real - left.imaginary* right.imaginary);
	result.imaginary=(left.real * right.imaginary + left.imaginary * right.real);
	return result;
}

/**/
ComplexNumber operator * (double scalar, ComplexNumber right)
{
	//right.real=scalar*right.real;
	//right.imaginary=scalar*right.imaginary;
	//right= scalar*right.real + scalar*right.imaginary;
	return ComplexNumber(scalar*right.real , scalar*right.imaginary);

}

/**/
ostream& operator << (ostream& out, const ComplexNumber& cn)
{
	//Use the ComplexNumber toString function to convert to a string an print
	//then returns the stream
 
	out<< cn.toString(); 
	//out<< cn.imaginary;   
	return out;
}

istream& operator >> (istream& in, ComplexNumber& cn)
{
	//Reads the real number then the imaginary part from the stream into the ComplexNumber
	in >> cn.real; 
	in >> cn.imaginary;  
	return in;
}

//----------------- Helper function implementations -----------------

//Returns the magnitude of this ComplexNumber, treating it like a vector
double ComplexNumber::magnitude()
{
	return sqrt(real * real + imaginary * imaginary);
}

//Normalizes the contents of the vector so that the magnitude is 1
void ComplexNumber::normalize()
{
	double m = this->magnitude(); //Get the magnitude of this vector
	this->imaginary /= m;
	this->real /= m;
}

//Returns the complex number in a string of the form:
//<real, imaginary>
string ComplexNumber::toString() const
{
	return "<" + to_string(real) + ", " + to_string(imaginary) + ">";
}

//Gets the angle in degrees of the rotation (just for printing)
double ComplexNumber::getDegrees() const
{
	//Check for asymptotes before doing arctan
	if (real == 0.0)
		return imaginary < 0.0 ? 270 : 90;

	double refAngle = atan(imaginary / real) * 180.0 / PI;

	//Figure out the quadrant
	if (imaginary < 0.0) //Negative vertical component
	{
		if (real < 0.0) //Quadrant III
			return 180 + refAngle;
		 //Quadrant IV
			return 360 + refAngle;
	}
	 //Non-negative vertical component
	{
		if (real < 0.0) //Quadrant II
			return 180 + refAngle;
		 //Quadrant I
			return refAngle;
	}
}
