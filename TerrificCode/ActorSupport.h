//#pragma once

#include <string>
using namespace std;

/**
 * Includes fundamental data structs for actor properties
 * **/

//prevents compiler errors since not working in Unreal
struct Actor {
    string name;
} ;

//prevents compiler errors since not in Unreal
struct Component {
    string name;
} ;

//related variables are grouped into meaningful struct
struct Position {
    double x;
    double y;
    double z;
};

//related variables are grouped into meaningful struct
struct Rotation {
    double yaw;
    double pitch;
    double roll;
} ;