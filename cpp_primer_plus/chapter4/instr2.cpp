/*
 * @Date: 2021-02-05 00:26:30
 * @LastEditors: lby
 */
#include <iostream>
int main()
{
  using namespace std;
  const int ArSize = 20;
  char name[ArSize];
  char dessert[ArSize];
  
  cout << "Enter your name:\n";
  cin.getline(name, ArSize);
  cout << "Enter your favorite dessert:\n";
  cin.getline(dessert, ArSize);
  cout << "I have some delicious " << dessert;
  cout << " for you, " << name << ".\n";
  return 0;
}