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
#include <ctime>

#include "everything.h"
using namespace libmath;

static void help(logger& log)
{
	log.print("Arithmetic -\n");
	log.print("  --add | adds two numbers (two arguments)\n");
	log.print("  --subtract | subtracts two numbers (two arguments)\n");
	log.print("  --multiply | multiplies two numbers (two arguments)\n");
	log.print("  --divide | divides two numbers (two arguments)\n");
	log.print("\n");
	log.print("Exponential -\n");
	log.print("  --power | puts x to the power of y (two arguments)\n");
	log.print("\n");
	log.print("Geometry (2D) -\n");
	log.print("  --trapezoid | finds the area of a trapezoid (three arguments) [base, 2nd base, height]\n");
	log.print("  --rectangle | finds the area of a rectangle (two arguments) [length, width]\n");
	log.print("  --triangle | finds the area of a triangle (two arguments) [base, height]\n");
	log.print("  --rhombus | finds the area of a rhombus (one argument) [side]\n");
	log.print("  --hexagon | finds the area of a hexagon (one argument) [side]\n");
	log.print("  --circle | finds the area of a circle (one argument) [radius]\n");
	log.print("  --square | finds the area of a square (one argument) [side]\n");
	log.print("\n");
	log.print("Geometry (3D) -\n");
	log.print("  --rectangular-prism | finds the volume of a rectangular prism (three arguments) [length, width, height]\n");
	log.print("  --triangular-prism | finds the volume of a triangular prism (three arguments) [length, width, height]\n");
	log.print("  --cone | finds the volume of a cone (two arguments) [radius, height]\n");
	log.print("  --cube | finds the volume of a cube (one argument) [face]\n");
	log.print("\n");
	log.print("Other -\n");
	log.print("  --author | details about yours truly\n");
}

static std::string GetFileName(std::string prepend)
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);

	std::ostringstream stream;
	stream << prepend << "_" << now->tm_mon + 1 << now->tm_mday << now->tm_year + 1900 << "_" << now->tm_hour << now->tm_min << ".log";

	return stream.str();
}

