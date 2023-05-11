#pragma once
#include <iostream>

class MyException : public std::exception {
public:
	MyException(const std::string& message_) {
		message = message_;
	}
	const char* what() const noexcept override {
		return message.c_str();
	}
private:
	std::string message;
};

class smart_array {
public:
	smart_array(int size_) {
		size = size_;
		smartArray = new int[size] {0};
	}
	smart_array(const smart_array&) = delete;
	smart_array(const smart_array&&) = delete;
	smart_array& operator=(const smart_array&) = delete;
	smart_array& operator=(const smart_array&&) = delete;

		void add_element(int el) {
		if (i_empty < size) {
			smartArray[i_empty] = el;
			++i_empty;
		}
		else {
			throw MyException("Количество элементов больше количества элементов, на которое выделена память!");
		}
	}
	int get_element(int index) {
		if (index >= 0 && index < size) {
			return smartArray[index];
		}
		else {
			throw MyException("Некорректный индекс!");
		}
	}
	~smart_array() {
		delete[] smartArray;
		smartArray = nullptr;
	}
private:
	int size; // количесвто элементов 
	int i_empty = 0; // текущая незаполненная ячейка массива
	int* smartArray;
};

