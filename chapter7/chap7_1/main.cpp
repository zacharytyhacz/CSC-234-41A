#include<iostream>
#include<string>


int main(){
	std::string my_string = "zachary tyhacz";
	std::string& my_reference = my_string;
	std::string* my_pointer = &my_reference;
	std::string* other_pointer = my_pointer;

	std::cout << "This is the string: " << my_string << std::endl;
	std::cout << "This is the pointer to the string: " << my_pointer << std::endl;
	std::cout << "This is the pointer to the pointer: " << other_pointer << std::endl;
	std::cout << ".size() from the pointer to the pointer: " << other_pointer->size() << std::endl;
	
	return 0;
}
