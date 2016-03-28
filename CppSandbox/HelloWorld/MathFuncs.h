#pragma once

#include "IMathFuncs.h"

class MathFuncs : public IMathFuncs
{
public:
    
    MathFuncs();
    
    ~MathFuncs();

    double Double(const double a) override;
    double Halve(const double a) override;
};