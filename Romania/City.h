#pragma once
#include <string>
#include <ostream>

class City
{
    std::string name;
public:
    City(std::string city)
    {
        name = std::string(city);
    }

    std::string Name() const
    {
        return name;
    }
};

inline std::ostream& operator<<(std::ostream& os, City* city)
{
    os << city->Name();
    return os;
}

inline bool operator==(City lhs, City rhs){
    return lhs.Name() == rhs.Name();
}


inline bool operator!=(City lhs, City rhs){
    return !operator==(lhs, rhs);
}

