#include <iostream>
#include <cstring>
#include "Ceaser.h"
#include "replace.h"

using namespace std;

int ask()
{
	int n;
	cout << "3-encode, 4-decode" << endl;
	cin >> n;
	return n;
}
int main()
{
	char* values;
	values = new char[26];
	do {
		cout << "What algoritm would you like to use? Enter 1-ceaser, 2-replace" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			switch (ask())
			{
			case 3:
			{
				cout << "Enter word" << endl;
				cin >> values;
				cout << "Enter key" << endl;
				Ceaser m;
				m.print(m.encode(values));
				break;
			}
			case 4:
			{
				cout << "Enter word" << endl;
				cin >> values;
				cout << "Enter key" << endl;
				Ceaser k;
				k.print(k.decode(values));
				break;
			}
			}
		break;
		}
		case 2:
		{
			switch (ask())
			{
			case 3:
			{
				cout << "Enter word" << endl;
				cin >> values;
				cout << "Enter dictionaty" << endl;
				Replace m;
				m.print(m.encode(values));
				break;
			}
			case 4:
			{
				cout << "Enter word" << endl;
				cin >> values;
				cout << "Enter dictionaty" << endl;
				Replace k;
				k.print(k.decode(values));
				break;
			}
			}
		break;
		}
		}
		} while (cin);


		return 0;
	}