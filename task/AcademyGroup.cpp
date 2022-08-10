#include "AcademyGroup.h"

#include <conio.h>
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

// Конструкторы:
// Конструктор по умолчанию (обнуляет поля). 
AcademyGroup::AcademyGroup() : m_pSt(nullptr), m_count(0) {}

// Конструктор копирования (нужен при наличии динамических полей в классе).
AcademyGroup::AcademyGroup(const AcademyGroup& obj)
{
	m_pSt = new Student * [obj.m_count];
	for (int i = 0; i < obj.m_count; i++)
		m_pSt[i] = new Student;

	for (int i = 0; i < obj.m_count; i++)
		*m_pSt[i] = *obj.m_pSt[i];
}

// Конструктор переноса.
AcademyGroup::AcademyGroup(AcademyGroup&& obj)
{
	m_pSt = obj.m_pSt;
	obj.m_pSt = nullptr;
}

// Деструктор.
AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < m_count; i++)
	{
		delete* (m_pSt + i);
	}
	delete[] m_pSt;
}

// Добавление студентов в группу.
void AcademyGroup::AddStudents()
{
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
	for (int i = m_count; i < m_count + studCount; i++)
	{
		cout << "\nВведите данные " << inputNumOfStud << " студента: ";
		inputNumOfStud++;

		cout << "\nИмя: ";
		char name[100];
		cin.getline(name, 100);

		cout << "Фамилия: ";
		char surname[100];
		cin.getline(surname, 100);

		cout << "Возраст: ";
		int age{ 0 };
		cin >> age;
		cin.get();

		cout << "Телефон: ";
		char phone[100];
		cin.getline(phone, 100);

		cout << "Средний балл: ";
		double avg{ 0 };
		cin >> avg;
		cin.get();

		newGroup[i] = new Student(name, surname, age, phone, avg);
	}

	m_pSt = newGroup;
	m_count += studCount;
}

// Удаление студента.
void AcademyGroup::DeleteStudent()
{
	// TODO: возможно добавить вывод списка перед вводом данных удаляемого студента.
	char name[50]{};
	char surname[50]{};

	cout << "Введите имя студента: ";
	cin.getline(name, 50);

	cout << "Введите фамилию студента: ";
	cin.getline(surname, 50);

	for (int i = 0; i < m_count; i++)
	{
		if (!strcmp(name, m_pSt[i]->getName()) && !strcmp(surname, m_pSt[i]->getSurname()))
		{
			delete m_pSt[i];
			for (int j = i; j < m_count - 1; j++)
				m_pSt[j] = m_pSt[j + 1];
			m_pSt[--m_count] = nullptr;
			return;
		}
	}
	cout << "Студент не найден!";
}

// Модификация данных студента.
void AcademyGroup::EditStudent()
{
	// TODO: возможно добавить вывод списка перед вводом данных редактируемого студента.
	char search_name[50]{};
	char search_surname[50]{};

	cout << "\nВведите данные студента, которого будем модифицировать. " << endl;
	cout << "Имя: ";
	cin.getline(search_name, 50);

	cout << "Фамилия: ";
	cin.getline(search_surname, 50);

	for (int i = 0; i < m_count; i++)
	{
		if (!strcmp(search_name, m_pSt[i]->getName()) && !strcmp(search_surname, m_pSt[i]->getSurname()))
		{
			cout << "\nВведите новые данные для этого студента: ";

			cout << "\nИмя: ";
			char name[100];
			cin.getline(name, 100);
			m_pSt[i]->setName(name);

			cout << "Фамилия: ";
			char surname[100];
			cin.getline(surname, 100);
			m_pSt[i]->setSurname(surname);

			cout << "Возраст: ";
			int age{ 0 };
			cin >> age;
			cin.get();
			m_pSt[i]->setAge(age);

			cout << "Телефон: ";
			char phone[100];
			cin.getline(phone, 100);
			m_pSt[i]->setPhone(phone);

			cout << "Средний балл: ";
			double avg{ 0 };
			cin >> avg;
			cin.get();
			m_pSt[i]->setRating(avg);

			return;
		}
	}
	cout << "Студент не найден!";
}

