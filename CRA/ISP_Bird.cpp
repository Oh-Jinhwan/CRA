// IPS(Interface Segregation Principle)

#pragma once
#define interface struct

interface Bird {
    virtual void Molt() = 0;
};

interface Flyable {
    virtual void Fly() = 0;
};

interface FlyableBird : public Bird {
    virtual void Fly() = 0;
};