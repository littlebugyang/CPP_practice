/*
 * @Date: 2021-02-22 21:15:12
 * @LastEditors: lby
 */
#include <iostream>
int main()
{
  using namespace std;
  char ch;
  int count = 0;
  cin.get(ch);
  while (cin.fail() == false)
  {
    cout << ch;
    ++count;
    cin.get(ch);
  }
  cout << endl
       << count << " characters read\n";
  return 0;
}