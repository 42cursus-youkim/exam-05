#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
  vector<ASpell*>::iterator ptr;
  for (ptr = spells.begin(); ptr != spells.end(); ptr++)
    delete (*ptr);
  spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
  if (spell == NULL)
    return;
  vector<ASpell*>::iterator ptr;
  for (ptr = spells.begin(); ptr != spells.end(); ptr++) {
    if ((*ptr)->getName() == spell->getName())
      return;
  }
  spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const string& spellName) {
  vector<ASpell*>::iterator ptr;
  for (ptr = spells.begin(); ptr != spells.end(); ptr++) {
    if ((*ptr)->getName() == spellName) {
      delete (*ptr);
      spells.erase(ptr);
      return;
    }
  }
}

ASpell* SpellBook::createSpell(const string& spellName) {
  vector<ASpell*>::iterator ptr;
  for (ptr = spells.begin(); ptr != spells.end(); ptr++) {
    if ((*ptr)->getName() == spellName)
      return (*ptr);
  }
  return 0;
}
