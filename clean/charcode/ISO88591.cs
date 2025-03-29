using System;

namespace clean.charcode
{
    internal class ISO88591
    {
        static byte[] convertUTF8(byte[] iso88591)
        {
            byte[] utf8 = new byte[1024];
            utf8[0] = 0x40;
            byte utf8I = 1;
            if(iso88591[0] != 0x20)
            {
                utf8[1] = 0x00;
                return utf8;
            }
            foreach(byte c in iso88591)
            {
                if(c < 0x80)
                {
                    utf8[utf8I] = c;
                    utf8I ++;
                }
            }
        }
    }
}
