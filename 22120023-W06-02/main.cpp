#include "Student.h"
#include "StudentList.h"

int main() {
	StudentList sl("Text.csv");
	bool ok = true;
	std::string option;
	std::string option2;
	while (ok) {
		menu1();
		while (!(std::getline(std::cin, option)) || (option != "1" && option != "2" && option != "exit")) {
			std::cin.clear();
			//std::cin.ignore(1000, '\n');
			std::cout << "Invalid input. Please re-enter: ";
		}
		system("cls");
		if (option == "1") {
			menu2();
			while (!(std::getline(std::cin, option2)) || (option2 != "1" && option2 != "2" && option2 != "return" && option2 != "exit")) {
				std::cin.clear();
				//std::cin.ignore(1000, '\n');
				std::cout << "Invalid input. Please re-enter: ";
			}
			if (option2 == "1") {
				executeRandom(sl, "1.1");
				ok = false;
			}
			else if (option2 == "2") {
				executeRandom(sl, "1.2");
				ok = false;
			}
			else if (option2 == "return") {
				system("cls");
			}
			else if (option2 == "exit") {
				ok = false;
			}
		}
		else if (option == "2") {
			menu2();
			while (!(std::getline(std::cin, option2)) || (option2 != "1" && option2 != "2" && option2 != "return" && option2 != "exit")) {
				std::cin.clear();
				//std::cin.ignore(1000, '\n');
				std::cout << "Invalid input. Please re-enter: ";
			}
			if (option2 == "1") {
				executeRandom(sl, "2.1");
				ok = false;
			}
			else if (option2 == "2") {
				executeRandom(sl, "2.2");
				ok = false;
			}
			else if (option2 == "return") {
				system("cls");
			}
			else if (option2 == "exit") {
				ok = false;
			}
		}
		else if (option == "exit") {
			ok = false;
		}		
	}
	return 0;
}