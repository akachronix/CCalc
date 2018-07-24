#pragma once

typedef struct {double side1, side2, height, area;} trapezoid_t;
typedef struct {double length, width, area;} rectangle_t;
typedef struct {double base, height, area;} triangle_t;
typedef struct {double radius, area;} circle_t;
typedef struct {double side, area;} square_t;
typedef struct {double face, area;} cube_t;

namespace libmath
{
	double add(double x, double y);
	double subtract(double x, double y);
	double multiply(double x, double y);
	double divide(double x, double y);
	double power(double base, double exponent);

	trapezoid_t Trapezoid(double side1, double side2, double height);
	rectangle_t Rectangle(double length, double height);
	triangle_t Triangle(double base, double height);
	circle_t Circle(double radius);
	square_t Square(double side);
	cube_t Cube(double face);
}
