#ifndef HEARTHSTONE_CL_HEROPOWER_H
#define HEARTHSTONE_CL_HEROPOWER_H

class HeroPower {
private:
  short cost;
  bool used;

public:
  HeroPower();
  virtual ~HeroPower();
  bool canUse() const;
  void use(Entity &entity);
};

#endif // HEARTHSTONE_CL_HEROPOWER_H
