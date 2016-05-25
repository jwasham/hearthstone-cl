#ifndef HEARTHSTONE_CL_HEROCLASS_H
#define HEARTHSTONE_CL_HEROCLASS_H

#include "HeroPower.h"

class HeroClass {
private:
  std::string name;
  HeroPower heroPower;

public:
  HeroClass();
  virtual ~HeroClass();
};

#endif // HEARTHSTONE_CL_HEROCLASS_H
