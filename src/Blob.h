#pragma once

#include <array>

struct Blob
{
    std::array<std::byte, 4096> data;
};