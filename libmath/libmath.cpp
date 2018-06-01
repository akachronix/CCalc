#include "libmath.hpp"

#define _PI_ (3.141592653f)

namespace libmath
{
	double add(double x, double y)
	{
		return x + y;
	}
	
	double subtract(double x, double y)
	{
		return x - y;
	}
	
	double multiply(double x, double y)
	{
		return x * y;
	}

	double divide(double x, double y)
	{
		return x / y;
	}
	
	double power(double base, double exponent)
	{
		double answer = base;

		for(int i = 1; i < exponent; i++)
			answer *= base;

		return answer;
	}

	trapezoid_t Trapezoid(double side1, double side2, double height)
	{
		trapezoid_t obj = {side1, side2, height, (side1 + side2) / 2 * height};
		return obj;
	}

	rectangle_t Rectangle(double length, double width)
	{
		rectangle_t obj = {length, width, length * width};
		return obj;
	}
	
	triangle_t Triangle(double base, double height)
	{
		triangle_t obj = {base, height, (base * height) / 2};
		return obj;
	}

	circle_t Circle(double radius)
	{
		circle_t obj = {radius, (radius * radius) * _PI_};
		return obj;
	}

	square_t Square(double side)
	{
		square_t obj = {side, side * side};
		return obj;
	}
}
