/*
 * @Date: 2021-02-10 23:26:55
 * @LastEditors: lby
 */
#include <iostream>
#include <cstring> // declare strlen(), strcpy()
int main()
{
  using namespace std;
  char animal[20] = "bear";
  const char *bird = "wren";
  char *ps;
  cout << animal << " and ";
  cout << bird << "\n";
  
  cout << "Enter a kind of animal: ";
  cin >> animal;
  
  ps = animal;
  cout << ps << "!\n";
  cout << "Before using strcpy():\n";
  cout << animal << " at " << (int *)animal << endl;
  cout << ps << " at " << (int *)ps << endl;
  ps = new char[strlen(animal) + 1];
  strcpy(ps, animal);
  cout << "After using strcpy():\n";
  cout << animal << " at " << (int *)animal << endl;
  cout << ps << " at " << (int *)ps << endl;
  delete[] ps;
  return 0;
}