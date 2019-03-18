/* Zachary Tyhacz 2019 */
/* Improve the critter program to have an unlisted menu choice that reveals exact values for the critter 
and 
change the critter program so that the critter is more expressive about its needs; hunger and boredom */
#include<iostream>
#include<string>
#include<vector>

class Critter{
	public:
		void Stats();
		void Greet();
		Critter(int hunger = 5, int boredom = 5);
		void Talk();
		void Eat();
		void Play();
		void PassTime();

	private:
		int Hunger;
		int Boredom;
};

void Critter::PassTime(){
	Hunger++;
	Boredom++;
}

void Critter::Eat(){
	Hunger -= 2;
	std::cout << "Yum yum!" << std::endl;
}

void Critter::Stats(){
	std::cout << "Hunger: " << Hunger << std::endl;
	std::cout << "Boredom: " << Boredom << std::endl;
}

void Critter::Talk(){
	std::cout << "Hi there, ";
	
	if(Boredom > 7)
		std::cout << " this is fun ";
	else if (Boredom > 4)
		std::cout << " this is kind of fun ";
	else 
		std::cout << " I'm bored ";

	std::cout << " and ";

	if(Hunger > 9)
		std::cout << " I am not hungry." << std::endl;
	else if(Hunger > 5)
		std::cout << " I am kind of hungry." << std::endl;
	else if(Hunger > 3)
		std::cout << " I'm hungry!" << std::endl;
	else
		std::cout << " I'm starving mister!" << std::endl;
}

Critter::Critter(int hunger, int boredom){
	std::cout << "A new critter has been born!" << std::endl;
	Hunger = hunger;
	Boredom = boredom;
}

void Critter::Play(){
	std::cout << "ha ha this is fun!" << std::endl;
	Boredom -= 2;
}

void Critter::Greet(){
	std::cout << "Hello, I'm a critter. My hunger level is " << Hunger << std::endl;
}

int main(){
    Critter my_pet(4);
	int choice;

	do {
		std::cout << "\n\n";
		std::cout << "0 - Quit" << std::endl;
		std::cout << "1 - Listen to your critter" << std::endl;
		std::cout << "2 - Feed your critter" << std::endl;
		std::cout << "3 - Play with your critter" << std::endl;

		std::cout << "\n Select a choice: ";
		std::cin >> choice;
		std::cout << "\n\n";

		switch(choice){
			case 0:
				std::cout << "Good byte \n";
				break;
			case 1:
				my_pet.Talk();
				break;
			case 2:
				my_pet.Eat();
				break;
			case 3:
				my_pet.Play();
				break;
			case 4:
				my_pet.Stats();
				break;
			default:
				std::cout << choice << " is an invalid choice." << std::endl;
		}
		my_pet.PassTime();
	} while(choice != 0); 
	return 0;
}
