// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/10
#include "TextFile.h"
#include "cstring.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
Line::operator const char *() const { return (const char *)m_value; }
Line &Line::operator=(const char *lineValue) {
  delete[] m_value;
  m_value = new char[strLen(lineValue) + 1];
  strCpy(m_value, lineValue);
  return *this;
}
Line::~Line() { delete[] m_value; }

void TextFile::setEmpty() {
  delete[] this->m_textLines;
  this->m_textLines = nullptr;

  delete[] this->m_filename;
  this->m_filename = nullptr;

  this->m_noOfLines = 0;
}

void TextFile::setFilename(const char *fname, bool isCopy) {
  delete[] this->m_filename;
  if (isCopy) {
    this->m_filename = new char[strLen(fname) + 3];
    this->m_filename[0] = 'C';
    this->m_filename[1] = '_';
    strCpy(this->m_filename + 2, fname);
  } else {
    this->m_filename = new char[strLen(fname) + 1];
    strCpy(this->m_filename, fname);
  }
}

void TextFile::setNoOfLines() {
  unsigned count = 0;  // Number of newline characters.
  ifstream ifs;
  char last;
  ifs.open(this->m_filename, ifstream::in);
  for (char c = ifs.get(); ifs.good(); c = ifs.get()) {
    count += c == '\n' ? 1 : 0;
    last = c;
  }
  ifs.close();

  if (last == '\n') count--;

  if (count == 0) {
    delete[] this->m_filename;
    this->m_filename = nullptr;
  } else {
    this->m_noOfLines = count + 1;
  }
}

void TextFile::loadText() {
  if (this->m_filename == nullptr) return;

  delete[] this->m_textLines;
  this->m_textLines = new Line[this->m_noOfLines];

  ifstream ifs;
  ifs.open(this->m_filename, ifstream::in);
  string line;
  for (unsigned i = 0; i < this->m_noOfLines; i++) {
    getline(ifs, line);
    this->m_textLines[i] = line.c_str();
  }
  ifs.close();
}

void TextFile::saveAs(const char *fileName) const {
  ofstream ofs;
  ofs.open(fileName, ofstream::out);
  for (unsigned i = 0; i < this->m_noOfLines; i++) {
    ofs << this->m_textLines[i] << endl;
  }
}

TextFile::TextFile(unsigned pageSize) {
  this->m_pageSize = pageSize;
}

TextFile::TextFile(const char* filename, unsigned pageSize) {
  this->m_pageSize = pageSize;
  if (filename != nullptr) {
    this->setFilename(filename);
    this->setNoOfLines();
    this->loadText();
  }
}

TextFile::TextFile(const TextFile &other) {
  this->m_pageSize = other.m_pageSize;

  if (!other) return;

  this->setFilename(other.m_filename, true);
  other.saveAs(this->m_filename);
  this->setNoOfLines();
  this->loadText();
}

TextFile& TextFile::operator=(const TextFile &other) {
  if (!other) return *this;

  delete[] this->m_textLines;
  this->m_textLines = nullptr;
  other.saveAs(this->m_filename);
  this->setNoOfLines();
  this->loadText();

  return *this;
}

TextFile::~TextFile() {
  delete[] this->m_textLines;
  delete[] this->m_filename;
}

unsigned TextFile::lines() const { return this->m_noOfLines; }

ostream &TextFile::view(ostream &ostr) const {
  if (!*this) return ostr;

  // Print the file name.
  ostr << this->m_filename << endl;
  // Underline.
  int fileNameLen = strLen(this->m_filename);
  for (int i = 0; i < fileNameLen; i++) {
    ostr << '=';
  }
  ostr << endl;
  for (unsigned i = 0; i < this->m_noOfLines; i++) {
    if (i % this->m_pageSize == 0 && i != 0) {
      // End of page.
      // Prompt user.
      cout << "Hit ENTER to continue...";
      cin.ignore(10000, '\n');
    }
    ostr << this->m_textLines[i] << endl;
  }

  return ostr;
}

istream &TextFile::getFile(istream &istr) {
  string filename;
  istr >> filename;
  istr.ignore();
  this->setFilename(filename.c_str());
  this->setNoOfLines();
  this->loadText();

  return istr;
}

const char *TextFile::operator[](unsigned int index) const {
  if (!*this) return nullptr;
  return this->m_textLines[index % this->m_noOfLines];
}

TextFile::operator bool() const { return this->m_textLines != nullptr; }

const char *TextFile::name() const { return this->m_filename; }

ostream &operator<<(ostream &ostr, const TextFile &text) {
  return text.view(ostr);
}

istream &operator>>(istream &istr, TextFile &text) {
  return text.getFile(istr);
}
} // namespace sdds
