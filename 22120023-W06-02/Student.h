#pragma once
#ifndef _Student_h
#define _Student_h

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <random>
#include <sstream>

class Student {
private:
	std::string student_code;
	int count;
public:
	friend std::istream& operator >> (std::istream& in, Student& s);
	Student();
	std::string getStudentCode();
	int getCount();
	void setStudentCode(std::string student_code);
	void setCount(int count);
};
#endif // !_Student_h