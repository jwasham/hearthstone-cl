#ifndef HEARTHSTONE_CL_CARD_H
#define HEARTHSTONE_CL_CARD_H

#include <string>

class Card {
 public:
  Card();
  Card(const Card &c){};  // dummy copy constructor
  Card &operator=(const Card &c) {
    return *this;
  };  // dummy assignment operator
  virtual ~Card();
  //  bool canPlayCard() const;

private:
  short cost;
  std::string name;
};

#endif  // HEARTHSTONE_CL_CARD_H
