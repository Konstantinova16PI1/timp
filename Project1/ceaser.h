#pragma once
#include <string>

class Ceaser
{
private:
  int key;

public:
  Ceaser(int key);
  std::string decrypt(std::string values);
  std::string encrypt(std::string values);
};

class CeaserException:std::exception // класс-исключение
{
 public:
   const char* what() const noexcept
   {
     return "Ceaser creapter error";
   }
};
