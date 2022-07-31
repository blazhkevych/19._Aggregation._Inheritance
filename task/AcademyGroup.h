#pragma once
#include <ostream>

#include "Student.h"

class AcademyGroup
{
	Student** m_pSt;
	int m_count;
public:
	AcademyGroup();
	AcademyGroup(const AcademyGroup& obj);
	AcademyGroup(AcademyGroup&& obj);
	~AcademyGroup();
	void AddStudents();
	void DeleteStudent();
	void EditStudent();
	void Print();
	void FindStudent();
	void Sort();
	void Save();
	void Load();
	AcademyGroup& operator=(const AcademyGroup& obj);
	AcademyGroup& operator=(AcademyGroup&& obj);
	Student& operator[](int index);
	friend std::ostream& operator<<(std::ostream& os, AcademyGroup& obj);
};