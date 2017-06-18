#pragma once
#include <iostream>
#include <string>

class Replace
{
private:
  int range;
  std::string key;
  std::string abc = "abcdefghijklmnopqrstuvwxyz";

public:
  Replace(std::string key);
  std::string encrypt(std::string values);
  std::string decrypt(std::string values);
};


class ReplaceException:std::exception // класс-исключение
{
 public:
 const char* what() const noexcept
 {
   return "Replace creapter error";
 }
};
