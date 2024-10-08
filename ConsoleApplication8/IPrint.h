#pragma once

class IPrint {
public:
    virtual void print() const = 0; 
    virtual ~IPrint() = default;    
};

