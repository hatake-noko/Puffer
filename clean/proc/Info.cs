using System;

namespace clean.proc
{
    internal class Info
    {
        int version;
        byte[] title = new byte[1024];
        byte[] author = new byte[1024];
        Time createTime;
        Time updateTime;

        void SetDefault()
        {
            version = 0;
            title[0] = 0x81;
            title[1] = 0x00;
            author[0] = 0x81;
            author[1] = 0x00;
            createTime.SetDefault();
            updateTime.SetDefault();
        }
    }
}
