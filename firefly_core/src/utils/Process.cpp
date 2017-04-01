// Copyright 2017 <Célian Garcia>

#include <firefly/core/utils/Process.hpp>

namespace firefly {
    Process::Process(const std::string &raw_input) {
        this->m_proc_type = Process::computeProcessType(raw_input);
        this->m_mod_type = Process::computeModuleType(this->m_proc_type);
        this->m_name = Process::computeProcessName(this->m_proc_type);
    }

    std::string Process::getName() {
        return this->m_name;
    }

    ProcessType Process::getProcessType() {
        return this->m_proc_type;
    }

    ModuleType Process::getModuleType() {
        return this->m_mod_type;
    }

    ProcessType Process::computeProcessType(const std::string &raw_input) {
        std::string input = raw_input;
        boost::to_lower(input);
        for (auto it = PROC_TYPES_MAP.begin(); it != PROC_TYPES_MAP.end(); ++it) {
            auto aliases = it->second;
            if (std::find(aliases.begin(), aliases.end(), input) != aliases.end())
                return it->first;
        }
        throw FireflyException(HtmlStatusCode::BAD_REQUEST, input + " unknown.");
    }

    std::string Process::computeProcessName(const ProcessType &type) {
        auto elt = NAMES_MAP.find(type);
        if (elt != NAMES_MAP.end())
            return elt->second;
        throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, "Unknown error");
    }

    ModuleType Process::computeModuleType(const ProcessType &type) {
        auto elt = MOD_TYPES_MAP.find(type);
        if (elt != MOD_TYPES_MAP.end())
            return elt->second;
        throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, "Unknown error");
    }

    const std::map<ProcessType, std::vector<std::string>> Process::PROC_TYPES_MAP = {
            std::make_pair(ProcessType::FLY_R3D, std::vector<std::string>{"r3d", "reconstruct3d", "reconstruction3d"}),
            std::make_pair(ProcessType::FLY_P3D, std::vector<std::string>{"p3d", "populate3d", "population3d"}),
            std::make_pair(ProcessType::CV_GFILTER, std::vector<std::string>{"gaussian_filter", "gaussianfilter"})
    };

    const std::map<ProcessType, ModuleType> Process::MOD_TYPES_MAP = {
            std::make_pair(ProcessType::FLY_R3D, ModuleType::FLY),
            std::make_pair(ProcessType::FLY_P3D, ModuleType::FLY),
            std::make_pair(ProcessType::CV_GFILTER, ModuleType::CV)
    };

    const std::map<ProcessType, std::string> Process::NAMES_MAP = {
            std::make_pair(ProcessType::FLY_R3D, "Reconstruction 3D"),
            std::make_pair(ProcessType::FLY_P3D, "Population 3D"),
            std::make_pair(ProcessType::CV_GFILTER, "Gaussian Filter")
    };

};