// CCalc, one stop shop for mathematical formulas
// Copyright (C) 2018 Chronix
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <iostream>
#include <cstring>

#include "libmath.hpp"
using namespace libmath;

int main(int argc, const char* argv[])
{
	double num1, num2, num3;
	if (argc >= 4)
	{
		num1 = atof(argv[1]);
		num2 = atof(argv[2]);
		num3 = atof(argv[3]);
	}

	else if(argc == 1)
	{
		std::cout << "Please open me in the terminal!" << std::endl;
		return -1;
	}

	else
	{
		std::cout << "Please enter at least three arguments!" << std::endl;
		return -1;
	}

	trapezoid_t trapezoid = Trapezoid(num1, num2, num3);
	rectangle_t rectangle = Rectangle(num1, num2);
	triangle_t triangle = Triangle(num1, num2);
	rhombus_t rhombus = Rhombus(num1);
	hexagon_t hexagon = Hexagon(num1);
	circle_t circle = Circle(num1);
	square_t square = Square(num1);

	rectangular_prism_t rectangular_prism = Rectangular_Prism(num1, num2, num3);
	triangular_prism_t triangular_prism = Triangular_Prism(num1, num2, num2);
	cone_t cone = Cone(num1, num2);
	cube_t cube = Cube(num1);

	std::cout << "You entered: " << num1 << ", " << num2 << ", and " << num3 << std::endl;
	std::cout << std::endl;

	std::cout << "Trapezoid: " << trapezoid.area << std::endl;
	std::cout << "Rectangle: " << rectangle.area << std::endl;
	std::cout << "Triangle: " << triangle.area << std::endl;
	std::cout << "Rhombus: " << rhombus.area << std::endl;
	std::cout << "Hexagon: " << hexagon.area << std::endl;
	std::cout << "Circle: " << circle.area << std::endl;
	std::cout << "Square: " << square.area << std::endl;
	std::cout << std::endl;

	std::cout << "Rectangular Prism: " << rectangular_prism.area << std::endl;
	std::cout << "Triangular Prism: " << triangular_prism.area << std::endl;
	std::cout << "Cone: " << cone.area << std::endl;
	std::cout << "Cube: " << cube.area << std::endl;

	return 0;
}
