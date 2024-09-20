#include "ToyRobot.h"

#include <cassert>
#include "Map2d.h"
#include "Position2d.h"

ToyRobot::ToyRobot(const Map2d& _map)
    : map(_map)
    , pos{ _map.minX, _map.minY, Position2d::Direction::NORTH }
{
    assert(map.valid());
    assert(map.contains(pos));
}

bool ToyRobot::place(const Position2d& _pos)
{
    if (!map.contains(_pos)) return false;

    pos = _pos;
    return true;
}

void ToyRobot::move()
{
    switch (pos.direction)
    {
        case Position2d::Direction::NORTH:
            if (pos.y >= map.maxY) return;
            pos.y++;
            break;
    
        case Position2d::Direction::EAST:
            if (pos.x >= map.maxX) return;
            pos.x++;
            break;
    
        case Position2d::Direction::SOUTH:
            if (pos.y <= map.minY) return;
            pos.y--;
            break;
    
        case Position2d::Direction::WEST:
            if (pos.x <= map.minX) return;
            pos.x--;
            break;
    }
}

void ToyRobot::left()
{
    switch (pos.direction)
    {
        case Position2d::Direction::NORTH:
            pos.direction = Position2d::Direction::WEST;
            break;

        case Position2d::Direction::EAST:
            pos.direction = Position2d::Direction::NORTH;
            break;
    
        case Position2d::Direction::SOUTH:
            pos.direction = Position2d::Direction::EAST;
            break;
    
        case Position2d::Direction::WEST:
            pos.direction = Position2d::Direction::SOUTH;
            break;
    }
}

void ToyRobot::right()
{
    switch (pos.direction)
    {
        case Position2d::Direction::NORTH:
            pos.direction = Position2d::Direction::EAST;
            break;
        
        case Position2d::Direction::EAST:
            pos.direction = Position2d::Direction::SOUTH;
            break;
        
        case Position2d::Direction::SOUTH:
            pos.direction = Position2d::Direction::WEST;
            break;
        
        case Position2d::Direction::WEST:
            pos.direction = Position2d::Direction::NORTH;
            break;
    }
}

Position2d ToyRobot::getPosition() const
{
    return pos;
}
