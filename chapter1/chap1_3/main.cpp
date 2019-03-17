#include<iostream>
#include<string>

int main(){
	int inputs[3];
	int i = 0;
	int total = 0;
	std::cout << "YOUR AVERAGE GAME SCORE CALCULATOR" << std::endl << std::endl;

	for(i = 0; i < 3; i++){
		std::cout << "Enter score #" << i+1 << ": ";
		std::cin >> inputs[i];
		total += inputs[i];
	}

	std::cout << std::endl << "Average Score: " << total/3.0 << std::endl;
	return 0;
}
