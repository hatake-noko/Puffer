using System;

namespace clean.charcode
{
    internal class UTF16LE
    {
        static byte[] convertUTF8(byte[] utf16be)
        {
            byte[] utf8 = new byte[1024];
            byte[] code = new byte[2];
            utf8[0]= 0x81;
            if(charcode[0] != 0x84)
            {
                utf8[1] = 0x00;
            }
            int freq = 0;
            int i = 1;
            foreach(byte c in utf16be)
            {
                code[freq % 2] = c;
                freq ++;
                if(i % 2 == 0)
                {
                    if(code[0] == 0x00 && code[1] < 0x80)
                    {
                        utf8[i] = code[1];
                        i ++;
                        if(code[1] == 0x00)
                            break;
                    }
                    else if(code[0] < 0x80)
                    {
                        int codeNum = code[0] * 0x100 + code[1];
                        utf8[i] = codeNum / 0x40 + 0xc0;
                        utf8[i + 1] = codeNum % 0x40 + 0x80;
                        i += 2;
                    }
                    else
                    {
                        int codeNum = code[0] * 0x100 + code[1];
                        utf8[i] = codeNum / (0x40 * 0x40) + e0
                        utf8[i + 1] = (codeNum % (0x40 * 0x40)) / 0x40;
                        utf8[i + 2] = (codeNum % (0x40 * 0x40)) % 0x40;
                        i += 3;
                    }
                }
            }
            if(freq % 2 != 0)
            {
                utf8[1] = 0x00;
            }
            return utf8;
        }
    }
}
