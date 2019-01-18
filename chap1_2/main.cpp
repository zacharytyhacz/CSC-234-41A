#include<iostream>
#include<string>

int main(){
	std::cout << " 7 / 3 = " << 7/3 << std::endl;
	std::cout << "Both values are integers so the end result value is still an integer type." << std::endl << std::endl;
	std::cout << " 7.0 / 3 = " << 7.0/3 << std::endl;
	std::cout << "One value is a float which is more specific than the integer, so the final value is a float value" << std::endl << std::endl;
	std::cout << " 7.0 / 3.0 = " << 7.0/3.0 << std::endl;	
	std::cout << " Both values are float values so the end value is a float " << std::endl;

	return 0;
}
