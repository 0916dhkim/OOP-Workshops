#include "Text.h"
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds {
const char DUMMY_NULL = '\0';
const char &Text::operator[](int index) const {
  if (m_content == nullptr) {
    return DUMMY_NULL;
  }
  return m_content[index];
}

Text::Text(const char *filename) {
  if (filename == nullptr) {
    return;
  }

  m_filename = new char[strlen(filename) + 1];
  strcpy(m_filename, filename);
  read();
}

Text::Text(const Text &other) {
  if (other.m_filename != nullptr) {
    m_filename = new char[strlen(other.m_filename) + 1];
    strcpy(m_filename, other.m_filename);
  }

  if (other.m_content != nullptr) {
    m_content = new char[strlen(other.m_content) + 1];
    strcpy(m_content, other.m_content);
  }
}

Text &Text::operator=(const Text &other) {
  delete[] m_filename;
  if (other.m_filename != nullptr) {
    m_filename = new char[strlen(other.m_filename) + 1];
    strcpy(m_filename, other.m_filename);
  } else {
    m_filename = nullptr;
  }

  delete[] m_content;
  if (other.m_content != nullptr) {
    m_content = new char[strlen(other.m_content) + 1];
    strcpy(m_content, other.m_content);
  } else {
    m_content = nullptr;
  }

  return *this;
}

Text::~Text() {
  delete[] m_filename;
  delete[] m_content;
}

int Text::getFileLength() const {
  int len = 0;
  ifstream fin(m_filename);
  while (fin) {
    fin.get();
    len += !!fin;
  }
  return len;
}

void Text::read() {
  try {
    int fileLength = getFileLength();
    delete[] m_content;
    m_content = new char[fileLength + 1];

    ifstream fin(m_filename);
    for (int i = 0; i < fileLength; i++) {
      m_content[i] = fin.get();
    }
    m_content[fileLength] = '\0';
  } catch (...) {
    delete[] m_filename;
    delete[] m_content;
    m_filename = nullptr;
    m_content = nullptr;
  }
}

void Text::write(ostream &ostr) const {
  if (m_content == nullptr) {
    return;
  }

  ostr << m_content;
}

ostream &operator<<(ostream &ostr, const Text &text) {
  text.write(ostr);
  return ostr;
}
} // namespace sdds