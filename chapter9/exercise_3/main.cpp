#include<iostream>

int main(){
	int* pScore = new int;
	*pScore = 500;
	pScore = new int(1000);
	delete pScore;
	pScore = 0;
	return 0;
}
