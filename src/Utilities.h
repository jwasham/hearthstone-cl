#ifndef HEARTHSTONE_CL_UTILITIES_H
#define HEARTHSTONE_CL_UTILITIES_H

#include <string>

class Utilities {
public:
  Utilities(const Utilities &h){}; // dummy copy constructor
  Utilities &operator=(const Utilities &h) {
    return *this;
  }; // dummy assignment operator
  static void trimString(std::string &str);
  static void lowerCase(std::string &str);
};

#endif // HEARTHSTONE_CL_UTILITIES_H
