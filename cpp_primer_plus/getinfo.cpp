/*
 * @Date: 2021-01-29 11:24:20
 * @LastEditors: lby
 */
#include <iostream>

int main()
{
  using namespace std;

  int carrots;

  cout << "How many carrots do you have?" << endl;
  cin >> carrots;
  cout << "Here are tow more. ";
  carrots = carrots + 2;
  cout << "Now you have " << carrots << " carrots." << endl;
  return 0;
}