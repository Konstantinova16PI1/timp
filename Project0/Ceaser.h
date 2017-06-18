#pragma once
#include <exception>
class Ceaser
{
private:
	int key;


public:
	char* encode(char* values);
	char* decode(char* values);
	void print(char* values);
	Ceaser();
};

class CeaserException :std::exception 
{
public:
	const char* what() const noexcept
	{
		return "Ceaser cipher error";
	}
};