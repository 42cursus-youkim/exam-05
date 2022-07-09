#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++)
    delete (*it);
  spells.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
  if (spell == NULL)
    return;
  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spell->getName())
      return;
  }
  spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const string& spellName) {
  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spellName) {
      delete (*it);
      spells.erase(it);
      return;
    }
  }
}

ASpell* SpellBook::createSpell(const string& spellName) {
  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spellName)
      return (*it);
  }
  return NULL;
}
