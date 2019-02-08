#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> titles;

void show_help(){
	std::cout << "\n\nType 'quit' to stop editing your favorite game titles." << std::endl;
	std::cout << "Type 'add' to add a title." << std::endl;
	std::cout << "Type 'remove' to remove a title." << std::endl;
	std::cout << "Type 'list' to see all your favorite titles." << std::endl;
	std::cout << "Type 'help' for help.\n\n";
}

void show_titles(){
	std::cout << std::endl << std::endl;
	for(int i = 0; i < titles.size(); i++){
		std::cout << titles[i] << std::endl;
	}
	std::cout << std::endl;
}

int main(){
	std::cout << "|~_YOUR FAVORITE GAMES_~|" << std::endl << std::endl;
	std::string input = "";
	
	show_help();

	while(input != "quit"){
		std::cin >> input;
		while(input == "add"){
			std::cout << "\nEnter the title of the game: " << std::endl;
			std::cin >> input;
			titles.insert(titles.end(), input);
			std::cout << "Adding " << input << "...\n";
			input = "";
			break;
		}

		while(input == "help"){
			show_help();
			input = "";
			break;
		}

		while(input == "remove"){
			show_titles();
			std::string to_remove = "";

			std::cout << "Enter the title of the game you want to remove: ";
			std::cout << "\nType 'cancel' to cancel." << std::endl;
	
			while(to_remove != "cancel"){
				std::cin >> to_remove;
				for(std::vector<int>::size_type j = 0; j < titles.size(); j++){
					if(titles[j] == to_remove){
						titles.erase(titles.begin()+j);
						std::cout << "Removing " << to_remove << "...\n";
						to_remove = "cancel";
						input = "";
						break;
					}
				}
				std::cout << to_remove << " was not found." << std::endl;
				to_remove = "cancel";
				input = "";
			}
		}

		while(input == "list"){
			show_titles();
			input = "";
		}
	}
	std::cout << "\nBye." << std::endl;
	return 0;
}
