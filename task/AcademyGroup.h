#pragma once
#include <ostream>

#include "Student.h"

class AcademyGroup
{
	Student** m_pSt;	// Группа студентов.
	int m_count;		// Количество студентов в группе.
public:
	// Конструкторы:
	// Конструктор по умолчанию (обнуляет поля). 
	AcademyGroup();
	// Конструктор копирования (нужен при наличии динамических полей в классе).
	//AcademyGroup(const AcademyGroup& obj);





	/*AcademyGroup(AcademyGroup&& obj);
	~AcademyGroup();*/



	// Добавление студентов в группу.
	void AddStudents();


	/*void DeleteStudent();
	void EditStudent();
	void Print();
	void FindStudent();
	void Sort();
	void Save();
	void Load();
	AcademyGroup& operator=(const AcademyGroup& obj);
	AcademyGroup& operator=(AcademyGroup&& obj);
	Student& operator[](int index);
	friend std::ostream& operator<<(std::ostream& os, AcademyGroup& obj);*/
};

// как было в программе библиотека. https://github.com/blazhkevych/41._Program_Library._Loading_and_saving_data