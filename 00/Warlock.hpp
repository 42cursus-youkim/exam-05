#include <iostream>
#include <string>
using namespace std;

class Warlock {
 private:
  string name;
  string title;

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
};
