#include <iostream>
#include "Warlock.hpp"
using namespace std;

int main() {
  const Warlock richard("Richard", "Mistress of Magma");
  richard.introduce();
  cout << richard.getName() << " - " << richard.getTitle() << endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}
