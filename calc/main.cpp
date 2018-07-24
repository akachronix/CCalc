#include <iostream>
#include <cstdlib>
#include <cstring>

#include "libmath.hpp"
using namespace libmath;

#include "liblog.hpp"

void help()
{
	std::cout << "Usage:" << std::endl;
	std::cout << "Arithmetic -" << std::endl;
	std::cout << "--add       | adds two numbers (two arguments)" << std::endl;
	std::cout << "--subtract  | subtracts two numbers (two arguments)" << std::endl;
	std::cout << "--multiply  | multiplies two numbers (two arguments)" << std::endl;
	std::cout << "--divide    | divides two numbers (two arguments)" << std::endl;
	std::cout << std::endl;
	std::cout << "Exponential -" << std::endl;
	std::cout << "--power     | puts x to the power of y (two arguments)" << std::endl;
	std::cout << std::endl;
	std::cout << "Geometry -" << std::endl;
	std::cout << "--trapezoid | finds the area of a trapezoid (three arguments) [base, 2nd base, height])" << std::endl;
	std::cout << "--rectangle | finds the area of a rectangle (two arguments)   [length, width]" << std::endl;
	std::cout << "--triangle  | finds the area of a triangle  (two arguments)   [base, height]" << std::endl;
	std::cout << "--circle    | finds the area of a circle    (one argument)    [radius]" << std::endl;
	std::cout << "--square    | finds the area of a square    (one argument)    [side]" << std::endl;
	std::cout << std::endl;
}

