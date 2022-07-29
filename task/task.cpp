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
#include <windows.h>
using std::cout;
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

	char menu[][50] = {
		"1. Добавление книг",
		"2. Печать всех книг",
		"3. Удаление книги по указанному критерию",
		"4. Редактирование книги",
		"5. Поиск книг по автору" ,
		"6. Поиск книги по названию" ,
		"7. Сортировка книг по названию" ,
		"8. Сортировка книг по автору" ,
		"9. Сортировка книг по издательству",
		"10. Выход" };
	// Место для метода загрузки из файла.
	while (true)
	{
		system("cls");
		Menu(menu, 10);
		int choice{ 0 };
		cout << "\n   >>> ";
		cin >> choice;
		cin.get();
		switch (choice)
		{
		case 1:
			AddBooks(b);
			break;
		case 2:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
			{
				PrintHeaderBooks();
				PrintBooks(b);
			}
			break;
		case 3:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				RemoveBookBySpecCriteria(b);
			break;
		case 4:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				EditBook(b);
			break;
		case 5:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SearchBookByAuthor(b);
			break;
		case 6:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				BookSearchByTitle(b);
			break;
		case 7:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SortBooksByTitle(b);
			break;
		case 8:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SortBooksByAuthor(b);
			break;
		case 9:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SortBooksByPublisher(b);
			break;
		case 10:
			SaveToFile(b);
			Destroy(b);
			return 0;
			break;
		}
	}
}