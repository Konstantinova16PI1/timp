#include "Ceaser.h"
#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;



Ceaser::Ceaser()
{
	cin >> key;
	if (typeid(key) != typeid(int))
		throw CeaserException();
}


char* Ceaser::encode(char* values)
{
	for (unsigned int i = 0; i < strlen(values); i++)
	{
		if ((values[i] >= 'a') && (values[i] <= 'z') || (values[i] >= 'A') && (values[i] <= 'Z'))
		{
			if ((values[i] >= 'a') && (values[i] <= 'z'))
			{
				if (values[i] >= ('z' - key))
				{
					values[i] = values[i] - 26 + key;
				}
				else values[i] = values[i] + key;
			}
			else if ((values[i] >= 'A') && (values[i] <= 'Z'))
			{
				if (values[i] >= ('Z' - key))
				{
					values[i] = values[i] - 26 + key;
				}
				else values[i] = values[i] + key;
			}
		}
		else throw CeaserException();
	}
	return values;
};

char* Ceaser::decode(char*values)
{

	for (unsigned int i = 0; i < strlen(values); i++)
	{
		if ((values[i] >= 'a') && (values[i] <= 'z') || (values[i] >= 'A') && (values[i] <= 'Z'))
		{
			if ((values[i] >= 'a') && (values[i] <= 'z'))
			{
				if (values[i] <= ('a' + key))
				{
					values[i] = values[i] + 26 - key;
				}
				else values[i] = values[i] - key;
			}
			if ((values[i] >= 'A') && (values[i] <= 'Z'))
			{
				if (values[i] <= ('A' + key))
				{
					values[i] = values[i] + 26 - key;
				}
				else values[i] = values[i] - key;
			}
		}
		else throw CeaserException();

	}
	return values;
};
void Ceaser::print(char* values)
{
	cout << values << endl;
}