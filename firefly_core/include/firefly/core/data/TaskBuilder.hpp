// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_TASKBUILDER_HPP
#define FIREFLY_TASKBUILDER_HPP

#include <firefly/core/config/DataCommonStore.hpp>
#include "Task.hpp"
#include "json/json.hpp"

namespace firefly {
    class TaskBuilder {

    public:
        TaskBuilder() = default;

        TaskBuilder(const TaskBuilder &builder) = default;

        Task buildTask(DataCommonStore dataStore);

        void setState(Task::State state);

        void setName(const std::string &name);

        void setIdentifier(const int &identifier);

        void setDescription(const std::string &description);

        void setType(const int &type);

        void setModule(const int &module);

        void setUserName(const std::string &userName);

        void setDate(const std::string &date);

    private:
        Task task;
        int type_id;
        int module_id;
    };
}

namespace nlohmann {

    template<>
    struct adl_serializer<firefly::TaskBuilder> {
        static void from_json(const json &j, firefly::TaskBuilder &taskBuilder) {
            try {
                taskBuilder.setState(j.at("state").get<firefly::Task::State>());
            } catch (std::out_of_range &e) {
                std::cout << "No field state in task json" << std::endl;
            }
            try {
                taskBuilder.setIdentifier(j.at("id").get<int>());
            } catch (std::out_of_range &e) {
                std::cout << "No field id in task json" << std::endl;
            }
            try {
                taskBuilder.setDescription(j.at("description").get<std::string>());
            } catch (std::out_of_range &e) {
                std::cout << "No field description in task json" << std::endl;
            }
            try {
                taskBuilder.setName(j.at("name").get<std::string>());
            } catch (std::out_of_range &e) {
                std::cout << "No field name in task json" << std::endl;
            }
            try {
                taskBuilder.setType(j.at("type").get<int>());
            } catch (std::out_of_range &e) {
                std::cout << "No field type in task json" << std::endl;
            }
            try {
                taskBuilder.setModule(j.at("module").get<int>());
            } catch (std::out_of_range &e) {
                std::cout << "No field module in task json" << std::endl;
            }
            try {
                taskBuilder.setUserName(j.at("user_name").get<std::string>());
            } catch (std::out_of_range &e) {
                std::cout << "No field user_name in task json" << std::endl;
            }
            try {
                taskBuilder.setDate(j.at("date").get<std::string>());
            } catch (std::out_of_range &e) {
                std::cout << "No field date in task json" << std::endl;
            }

        }
    };
}

#endif //FIREFLY_TASKBUILDER_HPP
