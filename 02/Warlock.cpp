#include "Warlock.hpp"

Warlock::Warlock(const string& name, const string& title)
    : name(name), title(title) {
  cout << this->name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock() {
  cout << this->name << ": My job here is done!" << endl;
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
  this->spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(const string& spellName) {
  this->spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(const string& spellName, const ATarget& target) {
  ASpell* spell = this->spellBook.createSpell(spellName);
  if (spell)
    spell->launch(target);
}
