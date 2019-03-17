#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

int main(){
	std::string input = "";
	int number;
	int min = 10;
	int max = 5;
	int bot_guess;
	int temp_guess;
	int guesses = 0;
	
	while(min > max){
		std::cout << "Pick a minimum guess number: ";
		std::cin >> min;
	
		std::cout << "Pick a maximum guess number: ";
		std::cin >> max;

		if(min >= max)
			std::cout << "Minimum must be lower than the maximum" << std::endl;
	}

	while(number <= min || number >= max){
		std::cout << "Pick the correct number: ";
		std::cin >> number;

		if(number >= min || number >= max)
			std::cout << "The correct number must be between " << min << " and " << max << "." << std::endl;
	}

	std::cout << "BEGIN!!!" << std::endl;

	while(bot_guess != number){
		srand(static_cast<unsigned int>(time(0)));
		temp_guess = rand() % max + min;
		guesses++;
		std::cout << std::endl << "Bot guesses: " << temp_guess << std::endl;
		bot_guess = temp_guess;
	}
	
	std::cout << "Bot guessed it in " << guesses << " guesses." << std::endl;
	std::cin >> input;
	return 0;
}
