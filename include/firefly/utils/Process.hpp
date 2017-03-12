// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_MODULENAME_HPP
#define FIREFLY_MODULENAME_HPP

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <firefly/utils/FireflyException.hpp>
#include <firefly/utils/HtmlStatusCode.hpp>
#include <boost/algorithm/string.hpp>

namespace firefly {

    enum class ProcessType {
        FLY_R3D = 0,
        FLY_P3D = 1,
        CV_GFILTER = 2
    };

    enum class ModuleType {
        FLY = 0,
        CV = 1
    };

    class Process {
    public:
        Process(const std::string &raw_input);

        std::string getName();

        ProcessType getProcessType();

        ModuleType getModuleType();

    private:
        static ProcessType computeProcessType(const std::string &raw_input);

        static std::string computeProcessName(const ProcessType &type);

        static ModuleType computeModuleType(const ProcessType &type);

        // TODO(Célian): READ this dynamically from configuration files or database
        static const std::map<ProcessType, std::vector<std::string>> PROC_TYPES_MAP;

        // TODO(Célian): READ this dynamically from configuration files or database
        static const std::map<ProcessType, ModuleType> MOD_TYPES_MAP;

        // TODO(Célian): READ this dynamically from configuration files or database
        static const std::map<ProcessType, std::string> NAMES_MAP;

        std::string m_name;
        ProcessType m_proc_type;
        ModuleType m_mod_type;
    };

}

#endif //FIREFLY_MODULENAME_HPP
