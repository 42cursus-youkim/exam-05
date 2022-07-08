#include "Warlock.hpp"

Warlock::Warlock(const string& name, const string& title)
    : name(name), title(title) {
  cout << this->name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock() {
  cout << this->name << ": My job here is done!" << endl;

  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++)
    delete (*ptr);
  this->spells.clear();
}

const string& Warlock::getName() const {
  return this->name;
}

const string& Warlock::getTitle() const {
  return this->title;
}

void Warlock::setTitle(const string& title) {
  this->title = title;
}

void Warlock::introduce() const {
  cout << this->name << ": I am " << this->name << ", " << this->title << "!"
       << endl;
}

void Warlock::learnSpell(ASpell* spell) {
  if (spell == NULL)
    return;
  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++) {
    if ((*ptr)->getName() == spell->getName())
      return;
  }
  this->spells.push_back(spell->clone());
}

void Warlock::forgetSpell(const string& spellName) {
  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++) {
    if ((*ptr)->getName() == spellName) {
      delete (*ptr);
      this->spells.erase(ptr);
      return;
    }
  }
}

void Warlock::launchSpell(const string& spellName, const ATarget& target) {
  vector<ASpell*>::iterator ptr;
  for (ptr = this->spells.begin(); ptr != this->spells.end(); ptr++) {
    if ((*ptr)->getName() == spellName) {
      (*ptr)->launch(target);
      return;
    }
  }
}
