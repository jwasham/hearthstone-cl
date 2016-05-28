#include "Utilities.h"

void Utilities::trimString(std::string & str) {

  unsigned long strLength = str.length();
  bool foundStart = false;
  bool foundEnd = false;
  unsigned long startPos = 0;
  unsigned long endPos = 0;

  for (unsigned long i = 0; i < strLength; i++) {
    bool isSpace = std::isspace(str[i]);

    if (not (foundStart or isSpace)) {
      startPos = i;
      foundStart = true;
      break;
    }
  }

  for (unsigned long i = strLength; i > 0; --i) {
    bool isSpace = std::isspace(str[i]);

    if (not (foundEnd or isSpace)) {
      endPos = i;
      foundEnd = true;
      break;
    }
  }

  if (not foundStart) startPos = 0;
  if (not foundEnd) endPos = strLength - 1;

  str = str.substr(startPos, endPos - startPos);
}