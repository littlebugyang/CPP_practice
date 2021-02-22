/*
 * @Date: 2021-02-22 17:50:00
 * @LastEditors: lby
 */
#include <iostream>
int main()
{
  using namespace std;
  char ch;
  int count = 0;
  cout << "Enter characters; enter # to quit:\n";
  cin >> ch;
  while (ch != '#')
  {
    cout << ch;
    ++count;
    cin >> ch;
  }
  cout << endl
       << count << " characters read\n";
  return 0;
}