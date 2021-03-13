// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/01/23
#include "cstring.h"

namespace sdds {
int strLen(const char *s) {
  int len = 0;
  for (len = 0; s[len] != '\0'; len++)
    ;
  return len;
}

int strCmp(const char *s1, const char *s2) {
  int i = 0;
  for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    int diff = (int)s1[i] - (int)s2[i];
    if (diff != 0) {
      return diff;
    }
  }
  return (int)s1[i] - (int)s2[i];
}

int strnCmp(const char *s1, const char *s2, int len) {
  for (int i = 0; i < len; i++) {
    int diff = (int)s1[i] - (int)s2[i];
    if (diff != 0) {
      return diff;
    }
  }
  return 0;
}

void strCpy(char *des, const char *src) {
  char c;
  int i;
  for (c = -1, i = 0; c != '\0'; i++) {
    c = src[i];
    des[i] = c;
  }
}

void strnCpy(char *des, const char *src, int len) {
  char c;
  int i;
  for (c = -1, i = 0; i < len && c != '\0'; i++) {
    c = src[i];
    des[i] = c;
  }
}

void strCat(char *des, const char *src) {
  int i;
  char c;
  int j;
  for (c = -1, i = strLen(des), j = 0; c != '\0'; j++, i++) {
    c = src[j];
    des[i] = c;
  }
}

const char *strStr(const char *str1, const char *str2) {
  int i;
  int n1 = strLen(str1);
  int n2 = strLen(str2);
  for (i = 0; 0 != strnCmp(&str1[i], str2, n2) && i < n1 - n2; i++)
    ;
  if (i == n1 - n2)
    return nullptr;
  return &str1[i];
}
} // namespace sdds
