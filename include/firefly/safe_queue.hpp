/// Copyright 2017 <Célian Garcia>
#ifndef INCLUDE_FIREFLY_SAFE_QUEUE_HPP_
#define INCLUDE_FIREFLY_SAFE_QUEUE_HPP_

#include <queue>
#include <boost/thread.hpp>

namespace firefly {
template <class T>
class SafeQueue {
 public:
  SafeQueue(void)
    : q()
    , m()
    , c()
  {}

  ~SafeQueue(void)
  {}

  void enqueue(T t) {
    boost::lock_guard<boost::mutex> lock(m);
    q.push(t);
    c.notify_one();
  }

  T dequeue(void) {
    boost::unique_lock<boost::mutex> lock(m);
    while (q.empty()) {
      c.wait(lock);
    }
    T val = q.front();
    q.pop();
    return val;
  }

 private:
  std::queue<T> q;
  mutable boost::mutex m;
  boost::condition_variable c;
};
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_SAFE_QUEUE_HPP_
