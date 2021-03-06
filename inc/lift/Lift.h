#pragma once

#include "lift/EventLoop.h"
#include "lift/QueryBuilder.h"
#include "lift/Request.h"
#include "lift/RequestHandle.h"
#include "lift/RequestPool.h"

namespace lift {

/**
 * Initializes the LiftHttp library, this function should be called once
 * per application and on a single thread.
 */
auto startup() -> void;

/**
 * Shuts down the LiftHttp library, this function should be called once
 * per application on a single thread when shutting down.
 */
auto shutdown() -> void;

/**
 * Use this class at the beginning of main() instead of directly
 * calling startup() and shutdown() to get a nice RAII behavior.
 *
 * e.g:
 *
 * int main()
 * {
 *      lift::GlobalScopeInitializer lift_global{};
 *
 *      ... code ...
 * }
 *
 */
struct GlobalScopeInitializer {
    GlobalScopeInitializer();
    ~GlobalScopeInitializer();

    GlobalScopeInitializer(const GlobalScopeInitializer&) = delete;
    GlobalScopeInitializer(GlobalScopeInitializer&&) = delete;
    auto operator=(const GlobalScopeInitializer&) -> GlobalScopeInitializer& = delete;
    auto operator=(GlobalScopeInitializer &&) -> GlobalScopeInitializer& = delete;
};

} // lift
