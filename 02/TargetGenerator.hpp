#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <vector>
#include "ATarget.hpp"
using namespace std;

class TargetGenerator {
 private:
  vector<ATarget*> targets;

  TargetGenerator(const TargetGenerator& other);
  TargetGenerator& operator=(const TargetGenerator& other);

 public:
  TargetGenerator();
  ~TargetGenerator();

  void learnTargetType(ATarget* target);
  void forgetTargetType(const string& targetType);
  ATarget* createTarget(const string& targetType);
};

#endif
