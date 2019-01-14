/* Zachary Tyhacz 2018
** chapter one refresher with c++, make a game asking if a given variable name
** is a valid variable name 
*/ 

#include<iostream>
#include<cstring>

std::string answers[5] = {"n", "y", "y", "n", "n"};
std::string questions[5] = {"int", "bIsCorrect", "my_name", "3_cars", "foo bar"};

int main(){
   std::string input;
	bool bQuit = true;
	int i = 0;
	int questions_count = (sizeof(questions)/sizeof(*questions));
	int missed = 0;

	do {
		std::cout << "-_VARIABLE_VALIDITY_-" << std::endl;
		/* Loop through questions and check each answer with the corresponding index in answers array */
		for(i = 0; i < questions_count; i++){
			std::cout << "Question #" << i << ":  Is '" << questions[i] << "' a valid variable name?" << std::endl << "Enter Y / N : ";
			std::cin >> input;

			/* turn input string to lower */
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);

			if(input == answers[i]){
				std::cout << std::endl << "Correct!" << std::endl;
			}else{
				missed++;
				std::cout << std::endl << "Incorrect..." << std::endl;
			}
		}
		/* Show score */ 
		std::cout << "Your score: " << (questions_count / (questions_count-missed));
		/* Ask if they want to go through the quiz again */
		std::cout << "Would you like to go through the quiz again to practice your variable naming skills?" << std::endl
				  << "Y / N : ";
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		
		if(input == "y")
			bQuit = false;

	} while (!bQuit);

	return 0; 
}
