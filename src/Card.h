#ifndef HEARTHSTONE_CL_CARD_H
#define HEARTHSTONE_CL_CARD_H

class Card {
private:
  std::string name;
  short cost;

public:
  Card();
  virtual ~Card();
  bool canPlayCard() const;
};

#endif // HEARTHSTONE_CL_CARD_H
