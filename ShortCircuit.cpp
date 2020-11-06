// Check if compiler optimisation doesn't change the below behaviour - validating subsequent conditions should be ommited if a condition is met:
// -> 'short-circuit evaluation' guarantees the wanted behaviour:
// Checked on vs2019; Linux g++ (20201010, wd)

// Quote: Short-circuit evaluation, minimal evaluation, or McCarthy evaluation (after John McCarthy) is the semantics of some Boolean
//        operators in some programming languages in which the second argument is executed or evaluated only if the first argument
//        does not suffice to determine the value of the expression: when the first argument of the AND function evaluates to false,
//        the overall value must be false; and when the first argument of the OR function evaluates to true, the overall value must
//        be true.

#include <iostream>
#include <string>

using namespace std;

#include <math.h>

int main(int argc, char * argv[])
{
   string sPattern = { "123456 " };

   // default pattern can be replace with the optional first command line parameter
   if (argc > 1) sPattern = argv[1];

   cout << "Pattern testing: " << sPattern << endl;

   auto bOne   = false;
   auto bTwo   = false;
   auto bThree = false;

   cout << "Overall: ";
   if (   (bOne   = (sPattern.find("1") != string::npos))
       || (bTwo   = (sPattern.find("2") != string::npos))
       || (bThree = (sPattern.find("3") != string::npos))
      )
   {
      cout << "true" << endl;
   }
   else
   {
      cout << "false" << endl;
   }

   cout << "bOne:    " << (bOne   ? "true" : "false") << endl;
   cout << "bTwo:    " << (bTwo   ? "true" : "false") << endl;
   cout << "bThree:  " << (bThree ? "true" : "false") << endl;

   // so the following is allowed:
   int a = 10;
   int b = 0;
   int c = 20;
   // Intentional empty control statement, but with an operation and an assignment -> mark with {}
   b = 0;  if (b != 0 && (c = a / b) > 0){};  cout << c << endl;
   b = 2;  if (b != 0 && (c = a / b) > 0){};  cout << c << endl;

   return (0);
}
