#include<iostream>
#include<string>


int main(){
	std::string input = "";
	while(input == ""){
		std::cout << "Enter a string: ";
		std::cin >> input;
	}
	std::string* pInput = &input;
	std::cout << "Pointer address: " << pInput << std::endl;
	std::cout << "String Size Via Pointer: " << pInput->size() << std::endl;
	return 0;
}
