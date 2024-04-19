#include "StudentList.h"

StudentList::StudentList(std::string file) {
	Student student;
	std::string s;
	std::fstream in(file, std::ios::in);
	if (in.fail()) {
		std::cout << "Opening file failed!" << std::endl;
		return;
	}
	while (!in.eof()) {
		in >> s;
		std::stringstream ss(s);
		std::string word;
		std::getline(ss, word, ',');
		student.setStudentCode(word);
		std::getline(ss, word, ',');
		student.setCount(std::stoi(word));
		this->mp[student.getCount()].insert(student.getStudentCode());
	}
	in.close();
}

std::map<int, std::set<std::string>> StudentList::getMp() {
	return this->mp;
}

// Áp dụng hàm nghịch đảo tuyến tính để tăng xác suất cho các giá trị nhỏ hơn
double inverseLinear(double x, double min_val, double max_val) {
	return min_val + x * x * (max_val - min_val);
}

// Hàm random chuỗi từ một mảng các chuỗi
std::string randomString(const std::set<std::string>& se) {
	std::vector<std::string> v(se.begin(), se.end());
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, v.size() - 1);
	int random_index = dis(gen);
	return v[random_index];
}

void StudentList::randomStudent(std::string choice) {
	std::vector<double> v;
	if (choice == "1.1" || choice == "1.2") {
		int sum = 0;
		for (int i = 0; i < this->mp.size(); i++) sum += (i + 1);
		double x = (double)100 / sum;
		int cnt = this->mp.size();
		for (int i = 0; i < this->mp.size(); i++) {
			if (i == 0) {
				v.push_back(x * cnt / 100);
			}
			else {
				v.push_back(v[i - 1] + (x * cnt / 100));
			}
			cnt--;
		}
	}
	else if (choice == "2.1" || choice == "2.2") {
		std::string s;
		std::fstream in("config.txt", std::ios::in);
		if (in.fail()) {
			std::cout << "Opening file failed!" << std::endl;
			return;
		}
		int count;
		std::string word;
		std::getline(in, word);
		while (!in.eof()) {
			in >> s;
			std::stringstream ss(s);
			std::getline(ss, word, ',');
			count = std::stoi(word);
			std::getline(ss, word, ',');
			v.push_back(std::stod(word));
		}
		in.close();
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dis(0.0, 1.0);
	double min_val = 0; // Giá trị nhỏ nhất trong dãy
	double max_val = 1; // Giá trị lớn nhất trong dãy
	double random_value = dis(gen);
	double random_number = inverseLinear(random_value, min_val, max_val);
	auto it_v = std::lower_bound(v.begin(), v.end(), random_number);
	Student s;
	int ans = 0;
	for (auto it : this->mp) {
		if (ans == it_v - v.begin()) {
			s.setStudentCode(randomString(it.second));
			s.setCount(it.first);
			break;
		}
		ans++;
	}
	std::cout << s.getStudentCode() << std::endl;
	this->mp[s.getCount()].erase(s.getStudentCode());
	if (this->mp[s.getCount()].empty()) {
		auto it = this->mp.find(s.getCount());
		this->mp.erase(it);
	}
	if (choice == "1.1" || choice == "2.1") {
		this->mp_new[s.getCount() + 1].insert(s.getStudentCode());
	}
	if (choice == "1.2" || choice == "2.2")	{
		this->mp[s.getCount() + 1].insert(s.getStudentCode());
	}
}

void StudentList::updateMpNew() {
	if (this->mp.empty()) return;
	for (auto it : mp) {
		for (auto x : it.second) {
			this->mp_new[it.first].insert(x);
		}
	}
}

std::map<int, std::set<std::string>> StudentList::getMpNew() {
	return this->mp_new;
}

void StudentList::updateFile(std::string file) {
	updateMpNew();
	std::fstream out(file, std::ios::out | std::ios::trunc);
	if (out.fail()) {
		std::cout << "Opening file failed!" << std::endl;
		return;
	}
	for (auto x : this->mp_new) {
		for (auto y : x.second) {
			out << y << "," << x.first << std::endl;
		}
	}
	out.close();
}