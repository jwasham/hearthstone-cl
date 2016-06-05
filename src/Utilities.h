#ifndef HEARTHSTONE_CL_UTILITIES_H
#define HEARTHSTONE_CL_UTILITIES_H

#include <string>

namespace General {

class Utilities {
 public:
  Utilities(const Utilities &) = delete;
  Utilities &operator=(const Utilities &) = delete;
  static void TrimString(std::string &str);
  static void LowerCase(std::string &str);
};

} // namespace General

#endif  // HEARTHSTONE_CL_UTILITIES_H
