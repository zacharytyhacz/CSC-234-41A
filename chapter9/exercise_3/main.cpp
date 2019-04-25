#include<iostream>

int main(){
	int* pScore = new int;
	std::cout << *pScore << std::endl;
	*pScore = 500;
	std::cout << *pScore << std::endl;
	pScore = new int(1000);
	std::cout << *pScore << std::endl;
	delete pScore;
	std::cout << *pScore << std::endl;
	pScore = 0;		// <<< since pScore has been deleted on line 10, this is null and cannot be set as if pScore was never initialized.
	std::cout << *pScore << std::endl;
	return 0;
}
