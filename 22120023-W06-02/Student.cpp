#include "Student.h"

std::istream& operator >> (std::istream& in, Student& s) {
	in >> s.student_code >> s.count;
	return in;
}

Student::Student() {
	this->student_code = "";
	this->count = 0;
}

std::string Student::getStudentCode() {
	return this->student_code;
}

int Student::getCount() {
	return this->count;
}

void Student::setStudentCode(std::string student_code) {
	this->student_code = student_code;
}

void Student::setCount(int count) {
	this->count = count;
}