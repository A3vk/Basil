#include "hzpch.h"
#include "UUID.hpp"

#include <random>

namespace Basil
{
    static std::random_device RandomDevice;
    static std::mt19937_64 Engine(RandomDevice());
    static std::uniform_int_distribution<uint64_t> UniformDistribution;

    UUID::UUID() : m_UUID(UniformDistribution(Engine)) {}

    UUID::UUID(uint64_t uuid) : m_UUID(uuid) {}

}
