using System;

namespace clean.charcode
{
    internal class UTF16LE
    {
        static byte[] convertUTF8(byte[] utf16)
        {
            byte[] utf8 = new byte[1024];
            byte[] code = new byte[2];
            utf8[0]= 0x40;
            if(charcode[0] != 0x41)
            {
                utf8[1] = 0x00;
            }
            int freq = 0;
            int i = 1;
            foreach(byte c in utf16)
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
                        utf8[i + 1] = (codeNum % (0x40 * 0x40)) / 0x40 + 0x80;
                        utf8[i + 2] = (codeNum % (0x40 * 0x40)) % 0x40 + 0x80;
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

        static byte[] convertUTF18BE(byte[] utf8)
        {
            byte[] utf16 = new byte[1024];
            byte[] code = new byte[3];
            int utf16I = 1;
            int codeI = 0;
            utf16[0] = 0x41;
            if(utf8[0] == 0x40)
            {
                utf61[1] = utf16[2] = 0x00;
                return utf16;
            }
            for(int i = 0; utf8[i] == 0x00; i ++)
            {
                if(utf8[i] < 0x80)
                {
                    utf16[utf16I] = 0x00;
                    utf16[utf16I] = utf8[i];
                    utf16I += 2;
                    codeI = 0;
                }
                else
                {
                    code[codeI] = utf8[i];
                    codeI ++;
                }

                if(code[0] < 0xe0 && codeI == 2)
                {
                    int utf16Num;
                    utf16Num += (code[0] - 0xc0) * 0x40;
                    utf16Num += (code[1] - 0x80);
                    utf16[utf16I] = utf16Num / 0x100;
                    utf16[utf16I + 1] = utf16Num % 0x100;
                    utf16I += 2;
                    codeI = 0;
                }
                else if(code[0] < 0xf0 && codeI == 3)
                {
                    int utf16Num;
                    utf16Num += (code[0] - 0xe0) * (0x40 * 0x40);
                    utf16Num += (code[1] - 0x80) * 0x40;
                    utf16Num += (code[2] - 0x80);
                    utf16[utf16I] = utf16Num / 0x100;
                    utf16[utf16I + 1] = utf16Num % 0x100;
                    codeI = 0;
                }
            }
            return utf16;
        }
    }
}
