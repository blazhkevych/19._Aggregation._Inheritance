#include "Person.h"

// Конструкторы:
// Конструктор по умолчанию (обнуляет поля).
Person::Person() :m_name(nullptr), m_surname(nullptr), m_age(0) {}

// Конструктор с всеми параметрами (нужен для инициализации всех полей).
Person::Person(const char* name, const char* surname, int age)
{
	strcpy_s(m_name = new char[strlen(name) + 1], strlen(name) + 1, name);
	strcpy_s(m_surname = new char[strlen(surname) + 1], strlen(surname) + 1, surname);
	m_age = age;
}

// Конструктор копирования (нужен при наличии динамических полей в классе).
Person::Person(const Person& obj)
{
	/*int name_strlen = strlen(obj.m_name) + 1;
	m_name = new char[name_strlen];
	strcpy_s(m_name, name_strlen, obj.m_name);*/
	strcpy_s(m_name = new char[strlen(obj.m_name) + 1], strlen(obj.m_name) + 1, obj.m_name);

	/*int surname_strlen = strlen(obj.m_surname) + 1;
	m_surname = new char[surname_strlen];
	strcpy_s(m_surname, surname_strlen, obj.m_surname);*/
	strcpy_s(m_surname = new char[strlen(obj.m_surname) + 1], strlen(obj.m_surname) + 1, obj.m_surname);

	m_age = obj.m_age;
}

// Конструктор переноса (семантика переноса с использованием r-value ссылок).
Person::Person(Person&& obj)
{
	m_name = obj.m_name;
	obj.m_name = nullptr;

	m_surname = obj.m_surname;
	obj.m_surname = nullptr;

	m_age = obj.m_age;
	obj.m_age = 0;
}

// Деструктор.
Person::~Person()
{
	delete[] m_name;
	delete[] m_surname;
}