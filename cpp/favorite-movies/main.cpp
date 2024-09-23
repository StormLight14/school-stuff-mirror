#include <iostream>

using std::cout, std::cin, std::endl, std::string;

enum Rating {G, PG, PG13, R};

struct Movie {
  string title;
  int year;
  Rating rating;
};

string getRating(Rating rating) {
  switch(rating) {
    case G: return "G";
    case PG: return "PG";
    case PG13: return "PG-13";
    case R: return "R";
    default: return "invalid rating";
  }
}

void displayMovie(Movie movie) {
  cout << movie.title << ", " << movie.year << ", " << getRating(movie.rating) << endl;
}

int main() {
  cout << "Favorite Movies" << endl;
  Movie favoriteMovie {"Real Movie", 1888, PG};
  displayMovie(favoriteMovie);

  return 0;
}

