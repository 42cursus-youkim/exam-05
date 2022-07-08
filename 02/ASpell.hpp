#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
using namespace std;

class ASpell;

#include "ATarget.hpp"
class ASpell {
 protected:
  string name;
  string effects;

 public:
  ASpell();
  ASpell(string name, string effects);
  ASpell(const ASpell& spell);
  ASpell& operator=(const ASpell& spell);
  virtual ~ASpell();
  const string& getName() const;
  const string& getEffects() const;
  virtual ASpell* clone() const = 0;
  void launch(const ATarget& target) const;
};

#endif
