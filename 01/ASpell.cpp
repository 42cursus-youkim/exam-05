#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(string name, string effects) : name(name), effects(effects) {}

ASpell::ASpell(const ASpell& spell)
    : name(spell.getName()), effects(spell.getEffects()) {}

ASpell& ASpell::operator=(const ASpell& spell) {
  name = spell.getName();
  effects = spell.getEffects();
  return (*this);
}

ASpell::~ASpell() {}

const string& ASpell::getName() const {
  return name;
}

const string& ASpell::getEffects() const {
  return effects;
}

void ASpell::launch(const ATarget& target) const {
  target.getHitBySpell(*this);
}
