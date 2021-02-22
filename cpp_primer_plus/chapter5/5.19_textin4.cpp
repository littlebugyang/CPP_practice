/*
 * @Date: 2021-02-22 21:50:48
 * @LastEditors: lby
 */
#include <iostream>
int main(void)
{
  using namespace std;
  int ch;
  int count = 0;
  while ((ch = cin.get()) != EOF)
  {
    cout.put(char(ch));
    ++count;
  }
  cout << endl
       << count << " characters read\n";
  return 0;
}