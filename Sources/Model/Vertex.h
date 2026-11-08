#pragma once

#include <string_view>
#include "INode.h"

class Vertex: public INode
{
public:
    explicit Vertex(std::string_view name);
    [[nodiscard]] std::string toString() const override;
    [[nodiscard]] bool equals(const INode& node) const noexcept override;
private:
    std::string m_Name;
};


