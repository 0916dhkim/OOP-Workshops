#include "HtmlText.h"
#include <cstring>
using namespace std;
namespace sdds {
HtmlText::HtmlText(const char *filename, const char *title) : Text(filename) {
  if (title != nullptr) {
    m_title = new char[strlen(title) + 1];
    strcpy(m_title, title);
  }
}
HtmlText::HtmlText(const HtmlText &other) : Text(other) {
  if (other.m_title != nullptr) {
    m_title = new char[strlen(other.m_title) + 1];
    strcpy(m_title, other.m_title);
  }
}
HtmlText::~HtmlText() { delete[] m_title; }
HtmlText &HtmlText::operator=(const HtmlText &other) {
  Text::operator=(other);
  delete[] m_title;
  if (other.m_title != nullptr) {

    m_title = new char[strlen(other.m_title) + 1];
    strcpy(m_title, other.m_title);
  } else {
    m_title = nullptr;
  }

  return *this;
}
void HtmlText::write(std::ostream &ostr) const {
  bool multipleSpaces = false;

  ostr << "<html><head><title>";
  if (m_title == nullptr) {
    ostr << "No Title";
  } else {
    ostr << m_title;
  }
  ostr << "</title></head>\n<body>\n";

  if (m_title != nullptr) {
    ostr << "<h1>" << m_title << "</h1>\n";
  }

  for (int i = 0; (*this)[i] != '\0'; i++) {
    switch ((*this)[i]) {
    case ' ': {
      if (multipleSpaces) {
        ostr << "&nbsp;";
      } else {
        multipleSpaces = true;
        ostr << ' ';
      }
      break;
    }
    case '<': {
      ostr << "&lt;";
      multipleSpaces = false;
      break;
    }
    case '>': {
      ostr << "&gt;";
      multipleSpaces = false;
      break;
    }
    case '\n': {
      ostr << "<br />\n";
      multipleSpaces = false;
      break;
    }
    default: {
      ostr << (*this)[i];
      multipleSpaces = false;
      break;
    }
    }
  }

  ostr << "</body>\n</html>";
}
} // namespace sdds