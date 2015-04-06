#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

string rand_card(string cards[]);
float sum(string cards[]);

int main()
{	int judge, i, j;
	int WorL, cards_num_1, cards_num_2;
	float sum_1, sum_2;
	char choice, choice_1;
	int mark_cards[4][13] = {0};
	string cards_1[21], cards_2[21];						//store a 4-character string
	
	judge = 1;
	while (judge)
	{	WorL = 1;											//initialization
		cards_num_1 = cards_num_2 = 0;
		for (i=0; i<21; ++i)
		{	cards_1[i] = "";
			cards_2[i] = "";
		}
		memset(mark_cards,0,sizeof(mark_cards));
		sum_1 = sum_2 = 0;
		
		cout << "Game on~~~" << endl;						//player stage
		cout << "Ur turn." << endl;
		cards_1[cards_num_1] = rand_card(cards_1[21]);
		sum_1 = sum(cards_1[21]);
		++cards_num_1;
		cards_1[cards_num_1] = rand_card(cards_1[21]);
		sum_1 = sum(cards_1[21]);
		++cards_num_1;
		cout << "U've got cards: ";
		for (j=0; cards_1[j]!=""; ++j)  cout << cards_1[j] << "  ";
		cout << endl;
		while (true)
		{	cout << "One more card?";
			cin >> choice_1;
			if (choice_1 == 'Y' || choice_1 == 'y')
			{	cards_1[cards_num_1] = rand_card(cards_1[21]);
				sum_1 = sum(cards_1[21]);
				++cards_num_1;
				cout << "U've got cards: ";
				for (j=0; cards_1[j]!=""; ++j)  cout << cards_1[j] << "  ";
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
		if (WorL)
		{	cout << "Now my turn." << endl;
			cards_2[cards_num_2] = rand_card(cards_2[21]);
			sum_2 = sum(cards_2[21]);
			++cards_num_2;
			cards_2[cards_num_2] = rand_card(cards_2[21]);
			sum_2 = sum(cards_2[21]);
			++cards_num_2;
			cout << "I've got cards: ";
			for (j=0; cards_2[j]!=""; ++j)  cout << cards_2[j] << "  ";
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
				cards_2[cards_num_2] = rand_card(cards_2[21]);
				sum_2 = sum(cards_2[21]);
				++cards_num_2;
				cout << "I've got cards: ";
				for (j=0; cards_2[j]!=""; ++j)  cout << cards_2[j] << "  ";
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

string rand_card(string cards[])
{	int a[2],j, judge;
	string result;
	
	do
	{	srand(time(NULL));
		a[0] = rand() % 4;
		a[1] = rand() % 13;
		result = a[0] + " " + a[1];
		for (j=0; cards[j]!=""; ++j)
		{	if (result == cards[j])  judge = 1;
		}
	} while (judge);
	
	return result;
}

float sum(string cards[])
{	int k;
	int num;
	string num_str;
	float result;
	
	result = 0;
	for (k=0; cards[k]!=""; ++k)
	{	num_str = cards[k].substr(2,2);
		num = atoi(num_str.c_str());
		switch (num)
		{	case 10:
			case 11:
			case 12: result += 0.5; break;
			default: result += num + 1;
		}
	}
	
	return result;
}
