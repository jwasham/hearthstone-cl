#ifndef HEARTHSTONE_CL_CHARACTER_H
#define HEARTHSTONE_CL_CHARACTER_H

class Character {
private:
public:
  Character();
  Character(const Character &c){}; // dummy copy constructor
  Character &operator=(const Character &c) {
    return *this;
  }; // dummy assignment operator
  virtual ~Character();
};

#endif // HEARTHSTONE_CL_CHARACTER_H
