#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <vector>
#include "ASpell.hpp"
using namespace std;

class SpellBook {
 private:
  vector<ASpell*> spells;
  SpellBook(const SpellBook& spellBook);
  SpellBook& operator=(const SpellBook& spellBook);

 public:
  SpellBook();
  ~SpellBook();
  void learnSpell(ASpell* spell);
  void forgetSpell(const string& spellName);
  ASpell* createSpell(const string& spellName);
};

#endif