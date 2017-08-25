# static_queue
A C++ container template class similar to STL's queue but which avoids dynamic memory allocation.  Intended for use embeded systems where dynamic memory allaocation is unfavourable, but may also have a cache performance benefit on larger systems.  
The interface is the same as that of [std::queue](http://www.cplusplus.com/reference/queue/queue/) with all C++03 methods replicated, except for operators.

## usage
Just 
```C++
#include "static_queue.h"
```
and create a queue of e.g. ints with a max size of e.g. 20
```C++
static_queue<int, 20> q;
```

If using Arduino, it is assumed that the C++ standard library is unavailable and all relevant dependencies are worked around by the preproccessor.  If you are using Arduino but you do have the standard library available, then you may need to
```C++
#define STD_LIB_AVAILABLE
```
before including the headder.  
For non Arduino environments the opposite is true.  If the C++ standard library is not available then you must 
```C++
#define STD_LIB_UNAVAILABLE
```
before including the headder.

## compatibility
Tested to work with GCC and Clang in C++97, C++03, C++11, C++14 and C++17 modes.  Also works in Arduino and Visual Studio 2017.  Does not require STL to be available but does depend on <stddef.h>.
