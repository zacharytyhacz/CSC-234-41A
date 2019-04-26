/* Game Player Lobby */
#include<iostream>
#include<string>


class Player {
	friend std::ostream& operator <<(std::ostream& os, const Player& a_player);
	public:
		Player(const std::string& name = "", const std::string& rank = "Noob", const int age = 18);
		std::string get_name() const;
		std::string get_rank() const;
		int get_age() const;
		Player* get_next() const;
		void set_next(Player* next);
	private:
		std::string name;
		std::string rank;
		int age;
		Player* next_player;
};

std::ostream& operator<<(std::ostream& os, const Player& a_player){
	os << "Player Name: " << a_player.get_name();
	os << "\nPlayer Rank: " << a_player.get_rank();
	os << "\nPlayer Age: " << a_player.get_age();

	return os;
}

Player::Player(const std::string& name, const std::string& rank, const int age):
	name(name),
	age(age),
	rank(rank),
	next_player(0){
		std::cout << get_name() << " has been added to the lobby!\n"; 	
}

std::string Player::get_name() const {
	return name;
}

std::string Player::get_rank() const {
	return rank;
}

int Player::get_age() const {
	return age;
}
Player* Player::get_next() const {
	return next_player;
}

void Player::set_next(Player* next){
	next_player = next;
}

class Lobby {
	friend std::ostream& operator <<(std::ostream& os, const Lobby& aLobby);
	public: 
		Lobby();
		~Lobby();
		void add_player();
		void remove_player();
		void clear();
	private:
		Player* head_player;
};

Lobby::Lobby(): head_player(0){}

Lobby::~Lobby() {
	clear();
}

void Lobby::add_player(){
	std::string name;
	std::string rank;
	int age;
	Player* new_player;

	std::cout << std::endl << "Player Name: ";
	std::cin >> name;

	std::cout << std::endl << "Player Rank: ";
	std::cin >> rank;

	std::cout << std::endl << "Player Age: ";
	std::cin >> age;

	
	new_player = new Player(name,rank,age);

	if(head_player == 0){
		head_player = new_player;
	}
	else {
		Player* a_player = head_player;
		while(a_player->get_next() != 0){
			a_player = a_player->get_next();
		}
		a_player->set_next(new_player);
	}
}

void Lobby::remove_player(){
	if(head_player == 0){
		std::cout << "The game lobby is empty. No one to remove.\n";
	}else{
		Player* temp_player = head_player;
		head_player = head_player->get_next();
		delete temp_player;
	}
}

void Lobby::clear(){
	while(head_player != 0){
		remove_player();
	}
}

std::ostream& operator<<(std::ostream& os, const Lobby& a_lobby){
	Player* a_player = a_lobby.head_player;

	os << "\nHere's who's in the game lobby:\n";

	if(a_player == 0){
		os << "The lobby is empty.\n";
	}else{
		while(a_player != 0){
			os << "--------------------------\n";
			os << *a_player << std::endl;
			a_player = a_player->get_next();
		}
	}

	return os;
}

int main(){
	Lobby my_lobby;
	int choice;
	do {
		std::cout << my_lobby;
		std::cout << "\n T H E   G A M E   L O B B Y\n\n";
		std::cout << "0 - Exit\n";
		std::cout << "1 - Add Player\n";
		std::cout << "2 - Kick Player\n";
		std::cout << "3 - Clear Lobby\n\n";
		std::cout << " >> ";
		std::cin >> choice;
		switch(choice){
			case 0: 
				std::cout << "Good bye.\n";
				break;
			case 1:
				my_lobby.add_player();
				break;
			case 2:
				my_lobby.remove_player();
				break;
			case 3:
				my_lobby.clear();
				break;
			default: 
				std::cout << "Invalid\n";
		}
	} while(choice != 0);

	return 0;
}