int main(int argc, const char* argv[])
{
	logger frontend_logger(loglevel_t::everything, "frontend.log");

	// actual frontend
	if(argc == 1)
	{
		frontend_logger.just_print("cCalc v3.0\n");
		frontend_logger.just_print("(C) 2018 akachronix\n");

		// std::cout << std::endl;
		frontend_logger.just_print("\n");

		bool running = true;
		
		while(running)
		{
			// std::cout << "1) Arithmetic" << std::endl;
			// std::cout << "2) Exponential" << std::endl;
			// std::cout << "3) Geometry" << std::endl;
			// std::cout << "4) Help" << std::endl;
			// std::cout << "5) Exit" << std::endl;
			//
			// std::cout << std::endl;

			frontend_logger.just_print("1) Arithmetic\n");
			frontend_logger.just_print("2) Exponential\n");
			frontend_logger.just_print("3) Geometry\n");
			frontend_logger.just_print("4) Interpreter\n");
			frontend_logger.just_print("5) Help\n");
			frontend_logger.just_print("6) Exit\n");

			frontend_logger.just_print("\n");

			int option;
			std::cin >> option;

			// std::cout << std::endl;
			frontend_logger.just_print("\n");

			if(option == 1)
			{
				// std::cout << "1) Add" << std::endl;
				// std::cout << "2) Subtract" << std::endl;
				// std::cout << "3) Multiply" << std::endl;
				// std::cout << "4) Divide" << std::endl;
				//
				// std::cout << std::endl;

				frontend_logger.just_print("1) Add\n");
				frontend_logger.just_print("2) Subtract\n");
				frontend_logger.just_print("3) Multiply\n");
				frontend_logger.just_print("4) Divide\n");

				frontend_logger.just_print("\n");

				std::cin >> option;

				// std::cout << std::endl;
				frontend_logger.just_print("\n");

				double num1, num2;

				// std::cout << "Enter first number: ";
				frontend_logger.just_print("Enter first number: ");

				std::cin >> num1;
				frontend_logger.log_value("", num1);

				// std::cout << "Enter second number: ";
				frontend_logger.just_print("Enter second number: ");

				std::cin >> num2;

				// std::cout << std::endl;
				frontend_logger.just_print("\n");

				switch(option)
				{
				case 1:
					std::cout << "Answer: " << add(num1, num2) << std::endl;
					break;

				case 2:
					std::cout << "Answer: " << subtract(num1, num2) << std::endl;
					break;

				case 3:
					std::cout << "Answer: " << multiply(num1, num2) << std::endl;
					break;

				case 4:
					std::cout << "Answer: " << divide(num1, num2) << std::endl;
					break;

				default:
					frontend_logger.log_error("Invalid input.");
					break;
				}

				std::cout << std::endl;
			}

			else if(option == 2)
			{
				std::cout << "1) Power" << std::endl;

				std::cout << std::endl;

				std::cin >> option;

				std::cout << std::endl;

				double num1, num2;

				std::cout << "Enter first number: ";
				std::cin >> num1;

				std::cout << "Enter second number: ";
				std::cin >> num2;

				std::cout << std::endl;

				switch(option)
				{
				case 1:
					std::cout << "Answer: " << power(num1, num2) << std::endl;
					break;

				default:
					frontend_logger.log_error("Invalid input.");
					break;
				}

				std::cout << std::endl;
			}

			else if(option == 3)
			{
				// std::cout << "1) Trapezoid" << std::endl;
				// std::cout << "2) Rectangle" << std::endl;
				// std::cout << "3) Triangle" << std::endl;
				// std::cout << "4) Circle" << std::endl;
				// std::cout << "5) Square" << std::endl;
				//
				// std::cout << std::endl;
				
				frontend_logger.just_print("1) Trapezoid");
				frontend_logger.just_print("2) Rectangle");
				frontend_logger.just_print("3) Triangle");
				frontend_logger.just_print("4) Circle");
				frontend_logger.just_print("5) Square");

				frontend_logger.just_print("\n");

				std::cin >> option;
				// frontend_logger.log("Option: " + (std::string)option);

				// std::cout << std::endl;

				frontend_logger.just_print("\n");

				double area;

				switch(option)
				{
				case 1:
				{
					double base, base2, height;

					std::cout << "Enter base: ";
					std::cin >> base;

					std::cout << "Enter base 2: ";
					std::cin >> base2;

					std::cout << "Enter height: ";
					std::cin >> height;

					std::cout << std::endl;

					trapezoid_t shape = Trapezoid(base, base2, height);
					area = shape.area;
					
					break;
				}
				
				case 2:
				{
					double length, width;
					
					std::cout << "Enter length: ";
					std::cin >> length;
					
					std::cout << "Enter width: ";
					std::cin >> width;
					
					std::cout << std::endl;
					
					rectangle_t shape = Rectangle(length, width);
					area = shape.area;
					
					break;
				}
				
				case 3:
				{
					double base, height;
					
					frontend_logger.just_print("Enter base: ");
					std::cin >> base;
					
					frontend_logger.just_print("Enter height: ")
					std::cin >> height;
					
					frontend_logger.just_print("\n");
					
					triangle_t shape = Triangle(base, height);
					area = shape.area;
					
					break;
				}
				
				case 4:
				{
					double radius;

					std::cout << "Enter radius: ";
					std::cin >> radius;

					std::cout << std::endl;

					circle_t shape = Circle(radius);
					area = shape.area;

					break;
				}

				case 5:
				{
					double side;

					std::cout << "Enter side: ";
					std::cin >> side;

					std::cout << std::endl;

					square_t shape = Square(side);
					area = shape.area;
					
					break;
				}

				default:
					frontend_logger.log_error("Invalid input.");
					break;
				}
				
				std::cout << "Area: " << area << std::endl;
				
				frontend_logger.just_print("\n";)
			}

			else if(option == 4)
			{
				// Interpreter mode is planned here. Pending reconstruction of codebase.
				frontend_logger.just_print("Interpreter mode is planned here. Pending reconstruction of codebase.\n\n");
			}

			else if(option == 5)
			{
				help();
			}

			else if(option == 6)
			{
				running = false;
			}
		}

		return 0;
	}

	else if(argc > 0)
	{
		logger terminal_logger(loglevel_t::everything, "terminal.log");

		if(argc <= 2)
		{
			terminal_logger.log_error("Invalid command.");
			help();

			return -1;
		}

		double num1 = atof(argv[2]);
		double num2 = atof(argv[3]);

		if((strcmp(argv[1], "--add") == 0) || (strcmp(argv[1], "-a") == 0))
		{
			std::cout << "Answer: " << add(num1, num2) << std::endl;
		}

		else if((strcmp(argv[1], "--subtract") == 0) || (strcmp(argv[1], "-s") == 0))
		{
			std::cout << "Answer: " << subtract(num1, num2) << std::endl;
		}

		else if((strcmp(argv[1], "--multiply") == 0) || (strcmp(argv[1], "-m") == 0))
		{
			std::cout << "Answer: " << multiply(num1, num2) << std::endl;
		}

		else if((strcmp(argv[1], "--divide") == 0) || (strcmp(argv[1], "-d") == 0))
		{
			std::cout << "Answer: " << divide(num1, num2) << std::endl;
		}

		else if((strcmp(argv[1], "--power") == 0) || (strcmp(argv[1], "-p") == 0))
		{
			std::cout << "Answer: " << power(num1, num2) << std::endl;
		}

		else if((strcmp(argv[1], "--trapezoid") == 0))
		{
			trapezoid_t shape = Trapezoid(atof(argv[2]), atof(argv[3]), atof(argv[4]));
			std::cout << "Answer: " << shape.area << std::endl;
		}
		
		else if((strcmp(argv[1], "--rectangle") == 0))
		{
			rectangle_t shape = Rectangle(atof(argv[2]), atof(argv[3]));
			std::cout << "Answer: " << shape.area << std::endl;
		}
		
		else if((strcmp(argv[1], "--triangle") == 0))
		{
			triangle_t shape = Triangle(atof(argv[2]), atof(argv[3]));
			std::cout << "Answer: " << shape.area << std::endl;
		}

		else if((strcmp(argv[1], "--circle")) == 0)
		{
			circle_t shape = Circle(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
		}

		else if((strcmp(argv[1], "--square")) == 0)
		{
			square_t shape = Square(atof(argv[2]));
			std::cout << "Answer: " << shape.area << std::endl;
		}

		else if((strcmp(argv[1], "--help") == 0))
		{
			help();
		}

		else
		{
			terminal_logger.log_error("Invalid command.");
			help();

			return -1;
		}
	}

	return 0;
}
