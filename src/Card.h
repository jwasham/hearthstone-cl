#ifndef HEARTHSTONE_CL_CARD_H
#define HEARTHSTONE_CL_CARD_H

#include <string>

class Card {
 private:
  std::string name;
  short cost;

 public:
  Card();
  Card(const Card &c){};  // dummy copy constructor
  Card &operator=(const Card &c) {
    return *this;
  };  // dummy assignment operator
  virtual ~Card();
  //  bool canPlayCard() const;
};

#endif  // HEARTHSTONE_CL_CARD_H
