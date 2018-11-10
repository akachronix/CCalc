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
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include "everything.h"

void help(Logger& log)
{
	log << "Arithmetic -"  << newl;
	log << "  --add | adds two numbers (two arguments)" << newl;
	log << "  --subtract | subtracts two numbers (two arguments)" << newl;
	log << "  --multiply | multiplies two numbers (two arguments)" << newl;
	log << "  --divide | divides two numbers (two arguments)" << newl;
	log << "  --modulus | divides two numbers and returns the remainder (two arguments)" << newl;
	log << newl;
	log << "Exponential -" << newl;
	log << "  --power | puts x to the power of y (two arguments)" << newl;
	log << "  --square-root | finds the square root of a number (one argument)" << newl;
	log << "  --cubic-root | finds the cubic root of a number (one argument)" << newl;
	log << newl;
	log << "Geometry (2D) -" << newl;
	log << "  --trapezoid | finds the area of a trapezoid (three arguments) [base, 2nd base, height]" << newl;
	log << "  --rectangle | finds the area of a rectangle (two arguments) [length, width]" << newl;
	log << "  --triangle | finds the area of a triangle (two arguments) [base, height]" << newl;
	log << "  --rhombus | finds the area of a rhombus (one argument) [side]" << newl;
	log << "  --hexagon | finds the area of a hexagon (one argument) [side]" << newl;
	log << "  --circle | finds the area of a circle (one argument) [radius]" << newl;
	log << "  --square | finds the area of a square (one argument) [side]" << newl;
	log << newl;
	log << "Geometry (3D) -" << newl;
	log << "  --rectangular-prism | finds the volume of a rectangular prism (three arguments) [length, width, height]" << newl;
	log << "  --triangular-prism | finds the volume of a triangular prism (three arguments) [length, width, height]" << newl;
	log << "  --cone | finds the volume of a cone (two arguments) [radius, height]" << newl;
	log << "  --cube | finds the volume of a cube (one argument) [face]" << newl;
	log << newl;
	log << "Other -" << newl;
	log << "  --author | details about yours truly" << newl;
}

static std::string GetFileName(std::string prepend)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	std::stringstream stream;
	stream << prepend << "_" << now->tm_mon + 1 << now->tm_mday << now->tm_year + 1900 << "_" << now->tm_hour << now->tm_min << ".log";

	return stream.str();
}

