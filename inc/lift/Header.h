#pragma once

#include <string_view>

namespace lift {

class Header {
public:
    /**
     * Creates a view into the header data.
     * @param header_data The full header data to split into name/value pair.
     */
    explicit Header(
        std::string_view header_data);

    /**
     * @return The entire header, e.g. "Connection: Keep-Alive"
     */
    [[nodiscard]]
    auto GetHeader() const -> std::string_view;

    /**
     * @return A view into the header's name.
     */
    [[nodiscard]]
    auto GetName() const -> std::string_view;

    /**
     * @return True if this header has a value.
     */
    [[nodiscard]]
    auto HasValue() const -> bool;

    /**
     * @return A view into the header's value or empty if it doesn't have a value.
     */
    [[nodiscard]]
    auto GetValue() const -> std::string_view;

private:
    /// The full header data.
    std::string_view m_header;
    /// The header's name.
    std::string_view m_name;
    /// The header's value if it has one.
    std::string_view m_value {};
};

} // lift
