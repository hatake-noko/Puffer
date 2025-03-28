using clean;

namespace clean
{
    internal class Color
    {
        byte red;
        byte green;
        byte blue;
        byte transparency;

        void SetDefault()
        {
            red = green = blue = transparency = 0;
        }
    }

    internal class Font
    {
    }

    internal class Pos
    {
        int x;
        int y;

        void SetDefault()
        {
            x = y = 0;
        }
    }

    internal class Time
    {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
        int millisecond;

        void SetDefault()
        {
            year = 2025;
            month = day = 1;
            hour = minute = second = millisecond = 0;
        }
    }
}
