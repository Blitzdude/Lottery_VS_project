#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

/*
Tee lotto - ohjelma, joka arpoo 7 satunnaislukua v‰lilt‰ 1 - 39 (rand() % 39 + 1) ja lis‰‰ ne vektoriin.
Ohjelma kyselee k‰ytt‰j‰lt‰ lottorivej‰ ja kertoo, montako meni oikein.
*/
void printBuffer(char buffer[]);
void printInt(int i);

using namespace std;
const int BUF_SIZE = 15;

int main(int argc, char* argv[]) 
{

	time_t t;	// time muuttuja t	
	srand(time(&t));	// alustetaan aika 
	vector<int> lotto; 

	// t‰ytet‰‰n vektori sattumanvaraisilla numeroilla 1-39
	for (int i = 0; i < 7; i++) 
	{
		lotto.push_back(rand() & 39 + 1);	
	}
	
	// Tulsotetaan vectori testausta varten
	for_each(lotto.begin(), lotto.end(), printInt);

	cout << "\nAnna lotto rivi (max 7 nro)" << endl;


	//array<char, BUF_SIZE> buffer = { '\0' };
	char buffer[BUF_SIZE] = { '\0' };
	cin.getline(buffer, BUF_SIZE, '\n'); // kysyt‰‰n k‰ytt‰j‰lt‰ lottorivi

	printBuffer(buffer);

	int count = 0;

	for (char *ptr = buffer, int i = 0; *ptr != '\0'; ptr = &buffer[i++]) {
		vector<int>::iterator it = find(lotto.begin(), lotto.end(), *ptr);
		if (it != lotto.end()) {

		}
	}
	return 0;
}

void printBuffer(char buffer[]) {
	for (int i = 0; i < BUF_SIZE; ++i)
	{
		switch (buffer[i]) {
		case '\0':
		case ' ':
			break;
		default:
			cout << buffer[i] << " ";
			break;
		}
	}

}

void printInt(int i) {
	cout << i << " ";
}
	// char guess;	// laitetaan bufferin sis‰ltˆ ilman v‰lej‰ arvaukseen. 

	



