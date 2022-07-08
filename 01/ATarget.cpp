#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const string& type) : type(type) {}

ATarget::ATarget(const ATarget& other) : type(other.getType()) {}

ATarget& ATarget::operator=(const ATarget& other) {
  type = other.getType();
  return (*this);
}

ATarget::~ATarget() {}

const string& ATarget::getType() const {
  return type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
  cout << type << " has been " << spell.getEffects() << "!" << endl;
}
