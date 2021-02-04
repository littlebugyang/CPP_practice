/*
 * @Date: 2021-02-05 00:52:08
 * @LastEditors: lby
 */
#include <iostream>
int main()
{
  using namespace std;
  cout << "What year was your house built?\n";
  int year;
  // cin >> year;
  // this results in never getting the opportunity to enter the address
  (cin >> year).get(); // read and discard the newline character
  cout << "What is its street address?\n";
  char address[80];
  cin.getline(address, 80);
  cout << "Year built: " << year << endl;
  cout << "Address: " << address << endl;
  cout << "Done!\n";
  return 0;
}