// Печать академической группы.
void AcademyGroup::Print()
{
	for (int i = 0; i < m_count; i++)
	{
		if (i == 0)
			cout << " -------------------------------------------------------------------------------" << endl;
		m_pSt[i]->Print();
		cout << " -------------------------------------------------------------------------------" << endl;
	}
}

// Поиск студента по заданному критерию.
void AcademyGroup::FindStudent()
{
	cout << "\n1. Имя." << endl
		<< "2. Фамилия." << endl
		<< "3. Возраст." << endl
		<< "4. Телефон." << endl
		<< "5. Средний балл." << endl;

	cout << "\nВыберите критерий для поиска студента: ";
	char criteriaChoice;
	cin >> criteriaChoice;
	cin.get();

	char enteredData[50]{ '\0' };
	bool firstElementFound{ true };
	int enteredAge{ 0 };
	int findCounter{ 0 };
	double enteredAvg{ 0.0 };

	cout << endl;
	switch (criteriaChoice)
	{
	case '1':													// Поиск по имени.
		cout << "Введите имя: ";
		cin.getline(enteredData, 50);
		for (int i = 0; i < m_count; i++)
		{
			if (!strcmp(enteredData, m_pSt[i]->getName()))
			{
				findCounter++;
				if (firstElementFound == true)
				{
					cout << endl << " -------------------------------------------------------------------------------" << endl;
					firstElementFound = false;
				}
				m_pSt[i]->Print();
				cout << " -------------------------------------------------------------------------------" << endl;
			}
		}
		if (findCounter > 0)
		{
			cout << endl << "Найдено " << findCounter << " студентов." << endl;
		}
		else
			cout << endl << "Ничего не найдено!" << endl;
		firstElementFound = true;
		break;

	case '2':													// Поиск по фамилии.
		cout << "Введите фамилию: ";
		cin.getline(enteredData, 50);
		for (int i = 0; i < m_count; i++)
		{
			if (!strcmp(enteredData, m_pSt[i]->getSurname()))
			{
				findCounter++;
				if (firstElementFound == true)
				{
					cout << endl << " -------------------------------------------------------------------------------" << endl;
					firstElementFound = false;
				}
				m_pSt[i]->Print();
				cout << " -------------------------------------------------------------------------------" << endl;
			}
		}
		if (findCounter > 0)
		{
			cout << endl << "Найдено " << findCounter << " студентов." << endl;
		}
		else
			cout << endl << "Ничего не найдено!" << endl;
		firstElementFound = true;
		break;
	case '3':													// Поиск по возрасту.
		cout << "Введите возраст: ";
		cin >> enteredAge;
		for (int i = 0; i < m_count; i++)
		{
			if (enteredAge == m_pSt[i]->getAge())
			{
				findCounter++;
				if (firstElementFound == true)
				{
					cout << endl << " -------------------------------------------------------------------------------" << endl;
					firstElementFound = false;
				}
				m_pSt[i]->Print();
				cout << " -------------------------------------------------------------------------------" << endl;
			}
		}
		if (findCounter > 0)
		{
			cout << endl << "Найдено " << findCounter << " студентов." << endl;
		}
		else
			cout << endl << "Ничего не найдено!" << endl;
		firstElementFound = true;
		break;
	case '4':													// Поиск по телефону.
		cout << "Введите телефон: ";
		cin.getline(enteredData, 50);
		for (int i = 0; i < m_count; i++)
		{
			if (!strcmp(enteredData, m_pSt[i]->getPhone()))
			{
				findCounter++;
				if (firstElementFound == true)
				{
					cout << endl << " -------------------------------------------------------------------------------" << endl;
					firstElementFound = false;
				}
				m_pSt[i]->Print();
				cout << " -------------------------------------------------------------------------------" << endl;
			}
		}
		if (findCounter > 0)
		{
			cout << endl << "Найдено " << findCounter << " студентов." << endl;
		}
		else
			cout << endl << "Ничего не найдено!" << endl;
		firstElementFound = true;
		break;
	case '5':													// Поиск по среднему баллу.
		cout << "Введите средний балл: ";
		cin >> enteredAvg;
		for (int i = 0; i < m_count; i++)
		{
			if (enteredAvg == m_pSt[i]->getRating()) // TODO: возможны проблемы со сравнение, возможно нужно округлить сравниваемые переменные.
			{
				findCounter++;
				if (firstElementFound == true)
				{
					cout << endl << " -------------------------------------------------------------------------------" << endl;
					firstElementFound = false;
				}
				m_pSt[i]->Print();
				cout << " -------------------------------------------------------------------------------" << endl;
			}
		}
		if (findCounter > 0)
		{
			cout << endl << "Найдено " << findCounter << " студентов." << endl;
		}
		else
			cout << endl << "Ничего не найдено!" << endl;
		firstElementFound = true;
		break;

	default:
		system("cls");
		cout << "\nПопробуйте еще раз !" << endl;
		cout << "\nДля продолжения нажмите любую клавишу." << endl;
		_getch();
		break;
	}
}

