// Copyright 2017 <Célian Garcia>
#ifndef INCLUDE_FIREFLY_OPERATION_HPP_
#define INCLUDE_FIREFLY_OPERATION_HPP_

#include <queue>
#include <opencv2/opencv.hpp>
#include <boost/thread.hpp>
#include <json/json.hpp>

namespace firefly {

    using json = nlohmann::json;
    enum class OperationType {
        ADD, REMOVE, END
    };

    class Operation {
    public:
        Operation(int id, OperationType type, cv::Vec3f value)
                : m_id(id), m_type(type), m_value(value) {}

        Operation(OperationType type, cv::Vec3f value)
                : m_type(type), m_value(value) {}

        int getId() const { return this->m_id; }

        cv::Vec3f getValue() const { return this->m_value; }

        OperationType getType() const { return this->m_type; }

        void setId(const int &id) { this->m_id = id; }
        void setValue(const cv::Vec3f &value) { this->m_value = value; }
        void setType(const OperationType &type) { this->m_type = type; }

        static Operation buildEndOperation() {
            return Operation(-1, OperationType::END, cv::Vec<float, 3>());
        }

        bool isEndOperation() {
            return this->getType() == OperationType::END;
        }

    private:
        int m_id = 0;
        OperationType m_type;
        cv::Vec3f m_value;
    };


    class ConcurrentOperationQueue {
    public:
        void enqueue(Operation operation) {
            boost::lock_guard <boost::mutex> lock(m);
            operation.setId(last_index++);
            q.push(operation);
            c.notify_one();
        }

        Operation dequeue() {
            boost::unique_lock <boost::mutex> lock(m);
            while (q.empty()) {
                c.wait(lock);
            }
            Operation val = q.front();
            q.pop();
            return val;
        }

    private:
        int last_index = 0;
        std::queue <Operation> q;
        mutable boost::mutex m;
        boost::condition_variable c;
    };
}  // end namespace firefly

namespace nlohmann {
    template <>
    struct adl_serializer<cv::Vec3f> {
        static void to_json(json& j, const cv::Vec3f& v) {
            std::string x_key = "x";
            std::string y_key = "y";
            std::string z_key = "z";
            j = json{{x_key, v[0]}, {y_key, v[1]}, {z_key, v[2]}};
        }
    };

    template <>
    struct adl_serializer<firefly::OperationType> {
        static void to_json(json& j, const firefly::OperationType& operationType) {
            j = std::string("enum");
        }
    };

    template <>
    struct adl_serializer<firefly::Operation> {
        static void to_json(json& j, const firefly::Operation& operation) {
            std::string id_key = "id";
            std::string value_key = "value";
            std::string type_key = "type";
            j = json{{id_key, operation.getId()}, {value_key, operation.getValue()}, {type_key, operation.getType()}};
        }
    };
}
#endif  // INCLUDE_FIREFLY_OPERATION_HPP_
