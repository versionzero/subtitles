
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

typedef map<string, long long> frequencies_t;

void
print(frequencies_t::value_type const &p) {
  cout << p.first << " " << p.second << endl;
}

int 
main() {
  string                  word;
  long long               frequency;
  frequencies_t           frequencies;
  frequencies_t::iterator it;
  while (cin >> word >> frequency) {
    frequencies[word] += frequency;
  }
  for_each(frequencies.begin(),
	   frequencies.end(),
	   print);
  return 0;
}
