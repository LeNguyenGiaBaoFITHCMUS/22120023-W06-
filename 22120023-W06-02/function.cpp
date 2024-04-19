#include "Student.h"
#include "StudentList.h"

void menu1() {
	std::cout << "REQUIREMENT 1:\n";
	std::cout << "* Type '1': Use source code\n";
	std::cout << "* Type '2': Use file config.txt\n";
	std::cout << "* Type 'exit': stop\n";
	std::cout << "Type selection: ";
}

void menu2() {
	std::cout << "REQUIREMENT 2:\n";
	std::cout << "* Type '1': Each student can only call up to 1 time in 1 class session\n";
	std::cout << "* Type '2': Each student can be called multiple times\n";
	std::cout << "* Type 'return': return to REQUIREMENT 1\n";
	std::cout << "* Type 'exit': stop\n";
	std::cout << "Type selection: ";
}

void executeRandom(StudentList& sl, std::string choice) {
	system("cls");
	bool ok = true;
	std::string s;
	while (ok && !sl.getMp().empty()) {
		std::cout << "The lucky student selected is: ";
		sl.randomStudent(choice);
		std::cout << "Press Enter to continue program or type 'exit' to stop." << std::endl;
		std::getline(std::cin, s);
		if (s == "exit") ok = false;
		else ok = true;
		system("cls");
	}
	system("cls");
	if (sl.getMp().empty()) std::cout << "All the students got to speak! End of class!" << std::endl;
	else std::cout << "End of class!" << std::endl;
	sl.updateFile("Text.csv");
	//Cap nhat file config.txt
	std::vector<double> v;
	int sum = 0;
	for (int i = 0; i < sl.getMpNew().size(); i++) sum += (i + 1);
	double x = (double)100 / sum;
	int cnt = sl.getMpNew().size();
	for (int i = 0; i < sl.getMpNew().size(); i++) {
		if (i == 0) {
			v.push_back(x * cnt / 100);
		}
		else {
			v.push_back(v[i - 1] + (x * cnt / 100));
		}
		cnt--;
	}
	std::fstream out("config.txt", std::ios::out | std::ios::trunc);
	out << "SoLanPhatBieu,HeSoTiLe\n";
	int i = 0;
	for (auto x : sl.getMpNew()) {
		out << x.first << "," << std::fixed << std::setprecision(4) << v[i++] << std::endl;
	}
}