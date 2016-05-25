#ifndef HEARTHSTONE_CL_HEROCLASS_H
#define HEARTHSTONE_CL_HEROCLASS_H

#include "HeroPower.h"

class HeroClass {
private:
  std::string name;
  HeroPower heroPower;

public:
  HeroClass();
  HeroClass(const HerClass &hc){}; // dummy copy constructor
  HeroClass &operator=(const HeroClass &hc) {
    return *this;
  }; // dummy assignment operator
  virtual ~HeroClass();
};

#endif // HEARTHSTONE_CL_HEROCLASS_H