// Сортировка списка студентов.
void AcademyGroup::Sort()
{
	for (int startIndex = 0; startIndex < m_count; ++startIndex)
	{
		int biggerIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < m_count; ++currentIndex)
		{
			if (strcmp(m_pSt[currentIndex]->getSurname(), m_pSt[biggerIndex]->getSurname()) < 0) // Сортировка по убыванию
				biggerIndex = currentIndex;
		}

		Student* temp = m_pSt[startIndex];
		m_pSt[startIndex] = m_pSt[biggerIndex];
		m_pSt[biggerIndex] = temp;
	}
}

// Сохранение списка студентов в файл(при завершении работы программы).
void AcademyGroup::Save()
{
	if (m_count == 0)
		return;

	char fileNameWrite[50]{ "AcademyGroup.data" };
	FILE* f_wright{ nullptr };
	fopen_s(&f_wright, fileNameWrite, "wb");
	if (f_wright == nullptr)
	{
		perror("Error opening");
		return;
	}

	// Пишем поле "m_count".
	int count = m_count;
	fwrite(&count, sizeof(int), 1, f_wright);

	for (int i = 0; i < m_count; i++)
	{
		// Пишем размер поля "m_name".
		int name_strlen = strlen(m_pSt[i]->getName()) + 1;
		fwrite(&name_strlen, sizeof(int), 1, f_wright);

		// Пишем значение поля "m_name".
		fwrite(m_pSt[i]->getName(), name_strlen, 1, f_wright);

		// Пишем размер поля "m_surname".
		int surname_strlen = strlen(m_pSt[i]->getSurname()) + 1;
		fwrite(&surname_strlen, sizeof(int), 1, f_wright);

		// Пишем значение поля "m_surname".
		fwrite(m_pSt[i]->getSurname(), surname_strlen, 1, f_wright);

		// Пишем значение поля "m_age".
		int age = m_pSt[i]->getAge();
		fwrite(&age, sizeof(int), 1, f_wright);

		// Пишем размер поля "m_phone".
		int phone_strlen = strlen(m_pSt[i]->getPhone()) + 1;
		fwrite(&phone_strlen, sizeof(int), 1, f_wright);

		// Пишем значение поля "m_phone".
		fwrite(m_pSt[i]->getPhone(), phone_strlen, 1, f_wright);

		// Пишем значение поля "m_rating".
		double rating = m_pSt[i]->getRating();
		fwrite(&rating, sizeof(double), 1, f_wright);
	}

	fclose(f_wright);
}

