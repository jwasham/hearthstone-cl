#ifndef HEARTHSTONE_CL_HEROCLASS_H
#define HEARTHSTONE_CL_HEROCLASS_H

#include "HeroPower.h"

namespace HearthstoneHeroClass {

class HeroClass {
 private:
  std::string name;
  HeroPower heroPower;

 public:
  HeroClass();
  HeroClass(const HerClass &hc) = delete;
  HeroClass &operator=(const HeroClass &hc) = delete;
  virtual ~HeroClass();
};

}  // namespace HearthstoneHeroClass

#endif  // HEARTHSTONE_CL_HEROCLASS_H
