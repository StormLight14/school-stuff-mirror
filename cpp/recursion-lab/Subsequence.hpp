#pragma once
#include <iostream>

using std::string, std::ostream;

class Subsequences {
  public:
    Subsequences(string word);
    bool isSubsequence(string subseq);
    bool isSubsequence(string subseq, int idx);
    friend ostream& operator<<(ostream& out, Subsequences& subseq);
  private:
    string word;
};

Subsequences::Subsequences(string word) {
  this->word = word;
}

// overcomplicated method using recursion
bool Subsequences::isSubsequence(string subseq) {
  return isSubsequence(subseq, 0);
}

bool Subsequences::isSubsequence(string subseq, int idx) {
  if (subseq.length() == 0) {
    return true;
  }

  if (idx >= word.length()) { // reached end of word
    return false;
  }

  if (word[idx] == subseq.front()) {
    return isSubsequence(subseq.substr(1), idx + 1);
  }

  return isSubsequence(subseq, idx + 1);
}

/* good method
bool Subsequences::isSubsequence(string subseq) {
  for (char c : word) {
    if (c == subseq.front()) {
      subseq.erase(subseq.begin());
    }
  }

  if (subseq.length() > 0) {
    return false;
  } else {
    return true;
  }
}
*/

ostream& operator<<(ostream& out, Subsequences& subseq) {
  return out;
}