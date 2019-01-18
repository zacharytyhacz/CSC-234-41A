#include<iostream>
#include<string>

int main(){
	std::string questions[6] = {"int", "3cars", "foo bar", "foo_bar", "bIsCorrect", "cars"};
	std::string answers[6]   = {"n", "n", "n", "y", "y", "y"};
	std::string input = "";
	int correct = 6;
	int i = 0;	

	std::cout << std::endl << "_-_-_| VARIABLE VALIDITY QUIZ |_-_-_" << std::endl;

	for(i = 0; i < 6; i++){
		std::cout << std::endl << "Question #" << i+1 << ":    Is '" << questions[i] << "' a valid variable name?" << std::endl;
		std::cout << "Enter Y / N : ";
		std::cin >> input;

		/* Change input to lower case */
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		
		if(input == answers[i]){
			std::cout << "Correct!" << std::endl;
		} else {
			std::cout << "Incorrect..." << std::endl;
			correct--;
		}
	}

	std::cout << std::endl << std::endl << "Your score: " << correct << " / 6 " << std::endl;
	std::cout << std::endl << "Would you like to go through the quiz again to practice your variable naming skills?" << std::endl;
	std::cout << "Enter Y / N : ";
	std::cin >> input;

	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	if(input == "y")
		main();
	std::cout << "Bye" << std::endl;
	return 0;
}
