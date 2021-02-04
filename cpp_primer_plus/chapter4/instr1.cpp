/*
 * @Date: 2021-02-04 23:59:27
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
  cin >> name;
  cout << "Enter your favorite dessert:\n";
  cin >> dessert;
  cout << "I have some delicious " << dessert;
  cout << " for you, " << name << ".\n";
  return 0;
}