int main(int argc, const char* argv[])
{
	if (argc == 1)
	{
		Logger frontend_logger(loglevel_t::everything, GetFileName("ccalc"));

		frontend_logger << "cCalc v3.0" << newl;
		frontend_logger << "(C) 2018 akachronix" << newl;
		frontend_logger << "https://github.com/akachronix" << newl;
		frontend_logger << newl;
		frontend_logger << "Choose \"Help\" to view features." << newl;
		frontend_logger << newl;
		frontend_logger << "This program comes with ABSOLUTELY NO WARRANTY." << newl;
		frontend_logger << "This is free software, and you are welcome to redistribute it under certain conditions." << newl;
		frontend_logger << newl;
		frontend_logger << "See LICENSE for details." << newl;
		frontend_logger << newl;

		bool running = true;

		while (running)
		{
			frontend_logger << "1) Arithmetic" << newl;
			frontend_logger << "2) Exponential" << newl;
			frontend_logger << "3) Geometry" << newl;
			frontend_logger << "4) Dump Log" << newl;
			frontend_logger << "5) Help" << newl;
			frontend_logger << "6) Exit" << newl;
			frontend_logger << newl;

			int option = 0;

			std::string buffer = "";
			frontend_logger >> buffer;

			if (atof(buffer.c_str()) > 0 && atof(buffer.c_str()) < 7)
				option = atoi(buffer.c_str());
			
			else
				frontend_logger.logError("Invalid input.");

			frontend_logger << newl;

			if (option == 1)
			{
				frontend_logger << "1) Add" << newl;
				frontend_logger << "2) Subtract" << newl;
				frontend_logger << "3) Multiply" << newl;
				frontend_logger << "4) Divide" << newl;
				frontend_logger << "5) Modulus" << newl;
				frontend_logger << newl;

				frontend_logger >> option;
				frontend_logger << newl;

				double num1, num2;

				frontend_logger << "Enter first number: ";
				frontend_logger >> num1;

				frontend_logger << "Enter second number: ";
				frontend_logger >> num2;

				frontend_logger << newl;

				switch (option)
				{
				case 1:
					frontend_logger << "Answer: " << num1 + num2 << newl;
					break;

				case 2:
					frontend_logger << "Answer: " << num1 + num2 << newl;
					break;

				case 3:
					frontend_logger << "Answer: "<< num1 - num2 << newl;
					break;

				case 4:
					frontend_logger << "Answer: " << num1 / num2 << newl;
					break;
				
				case 5:
					frontend_logger << "Answer: " << (int)num1 % (int)num2 << newl;
					break;

				default:
					frontend_logger.logError("Invalid input.");
					break;
				}

				frontend_logger << newl;
			}

			else if (option == 2)
			{
				frontend_logger << "1) Power" << newl;
				frontend_logger << "2) Square Root" << newl;
				frontend_logger << "3) Cubic Root" << newl;
				frontend_logger << newl;

				frontend_logger >> option;
				frontend_logger << newl;

				switch (option)
				{
				case 1:
				{
					long long num1, num2;

					frontend_logger << "Enter first number: ";
					frontend_logger >> num1;

					frontend_logger << "Enter second number: ";
					frontend_logger >> num2;

					frontend_logger << newl;

					frontend_logger << "Answer: " << pow(num1, num2) << newl;
					break;
				}

				case 2:
				{
					long long num1;
					frontend_logger << "Enter number: ";
					frontend_logger >> num1;

					frontend_logger << newl;

					frontend_logger << "Answer: " << sqrt(num1) << newl;
					break;
				}

				case 3:
				{
					long long num1;
					frontend_logger << "Enter number: ";
					frontend_logger >> num1;

					frontend_logger << newl;

					frontend_logger << "Answer: " << cbrt(num1) << newl;
					break;
				}

				default:
					frontend_logger.logError("Invalid input.");
					break;
				}

				frontend_logger << newl;
			}

			else if (option == 3)
			{
				frontend_logger << "1) Trapezoid" << newl;
				frontend_logger << "2) Rectangle" << newl;
				frontend_logger << "3) Triangle" << newl;
				frontend_logger << "4) Rhombus" << newl;
				frontend_logger << "5) Hexagon" << newl;
				frontend_logger << "6) Circle" << newl;
				frontend_logger << "7) Square" << newl;
				frontend_logger << "8) Rectangular Prism" << newl;
				frontend_logger << "9) Triangular Prism" << newl;
				frontend_logger << "10) Cone" << newl;
				frontend_logger << "11) Cube" << newl;
				frontend_logger << newl;

				frontend_logger >> option;
				frontend_logger << newl;

				double area;

				switch (option)
				{
				case 1:
				{
					double base, base2, height;

					frontend_logger << "Enter base: ";
					frontend_logger >> base;

					frontend_logger << "Enter base 2: ";
					frontend_logger >> base2;

					frontend_logger << "Enter height: ";
					frontend_logger >> height;

					frontend_logger << newl;

					Trapezoid<double> shape(base, base2, height);
					area = shape.area();

					break;
				}

				case 2:
				{
					double length, width;

					frontend_logger << "Enter length: ";
					frontend_logger >> length;

					frontend_logger << "Enter width: ";
					frontend_logger >> width;

					frontend_logger << newl;

					Rectangle<double> shape(length, width);
					area = shape.area();

					break;
				}

				case 3:
				{
					double base, height;

					frontend_logger << "Enter base: ";
					frontend_logger >> base;

					frontend_logger << "Enter height: ";
					frontend_logger >> height;

					frontend_logger << newl;

					Triangle<double> shape(base, height);
					area = shape.area();

					break;
				}

				case 4:
				{
					double side;

					frontend_logger << "Enter side: ";
					frontend_logger >> side;

					frontend_logger << newl;

					Rhombus<double> shape(side);
					area = shape.area();

					break;
				}

				case 5:
				{
					double side;

					frontend_logger << "Enter side: ";
					frontend_logger >> side;

					frontend_logger << newl;

					Hexagon<double> shape(side);
					area = shape.area();

					break;
				}

				case 6:
				{
					double radius;

					frontend_logger << "Enter radius: ";
					frontend_logger >> radius;

					frontend_logger << newl;

					Circle<double> shape(radius);
					area = shape.area();

					break;
				}

				case 7:
				{
					double side;

					frontend_logger << "Enter side: ";
					frontend_logger >> side;

					frontend_logger << newl;

					Square<double> shape(side);
					area = shape.area();

					break;
				}

				case 8:
				{
					double length, width, height;

					frontend_logger << "Enter length: ";
					frontend_logger >> length;

					frontend_logger << "Enter width: ";
					frontend_logger >> width;

					frontend_logger << "Enter height: ";
					frontend_logger >> height;

					frontend_logger << newl;

					RectangularPrism<double> shape(length, width, height);
					area = shape.area();

					break;
				}

				case 9:
				{
					double length, width, height;

					frontend_logger << "Enter length: ";
					frontend_logger >> length;

					frontend_logger << "Enter width: ";
					frontend_logger >> width;

					frontend_logger << "Enter height: ";
					frontend_logger >> height;

					frontend_logger << newl;

					TriangularPrism<double> shape(length, width, height);
					area = shape.area();

					break;
				}

				case 10:
				{
					double radius, height;

					frontend_logger << "Enter radius: ";
					frontend_logger >> radius;

					frontend_logger << "Enter height: ";
					frontend_logger >> height;

					frontend_logger << newl;

					Cone<double> shape(radius, height);
					area = shape.area();

					break;
				}

				case 11:
				{
					double face;

					frontend_logger << "Enter side: ";
					frontend_logger >> face;

					frontend_logger << newl;

					Cube<double> shape(face);
					area = shape.area();

					break;
				}

				default:
					frontend_logger.logError("Invalid input.");
					area = 0.0;
					break;
				}

				if (option > 0 && option <= 7)
				{
					frontend_logger << "Area: " << area << newl;
				}

				else if (option > 7 && option <= 11)
				{
					frontend_logger << "Volume: " << area << newl;
				}

				frontend_logger << newl;
			}
			
			else if (option == 4)
			{
				frontend_logger.dumpLog();
			}

			else if (option == 5)
			{
				help(frontend_logger);
				frontend_logger << newl;
			}

			else if (option == 6)
			{
				running = false;
			}
		}

		return 0;
	}

	else
	{
		Logger terminal_logger(loglevel_t::everything, GetFileName("ccalc"));

		if ((strcmp(argv[1], "--add")) == 0 && argc >= 4)
		{
			terminal_logger << "Answer: " << atof(argv[2]) + atof(argv[3]) << newl;
		}

		else if ((strcmp(argv[1], "--subtract")) == 0 && argc >= 4)
		{
			terminal_logger << "Answer: " << atof(argv[2]) - atof(argv[3]) << newl;
		}

		else if ((strcmp(argv[1], "--multiply")) == 0 && argc >= 4)
		{
			terminal_logger << "Answer: " << atof(argv[2]) * atof(argv[3]) << newl;
		}

		else if ((strcmp(argv[1], "--divide")) == 0 && argc >= 4)
		{
			terminal_logger << "Answer: " << atof(argv[2]) / atof(argv[3]) << newl;
		}

		else if ((strcmp(argv[1], "--modulus")) == 0 && argc >= 4)
		{
			terminal_logger << "Answer: " << atol(argv[2]) % atol(argv[3]) << newl;
		}

		else if ((strcmp(argv[1], "--power")) == 0 && argc >= 4)
		{
			terminal_logger << "Answer: " << pow(atof(argv[2]), atof(argv[3])) << newl;
		}

		else if ((strcmp(argv[1], "--square-root")) == 0 && argc >= 3)
		{
			terminal_logger << "Answer: " << sqrt(atof(argv[2])) << newl;
		}

		else if ((strcmp(argv[1], "--cubic-root")) == 0 && argc >= 3)
		{
			terminal_logger << "Answer: " << cbrt(atof(argv[2])) << newl;
		}

		else if ((strcmp(argv[1], "--trapezoid")) == 0 && argc >= 5)
		{
			Trapezoid<long double> shape(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--rectangle")) ==  0  && argc >= 4)
		{
			Rectangle<long double> shape(atof(argv[2]), atof(argv[3]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--triangle")) == 0 && argc >= 4)
		{
			Triangle<long double> shape(atof(argv[2]), atof(argv[3]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--rhombus")) == 0 && argc >= 3)
		{
			Rhombus<long double> shape(atof(argv[2]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--hexagon")) == 0 && argc >= 3)
		{
			Hexagon<long double> shape(atof(argv[2]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--circle")) == 0 && argc >= 3)
		{
			Circle<long double> shape(atof(argv[2]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--square")) == 0 && argc >= 3)
		{
			Square<long double> shape(atof(argv[2]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--rectangular-prism")) == 0 && argc >= 5)
		{
			RectangularPrism<long double> shape(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--triangular-prism")) == 0 && argc >= 5)
		{
			TriangularPrism<long double> shape(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--cone")) == 0 && argc >= 4)
		{
			Cone<long double> shape(atof(argv[2]), atof(argv[3]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--cube")) == 0 && argc >= 3)
		{
			Cube<long double> shape(atof(argv[2]));
			terminal_logger << "Answer: " << shape.area() << newl;
		}

		else if ((strcmp(argv[1], "--help")) == 0)
		{
			help(terminal_logger);
		}

		else if ((strcmp(argv[1], "--author")) == 0)
		{
			terminal_logger << "Github: https://www.github.com/akachronix" << newl;
			terminal_logger << "SoundCloud: https://www.soundcloud.com/chronix2" << newl;
			terminal_logger << "Steam: https:///www.steamcommunity.com/id/datboichronchron" << newl;
			terminal_logger << "Instagram: https://www.instagram.com/akachronix" << newl;
			terminal_logger << "Snapchat: https://www.snapchat.com/add/aka.chronix" << newl;
			terminal_logger << newl;
			terminal_logger << "You were curious about me, eh? ;)" << newl;
		}

		else
		{
			terminal_logger.logError("Invalid command.");
			help(terminal_logger);

			return -1;
		}
	}

	return 0;
}