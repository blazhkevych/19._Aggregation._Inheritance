#include "Person.h"

#include <iomanip>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

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
	strcpy_s(m_name = new char[strlen(obj.m_name) + 1], strlen(obj.m_name) + 1, obj.m_name);
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

// Установить имя.
void Person::setName(const char* name)
{
	delete[] m_name;
	//int с = strlen(name) + 1;
	//int с2 = sizeof(*name) + 1;
	//int с3 = sizeof(name) + 1;
	strcpy_s(m_name = new char[strlen(name) + 1], strlen(name) + 1, name);
}

// Установить фамилию.
void Person::setSurname(const char* surname)
{
	delete[] m_surname;
	strcpy_s(m_surname = new char[strlen(surname) + 1], strlen(surname) + 1, surname);
}

// Установить возраст.
void Person::setAge(int age)
{
	m_age = age;
}

// Вывод объекта person на экран. 
void Person::Print() const
{
	cout << " -------------------------------------------------------------------------------" << endl
		<< '|' << setw(15) << m_surname << '|' << setw(15) << m_name << '|' << setw(15) << m_age << '|';
}

// Оператор присваивания копированием.
Person& Person::operator=(const Person& obj)
{
	if (this == &obj)
		return *this;

	delete[]m_name;
	delete[]m_surname;
	m_age = 0;

	strcpy_s(m_name = new char[strlen(obj.m_name) + 1], strlen(obj.m_name) + 1, obj.m_name);
	strcpy_s(m_surname = new char[strlen(obj.m_surname) + 1], strlen(obj.m_surname) + 1, obj.m_surname);
	m_age = obj.m_age;

	return *this;
}

// Оператор присваивания перемещением.
Person& Person::operator=(Person&& obj)
{
	if (this == &obj)
		return *this;

	delete[]m_name;
	delete[]m_surname;
	m_age = 0;

	m_name = obj.m_name;
	m_surname = obj.m_surname;
	m_age = obj.m_age;

	obj.m_name = nullptr;
	obj.m_surname = nullptr;
	obj.m_age = 0;

	return *this;
}

// Ввод объекта person.
istream& operator>>(istream& is, Person& obj)
{
	cout << "Введите имя персоны: ";
	char name[100];
	cin.getline(name, 100);
	obj.setName(name);

	cout << "Введите фамилию персоны: ";
	char surname[100];
	cin.getline(surname, 100);
	obj.setSurname(surname);

	cout << "Введите возраст персоны: ";
	int age{ 0 };
	cin >> age;
	obj.setAge(age);
	cin.get();

	return is;
}

// Вывод объекта person.
ostream& operator<<(ostream& os, const Person& obj)
{
	cout << endl;
	obj.Print();

	return os;
}