// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_PROCESSING_HPP
#define FIREFLY_PROCESSING_HPP

#include <string>
#include "ProcessingType.hpp"

namespace firefly {

    class Task {
    public:
        enum State {
            CREATED,
            STARTED,
            PAUSED,
            FINISHED,
            ABORTED
        };

        Task(const std::string &name, const std::string &description, const ProcessingType &type);

        const std::string &getIdentifier() const;

        const std::string &getName() const;

        const std::string &getDescription() const;

        const ProcessingType &getType() const;

        const std::string &getCategory() const;

        const std::string &getUserName() const;

        State getState() const;

    private:
        std::string identifier;
        std::string name;
        std::string description;
        ProcessingType type;
        std::string category;
        std::string userName;
        State state = State::CREATED;
    };

}
namespace nlohmann {
    template<>
    struct adl_serializer<firefly::Task> {
        static void to_json(json &j, const firefly::Task &task) {
            j = json{
                    {"id",          task.getIdentifier()},
                    {"name",        task.getName()},
                    {"description", task.getDescription()},
                    {"type",        task.getType()},
                    {"category",    task.getCategory()},
                    {"userName",    task.getUserName()},
                    {"state",       task.getState()}
            };
        }
    };
}

#endif //FIREFLY_PROCESSING_HPP
