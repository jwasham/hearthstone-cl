#ifndef HEARTHSTONE_CL_CHARACTER_H
#define HEARTHSTONE_CL_CHARACTER_H

namespace HearthstoneCharacter {

class Character {
 public:
  Character();
  Character(const Character &c) = delete;
  Character &operator=(const Character &c) = delete;
  virtual ~Character();
};

}  // namespace HearthstoneCharacter

#endif  // HEARTHSTONE_CL_CHARACTER_H
