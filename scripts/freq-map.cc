
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

void
print(string const &s) {
  cout << s << " 1" << endl;
}

int 
main() {
  for_each(istream_iterator<string>(cin),
	   istream_iterator<string>(),
	   print);
  return 0;
}
