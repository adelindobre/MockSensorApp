#pragma once
#include "AbstractReactorFactory.hpp"

struct PressureSensorReactorFactory : AbstractReactorFactory
{
    std::unique_ptr<AbstractReactor> deploy() const override {
        return std::make_unique<PressureSensorReactor>();
    }
};