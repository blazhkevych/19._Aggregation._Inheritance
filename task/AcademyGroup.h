#pragma once
#include "Student.h"

#include <ostream>

class AcademyGroup
{
	Student** m_pSt;	// Группа студентов.
	int m_count;		// Количество студентов в группе.
public:
	// Конструкторы:
	// Конструктор по умолчанию (обнуляет поля). 
	AcademyGroup();
	// Конструктор копирования (нужен при наличии динамических полей в классе).
	AcademyGroup(const AcademyGroup& obj);
	// Конструктор переноса.
	AcademyGroup(AcademyGroup&& obj);

	// Деструктор.
	~AcademyGroup();

	// Добавление студентов в группу.
	void AddStudents();

	// Удаление студента.
	void DeleteStudent();

	// Модификация данных студента.
	void EditStudent();

	// Печать академической группы.
	void Print();

	// Поиск студента по заданному критерию.
	void FindStudent();

	// Сортировка списка студентов.
	void Sort();

	// Сохранение списка студентов в файл(при завершении работы программы).
	void Save();

	// Загрузка списка студентов из файла (при старте программы).
	void Load();

	// Присваивание копированием.
	AcademyGroup& operator=(const AcademyGroup& obj);

	// Присваивание перемещением.
	AcademyGroup& operator=(AcademyGroup&& obj);

	// Получить по индексу конкретного студента группы.
	Student& operator[](int index);

	// Печать группы.
	friend ostream& operator<<(ostream& os, AcademyGroup& obj);
};

// Печать группы.
ostream& operator<<(ostream& os, AcademyGroup& obj);