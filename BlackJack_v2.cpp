#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

int rand_card(int mark_cards[4][13]);						//function declaration
float sum(int cards[]);

int main()
{	int j;
	int cards_num_1, cards_num_2;
	bool judge, WorL;
	float sum_1, sum_2;
	char choice, choice_1;
	int cards_1[21], cards_2[21];
	int mark_cards[4][13] = {0};
	string color[] = {"","Heart","Diamond","Spade","Club"};
	string number[] = {"","Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};					
	
	srand(time(NULL));
	judge = 1;
	while (judge)
	{	WorL = 1;											//initialization
		cards_num_1 = cards_num_2 = 0;
		memset(cards_1,0,sizeof(cards_1));
		memset(cards_2,0,sizeof(cards_2));
		memset(mark_cards,0,sizeof(mark_cards));
		sum_1 = sum_2 = 0;
		
		cout << "Game on~~~" << endl;						//player stage
		cout << "Ur turn." << endl;
		cards_1[cards_num_1] = rand_card(mark_cards);
		sum_1 = sum(cards_1);
		++cards_num_1;
		cards_1[cards_num_1] = rand_card(mark_cards);
		sum_1 = sum(cards_1);
		++cards_num_1;
		cout << "U've got cards: ";
		for (j=0; cards_1[j]!=0; ++j)
			cout << color[cards_1[j] / 100] << " " << number[cards_1[j] % 100] << "  ";
		cout << endl;
		while (true)
		{	cout << "One more card?";
			cin >> choice_1;
			if (choice_1 == 'Y' || choice_1 == 'y')
			{	cards_1[cards_num_1] = rand_card(mark_cards);
				sum_1 = sum(cards_1);
				++cards_num_1;
				cout << "U've got cards: ";
				for (j=0; cards_1[j]!=0; ++j)
					cout << color[cards_1[j] / 100] << " " << number[cards_1[j] % 100] << "  ";
				cout << endl;
				if (sum_1 > 21)
				{	cout << "U lose!!!" << endl;
					WorL = 0;
					break;
		 	    }
			}
			if (choice_1 == 'N' || choice_1 == 'n')
			{	break;
			}
		}
		
		if (WorL)											//PC stage
		{	cout << "Now my turn." << endl;
			cards_2[cards_num_2] = rand_card(mark_cards);
			sum_2 = sum(cards_2);
			++cards_num_2;
			cards_2[cards_num_2] = rand_card(mark_cards);
			sum_2 = sum(cards_2);
			++cards_num_2;
			cout << "I've got cards: ";
			for (j=0; cards_2[j]!=0; ++j)
				cout << color[cards_2[j] / 100] << " " << number[cards_2[j] % 100] << "  ";
			cout << endl;
			while (sum_2 <= sum_1)
			{	if (sum_2 == sum_1  &&  cards_num_2 > cards_num_1)  
				{	cout << "U lose!!!";
					break;
				}
				if (sum_2 == sum_1  &&  cards_num_2 == cards_num_1 == 21)
				{	cout << "DRAW!!!" << endl;
					break;
				}
				cards_2[cards_num_2] = rand_card(mark_cards);
				sum_2 = sum(cards_2);
				++cards_num_2;
				cout << "I've got cards: ";
				for (j=0; cards_2[j]!=0; ++j)
					cout << color[cards_2[j] / 100] << " " << number[cards_2[j] % 100] << "  ";
				cout << endl;
			}
			if (sum_2 > 21) cout << "U win!!!" <<endl;
			else cout << "U lose!!!" << endl;
		}
		while (true)
		{	cout << "continue?" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')  break;
			if (choice == 'N' || choice == 'n')  
			{	judge = 0;
				break;
			}
		}
	}
	
	return 0; 
}

int rand_card(int mark_cards[4][13])						//create me a random card
{	int j;
	int a[2];
	int result;
	
	do
	{	a[0] = rand() % 4;
		a[1] = rand() % 13;
		result = (a[0]+1)*100 + (a[1]+1);
	} while (mark_cards[a[0]][a[1]]);
	mark_cards[a[0]][a[1]] = 1;
	
	return result;
}

float sum(int cards[])										//calculate the sum of numbers
{	int j;
	int num;
	float result;
	
	result = 0;
	for (j=0; cards[j]!=0; ++j)
	{	num = cards[j] % 100;
		switch (num)
		{	case 11:
			case 12:
			case 13: result += 0.5; break;
			default: result += num;
		}
	}
	
	return result;
}