// Загрузка списка студентов из файла (при старте программы).
void AcademyGroup::Load()
{
	char fileNameRead[50]{ "AcademyGroup.data" };
	FILE* f_read{ nullptr };
	fopen_s(&f_read, fileNameRead, "rb");
	if (f_read == nullptr)
	{
		perror("Error opening");
		return;
	}

	// Читаем поле "m_count".
	int count{};
	fread(&count, sizeof(int), 1, f_read);
	m_count = count;

	// Выделяем память под считываемые данные.
	m_pSt = new Student * [m_count];
	for (int i = 0; i < m_count; i++)
		m_pSt[i] = new Student;

	for (int i = 0; i < m_count; i++)
	{
		// Читаем размер поля "m_name"
		int name_strlen{ 0 };
		fread(&name_strlen, sizeof(int), 1, f_read);

		// Читаем значение поля "m_name"
		char* nameBufferRead = new char[name_strlen];
		fread(nameBufferRead, name_strlen, 1, f_read);
		m_pSt[i]->setName(nameBufferRead);

		// Читаем размер поля "m_surname"
		int surname_strlen{ 0 };
		fread(&surname_strlen, sizeof(int), 1, f_read);

		// Читаем значение поля "m_surname"
		char* surnameBufferRead = new char[surname_strlen];
		fread(surnameBufferRead, surname_strlen, 1, f_read);
		m_pSt[i]->setSurname(surnameBufferRead);

		// Читаем значение поля "m_age"
		int age{ 0 };
		fread(&age, sizeof(int), 1, f_read);
		m_pSt[i]->setAge(age);

		// Читаем размер поля "m_phone"
		int phone_strlen{ 0 };
		fread(&phone_strlen, sizeof(int), 1, f_read);

		// Читаем значение поля "m_phone"
		char* phoneBufferRead = new char[phone_strlen];
		fread(phoneBufferRead, phone_strlen, 1, f_read);
		m_pSt[i]->setPhone(phoneBufferRead);

		// Читаем значение поля "m_rating"
		double rating{ 0.0 };
		fread(&rating, sizeof(double), 1, f_read);
		m_pSt[i]->setRating(rating);

		delete[]nameBufferRead;
		delete[]surnameBufferRead;
		delete[]phoneBufferRead;
	}
	fclose(f_read);
}

// Присваивание копированием.
AcademyGroup& AcademyGroup::operator=(const AcademyGroup& obj)
{
	if (this == &obj)
		return *this;

	for (int i = 0; i < m_count; i++)
	{
		delete* (m_pSt + i);
	}
	delete[] m_pSt;

	m_pSt = new Student * [obj.m_count];

	m_count = obj.m_count;

	for (int i = 0; i < m_count; i++)
		m_pSt[i] = new Student;

	for (int i = 0; i < m_count; ++i)
		*m_pSt[i] = *obj.m_pSt[i];

	return *this;
}

// Присваивание перемещением.
AcademyGroup& AcademyGroup::operator=(AcademyGroup&& obj)
{
	if (this == &obj)
		return *this;

	for (int i = 0; i < m_count; i++)
	{
		delete* (m_pSt + i);
	}
	delete[] m_pSt;

	m_pSt = new Student * [obj.m_count];

	m_count = obj.m_count;
	for (int i = 0; i < m_count; ++i)
		m_pSt[i] = obj.m_pSt[i];

	for (int i = 0; i < m_count; ++i)
		obj.m_pSt[i] = nullptr;
	obj.m_pSt = nullptr;
	obj.m_count = 0;
}

// Получить по индексу конкретного студента группы.
Student& AcademyGroup::operator[](int index)
{
	if (index < 0 || index >= m_count)
		return *m_pSt[0];
	return *m_pSt[index];
}

// Печать группы.
ostream& operator<<(ostream& os, AcademyGroup& obj)
{
	cout << endl;
	obj.Print();
	return cout;
}