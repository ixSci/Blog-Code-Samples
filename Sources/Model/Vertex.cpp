#include "Vertex.h"

Vertex::Vertex(std::string_view name):
    m_Name{name}
{}

std::string Vertex::toString() const
{
    return m_Name;
}

bool Vertex::equals(const INode& node) const noexcept
{
    return toString() == node.toString();
}
