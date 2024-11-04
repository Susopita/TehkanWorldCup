#pragma once

namespace TWC::Graphics
{
    class Presenter
    {
    public:
        virtual void draw() = 0;
        virtual ~Presenter() = default;
    };
} // namespace TWC::Graphics