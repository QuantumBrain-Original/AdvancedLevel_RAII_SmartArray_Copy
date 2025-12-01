#include <iostream>
#include <string>
#include <Windows.h>
#include <exception>
#include <vector>

class smart_array
{
	int size, items;
	std::vector<int> arr;

public:
	smart_array(int arrsize) : size(arrsize), items(0)
	{
		if (arrsize <= 0)
			throw std::exception("Размер массива не может быть меньше или равен 0!");

		arr.resize(size);
	}

	void add_element(int a)
	{
		if (items >= size)
			throw std::exception("Размер массива достиг максимума. Новый элемент не может быть добавлен!");

		arr[items++] = a;
	}

	void get_element(int id) const
	{
		if (id >= size || id < 0)
			throw std::exception("Задан некорректный номер элемента!");

		std::cout << arr[id] << std::endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	try
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr.get_element(1);
		new_array.get_element(1);

		arr = new_array;

		arr.get_element(1);
		new_array.get_element(1);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
