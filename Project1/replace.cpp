#include "replace.h"
#include <string>
#include <iostream>
using namespace std;

Replace::Replace(std::string key)
{
  this->key = key;
  if (key.size() != 26)
    throw ReplaceException();
};


string Replace::encrypt(std::string values)
{
  if (values.size() == 0)
    throw ReplaceException();

  for (int i = 0; i < values.size(); i++)
  {
    for (int j = 0; j < abc.size(); j++)
    {
      if (values[i] == abc[j])
      {
        values[i] = key[j];
        break;
      }
      // Capital letters
      else if ((values[i] - 32) == abc[j])
      {
        values[i] = key[j] + 32;
      }
    }
  }
  return values;

};

string Replace::decrypt(std::string values)
{
  if (values.size() == 0)
    throw ReplaceException();

  for (int i = 0; i < values.size(); i++)
  {
    for (int j = 0; j < abc.size(); j++)
    {
      if (values[i]  == key[j])
      {
        values[i] = abc[j] ;
        break;
      }
      // Capital letters
      else if ((values[i]-32) == key[j])
      {
        values[i] = abc[j] + 32;
        break;
      }
    }
  }
  return values;

};
