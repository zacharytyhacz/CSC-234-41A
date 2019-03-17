#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> words; 

void ask(std::string& value){
	std::string word = "";
	std::string question = "Please enter a " + value + ": ";

	while(word == ""){
		std::cout << question;
		std::cin >> word;
	}
	value = word;
}

void story(){
	std::cout << "\n\nOnce upon a time, there was the holy ";
	std::cout << words[0] << ".\n";
	std::cout << "This mighy " << words[0] << " always had a " << words[1] << " by it's side.\n";
	std::cout << "Every time the " << words[0] << " came across a dangerous animal or situation, it would "  << words[2] << " it.\n";
	std::cout << "This was practical in it's local area. Every once in a while, you had to " << words[3] << " something.\n";
	std::cout << "To outsiders, this was seen as " << words[4] << " and looked down upon.\n";
	std::cout << "They nick-name the area '" << words[5] << "' because of this.\n";
	std::cout << "Indeed, the locals of " << words[6] << " are used to it as it is a daily occurence.\n";
	std::cout << "However, the locals want to rename the area to ' Land Of " << words[7] << "'.\n";
	std::cout << "\n\n The end.";
}

int main(){
	words.push_back("noun");
	words.push_back("noun");
	words.push_back("verb");
	words.push_back("verb");
	words.push_back("n adjective");
	words.push_back("name");
	words.push_back("place");
	words.push_back("noun");
	int i = 0;
	
	for(i = 0; i < words.size(); i++){
		ask(words[i]);
	}
	story();
	return 0;
}
