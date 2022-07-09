#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
  for (Iter it = spells.begin(); it != spells.end(); it++) {
    delete (*it);
  }
  spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
  if (not spell)
    return;
  for (Iter it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spell->getName())
      return;
  }
  spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const string& spellName) {
  for (Iter it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spellName) {
      delete (*it);
      spells.erase(it);
      return;
    }
  }
}

ASpell* SpellBook::createSpell(const string& spellName) {
  for (Iter it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spellName) {
      return (*it);
    }
  }
  return NULL;
}
