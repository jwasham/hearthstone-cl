#ifndef HEARTHSTONE_CL_HEROPOWER_H
#define HEARTHSTONE_CL_HEROPOWER_H

namespace HearthstoneHeroPower {

class HeroPower {
 private:
  short cost;
  bool used;

 public:
  HeroPower();
  HeroPower(const HeroPower &h){};  // dummy copy constructor
  HeroPower &operator=(const HeroPower &h) {
    return *this;
  };  // dummy assignment operator
  virtual ~HeroPower();
  bool canUse() const;
  void use(Entity &entity);
};

}  // namespace HearthstoneHeroPower

#endif  // HEARTHSTONE_CL_HEROPOWER_H
