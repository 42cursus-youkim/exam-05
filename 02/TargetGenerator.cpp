#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
  vector<ATarget*>::iterator ptr;
  for (ptr = this->targets.begin(); ptr != this->targets.end(); ptr++)
    delete (*ptr);
  this->targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
  if (target == NULL)
    return;
  vector<ATarget*>::iterator ptr;
  for (ptr = this->targets.begin(); ptr != this->targets.end(); ptr++) {
    if ((*ptr)->getType() == target->getType())
      return;
  }
  this->targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const string& targetType) {
  vector<ATarget*>::iterator ptr;
  for (ptr = this->targets.begin(); ptr != this->targets.end(); ptr++) {
    if ((*ptr)->getType() == targetType) {
      delete (*ptr);
      this->targets.erase(ptr);
      return;
    }
  }
}

ATarget* TargetGenerator::createTarget(const string& targetType) {
  vector<ATarget*>::iterator ptr;
  for (ptr = this->targets.begin(); ptr != this->targets.end(); ptr++) {
    if ((*ptr)->getType() == targetType)
      return (*ptr);
  }
  return 0;
}
