#pragma once
#include <stack>
#include <queue>

using namespace std;

class Palindrome {
  public:
    Palindrome(string sent) : sentence(sent){}
    bool isPalindrome() const;
    friend ostream& operator<<(ostream& out, const Palindrome& p);

  private:
    string sentence;
    string stripSentence() const;
};

string Palindrome::stripSentence() const {
  string cleanStr = "";
  for (char c :  sentence) {
    c = tolower(c);
    if (c >= 'a' && c <= 'z') {
      cleanStr += c;
    }
  }

  return cleanStr;
}

bool Palindrome::isPalindrome() const {
  string cleanStr = stripSentence();
  stack<char> s;
  queue<char> q;

  for (char c : cleanStr) {
    s.push(c);
    q.push(c);
  }

  if (s.size() != q.size()) {
    return false;
  }

  while (!s.empty()) {
    if (s.top() != q.front()) {
      return false;
    }
    s.pop();
    q.pop();
  }

  return true;
}

ostream& operator<<(ostream& out, const Palindrome& p) {
  if (p.isPalindrome()) {
    out << p.sentence << "is a palindrome.";
  } else {
    out << p.sentence << "is not a palindrome.";
  }

  return out;
}