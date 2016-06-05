#ifndef HEARTHSTONE_CL_CARD_H
#define HEARTHSTONE_CL_CARD_H

#include <string>

namespace HearthstoneCard {

class Card {
 public:
  Card();
//  Card(const Card &c) = delete;
//  Card &operator=(const Card &c) = delete;
  virtual ~Card();
  //  bool canPlayCard() const;

 private:
  int cost_;
  std::string name_;
};

}  // namespace HearthstoneCard

#endif  // HEARTHSTONE_CL_CARD_H
