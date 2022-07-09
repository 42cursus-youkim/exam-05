#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
  for (Iter it = targets.begin(); it != targets.end(); it++) {
    delete (*it);
  }
  targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
  if (not target)
    return;
  for (Iter it = targets.begin(); it != targets.end(); it++) {
    if ((*it)->getType() == target->getType()) {
      return;
    }
  }
  targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const string& targetType) {
  for (Iter it = targets.begin(); it != targets.end(); it++) {
    if ((*it)->getType() == targetType) {
      delete (*it);
      targets.erase(it);
      return;
    }
  }
}

ATarget* TargetGenerator::createTarget(const string& targetType) {
  for (Iter it = targets.begin(); it != targets.end(); it++) {
    if ((*it)->getType() == targetType) {
      return (*it);
    }
  }
  return NULL;
}
