#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stddef.h>

typedef size_t size_type;

template <typename T, size_type max_size> class static_queue {
public:
  static_queue() : start_idx(0), _size(0) {}
  bool empty() const { return size() == 0; }
  bool full() const { return size() == max_size; }
  void push(const T &val); // inserts a new element at the end of the queue if
                           // there is space
  T &front();              // accesses the oldest element in the queue
  void pop();              // removes the oldest element in the queue
  T &back();               // accesses the newest element in the queue
  size_type size() const { return _size; }

private:
  size_type start_idx;
  size_type _size;
  T data[max_size];
};

template <typename T, size_type max_size>
void static_queue<T, max_size>::push(const T &val) {
  if (full())
    return; // if there is no space, push() will do nothing
  _size++;
  back() = val;
}

template <typename T, size_type max_size>
void static_queue<T, max_size>::pop() {
  if (empty())
    return; // it is safe to call pop() on an empty queue
  _size--;
  start_idx = start_idx < max_size - 1 ? start_idx + 1 : 0;
}
// ideally I would want to call ~T() on the element being removed, but this
// causes problems for future calls of push() which does not call a constructor

// should not be called on an empty queue
template <typename T, size_type max_size>
T &static_queue<T, max_size>::front() {
  return data[start_idx];
}

// should not be called on an empty queue
template <typename T, size_type max_size> 
T &static_queue<T, max_size>::back() {
  size_type end_idx = start_idx + size() - 1;
  if(end_idx >= max_size) 
    end_idx -= max_size;
  return data[end_idx];
}

#endif
