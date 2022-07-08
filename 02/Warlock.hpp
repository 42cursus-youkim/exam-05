#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include "SpellBook.hpp"
using namespace std;

class Warlock {
 private:
  string name;
  string title;
  SpellBook spellBook;
  Warlock();
  Warlock(const Warlock& other);
  Warlock& operator=(const Warlock& other);

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
