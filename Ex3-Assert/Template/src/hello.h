#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Predefined
{
    std::shared_ptr<spdlog::logger> s_Logger;
    std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

    void InitLog()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_Logger = spdlog::stdout_color_mt("Console");
        s_Logger->set_level(spdlog::level::trace);
    }

}
//  log macros
#define _TRACE(...)    Predefined::GetLogger()->trace(__VA_ARGS__)
#define _INFO(...)     Predefined::GetLogger()->info(__VA_ARGS__)
#define _WARN(...)     Predefined::GetLogger()->warn(__VA_ARGS__)
#define _ERROR(...)    Predefined::GetLogger()->error(__VA_ARGS__)
#define _CRITICAL(...)    Predefined::GetLogger()->critical(__VA_ARGS__)