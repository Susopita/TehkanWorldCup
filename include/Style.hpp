#pragma once

#include <ostream>
#include <string>

namespace TWC::Style
{

    namespace ColorText
    {
        static const std::string BLACK = "\033[30m";
        static const std::string RED = "\033[31m";
        static const std::string GREEN = "\033[32m";
        static const std::string YELLOW = "\033[33m";
        static const std::string BLUE = "\033[34m";
        static const std::string MAGENTA = "\033[35m";
        static const std::string CYAN = "\033[36m";
        static const std::string WHITE = "\033[37m";
        static const std::string LIGHT_GRAY = "\033[90m";
        static const std::string LIGHT_RED = "\033[91m";
        static const std::string LIGHT_GREEN = "\033[92m";
        static const std::string LIGHT_YELLOW = "\033[93m";
        static const std::string LIGHT_BLUE = "\033[94m";
        static const std::string LIGHT_MAGENTA = "\033[95m";
        static const std::string LIGHT_CYAN = "\033[96m";
        static const std::string BRIGHT_WHITE = "\033[97m";
        static const std::string DEFAULT = "\033[39m";
    }

    namespace ColorBackground
    {
        static const std::string BLACK = "\033[40m";
        static const std::string RED = "\033[41m";
        static const std::string GREEN = "\033[42m";
        static const std::string YELLOW = "\033[43m";
        static const std::string BLUE = "\033[44m";
        static const std::string MAGENTA = "\033[45m";
        static const std::string CYAN = "\033[46m";
        static const std::string WHITE = "\033[47m";
        static const std::string LIGHT_GRAY = "\033[100m";
        static const std::string LIGHT_RED = "\033[101m";
        static const std::string LIGHT_GREEN = "\033[102m";
        static const std::string LIGHT_YELLOW = "\033[103m";
        static const std::string LIGHT_BLUE = "\033[104m";
        static const std::string LIGHT_MAGENTA = "\033[105m";
        static const std::string LIGHT_CYAN = "\033[106m";
        static const std::string BRIGHT_WHITE = "\033[107m";
        static const std::string DEFAULT = "\033[49m";
    }

    namespace Effect
    {
        static const std::string RESET = "\033[0m";
        static const std::string BOLD = "\033[1m";
        static const std::string DIM = "\033[2m";
        static const std::string ITALIC = "\033[3m";
        static const std::string UNDERLINE = "\033[4m";
        static const std::string SLOW_BLINK = "\033[5m";
        static const std::string RAPID_BLINK = "\033[6m";
        static const std::string INVERT = "\033[7m";
        static const std::string HIDDEN = "\033[8m";
        static const std::string STRIKETHROUGH = "\033[9m";
        static const std::string PRIMARY_FONT = "\033[10m";
        static const std::string ALTERNATIVE_FONT_1 = "\033[11m";
        static const std::string ALTERNATIVE_FONT_2 = "\033[12m";
        static const std::string DOUBLE_UNDERLINE = "\033[21m";
        static const std::string RESET_BOLD_DIM = "\033[22m";
        static const std::string RESET_FOREGROUND = "\033[39m";
        static const std::string RESET_BACKGROUND = "\033[49m";
    }

    struct Style
    {
        std::string colorText;
        std::string colorBackground;
        std::string effect;

        Style(std::string colorText, std::string colorBackground, std::string effect) : colorText(colorText), colorBackground(colorBackground), effect(effect) {}

        Style(std::string colorText, std::string colorBackground) : colorText(colorText), colorBackground(colorBackground) {}

        Style() = default;

        std::string applyStyle(const std::string &text) const
        {
            return colorText + colorBackground + effect + text + Effect::RESET;
        }
    };

    template <class derived>
    class Representation
    {
    protected:
        std::string representation;
        Style style;

        virtual void print(std::ostream &os) const;

        template <class U>
        friend std::ostream &operator<<(std::ostream &os, const Representation<U> &representation);

    public:
        Representation() = default;
        Representation(const std::string &representation, Style style) : representation(representation), style(style) {}
        derived &setStyle(const Style &style);
        derived &setRepresentation(const std::string &representation);
        virtual ~Representation() = default;
    };
};

#include "../src/Style.tpp"