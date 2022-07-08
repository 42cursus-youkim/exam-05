#include "Warlock.hpp"

Warlock::Warlock(const string& name, const string& title)
    : name(name), title(title) {
  cout << name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock() {
  cout << name << ": My job here is done!" << endl;

  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++)
    delete (*it);
  spells.clear();
}

const string& Warlock::getName() const {
  return name;
}

const string& Warlock::getTitle() const {
  return title;
}

void Warlock::setTitle(const string& title) {
  this->title = title;
}

void Warlock::introduce() const {
  cout << name << ": I am " << name << ", " << title << "!" << endl;
}

void Warlock::learnSpell(ASpell* spell) {
  if (spell == NULL)
    return;
  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spell->getName())
      return;
  }
  spells.push_back(spell->clone());
}

void Warlock::forgetSpell(const string& spellName) {
  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spellName) {
      delete (*it);
      spells.erase(it);
      return;
    }
  }
}

void Warlock::launchSpell(const string& spellName, const ATarget& target) {
  vector<ASpell*>::iterator it;
  for (it = spells.begin(); it != spells.end(); it++) {
    if ((*it)->getName() == spellName) {
      (*it)->launch(target);
      return;
    }
  }
}
