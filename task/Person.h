#pragma once
#include <istream>
#include <ostream>
using std::istream;
using std::ostream;

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

	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей).
	// Получить имя.
	const char* getName()const { return m_name; }
	// Получить фамилию.
	const char* getSurname()const { return m_surname; }
	// Получить возраст.
	int getAge() const { return m_age; }

	// Модификаторы (позволяют установить значения полей).
	// Установить имя.
	void setName(const char* name);
	// Установить фамилию.
	void setSurname(const char* surname);
	// Установить возраст.
	void setAge(int age);

	// Вывод объекта person на экран. 
	void Print()const;

	// Оператор присваивания копированием.
	Person& operator=(const Person& obj);

	// Оператор присваивания перемещением.
	Person& operator=(Person&& obj);

	// Ввод объекта person.
	friend  istream& operator>>(istream& is, Person& obj);

	// Вывод объекта person.
	friend  ostream& operator<<(ostream& os, const Person& obj);
};

// Ввод объекта person.
istream& operator>>(istream& is, Person& obj);

// Вывод объекта person.
ostream& operator<<(ostream& os, const Person& obj);