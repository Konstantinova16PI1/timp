#include "replace.h"
#include <cstring>
#include <iostream>
using namespace std;


Replace::Replace()
{
	dict = new char[26];
	cin >> dict;
	for (int i = 0; i < strlen(dict); i++)
	{
		if ((dict[i] >= 'a') && (dict[i] <= 'z') || (dict[i] >= 'A') && (dict[i] <= 'Z'))
		{

		}
		else throw ReplaceException();
	}
}

char* Replace::encode(char* values)
{
	for (int i = 0; i < strlen(values); i++)
	{
		if ((values[i] >= 'a') && (values[i] <= 'z') || (values[i] >= 'A') && (values[i] <= 'Z'))
		{
			int pos;
			for (int j = 0; j < strlen(abc); j++)
			{
				if (values[i] == abc[j])
				{
					pos = j;
					break;
				}
			}
			values[i] = dict[pos];
		}
		else throw ReplaceException();
		}
		return values;

};

char* Replace::decode(char* values)
{
	for (int i = 0; i < strlen(values); i++)
	{
		if ((values[i] >= 'a') && (values[i] <= 'z') || (values[i] >= 'A') && (values[i] <= 'Z'))
		{
			int pos;
			for (int j = 0; j < strlen(abc); j++)
			{
				if (values[i] == dict[j])
				{
					pos = j;
					break;
				}
			}
			values[i] = abc[pos];
		}
		else throw ReplaceException();
	}
	return values;
};
void Replace::print(char* values)
{
	cout << values << endl;
}
