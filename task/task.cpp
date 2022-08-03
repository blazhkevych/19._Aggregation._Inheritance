/*
############################################ ЗАДАНИЕ ###########################################
				Написать программу, позволяющую формировать список студентов академической группы.
	Интерфейс программы должен предоставлять пользователю следующие возможности:
	a. добавление студентов в группу;
	b. удаление студента из группы;
	c. модификация данных студента;
	d. печать академической группы;
	e. сортировка списка студентов;
	f. поиск студента по заданному критерию;
	g. сохранение списка студентов в файл (при завершении работы программы);
	h. загрузка списка студентов из файла (при старте программы);
	i. выход из программы.
	При разработке программы следует использовать двумерный динамический массив для хранения списка
студентов (одномерный динамический массив указателей на объекты класса Student).
	Для реализации функциональности программы необходимо разработать следующие классы:

	class Person
	{
	protected:
	char *name;
	char *surname;
	int age;
	public:
	Person();
	Person(const char * name, const char * surname, int age);
	Person(const Person &obj);
	Person(Person &&obj);
	~Person();
	const char* getName()const;
	const char * getSurname()const;
	int getAge() const;
	void setName(const char * name);
	void setSurname(const char * surname);
	void setAge(int age);
	void Print()const;
	Person& operator=(const Person &obj);
	Person& operator=(Person &&obj);
	friend std::istream& operator>>(std::istream &is, Person& obj);
	friend std::ostream& operator<<(std::ostream &os, const Person& obj);
	};

	class Student : public Person
	{
	char phone[14];
	double rating;
	public:
	Student();
	Student(const char * name, const char * surname, int age, const char * phone,
	double rating);
	Student(const Student &obj);
	Student(Student &&obj);
	double getRating() const;
	const char * getPhone() const;
	void setPhone(const char * phone);
	void setRating(double average);
	void Print() const;
	Student& operator=(const Student &obj);
	Student& operator=(Student &&obj);
	friend std::istream& operator>>(std::istream &is, Student& obj);
	friend std::ostream& operator<<(std::ostream &os, const Student& obj);
	};

	class AcademyGroup
	{
	Student ** pSt;
	int count;
	public:
	AcademyGroup();
	AcademyGroup(const AcademyGroup& obj);
	AcademyGroup(AcademyGroup &&obj);
	~AcademyGroup();
	void AddStudents();
	void DeleteStudent();
	void EditStudent();
	void Print();
	void FindStudent();
	void Sort();
	void Save();
	void Load();
	AcademyGroup& operator=(const AcademyGroup &obj);
	AcademyGroup& operator=(AcademyGroup &&obj);
	Student& operator[](int index);
	friend std::ostream& operator<<(std::ostream &os, AcademyGroup& obj);
	};
################################################################################################
02,41,10
бибилиотека
студент
сделать меню
fwrite fread для записи в файл и чтения.
Сохранение и загрузку студента взять из работы по студенту. https://github.com/blazhkevych/4._Student_class
Двумерный динамический массив использовать, как в программе библиотека https://github.com/blazhkevych/41._Program_Library._Loading_and_saving_data

*/

#include <iostream>
#include <conio.h>
#include <windows.h>

#include "Person.h"
#include "Student.h"
#include "AcademyGroup.h"
using std::cout;
using std::cin;
using std::endl;

