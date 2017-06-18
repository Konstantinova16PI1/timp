#pragma once
#include <exception>
class Replace
{
private:
	int step;
	char *dict;
	const char *abc = "abcdefghijklmnopqrstuvwxyz";
	


public:
	char* encode(char* values);
	char* decode(char* values);
	void print(char* values);
	Replace();
};
class ReplaceException :std::exception 
{
public:
	const char* what() const noexcept
	{
		return "Replace cipher error";
	}
};