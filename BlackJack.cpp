#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

string rand_card(); 
int player_stage();
int PC_stage();

string color[4] = {"Heart","Diamond","Spade","Club"};
string num[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
string cards_1[21], cards_2[21];
int mark_cards[4][13] = {0};
int WorL, cards_num_1, cards_num_2;
float sum, sum_1, sum_2;

int main()
{	int i, j;
	char choice;
	
	i = 0;
	while (i == 0)
	{	WorL = 0;
		for (j=0; j<21; ++j)
		{	cards_1[j] = "";
			cards_2[j] = "";
		}
		memset(mark_cards,0,sizeof(mark_cards));
		sum = sum_1 = 0;
		player_stage();
		if (WorL == 0)  PC_stage();
		while (true)
		{	cout << "continue?" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')  break;
			if (choice == 'N' || choice == 'n')  
			{	i = 1;
				break;
			}
		}
	}
	return 0;
}

string rand_card()
{	int a[2];
	string result;
	
	do
	{	srand(time(NULL));
		a[0] = rand() % 4;
		a[1] = rand() % 13;
	} while (mark_cards[a[0]][a[1]]);
	switch (a[1])
	{	case 10:
		case 11:
		case 12: sum += 0.5; break;
		default: sum += a[1]+1;
	}
	result = color[a[0]] + ' ' + num[a[1]];
	mark_cards[a[0]][a[1]] = 1;
	
	return result;
}

int player_stage()
{	int i, j;
	char choice_1;
	cards_num_1 = 0;
	sum = 0;
	sum_1 = 0;
	
	
	cout << "Game on~~~" << endl;
	cout << "Ur turn." << endl;
	cards_1[cards_num_1] = rand_card();
	sum_1 = sum;
	++cards_num_1;
	cards_1[cards_num_1] = rand_card();
	sum_1 = sum;
	++cards_num_1;
	cout << "U've got cards: ";
	for (i=0; cards_1[i]!=""; ++i)  cout << cards_1[i] << "  ";
	cout << endl;
	while (true)
	{	cout << "One more card?";
		cin >> choice_1;
		if (choice_1 == 'Y' || choice_1 == 'y')
		{	cards_1[cards_num_1] = rand_card();
			sum_1 = sum;
			++cards_num_1;
			cout << "U've got cards: ";
			for (j=0; cards_1[j]!=""; ++j)  cout << cards_1[j] << "  ";
			cout << endl;
			if (sum > 21)
			{	cout << "U lose!!!" << endl;
				WorL = 1;
				break;
		    }
		}
		if (choice_1 == 'N' || choice_1 == 'n')
		{	sum_1 = sum;
			break;
		}
	}
}

int PC_stage()
{	int i, j;
	cards_num_2 = 0;
	sum = 0;
	sum_2 = 0;
	
	cout << "Now my turn." << endl;
	cards_2[cards_num_2] = rand_card();
	sum_2 = sum;
	++cards_num_2;
	cards_2[cards_num_2] = rand_card();
	sum_2 = sum;
	++cards_num_2;
	cout << "I've got cards: ";
	for (i=0; cards_2[i]!=""; ++i)  cout << cards_2[i] << "  ";
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
		cards_2[cards_num_2] = rand_card();
		sum_2 = sum;
		++cards_num_2;
		cout << "I've got cards: ";
		for (j=0; cards_2[j]!=""; ++j)  cout << cards_2[j] << "  ";
		cout << endl;	
	}
	if (sum_2 > 21) cout << "U win!!!" <<endl;
	else cout << "U lose!!!" << endl;
}
