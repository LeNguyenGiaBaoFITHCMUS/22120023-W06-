#include "Student.h"
#include "StudentList.h"

int main() {
	StudentList sl("Text.csv");
	bool ok = true;
	std::string s;
	while (ok && !sl.getMp().empty()) {
		std::cout << "The lucky students selected are: ";
		sl.randomStudent();
		std::cout << "Press Enter to continue program or type 'exit' to stop." << std::endl;
		std::getline(std::cin, s);
		if (s == "exit") ok = false;
		else ok = true;
		system("cls");
	}
	if (sl.getMp().empty()) std::cout << "All the students got to speak! End of class!" << std::endl;
	else std::cout << "End of class!" << std::endl;
	sl.updateFile("Text.csv");
	return 0;
}