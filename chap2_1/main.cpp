#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

/* levels are :  level = max_number  */
enum levels {Easy = 50, Medium = 100, Hard = 200, Expert = 500, Custom = 100};
int max = 100;
int min = 0;
bool bPlayerTurn = true;

bool showMenu(){
	std::string input = "";
	int choice = 0;

	std::cout << std::endl << "Select a Level!" << std::endl;
	std::cout << "1.  Easy " << std::endl;
	std::cout << "2.  Medium " << std::endl;
	std::cout << "3.  Hard " << std::endl;
	std::cout << "4.  Expert" << std::endl;
	std::cout << "5.  Custom" << std::endl;

	std::cin >> input;
	choice = std::stoi(input);	

	if(choice < 1 || choice > 5){
		std::cout << "Invalid input." << std::endl;
		showMenu();
	}

	if(choice == 5){
		int new_min = 20;
		int new_max = 10;
	
		while(new_min >= new_max){
			std::cout << std::endl << "Select a minimum value: ";
			std::cin >> new_min;
			
			std::cout << std::endl << "Select a maximum value: ";
			std::cin >> new_max;

			if(new_min >= new_max)
				std::cout << "Minimum value must be lower than the maximum!!!" << std::endl;
		}
		max = new_max;
		min = new_min;
	}
	
	switch (choice){
		case 1:
			max = Easy;	
			break;
		case 2:
			max = Medium;
			break;
		case 3:
			max = Hard;
			break;
		case 4:
			max = Expert;
			break;
	}
	return true;
}

void startGame(){
	srand(static_cast<unsigned int>(time(0)));
	int number = ( rand() % max ) + min;
	int player_guess = 0;
	int bot_guess = 0;
	int bot_guess_temp = 0;
		
	std::cout << "Guess a number between " << min << " and " << max << " . " << std::endl << std::endl; 

	while(player_guess != number && bot_guess != number){
		srand(static_cast<unsigned int>(time(0)));
		if(bPlayerTurn){
			std::cout << "Your guess:  ";
			std::cin >> player_guess;
		} else {
			bot_guess_temp = ((rand() % max ) + min);
			std::cout << std::endl << "Bot guess:  " << bot_guess_temp << std::endl;
			bot_guess = bot_guess_temp;
		}
		bPlayerTurn = !bPlayerTurn;
	}
	
	if(player_guess == number)
		std::cout << "You guessed it!" << std::endl;
	else
		std::cout << "You lost. BOT guessed it before you." << std::endl << std::endl;
}

int main(){
	bool bQuit = false;
	std::string input = "";

	std::cout << "____.~| THE GUESSING GAME |~.____" << std::endl;

	while(!bQuit){
		showMenu();
		startGame();
		while(input != "n" && input != "N" && input != "Y" && input != "y"){
			std::cout << "Would you like to play again?" << std::endl << " Y / N  : ";
			std::cin >> input;
	
			if(input == "N" || input == "n")
				bQuit = true;
		}
	}
	
	return 0;
}
