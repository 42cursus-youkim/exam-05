#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <vector>
#include "ASpell.hpp"
using namespace std;

class SpellBook {
 private:
  typedef vector<ASpell*> Spells;
  typedef Spells::iterator Iter;

  Spells spells;

 private:
  SpellBook(const SpellBook& other);
  SpellBook& operator=(const SpellBook& other);

 public:
  SpellBook();
  ~SpellBook();

  void learnSpell(ASpell* spell);
  void forgetSpell(const string& spellName);
  ASpell* createSpell(const string& spellName);
};

#endif
