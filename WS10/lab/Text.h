#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
class Text {
  char *m_filename{nullptr};
  char *m_content{nullptr};
  int getFileLength() const;

protected:
  const char &operator[](int index) const;

public:
  Text(const char *filename = nullptr);
  Text(const Text &);
  virtual ~Text();
  Text &operator=(const Text &);

  void read();
  virtual void write(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &, const Text &);
} // namespace sdds
#endif // !SDDS_PERSON_H__
