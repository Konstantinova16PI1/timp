#include "ceaser.h"
#include <iostream>
#include <string>
using namespace std;

Ceaser::Ceaser(int key)
{
  this->key = key;
  if (key <= 0)
    throw CeaserException();

};

string Ceaser::encrypt(std::string values)
{
  if (values.size() == 0)
    throw CeaserException();

  for (int i = 0; i < values.size(); i++)
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
      return values;
};

string Ceaser::decrypt(std::string values)
{
  if (values.size() == 0)
    throw CeaserException();

  for (int i = 0; i < values.size(); i++)
  {
    if (((values[i] >= 'a') && (values[i] <= 'z')) || ((values[i] >= 'A') && (values[i] <= 'Z')))
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
    return values;

  }
}
