// Copyright 2017 <Célian Garcia>
#ifndef INCLUDE_FIREFLY_OPERATION_HPP_
#define INCLUDE_FIREFLY_OPERATION_HPP_
#include <queue>
#include <opencv2/core.hpp>
#include <boost/thread.hpp>

namespace firefly {
enum class OperationType {ADD, REMOVE, END};

class Operation  {
 public:
    Operation(int id, OperationType type, cv::Vec3f value)
        : m_id(id), m_type(type), m_value(value) {}

    Operation(OperationType type, cv::Vec3f value)
        : m_type(type), m_value(value) {}

    int getId() const {return this->m_id;}
    cv::Vec3f getValue() const {return this->m_value;}
    OperationType getType() const {return this->m_type;}
    void setId(const int & id) {this->m_id = id;}

 private:
    int m_id = 0;
    OperationType m_type;
    cv::Vec3f m_value;
};

class ConcurrentOperationQueue {
 public:
    void enqueue(Operation operation) {
        boost::lock_guard<boost::mutex> lock(m);
        operation.setId(last_index++);
        q.push(operation);
        c.notify_one();
    }

    Operation dequeue() {
        boost::unique_lock<boost::mutex> lock(m);
        while (q.empty()) {
          c.wait(lock);
        }
        T val = q.front();
        q.pop();
        return val;
    }

 private:
    int last_index = 0;
    std::queue<T> q;
    mutable boost::mutex m;
    boost::condition_variable c;
}
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_OPERATION_HPP_
