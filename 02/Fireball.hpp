#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"
using namespace std;

class Fireball : public ASpell {
 public:
  Fireball();
  ~Fireball();
  virtual ASpell* clone() const;
};

#endif
