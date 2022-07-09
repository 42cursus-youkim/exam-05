#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <vector>
#include "ASpell.hpp"
using namespace std;

class Warlock {
 private:
  typedef vector<ASpell*> Spells;
  typedef Spells::iterator Iter;

  string name;
  string title;
  Spells spells;

  Warlock();
  Warlock(const Warlock& warlock);
  Warlock& operator=(const Warlock& warlock);

 public:
  Warlock(const string& name, const string& title);
  ~Warlock();

  const string& getName() const;
  const string& getTitle() const;
  void setTitle(const string& title);

  void introduce() const;
  void learnSpell(ASpell* spell);
  void forgetSpell(const string& spellName);
  void launchSpell(const string& spellName, const ATarget& target);
};

#endif
