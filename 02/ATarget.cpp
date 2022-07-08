#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const string& type) : type(type) {}

ATarget::ATarget(const ATarget& target) : type(target.getType()) {}

ATarget& ATarget::operator=(const ATarget& target) {
  this->type = target.getType();
  return (*this);
}

ATarget::~ATarget() {}

const string& ATarget::getType() const {
  return this->type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
  cout << this->type << " has been " << spell.getEffects() << "!" << endl;
}
