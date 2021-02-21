/*
 * @Date: 2021-02-21 23:59:58
 * @LastEditors: lby
 */
#include <iostream>
#include <string>
int main()
{
  using namespace std;
  string word = "?ate";
  for (char ch = 'a'; word != "mate"; ch++)
  {
    cout << word << endl;
    word[0] = ch;
  }
  cout << "After loop ends, word is " << word << endl;
  return 0;
}