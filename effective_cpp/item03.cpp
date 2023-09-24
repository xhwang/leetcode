
#include <iostream>

using namespace std;

class TextBlock {
public:
  TextBlock() {
    text = "Hello";
  }

  // TODO: text[pos] is const char, return value has to be const
  const char& operator[](std::size_t position) const   // operator[] for
  { return text[position]; }                           // const objects

  // Achieve non const function through
  char& operator[](std::size_t position)               // operator[] for
  // { return text[position]; }                        // non-const objects
  { return
      const_cast<char&>(                               // remove const
          static_cast<const TextBlock&>(*this)         // add const
            [position]
      );
  }

private:
   std::string text;
};

class CTextBlock {
public:
  CTextBlock() {
    text = new char[6];
    text[0] = 'h';
  }

  // TODO: char is not the same with char*
  // function const only restrict char* to const, char& is OK
  // But this may cause `text` content change
  // Compiler only obey bitwise constant
  char& operator[](std::size_t position) const         // operator[] for
  { return text[position]; }                           // const objects

  char* const & getData() const
  { return text; }                                     // const objects

  char& operator[](std::size_t position)               // operator[] for
  { return text[position]; }                           // non-const objects

private:
   char* text;
};

int main() {

  CTextBlock a = CTextBlock();
  cout<<a[0]<<endl;
  a[0] = 'J';
  cout<<a[0]<<endl;

  // TODO: const string is treated as string, cannot be assigned to char*
  // char* text = "Hello";
  const char* text = "Hello";
  cout<<text<<endl;


  return 0;
}
