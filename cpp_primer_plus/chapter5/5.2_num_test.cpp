/*
 * @Date: 2021-02-20 02:18:41
 * @LastEditors: lby
 */
#include <iostream>
int main()
{
  using namespace std;
  cout << "Enter the starting countdown value: ";
  int limit;
  cin >> limit;
  int i;
  for (i = limit; i; i--)
    cout << "i = " << i << "\n";
  cout << "Done now that i = " << i << "\n";
  return 0;
}