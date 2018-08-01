#include <iostream>
#include <cstdlib>
#include <cstring>

#include "libmath.hpp"
using namespace libmath;

#include "liblog.hpp"

void help(logger& log)
{
	log.just_print("Usage:\n");
	log.just_print("Arithmetic -\n");
	log.just_print("--add | adds two numbers (two arguments)\n");
	log.just_print("--subtract | subtracts two numbers (two arguments)\n");
	log.just_print("--multiply | multiplies two numbers (two arguments)\n");
	log.just_print("--divide | divides two numbers (two arguments)\n");
	log.just_print("\n");
	log.just_print("Exponential -\n");
	log.just_print("--power | puts x to the power of y (two arguments)\n");
	log.just_print("\n");
	log.just_print("Geometry (2D) -\n");
	log.just_print("--trapezoid | finds the area of a trapezoid (three arguments) [base, 2nd base, height]\n");
	log.just_print("--rectangle | finds the area of a rectangle (two arguments) [length, width]\n");
	log.just_print("--triangle | finds the area of a triangle (two arguments) [base, height]\n");
	log.just_print("--circle | finds the area of a circle (one argument) [radius]\n");
	log.just_print("--square | finds the area of a square (one argument) [side]\n");
	log.just_print("\n");
	log.just_print("Geometry (3D) -\n");
	log.just_print("--rectangular-prism | finds the volume of a rectangular prism (three arguments) [length, width, height]\n");
	log.just_print("--cube | finds the volume of a cube (one argument) [face]");
	log.just_print("\n");
}