int main(int argc, const char* argv[])
{
	logger frontend_logger(everything, GetFileName("ccalc"));

	if(argc == 1)
	{
		frontend_logger.print("cCalc v2.2\n");
		frontend_logger.print("(C) 2018 akachronix\n");
		frontend_logger.print("https://github.com/akachronix\n");
		frontend_logger.print("\n");
		frontend_logger.print("Choose \"Help\" to view features.\n");
		frontend_logger.print("\n");
    	frontend_logger.print("This program comes with ABSOLUTELY NO WARRANTY.\n");
    	frontend_logger.print("This is free software, and you are welcome to redistribute it under certain conditions.\n");
		frontend_logger.print("\n");
		frontend_logger.print("See LICENSE for details.\n");
		frontend_logger.print("\n");

		bool running = true;

		while (running)
		{
			frontend_logger.print("1) Arithmetic\n");
			frontend_logger.print("2) Exponential\n");
			frontend_logger.print("3) Geometry\n");
			frontend_logger.print("4) Help\n");
			frontend_logger.print("5) Exit\n");

			frontend_logger.print("\n");

			int option;
			std::cin >> option;

			frontend_logger.log_value(option);

			frontend_logger.print("\n");

			if (option == 1)
			{
				frontend_logger.print("1) Add\n");
				frontend_logger.print("2) Subtract\n");
				frontend_logger.print("3) Multiply\n");
				frontend_logger.print("4) Divide\n");

				frontend_logger.print("\n");

				std::cin >> option;
				frontend_logger.log_value(option);

				frontend_logger.print("\n");

				double num1, num2;

				frontend_logger.print("Enter first number: ");

				std::cin >> num1;
				frontend_logger.log_value(num1);

				frontend_logger.print("Enter second number: ");

				std::cin >> num2;
				frontend_logger.log_value(num2);

				frontend_logger.print("\n");

				switch (option)
				{
				case 1:
					std::cout << "Answer: " << add(num1, num2) << std::endl;
					frontend_logger.log_value("Answer: ", add(num1, num2));
					break;

				case 2:
					std::cout << "Answer: " << subtract(num1, num2) << std::endl;
					frontend_logger.log_value("Answer: ", subtract(num1, num2));
					break;

				case 3:
					std::cout << "Answer: " << multiply(num1, num2) << std::endl;
					frontend_logger.log_value("Answer: ", multiply(num1, num2));
					break;

				case 4:
					std::cout << "Answer: " << divide(num1, num2) << std::endl;
					frontend_logger.log_value("Answer: ", divide(num1, num2));
					break;

				default:
					frontend_logger.log_error("Invalid input.");
					break;
				}

				frontend_logger.print("\n");
			}

			else if (option == 2)
			{
				frontend_logger.print("1) Power\n");

				frontend_logger.print("\n");

				std::cin >> option;
				frontend_logger.log_value(option);

				frontend_logger.print("\n");

				double num1, num2;

				frontend_logger.print("Enter first number: ");
				std::cin >> num1;

				frontend_logger.log_value(num1);

				frontend_logger.print("Enter second number: ");
				std::cin >> num2;

				frontend_logger.log_value(num2);

				frontend_logger.print("\n");

				switch (option)
				{
				case 1:
					std::cout << "Answer: " << power(num1, num2) << std::endl;
					frontend_logger.log_value("Answer: ", power(num1, num2));
					break;

				default:
					frontend_logger.log_error("Invalid input.");
					break;
				}

				frontend_logger.print("\n");
			}

			else if (option == 3)
			{
				frontend_logger.print("1) Trapezoid\n");
				frontend_logger.print("2) Rectangle\n");
				frontend_logger.print("3) Triangle\n");
				frontend_logger.print("4) Rhombus\n");
				frontend_logger.print("5) Hexagon\n");
				frontend_logger.print("6) Circle\n");
				frontend_logger.print("7) Square\n");
				frontend_logger.print("8) Rectangular Prism\n");
				frontend_logger.print("9) Triangular Prism\n");
				frontend_logger.print("10) Cone\n");
				frontend_logger.print("11) Cube\n");

				frontend_logger.print("\n");

				std::cin >> option;
				frontend_logger.log_value("", option);

				frontend_logger.print("\n");

				double area;

				switch (option)
				{
				case 1:
				{
					double base, base2, height;

					frontend_logger.print("Enter base: ");
					std::cin >> base;

					frontend_logger.log_value("", base);

					frontend_logger.print("Enter base 2: ");
					std::cin >> base2;

					frontend_logger.log_value("", base2);

					frontend_logger.print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.print("\n");

					trapezoid_t shape = Trapezoid(base, base2, height);
					area = shape.area;

					break;
				}

				case 2:
				{
					double length, width;

					frontend_logger.print("Enter length: ");
					std::cin >> length;

					frontend_logger.log_value("", length);

					frontend_logger.print("Enter width: ");
					std::cin >> width;

					frontend_logger.log_value("", width);

					frontend_logger.print("\n");

					rectangle_t shape = Rectangle(length, width);
					area = shape.area;

					frontend_logger.log_value("", shape.area);

					break;
				}

				case 3:
				{
					double base, height;

					frontend_logger.print("Enter base: ");
					std::cin >> base;

					frontend_logger.log_value("", base);

					frontend_logger.print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.print("\n");

					triangle_t shape = Triangle(base, height);
					area = shape.area;

					break;
				}

				case 4:
				{
					double side;

					frontend_logger.print("Enter side: ");
					std::cin >> side;

					frontend_logger.log_value("", side);

					frontend_logger.print("\n");

					rhombus_t shape = Rhombus(side);
					area = shape.area;

					break;
				}

				case 5:
				{
					double side;

					frontend_logger.print("Enter side: ");
					std::cin >> side;

					frontend_logger.log_value("", side);

					frontend_logger.print("\n");

					hexagon_t shape = Hexagon(side);
					area = shape.area;

					break;
				}

				case 6:
				{
					double radius;

					frontend_logger.print("Enter radius: ");
					std::cin >> radius;

					frontend_logger.log_value("", radius);

					frontend_logger.print("\n");

					circle_t shape = Circle(radius);
					area = shape.area;

					break;
				}

				case 7:
				{
					double side;

					frontend_logger.print("Enter side: ");
					std::cin >> side;

					frontend_logger.log_value("", side);

					frontend_logger.print("\n");

					square_t shape = Square(side);
					area = shape.area;

					break;
				}

				case 8:
				{
					double length, width, height;

					frontend_logger.print("Enter length: ");
					std::cin >> length;

					frontend_logger.log_value("", length);

					frontend_logger.print("Enter width: ");
					std::cin >> width;

					frontend_logger.log_value("", width);

					frontend_logger.print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.print("\n");

					rectangular_prism_t shape = Rectangular_Prism(length, width, height);
					area = shape.area;

					break;
				}

				case 9:
				{
					double length, width, height;

					frontend_logger.print("Enter length: ");
					std::cin >> length;

					frontend_logger.log_value("", length);

					frontend_logger.print("Enter width: ");
					std::cin >> width;

					frontend_logger.log_value("", width);

					frontend_logger.print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.print("\n");

					triangular_prism_t shape = Triangular_Prism(length, width, height);
					area = shape.area;

					break;
				}

				case 10:
				{
					double radius, height;

					frontend_logger.print("Enter radius: ");
					std::cin >> radius;

					frontend_logger.log_value("", radius);

					frontend_logger.print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.print("\n");

					cone_t shape = Cone(radius, height);
					area = shape.area;

					break;
				}

				case 11:
				{
					double face;

					frontend_logger.print("Enter side: ");
					std::cin >> face;

					frontend_logger.log_value("", face);

					frontend_logger.print("\n");

					cube_t shape = Cube(face);
					area = shape.area;

					break;
				}

				default:
					frontend_logger.log_error("Invalid input.");
					break;
				}

				if (option > 0 && option <= 7)
				{
					std::cout << "Area: " << area << std::endl;
					frontend_logger.log_value("Area: ", area);
				}

				else if (option > 7 && option <= 11)
				{
					std::cout << "Volume: " << area << std::endl;
					frontend_logger.log_value("Volume: ", area);
				}

				frontend_logger.print("\n");
			}

			else if (option == 4)
			{
				help(frontend_logger);
				frontend_logger.print("\n");
			}

			else if (option == 5)
			{
				running = false;
			}
		}

		return 0;
	}

	else if(argc > 0)
	{
		logger terminal_logger(everything, GetFileName("ccalc"));

		if((strcmp(argv[1], "--add")) == 0)
		{
			std::cout << "Answer: " << add(atof(argv[2]), atof(argv[3])) << std::endl;
			terminal_logger.log_value("Answer: ", add(atof(argv[2]), atof(argv[3])));
		}

		else if((strcmp(argv[1], "--subtract")) == 0)
		{
			std::cout << "Answer: " << subtract(atof(argv[2]), atof(argv[3])) << std::endl;
			terminal_logger.log_value("Answer: ", subtract(atof(argv[2]), atof(argv[3])));
		}

		else if((strcmp(argv[1], "--multiply")) == 0)
		{
			std::cout << "Answer: " << multiply(atof(argv[2]), atof(argv[3])) << std::endl;
			terminal_logger.log_value("Answer: ", multiply(atof(argv[2]), atof(argv[3])));
		}

		else if((strcmp(argv[1], "--divide")) == 0)
		{
			std::cout << "Answer: " << divide(atof(argv[2]), atof(argv[3])) << std::endl;
			terminal_logger.log_value("Answer: ", divide(atof(argv[2]), atof(argv[3])));
		}

		else if((strcmp(argv[1], "--power")) == 0)
		{
			std::cout << "Answer: " << power(atof(argv[2]), atof(argv[3])) << std::endl;
			terminal_logger.log_value("Answer: ", power(atof(argv[2]), atof(argv[3])));
		}

		else if((strcmp(argv[1], "--trapezoid")) == 0)
		{
			trapezoid_t shape = Trapezoid(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--rectangle")) ==  0)
		{
			rectangle_t shape = Rectangle(atof(argv[2]), atof(argv[3]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--triangle")) == 0)
		{
			triangle_t shape = Triangle(atof(argv[2]), atof(argv[3]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--rhombus")) == 0)
		{
			rhombus_t shape = Rhombus(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if ((strcmp(argv[1], "--hexagon")) == 0)
		{
			hexagon_t shape = Hexagon(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--circle")) == 0)
		{
			circle_t shape = Circle(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--square")) == 0)
		{
			square_t shape = Square(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--rectangular-prism")) == 0)
		{
			rectangular_prism_t shape = Rectangular_Prism(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--triangular-prism")) == 0)
		{
			triangular_prism_t shape = Triangular_Prism(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--cone")) == 0)
		{
			cone_t shape = Cone(atof(argv[2]), atof(argv[3]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--cube")) == 0)
		{
			cube_t shape = Cube(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--help")) == 0)
		{
			help(terminal_logger);
		}

		else if((strcmp(argv[1], "--author")) == 0)
		{
			terminal_logger.print("Github: https://www.github.com/akachronix\n");
			terminal_logger.print("SoundCloud: https://www.soundcloud.com/chronix2\n");
			terminal_logger.print("Steam: https:///www.steamcommunity.com/id/datboichronchron\n");
			terminal_logger.print("Instagram: https://www.instagram.com/akachronix\n");
			terminal_logger.print("Snapchat: https://www.snapchat.com/add/aka.chronix\n");
			terminal_logger.print("\n");
			terminal_logger.print("You were curious about me, eh? ;)\n");
		}

		else
		{
			terminal_logger.log_error("Invalid command.");
			help(terminal_logger);

			return -1;
		}
	}

	return 0;
}
