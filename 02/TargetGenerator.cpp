#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
  vector<ATarget*>::iterator it;
  for (it = targets.begin(); it != targets.end(); it++)
    delete (*it);
  targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
  if (target == NULL)
    return;
  vector<ATarget*>::iterator it;
  for (it = targets.begin(); it != targets.end(); it++) {
    if ((*it)->getType() == target->getType())
      return;
  }
  targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const string& targetType) {
  vector<ATarget*>::iterator it;
  for (it = targets.begin(); it != targets.end(); it++) {
    if ((*it)->getType() == targetType) {
      delete (*it);
      targets.erase(it);
      return;
    }
  }
}

ATarget* TargetGenerator::createTarget(const string& targetType) {
  vector<ATarget*>::iterator it;
  for (it = targets.begin(); it != targets.end(); it++) {
    if ((*it)->getType() == targetType)
      return (*it);
  }
  return 0;
}