int main(int argc, const char* argv[])
{
	logger frontend_logger(loglevel_t::everything, "ccalc-frontend.log");

	if(argc == 1)
	{
		frontend_logger.just_print("cCalc v3.2\n");
		frontend_logger.just_print("(C) 2018 akachronix\n");

		frontend_logger.just_print("\n");

		bool running = true;
		
		while (running)
		{
			frontend_logger.just_print("1) Arithmetic\n");
			frontend_logger.just_print("2) Exponential\n");
			frontend_logger.just_print("3) Geometry\n");
			//frontend_logger.just_print("4) Interpreter\n");
			frontend_logger.just_print("4) Help\n");
			//frontend_logger.just_print("6) View Log\n");
			frontend_logger.just_print("5) Exit\n");

			frontend_logger.just_print("\n");

			int option;
			std::cin >> option;

			frontend_logger.log_value("", option);

			frontend_logger.just_print("\n");

			if (option == 1)
			{
				frontend_logger.just_print("1) Add\n");
				frontend_logger.just_print("2) Subtract\n");
				frontend_logger.just_print("3) Multiply\n");
				frontend_logger.just_print("4) Divide\n");

				frontend_logger.just_print("\n");

				std::cin >> option;
				frontend_logger.log_value("", option);

				frontend_logger.just_print("\n");

				double num1, num2;

				frontend_logger.just_print("Enter first number: ");

				std::cin >> num1;
				frontend_logger.log_value("", num1);

				frontend_logger.just_print("Enter second number: ");

				std::cin >> num2;
				frontend_logger.log_value("", num2);

				frontend_logger.just_print("\n");

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

				frontend_logger.just_print("\n");
			}

			else if (option == 2)
			{
				frontend_logger.just_print("1) Power\n");

				frontend_logger.just_print("\n");

				std::cin >> option;
				frontend_logger.log_value("", option);

				frontend_logger.just_print("\n");

				double num1, num2;

				frontend_logger.just_print("Enter first number: ");
				std::cin >> num1;

				frontend_logger.log_value("", num1);

				frontend_logger.just_print("Enter second number: ");
				std::cin >> num2;

				frontend_logger.log_value("", num2);

				frontend_logger.just_print("\n");

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

				frontend_logger.just_print("\n");
			}

			else if (option == 3)
			{
				frontend_logger.just_print("1) Trapezoid\n");
				frontend_logger.just_print("2) Rectangle\n");
				frontend_logger.just_print("3) Triangle\n");
				frontend_logger.just_print("4) Circle\n");
				frontend_logger.just_print("5) Square\n");
				frontend_logger.just_print("6) Rectangular Prism\n");
				frontend_logger.just_print("7) Triangular Prism\n");
				frontend_logger.just_print("8) Cube\n");

				frontend_logger.just_print("\n");

				std::cin >> option;
				frontend_logger.log_value("", option);

				frontend_logger.just_print("\n");

				double area;

				switch (option)
				{
				case 1:
				{
					double base, base2, height;

					frontend_logger.just_print("Enter base: ");
					std::cin >> base;

					frontend_logger.log_value("", base);

					frontend_logger.just_print("Enter base 2: ");
					std::cin >> base2;

					frontend_logger.log_value("", base2);

					frontend_logger.just_print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.just_print("\n");

					trapezoid_t shape = Trapezoid(base, base2, height);
					area = shape.area;

					break;
				}

				case 2:
				{
					double length, width;

					frontend_logger.just_print("Enter length: ");
					std::cin >> length;

					frontend_logger.log_value("", length);

					frontend_logger.just_print("Enter width: ");
					std::cin >> width;

					frontend_logger.log_value("", width);

					frontend_logger.just_print("\n");

					rectangle_t shape = Rectangle(length, width);
					area = shape.area;

					frontend_logger.log_value("", shape.area);

					break;
				}

				case 3:
				{
					double base, height;

					frontend_logger.just_print("Enter base: ");
					std::cin >> base;

					frontend_logger.just_print("Enter height: ");
					std::cin >> height;

					frontend_logger.just_print("\n");

					triangle_t shape = Triangle(base, height);
					area = shape.area;

					break;
				}

				case 4:
				{
					double radius;

					frontend_logger.just_print("Enter radius: ");
					std::cin >> radius;

					frontend_logger.log_value("", radius);

					frontend_logger.just_print("\n");

					circle_t shape = Circle(radius);
					area = shape.area;

					break;
				}

				case 5:
				{
					double side;

					frontend_logger.just_print("Enter side: ");
					std::cin >> side;

					frontend_logger.log_value("", side);

					frontend_logger.just_print("\n");

					square_t shape = Square(side);
					area = shape.area;

					break;
				}

				case 6:
				{
					double length, width, height;

					frontend_logger.just_print("Enter length: ");
					std::cin >> length;

					frontend_logger.log_value("", length);

					frontend_logger.just_print("Enter width: ");
					std::cin >> width;

					frontend_logger.log_value("", width);

					frontend_logger.just_print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.just_print("\n");

					rectangular_prism_t shape = Rectangular_Prism(length, width, height);
					area = shape.area;

					break;
				}

				case 7:
				{
					double length, width, height;

					frontend_logger.just_print("Enter length: ");
					std::cin >> length;

					frontend_logger.log_value("", length);

					frontend_logger.just_print("Enter width: ");
					std::cin >> width;

					frontend_logger.log_value("", width);

					frontend_logger.just_print("Enter height: ");
					std::cin >> height;

					frontend_logger.log_value("", height);

					frontend_logger.just_print("\n");

					triangular_prism_t shape = Triangular_Prism(length, width, height);
					area = shape.area;

					break;			
				}

				case 8:
				{
					double face;

					frontend_logger.just_print("Enter side: ");
					std::cin >> face;

					frontend_logger.log_value("", face);

					frontend_logger.just_print("\n");

					cube_t shape = Cube(face);
					area = shape.area;

					break;
				}

				default:
					frontend_logger.log_error("Invalid input.");
					break;
				}

				if (option > 0 && option <= 5)
				{
					std::cout << "Area: " << area << std::endl;
					frontend_logger.log_value("Area: ", area);
				}

				else if (option > 5 && option <= 7)
				{
					std::cout << "Volume: " << area << std::endl;
					frontend_logger.log_value("Volume: ", area);
				}

				frontend_logger.just_print("\n");
			}

			/* else if (option == 4)
			{
				// Interpreter mode is planned here. Pending reconstruction of codebase.
				frontend_logger.just_print("Interpreter mode is planned here. Pending reconstruction of codebase.\n");
				frontend_logger.just_print("Or maybe when I feel like adding it.\n\n");
			} */

			else if (option == 4)
			{
				help(frontend_logger);
				frontend_logger.just_print("\n");
			}

			/* else if (option == 6)
			{
				// frontend_logger.dump_log(stdout);
			} */

			else if (option == 5)
			{
				running = false;
			}
		}

		return 0;
	}

	else if(argc > 0)
	{
		logger terminal_logger(loglevel_t::everything, "ccalc-terminal.log");

		double num1 = atof(argv[2]);
		double num2 = atof(argv[3]);

		if((strcmp(argv[1], "--add") == 0) || (strcmp(argv[1], "-a") == 0))
		{
			std::cout << "Answer: " << add(num1, num2) << std::endl;
			terminal_logger.log_value("Answer: ", add(num1, num2));
		}

		else if((strcmp(argv[1], "--subtract") == 0) || (strcmp(argv[1], "-s") == 0))
		{
			std::cout << "Answer: " << subtract(num1, num2) << std::endl;
			terminal_logger.log_value("Answer: ", subtract(num1, num2));
		}

		else if((strcmp(argv[1], "--multiply") == 0) || (strcmp(argv[1], "-m") == 0))
		{
			std::cout << "Answer: " << multiply(num1, num2) << std::endl;
			terminal_logger.log_value("Answer: ", multiply(num1, num2));
		}

		else if((strcmp(argv[1], "--divide") == 0) || (strcmp(argv[1], "-d") == 0))
		{
			std::cout << "Answer: " << divide(num1, num2) << std::endl;
			terminal_logger.log_value("Answer: ", divide(num1, num2));
		}

		else if((strcmp(argv[1], "--power") == 0) || (strcmp(argv[1], "-p") == 0))
		{
			std::cout << "Answer: " << power(num1, num2) << std::endl;
			terminal_logger.log_value("Answer: ", power(num1, num2));
		}

		else if((strcmp(argv[1], "--trapezoid") == 0))
		{
			trapezoid_t shape = Trapezoid(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}
		
		else if((strcmp(argv[1], "--rectangle") == 0))
		{
			rectangle_t shape = Rectangle(atof(argv[2]), atof(argv[3]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}
		
		else if((strcmp(argv[1], "--triangle") == 0))
		{
			triangle_t shape = Triangle(atof(argv[2]), atof(argv[3]));
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

		else if((strcmp(argv[1], "--cube")) == 0)
		{
			cube_t shape = Cube(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
			terminal_logger.log_value("Answer: ", shape.area);
		}

		else if((strcmp(argv[1], "--help") == 0))
		{
			help(terminal_logger);
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
