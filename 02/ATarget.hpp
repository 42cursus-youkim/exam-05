#ifndef ATARGET_HPP
#define ATARGET_HPP

class ATarget;

#include "ASpell.hpp"

class ATarget {
 protected:
  string type;

 public:
  ATarget();
  ATarget(const string& type);
  ATarget(const ATarget& target);
  ATarget& operator=(const ATarget& target);
  virtual ~ATarget();

  const string& getType() const;
  
  virtual ATarget* clone() const = 0;
  void getHitBySpell(const ASpell& spell) const;
};

#endif
