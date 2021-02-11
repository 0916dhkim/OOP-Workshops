#include "Label.h"
#include "cstring.h"
#include<cstdio>
using namespace sdds;
using namespace std;

void Label::setContent(const char *content) {
  int len = strLen(content);
  int i;
  this->m_content = new char[len <= MAX_LABEL_LENGTH ? len + 1 : MAX_LABEL_LENGTH + 1];
  for (i = 0; i < MAX_LABEL_LENGTH && content[i] != '\0'; i++) {
    this->m_content[i] = content[i];
  }
  this->m_content[i] = '\0';
}

Label::Label() {
  strnCpy(this->m_frame, "+-+|+-+|", 8);
  this->m_content = nullptr;
}

Label::Label(const char *frameArg) {
  strnCpy(this->m_frame, frameArg, 8);
  this->m_content = nullptr;
}

Label::Label(const char *frameArg, const char *content) {
  strnCpy(this->m_frame, frameArg, 8);
  this->setContent(content);
}

Label::~Label() {
  delete[] this->m_content;
}

void Label::readLabel() {
  char buffer[MAX_LABEL_LENGTH + 1];
  char end;
  scanf("%[^\n]%c", buffer, &end);
  this->setContent(buffer);
}

ostream &Label::printLabel() const {
  if (this->m_content == nullptr) return cout;
  int len = strLen(this->m_content);
  // Top.
  cout << this->m_frame[0];
  for (int i = 0; i < len + 2; i++) {
    cout << this->m_frame[1];
  }
  cout << this->m_frame[2] << endl;
  cout << this->m_frame[7];
  for (int i = 0; i < len + 2; i++) {
    cout << " ";
  }
  cout << this->m_frame[3] << endl;

  // Left.
  cout << this->m_frame[7] << " ";

  // Content.
  cout << this->m_content;

  // Right.
  cout << " " << this->m_frame[3] << endl;

  // Bottom.
  cout << this->m_frame[7];
  for (int i = 0; i < len + 2; i++) {
    cout << " ";
  }
  cout << this->m_frame[3] << endl;
  cout << this->m_frame[6];
  for (int i = 0; i < len + 2; i++) {
    cout << this->m_frame[5];
  }
  cout << this->m_frame[4] << endl;
  return cout;
}

