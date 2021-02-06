/*
 * @Date: 2021-02-07 00:05:09
 * @LastEditors: lby
 */
#include <iostream>
int main()
{
  using namespace std;
  int donuts = 6;
  double cups = 4.5;
  cout << "donuts value = " << donuts;
  cout << " and donuts address = " << &donuts << endl;

  cout << "cups value = " << cups;
  cout << " and cups address = " << &cups << endl;
  return 0;
}