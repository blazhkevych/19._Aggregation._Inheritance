#include "AcademyGroup.h"

#include <iostream>
using std::cin;
using std::endl;
using std::cout;

// Конструкторы:
// Конструктор по умолчанию (обнуляет поля). 
AcademyGroup::AcademyGroup() : m_pSt(nullptr), m_count(0) {}

// Конструктор копирования (нужен при наличии динамических полей в классе).
//AcademyGroup::AcademyGroup(const AcademyGroup& obj)
//{
//
//}

// Деструктор.
AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < m_count; i++)
	{
		delete[] * (m_pSt + i);
	}
	delete[] m_pSt;
}

// Добавление студентов в группу.
void AcademyGroup::AddStudents()
{
	// как в проекте библиотека
	int studCount;
	do
	{
		cout << "\nВведите количество студентов для добавления в список: ";
		cin >> studCount;
		cin.get();
	} while (studCount <= 0);

	Student** newGroup = new Student * [m_count + studCount];
	for (int i = 0; i < m_count; i++)
		newGroup[i] = m_pSt[i];

	delete[] m_pSt;

	int inputNumOfStud{ 1 };
	for (int i = m_count; i < m_count + studCount; i++) // TODO: протестировать.
	{
		cout << "\nВведите данные " << inputNumOfStud << " студента: ";
		inputNumOfStud++;

		cout << "\nВведите имя студента: ";
		char name[100];
		cin.getline(name, 100);
		//newGroup[i]->setName(name);

		cout << "Введите фамилию студента: ";
		char surname[100];
		cin.getline(surname, 100);
		//newGroup[i]->setSurname(surname);

		cout << "Введите возраст студента: ";
		int age{ 0 };
		cin >> age;
		cin.get();
		//newGroup[i]->setAge(age);

		cout << "Введите телефон студента: ";
		char phone[100];
		cin.getline(phone, 100);
		//newGroup[i]->setPhone(phone);

		cout << "Введите средний балл студента: ";
		double avg{ 0 };
		cin >> avg;
		cin.get();
		//newGroup[i]->setRating(avg);

		newGroup[i] = new Student(name, surname, age, phone, avg);
	}

	m_pSt = newGroup;
	m_count += studCount;

	cout << "Добавлено !" << endl;
}
