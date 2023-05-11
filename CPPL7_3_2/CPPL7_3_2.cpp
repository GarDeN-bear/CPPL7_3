#include <iostream>
#include <Windows.h>
#include "SmartArray.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	smart_array arr(3);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(arr);
	new_array.add_element(44);
	new_array.add_element(34);

	//arr = new_array;
	std::cout << new_array.get_element(2);
}