#include <iostream>
#include <cstring>
#include <csignal>

#include "libmath.hpp"
using namespace libmath;

sig_atomic_t signaled = 0;

void segfault_handle(int param)
{
	signaled = 1;
}

int main(int argc, const char* argv[])
{
	// set segmentation fault handler for cli errors
	void(*segfault_signal)(int) = signal(SIGSEGV, segfault_handle);

	// check if we got a signal
	if(signaled == 1) 
		return -1;

	// actual frontend
	if(argc == 1)
	{
		std::cout << "cCalc v3.0" << std::endl;
		std::cout << "(C) 2018 akachronix" << std::endl;

		std::cout << std::endl;

		bool running = true;
		while(running)
		{
			std::cout << "1) Arithmetic" << std::endl;
			std::cout << "2) Exponential" << std::endl;
			std::cout << "3) Geometry" << std::endl;
			std::cout << "4) Exit" << std::endl;

			std::cout << std::endl;

			int option;
			std::cin >> option;

			std::cout << std::endl;

			if(option == 1)
			{
				std::cout << "1) Add" << std::endl;
				std::cout << "2) Subtract" << std::endl;
				std::cout << "3) Multiply" << std::endl;
				std::cout << "4) Divide" << std::endl;

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
					std::cout << "[Error] Invalid input." << std::endl;
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
					std::cout << "[Error] Invalid input." << std::endl;
					break;
				}
				
				std::cout << std::endl;
			}
			
			else if(option == 3)
			{
				std::cout << "1) Trapezoid" << std::endl;
				std::cout << "2) Rectangle" << std::endl;
				std::cout << "3) Triangle" << std::endl;
				std::cout << "4) Circle" << std::endl;
				std::cout << "5) Square" << std::endl;
				
				std::cout << std::endl;
			
				std::cin >> option;
				
				std::cout << std::endl;
				
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
					
					std::cout << "Enter base: ";
					std::cin >> base;
					
					std::cout << "Enter height: ";
					std::cin >> height;
					
					std::cout << std::endl;
					
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
					std::cout << "[Error] Invalid input." << std::endl;
					break;
				}
				
				std::cout << "Area: " << area << std::endl;
				
				std::cout << std::endl;
			}

			else if(option == 4)
				running = false;
		}

		return 0;
	}

	else if(argc > 0)
	{
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

		else
		{
			std::cout << "[Error] Invalid command." << std::endl;
		}
	}

	return 0;
}
