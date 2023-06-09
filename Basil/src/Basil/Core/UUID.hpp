﻿#pragma once

namespace Basil
{
    class UUID
    {
    public:
        UUID();
        UUID(uint64_t uuid);
        UUID(const UUID&) = default;

        operator uint64_t() const { return m_UUID; }
    private:
        uint64_t m_UUID;
    };
}

namespace std
{
    template <typename T> struct Hash;

    template<>
    struct Hash<Basil::UUID>
    {
        std::size_t operator()(const Basil::UUID& uuid) const
        {
            return (uint64_t)uuid;
        }
    };
}
