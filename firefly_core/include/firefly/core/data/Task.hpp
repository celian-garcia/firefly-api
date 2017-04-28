// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_PROCESSING_HPP
#define FIREFLY_PROCESSING_HPP

#include <string>
#include "ProcessingType.hpp"
#include "Module.hpp"

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

        Task(const std::string &identifier, const std::string &name, const std::string &description,
             const ProcessingType &type, const Module &module, const std::string &userName, const std::string &date);

        const std::string &getIdentifier() const;

        const std::string &getName() const;

        const std::string &getDescription() const;

        const ProcessingType &getType() const;

        const Module &getModule() const;

        const std::string &getUserName() const;

        State getState() const;

        const std::string &getDate() const;

    private:
        std::string identifier;
        std::string name;
        std::string description;
        ProcessingType type;
        Module module;
        std::string userName;
        State state = State::CREATED;
        std::string date;
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
                    {"type",        task.getType().getName()},
                    {"module",      task.getModule().getName()},
                    {"user_name",   task.getUserName()},
                    {"date",        task.getDate()},
                    {"state",       task.getState()}
            };
        }
    };
}

#endif //FIREFLY_PROCESSING_HPP
