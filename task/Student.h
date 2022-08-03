#pragma once
#include "Person.h"

class Student : public Person
{
	char m_phone[14];	// Телефон.
	double m_rating;	// Средний балл.
public:
	// Конструкторы:
	// Конструктор по умолчанию (обнуляет поля).
	Student();
	// Конструктор с всеми параметрами (нужен для инициализации всех полей).
	Student(const char* name, const char* surname, int age, const char* phone, double rating);
	// Конструктор копирования (нужен при наличии динамических полей в классе).
	Student(const Student& obj);
	// Конструктор переноса (семантика переноса с использованием r-value ссылок).
	Student(Student&& obj);

	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей).
	// Получить средний балл.
	double getRating() const { return m_rating; }
	// Получить телефон.
	const char* getPhone() const { return m_phone; }

	// Модификаторы (позволяют установить значения полей).
	// Установить имя.
	// Установить телефон.
	void setPhone(const char* phone);
	// Установить средний балл.
	void setRating(double average);

	// Вывод объекта Student на экран. 
	void Print() const;

	// Оператор присваивания копированием.
	Student& operator=(const Student& obj);

	// Оператор присваивания перемещением.
	Student& operator=(Student&& obj);

	// Ввод объекта Student.
	friend istream& operator>>(istream& is, Student& obj);

	// Вывод объекта Student.
	friend ostream& operator<<(ostream& os, const Student& obj);
};

// Ввод объекта Student.
istream& operator>>(istream& is, Student& obj);

// Вывод объекта Student.
ostream& operator<<(ostream& os, const Student& obj);