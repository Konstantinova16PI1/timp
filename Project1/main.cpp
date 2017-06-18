#include "ceaser.h"
#include "replace.h"
#include <iostream>
#include <string>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TextTestRunner.h>

using namespace std;

class CreapterTest:public CppUnit::TestFixture
{
private:
  Ceaser * ceaser;
  Replace * replace;

public:
 void setUp()
 // Положительные тесты
 {
   ceaser = new Ceaser(20);
   replace = new Replace(string("zxcvbnmlkjhgfdsaqwertyuiop"));
 }
 void tearDown()
 {
   delete ceaser;
   delete replace;
 }

 void PositiveTest()
 {
   CPPUNIT_ASSERT_NO_THROW(ceaser->encrypt(string("Hello darkness my old friend")));
   CPPUNIT_ASSERT_NO_THROW(replace->decrypt(string("I've come to talk with you again")));
 }

 void testString()
  {
   CPPUNIT_ASSERT_THROW_MESSAGE("Нулевая строка",ceaser->encrypt(string("")),CeaserException);
   CPPUNIT_ASSERT_THROW_MESSAGE("Нулевая строка",replace->decrypt(string("")),ReplaceException);
 }

 void testLessKey()
 {
   CPPUNIT_ASSERT_THROW_MESSAGE("Нулевой ключ [Ceaser]", Ceaser(0), CeaserException );
   CPPUNIT_ASSERT_THROW_MESSAGE("Отрицательный ключ [Ceaser]", Ceaser(-2), CeaserException );
   CPPUNIT_ASSERT_THROW_MESSAGE("Ключ меньше 26 символов [Replace] ", Replace(string("zxcvbnmlkj")), ReplaceException );
 }

};

int main(void)
{
  CppUnit::TestSuite* suite = new CppUnit::TestSuite("CreapterTest");

  suite->addTest(new CppUnit::TestCaller<CreapterTest>
  ("PositiveTest", &CreapterTest::PositiveTest ));

  suite->addTest(new CppUnit::TestCaller<CreapterTest>
  ("testVoidString", &CreapterTest::testString ));

  suite->addTest(new CppUnit::TestCaller<CreapterTest>
  ("testLessKey", &CreapterTest::testLessKey ));

  CppUnit::TextTestRunner runner;
  runner.addTest(suite);
  runner.run();
  return 0;
}
