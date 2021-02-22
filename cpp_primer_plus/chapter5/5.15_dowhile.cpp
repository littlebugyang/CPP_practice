/*
 * @Date: 2021-02-22 17:41:07
 * @LastEditors: lby
 */
#include <iostream>
int main()
{
  using namespace std;
  int n;
  cout << "Enter numbers in the range 1-10 to find ";
  cout << "my favorite number\n";
  do
  {
    cin >> n;
  } while (n != 7);
  cout << "Yes, 7 is my favorite.\n";
  return 0;
}