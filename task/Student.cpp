#include "Student.h"

#include <iomanip>
#include <iostream>
using std::cout;
using std::setw;
using std::endl;

// Конструктор по умолчанию (обнуляет поля).
Student::Student() :Person(), m_phone{ '\0' }, m_rating(0.0){}

// Конструктор с всеми параметрами (нужен для инициализации всех полей).
Student::Student(const char* name, const char* surname, int age, const char* phone, double rating)
	:Person(name, surname, age)
{
	strcpy_s(m_phone, strlen(phone) + 1, phone);
	m_rating = rating;
}

// Конструктор копирования (нужен при наличии динамических полей в классе).
Student::Student(const Student& obj) :Person(obj)
{
	strcpy_s(m_phone, strlen(obj.m_phone) + 1, obj.m_phone);
	m_rating = obj.m_rating;
}

// Конструктор переноса (семантика переноса с использованием r-value ссылок).
Student::Student(Student&& obj) :Person(obj)
{
	strcpy_s(m_phone, strlen(obj.m_phone) + 1, obj.m_phone);
	obj.m_phone[0] = { '\0' };

	m_rating = obj.m_rating;
	obj.m_rating = 0.0;
}

// Установить телефон.
void Student::setPhone(const char* phone)
{
	strcpy_s(m_phone, strlen(phone) + 1, phone);
}

// Установить средний балл.
void Student::setRating(double average)
{
	m_rating = average;
}

// Вывод объекта Student на экран. 
void Student::Print() const
{
	Person::Print();
	cout << setw(15) << m_phone << '|' << setw(15) << m_rating << '|' << endl
		<< " -------------------------------------------------------------------------------" << endl;
}

// Оператор присваивания копированием.
Student& Student::operator=(const Student& obj)
{
	if (this == &obj)
		return *this;

	Person::operator=(obj);

	m_phone[0] = { '\0' };
	m_rating = 0.0;

	strcpy_s(m_phone, strlen(obj.m_phone) + 1, obj.m_phone);
	m_rating = obj.m_rating;

	return *this;
}
