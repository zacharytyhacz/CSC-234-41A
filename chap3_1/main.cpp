/* Zachary Tyhacz 2019 */
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

int main(){
	enum fields {WORD, HINT, NUM_FIELDS};
	enum difficulty {EASY, MEDIUM, HARD, NUM_DIFF_LEVELS = 3};
	const int NUM_WORDS = 8;
	const std::string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"program","This is an example of one."},
		{"glasses", "Geenkies, I lost my..."},
		{"compile","I had to do this to make this program."},
		{"coffee", "You drink this for boost."},
		{"linux", "An UNIX system that has many distributions and is the best."},
		{"computer", "Only knows 1s and 0s."},
		{"library", "I had to import a few of these for this program"},
		{"brunswick", "A community college in the middle of no where."}
	};

	std::string guess = "";
	int points = 0;

	std::cout << "There are " << NUM_DIFF_LEVELS << " difficulty levels." << std::endl;
 	std::cout << "\t\t Welcome to the Word Jumble Game \n\n";
 	std::cout << "Unscramble the letters to make a word. \n";
 	std::cout << "Enter 'hint' to get a hint to help you out. \n";
 	std::cout << "Enter 'quit' to quiet the game. \n\n";
	
	while(guess != "quit"){
		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		std::string theWord = WORDS[choice][WORD];
		std::string theHint = WORDS[choice][HINT];
		std::string jumble = theWord;
		int length = jumble.size();
		int tries = 0;	

		for(int i=0; i < length; ++i){
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		std::cout << "Unscrambled this word: " << jumble << std::endl << std::endl;
		while( guess != theWord) {
			tries++;
			std::cin >> guess;
			if(guess == "hint"){
				tries += 5;
				std::cout << theHint << std::endl;
			} else if(guess != "quit") {
				std::cout << "\n Guess again... \n\n"; 
			} else {
				break;
			}
		}
		if(guess != "quit"){
			std::cout << "Nice job!\n You won " << (length*10) - (tries*2) << " points!" << std::endl;
			points += (length*10) - (tries*2);
			std::cout << "\nYour total points: " << points << std::endl;
		}
	}
	std::cout << "Your final score: " << points << std::endl;
	return 0;
}
