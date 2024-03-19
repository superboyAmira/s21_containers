# s21_containers
A training project dedicated to the implementation of the basic data structures of the c++ language, such as vector, stack, set, map, etc.

it is worth highlighting the parts of the project responsible for map and set, in which I recreated the work of the red-black tree algorithms, including balancing and iteration through the tree. trying to get as close as possible to the standard stl implementation, I used allocators for memory management.
the main part of the code is covered by unit tests from the GTEst library. all code is checked by the valgrind and fsanitize profiling tool, and complies with the GOOGLE STYLE policy.

## Use tutorial

All operations are performed using the Make utility.
for example, to check the test coverage, you need to register:

```make gcov_report.```

To use the containers themselves from the library, just plug and use!

```
#include "pathToProject/s21_containers.h

...

s21::set<int> s21_set;

...
```
