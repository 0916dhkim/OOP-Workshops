#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
class HtmlText : public Text {
  char *m_title{nullptr};

public:
  HtmlText(const char *filename = nullptr, const char *title = nullptr);
  HtmlText(const HtmlText &);
  ~HtmlText();
  HtmlText &operator=(const HtmlText &);
  void write(std::ostream &) const override;
};
} // namespace sdds
#endif // !SDDS_HTMLTEXT_H__
