#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++)
    delete (*ptr);
  this->spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
  if (spell == NULL)
    return;
  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++) {
    if ((*ptr)->getName() == spell->getName())
      return;
  }
  this->spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const string& spellName) {
  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++) {
    if ((*ptr)->getName() == spellName) {
      delete (*ptr);
      this->spells.erase(ptr);
      return;
    }
  }
}

ASpell* SpellBook::createSpell(const string& spellName) {
  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++) {
    if ((*ptr)->getName() == spellName)
      return (*ptr);
  }
  return 0;
}
