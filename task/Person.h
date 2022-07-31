#pragma once
#include <ostream>

class Person
{
protected:
	char* m_name;		// Имя.
	char* m_surname;	// Фамилия.
	int m_age;			// Возраст.
public:
	// Конструкторы:
	// Конструктор по умолчанию (обнуляет поля).
	Person();
	// Конструктор с всеми параметрами (нужен для инициализации всех полей).
	Person(const char* name, const char* surname, int age);
	// Конструктор копирования (нужен при наличии динамических полей в классе).
	Person(const Person& obj);
	// Конструктор переноса (семантика переноса с использованием r-value ссылок).
	Person(Person&& obj);



	// Деструктор
	~Person();



	const char* getName()const;
	const char* getSurname()const;
	int getAge() const;
	void setName(const char* name);
	void setSurname(const char* surname);
	void setAge(int age);
	void Print()const;
	Person& operator=(const Person& obj);
	Person& operator=(Person&& obj);
	friend std::istream& operator>>(std::istream& is, Person& obj);
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
};