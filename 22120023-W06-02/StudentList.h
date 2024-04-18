#pragma once
#ifndef _StudentList_h
#define _StudentList_h

#include "Student.h"

class StudentList {
private:
	std::map<int, std::set<std::string>> mp;
	std::map<int, std::set<std::string>> mp_new;
public:
	StudentList(std::string file);
	std::map<int, std::set<std::string>> getMp();
	void randomStudent();
	void updateMpNew();
	std::map<int, std::set<std::string>> getMpNew();
	void updateFile(std::string file);
};
#endif // !_StudentList_h