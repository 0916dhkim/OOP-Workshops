// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/10
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
class Text;
class Line {
  char *m_value{nullptr};
  operator const char *() const;
  Line() {}
  Line &operator=(const char *);
  ~Line();
  friend class TextFile;
  // copy and copy assignment prevention goes here
  Line(const Line &) = delete;
  Line &operator=(const Line &) = delete;
};

class TextFile {
  Line *m_textLines{nullptr};
  char *m_filename{nullptr};
  unsigned m_noOfLines{0};
  unsigned m_pageSize{0};
  void setFilename(const char *fname, bool isCopy = false);
  void setNoOfLines();
  void loadText();
  void saveAs(const char *fileName) const;
  void setEmpty();

public:
  TextFile(unsigned pageSize = 15);
  TextFile(const char *filename, unsigned pageSize = 15);
  TextFile(const TextFile &);
  TextFile &operator=(const TextFile &);
  ~TextFile();
  std::ostream &view(std::ostream &ostr) const;
  std::istream &getFile(std::istream &istr);
  operator bool() const;
  unsigned lines() const;
  const char *name() const;
  const char *operator[](unsigned index) const;
};
std::ostream &operator<<(std::ostream &ostr, const TextFile &text);
std::istream &operator>>(std::istream &istr, TextFile &text);

} // namespace sdds
#endif // !SDDS_TEXTFILE_H__