// Меню
void Menu(char ptr[][50], int row)
{
	for (int i = 0; i < row; i++)
	{
		cout << ptr[i];
		cout << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	/*
	Задает кодовую страницу ввода, используемую консолью, связанной с вызывающим процессом.
	Консоль использует страницу входного кода для преобразования ввода с клавиатуры
	в соответствующее символьное значение.
	*/
	SetConsoleOutputCP(1251);
	/*
	Задает выходную кодовую страницу, используемую консолью, связанной с вызывающим процессом.
	Консоль использует свою кодовую страницу вывода для преобразования символьных значений,
	записанных различными функциями вывода, в изображения, отображаемые в окне консоли.
	*/

#pragma region Тестирование class Person
	// Конструкторы:
	// Конструктор по умолчанию (обнуляет поля). // OK
	Person person_0;

	// Конструктор с всеми параметрами (нужен для инициализации всех полей). // OK
	Person person_1{ "Петрик", "Пяточкін", 20 };

	// Конструктор копирования (нужен при наличии динамических полей в классе). // OK
	Person person_2{ person_1 };

	// Конструктор переноса (семантика переноса с использованием r-value ссылок). // ???
	//Person person_3 = person_2 + person_1; // ?!?!?!? // написан, но пока не ясно где и как его применять.
	//TODO: что делает конструктор переноса в классе персон ?

	// Получить имя. // OK
	const char* getName = person_1.getName();

	// Получить фамилию. // OK
	const char* getSurname = person_1.getSurname();

	// Получить возраст. // OK
	int getAge = person_1.getAge();

	// Установить имя. // OK
	person_0.setName("Іван");

	// Установить фамилию. // OK
	person_0.setSurname("Подорожний");

	// Установить возраст. // OK
	person_0.setAge(30);

	// Вывод объекта person на экран. // OK // TODO: доработать вывод, подогнав под общую таблицу вывода.
	//person_0.Print(); // РАБОТАЕТ. Отключено для удобства.

	// Оператор присваивания копированием. // OK
	Person person_4;
	person_4 = person_0;

	// Оператор присваивания перемещением. // Не протестировано. В данном проекте использоваться не будет.
	Person person_5;

	// Ввод объекта person. // OK
	Person person_6;
	//cin >> person_6; // РАБОТАЕТ. Отключено для удобства.

	// Вывод объекта person. // OK // TODO: но пока не ясно как будет работать в связке с наследуемыми классами.
	//cout << person_6; // РАБОТАЕТ. Отключено для удобства.

#pragma endregion

#pragma region Тестирование class Student
	// Конструкторы:
	// Конструктор по умолчанию (обнуляет поля). // OK
	Student student_0;

	// Конструктор с всеми параметрами (нужен для инициализации всех полей). // OK
	Student student_1{ "Вася", "Пупкин", 40, "+380998887745", 11.11 };

	// Конструктор копирования (нужен при наличии динамических полей в классе). // OK
	Student student_2{ student_1 };

	// Конструктор переноса (семантика переноса с использованием r-value ссылок).
	// Student student_3 = student_0 + student_1; // ?!?!?!? // написан, но пока не ясно где и как его применять.
	// TODO: что делает конструктор переноса в классе Student ?

	// Получить средний балл. // OK
	double getRating = student_1.getRating();

	// Получить телефон. // OK
	const char* getPhone = student_1.getPhone();

	// Установить телефон. // OK
	student_0.setPhone("+380256891133");

	// Установить средний балл. // OK
	student_0.setRating(10.10);

	// Вывод объекта Student на экран.  // OK
	//student_1.Print(); // РАБОТАЕТ. Отключено для удобства.

	// Оператор присваивания копированием. // OK
	Student student_4;
	student_4 = student_1;

	// Оператор присваивания перемещением. // Не протестировано. В данном проекте использоваться не будет.
	Student student_5;

	// Ввод объекта Student. // ОК
	Student student_6;
	//cin >> student_6; // РАБОТАЕТ. Отключено для удобства.

	// Вывод объекта Student.
	//cout << student_6; // РАБОТАЕТ. Отключено для удобства.



#pragma endregion

#pragma region Тестирование class AcademyGroup

	// Конструкторы:
	// Конструктор по умолчанию (обнуляет поля). // ОК
	AcademyGroup academyGroup_0{};

	// Добавление студентов в группу.
	academyGroup_0.AddStudents(); // TODO: начать тестировать добавление студента.

	// Конструктор копирования (нужен при наличии динамических полей в классе).
	//AcademyGroup academyGroup_2{ academyGroup_0 };




#pragma endregion


	char menu[][50] =
	{
		"1. Добавление студентов в группу.",
		"2. Удаление студента из группы.",
		"3. Модификация данных студента.",
		"4. Печать академической группы.",
		"5. Сортировка списка студентов." ,
		"6. Поиск студента по заданному критерию." ,
		"7. Выход из программы."
	};
	// TODO: Место для метода загрузки из файла.
	while (true)
	{
		system("cls");
		cout << "\tГлавное меню." << endl;
		Menu(menu, 7);
		int choice_mainMenu{ 0 };
		cout << "\n   >>> ";
		cin >> choice_mainMenu;
		cin.get();
		switch (choice_mainMenu)
		{
		case 1:														// 1. Добавление студентов в группу.
			/*if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
			{
				PrintHeaderBooks();
				PrintBooks(b);
			}*/
			// TODO: добавить проверку на наличие студентов в группе по выше закомментированному примеру во все пункты меню.
			system("cls");
			cout << "\tГлавное меню."
				"\n1. Добавление студентов в группу."
				<< endl;
			//phonebook.AddAbonent();
			cout << "\nСтудент успешно добавлен в группу !" << endl
				<< "\nДля продолжения нажмите любую клавишу." << endl;
			_getch();
			break;
		case 2:														// 2. Удаление студента из группы.
			system("cls");
			cout << "\tГлавное меню."
				"\n2. Удаление студента из группы."
				<< endl;
			//phonebook.AddAbonent();
			cout << "\nСтудент успешно удален из группы !" << endl
				<< "\nДля продолжения нажмите любую клавишу." << endl;
			_getch();
			break;
		case 3:														// 3. Модификация данных студента.
			system("cls");
			cout << "\tГлавное меню."
				"\n3. Модификация данных студента."
				<< endl;
			//phonebook.AddAbonent();
			cout << "\nСтудент успешно модифицирован !" << endl
				<< "\nДля продолжения нажмите любую клавишу." << endl;
			_getch();
			break;
		case 4:														// 4. Печать академической группы.
			system("cls");
			cout << "\tГлавное меню."
				"\n4. Печать академической группы."
				<< endl;
			//phonebook.AddAbonent();
			cout << "\nАкадемическая группа распечатана !" << endl
				<< "\nДля продолжения нажмите любую клавишу." << endl;
			_getch();
			break;
		case 5:														// 5. Сортировка списка студентов.
			system("cls");
			cout << "\tГлавное меню."
				"\n5. Сортировка списка студентов."
				<< endl;
			//phonebook.AddAbonent();
			//TODO: добавить подменю, уточнить критерий сортировки или сделать ее для каждого поля.
			//cout << "\nАкадемическая группа распечатана !" << endl; // возможно нужно отключить эту строчку.
			cout << "\nДля продолжения нажмите любую клавишу." << endl;
			_getch();
			break;
		case 6:														// 6. Поиск студента по заданному критерию.
			system("cls");
			cout << "\tГлавное меню."
				"\n6. Поиск студента по заданному критерию."
				<< endl;
			//phonebook.AddAbonent();
			//TODO: добавить подменю, уточнить критерии для поиска студента либо сделать поиск по всем полям.
			//cout << "\nАкадемическая группа распечатана !" << endl; // возможно нужно отключить эту строчку.
			cout << "\nДля продолжения нажмите любую клавишу." << endl;
			_getch();
			break;
		case 7:														// 7. Выход из программы.
			// TODO: Место для метода сохранения в файл.
			//Destroy(b); // TODO: Место для удаления массива, класса группы, которая содержит студентов.
			return 0;
		default:
			system("cls");
			cout << "\nПопробуйте еще раз !" << endl;
			cout << "\nДля продолжения нажмите любую клавишу." << endl;
			_getch();
			break;
		}
	}
}