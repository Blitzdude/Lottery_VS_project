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

muutetaan siten, ett‰ ei oteta k‰ytt‰jlt‰ arvoja, vaan generoidaan randomisti tuhat "arpalippua" ja katsotaan, montako menee oikein. 
*/
using namespace std;

// Function prototypes
void initLottery(vector<int> &vec);
int checkLotteryNumbers(vector<int>& vec1, vector<int>& vec2);
//void printBuffer(char buffer[]);


const int BUF_SIZE = 15;



int main(int argc, char* argv[]) 
{

	time_t t;	// time muuttuja t	
	srand(time(&t));	// alustetaan aika 

	vector<int> lotto; 
	vector<int> arpa;
	// t‰ytet‰‰n vektori sattumanvaraisilla numeroilla 1-39
	initLottery(lotto);
	initLottery(arpa);

	// Tulsotetaan vectori testausta varten
	for_each(lotto.begin(), lotto.end(), [](int i){ cout << i << " "; }); // algoritmi

	cout << "\nYour ticket: " << endl;
	for_each(arpa.begin(), arpa.end(), [](int i){ cout << i << " "; });

	int count = checkLotteryNumbers(lotto, arpa);
	
	cout << "You got " << count << " correct" << endl;
	return 0;
}

void initLottery(vector<int> &vec) {

	vector<int>::iterator it = vec.begin();
	for (int i = 0; i < 7; /*|*/) {

		static int num = rand() % 39 + 1;
		//check that number is not in the vector already
		it = find(vec.begin(), vec.end(), num);
		if (it != vec.end()) {
			// num not unique, generate it again.
			num = rand() % 39 + 1;
		} 
		else {
			vec.push_back(num);
			++i;
		}
	}
	sort(vec.begin(), vec.end());
}

int checkLotteryNumbers(vector<int>& vec1, vector<int>& vec2) {
	int count = 0;
	// k‰yd‰‰n jokainen arvo l‰pi, ja katsotaan montako saatiin oikein. 
	vector<int>::iterator it1;
	vector<int>::iterator it2;
	for (it1 = vec1.begin(); it1 != vec1.end(); ++it1) {
		it2 = find(vec2.begin(), vec2.end(), *it1);
		if (it2 != vec2.end()) {
			count++;
		}
	}
	return count;
}

/*
void printBuffer(char buffer[]) {	//TODO: Replace with template,
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
*/