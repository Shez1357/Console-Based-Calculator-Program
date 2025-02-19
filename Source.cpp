#include <iostream>//This allows input and output.
#include <string>	//Allows me to store a string.
#include <cctype>//Allows me to use functions such as toupper etc.
#include <fstream> //Allows me to store data into a file.
using namespace std;

//This handles the operation logic.
double add(double a, double b) {
	return a + b;
}

double subtract(double a, double b) {
	return a - b;
}

double divide(double a, double b) {
	return a / b;
}

double multiplication(double a, double b) {
	return a * b;
}


//Start of the program
int main() {
	while (true) {
		double Number1;
		double Number2;
		string choice;
		//Operation menu
		std::cout << "Calculator Program" << std::endl;
		std::cout << "Please choose what operation you would like to do." << std::endl;
		std::cout << "1.Add" << std::endl;
		std::cout << "2.Subtract" << std::endl;
		std::cout << "3.Multiplication" << std::endl;
		std::cout << "4.Divide" << std::endl;
		std::cin >> choice;
		//Prvents them for choosing any other option other than whats given to them.
		if (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
			system("cls");
			std::cout << "\033[1;031mPlease choose a valid option!\033[0m" << std::endl;
			continue;

		}
		bool valid = false;
		system("cls");
		//This prvents to the program from crashing.
		//This makes sure the user only inputs a int and not a string or speical character.
		do {
			std::cout << "What is your first number : ";
			std::cin >> Number1;

			if (!std::cin.fail()) {
				//Valid Integer
				valid = true;
			}
			else {
				//Invalid Integer
				system("cls");
				std::cout << "\033[1;31mPlease input a number!\033[0m" << std::endl;
				std::cin.clear();	
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (!valid);
		valid = false;

		do {
			std::cout << "What is your second number : ";
			std::cin >> Number2;

			if (!std::cin.fail()) {
				//Valid Integer
				valid = true;
			}
			else {
				//Invalid Integer
				std::cout << "\033[1;31mPlease input a number!\033[0m" << std::endl;
				std::cin.clear();
				std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (!valid);

		
		//This prevents the user from dividing by zero.
		if (choice == "4") {
			if (Number2 == 0) {
				system("cls");
				std::cout << "\033[1;31mDo not divide with 0! Try agin\033[0m" << std::endl;
				continue;
			}
		}

		double result;
		system("cls");
		//This brings everything together and stores the answer in result.
		if (choice == "1")
		{
			result = add(Number1, Number2);
			std::cout << Number1 << " + " << Number2 << " = " << result << std::endl;
		}
		else if (choice == "2") {
			result = subtract(Number1, Number2);
			std::cout << Number1<< " - " << Number2 << " = " << result<< std::endl;
		}
		else if (choice == "3") {
			result = multiplication(Number1, Number2);
			std::cout << Number1 << " * " << Number2 << " = " << result << std::endl;
		}
		else if (choice == "4") {
			result = divide(Number1, Number2);
			std::cout << Number1 << " / " << Number2 << " = " << result << std::endl;
		}
		else {
			std::cout << "Error.. Retry" << std::endl;
			continue;
		}
		//This stores the question and answer in a txt file.
		ofstream file ("Calculation.txt", ios::app);
		if (choice == "1") {
			file << Number1 << " + " << Number2 << " = " << result << std::endl;
		}

		else if (choice == "2") {
			file << Number1 <<" - " << Number2 << " = " << result << std::endl;
		}

		else if (choice == "3") {
			file << Number1 << " * " << Number2 << " = " << result << std::endl;
		}

		else if (choice == "4") {
			file << Number1 << " / " << Number2 << " = " << result << std::endl;
		}
		else if (!file.is_open())
		{
			std::cout << "\033[1;31mApolgies a file cannot be written at this moment please try again!\033[0m" << std::endl;
		}
		file.close();

		//This just asks the user if he wants to try again.
		bool LoopEndCheck = true;
		while (LoopEndCheck) {
			char choice2;
			std::cout << "Would you like to do another operation? (Y/N)" << std::endl;
			std::cin >> choice2;
			choice2 = toupper(choice2);

			if (choice2 == 'Y') {
				system("cls");
				break;
			}
			else if (choice2 == 'N') {
				return(0);
			}
			else {	
				system("cls");
				LoopEndCheck = true;
				std::cout << "\033[1;31mPlease enter a valid choice!\033[0m" << std::endl;
			}
		}

	}
}
