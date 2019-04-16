#pragma once
#include "AbstractReactor.hpp"
#include "PressureSensorReactor.hpp"

struct AbstractReactorFactory
{
    virtual std::unique_ptr<AbstractReactor> deploy() const = 0;
};