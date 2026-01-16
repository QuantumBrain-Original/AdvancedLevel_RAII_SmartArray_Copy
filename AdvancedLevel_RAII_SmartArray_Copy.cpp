#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>
#include <exception>
//#include <vector>

class smart_array
{
	int size, items;
	int* arr;

public:
	smart_array(int arrsize) : size(arrsize), items(0)
	{
		if (arrsize <= 0)
			throw std::exception("Размер массива не может быть меньше или равен 0!");

		this->arr = new int[size];
	}

	void add_element(int a)
	{
		if (items >= size)
			throw std::exception("Размер массива достиг максимума. Новый элемент не может быть добавлен!");

		arr[items++] = a;
	}

	int get_element(int id) const
	{
		if (id >= size || id < 0)
			throw std::exception("Задан некорректный номер элемента!");

		return arr[id];
	}

	smart_array& operator=(const smart_array& arr2) {
		if (this == &arr2)
			return *this;

		delete[] arr;

		items = arr2.items;
		size = arr2.size;
		arr = new int[items];

		for (int i = 0; i < size; ++i)
			arr[i] = arr2.arr[i];

		return *this;
	}

	void print() const
	{
		for (int i = 0; i < size; ++i)
			std::cout << arr[i] << " ";
	
		std::cout << std::endl;
	}

	~smart_array()
	{
		delete[] arr;
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

		std::cout << "Исходный массив:" << std::endl;
		arr.print();

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

		std::cout << "Новый массив:" << std::endl;
		arr.print();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
