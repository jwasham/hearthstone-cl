#ifndef HEARTHSTONE_CL_HERO_H
#define HEARTHSTONE_CL_HERO_H

#include "HeroClass.h"

// http://www.hearthhead.com/heroes

namespace HearthstoneHero {

class Hero : public Character {
 public:
  Hero();
  Hero(const Hero &h) = delete;
  Hero &operator=(const Hero &h) = delete;
  ~Hero();

 private:
  std::string name_;
  HeroClass hero_class_;
  int health_;
  int armor_;
};

}  // namespace HearthstoneHero

#endif  // HEARTHSTONE_CL_HERO_H
