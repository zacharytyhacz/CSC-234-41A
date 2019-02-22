#include<iostream>
#include<string>

void print(std::string in){
	std::cout << in << std::endl;
}

void print(int in){
	std::cout << in << std::endl;
}

int main(){
	print("this is a string");
	print(434343);
	return 0;
}
