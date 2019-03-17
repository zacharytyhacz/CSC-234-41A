#include<iostream>
#include<string>
#include<vector>

class Critter{
	public:
		static int population = 0;
		static int GetPopulation();
		int GetHunger() const;
		void SetHunger(int number);
		void Stats();
		void Greet();
		Critter(int hunger = 0);
		void Talk();
		void Eat();
		void Play();

	private:
		int Hunger;
		int Boredom;
};

void Critter::Eat(){
	Hunger--;
	std::cout << "Yum yum!" << std::endl;
}

void Critter:Stats(){
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
	else if(hunter > 3)
		std::cout << " I'm hungry!" << std::endl;
	else
		std::cout << " I'm starving mister!" << std::endl;
}

int Critter::GetPopulation(){
	return population;
}

void Critter::Critter(int hunger = 0){
	std::cout << "A new critter has been born!" << std::endl;
	Hunger = hunger;
	Boredom = 3;
	population++;
}

void Critter:Play(){
	std::cout << "ha ha this is fun!" << std::endl;
	Boredom--;
}

int Critter::GetHunger(){
	return Hunger;
}

void Critter::SetHunger(int number){
	if(number < 0){
		std::cout << "Invalid hunger level. Must be greater than 0." << std::endl;
		return;
	}

	Hunger = number;
}

void Critter::Greet(){
	std::cout << "Hello, I'm a critter. My hunger level is " << Hunger << << std::endl;
}

int main(){
    Critter my_pet(4);
	int choice;

	do {
		std::cout << "0 - Quit" << std::endl;
		std::cout << "1 - Listen to your critter" << std::endl;
		std::cout << "2 - Feed your critter" << std::endl;
		std::cout << "3 - Play with your critter" << std::endl;
		std::cout << "4 - View Stats" << std::endl;

		std::cout << "\n\n Select a choice: ";
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
			default:
				std::cout << choice << " is an invalid choice." << std::endl;
		}
	} while(choice != 0); 
	return 0;
}
