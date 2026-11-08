#pragma once

#include <string>

class INode
{
public:
    [[nodiscard]] virtual std::string toString() const = 0;
    [[nodiscard]] virtual bool equals(const INode& node) const noexcept = 0;
    virtual ~INode() = default;
};
