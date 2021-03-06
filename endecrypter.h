/*
 * SaveData En/Decrypter on PC (GPLv3+)
 * kirk-engine (C) draan / proxima
 * jpcsp (C) jpcsp team, especially CryptoEngine by hykem
 * ported by popsdeco (aka @cielavenir)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "libkirk/kirk_engine.h"

#define arraycopy(src,srcPos,dest,destPos,len) memcpy((dest)+(destPos),(src)+(srcPos),(len))

#define hleChnnlsv_21BE78B4(ctx) memset(ctx,0,sizeof(_SD_Ctx2));
 
typedef unsigned char byte;
 
#if defined(WIN32) || (!defined(__GNUC__) && !defined(__clang__))
        #define initstdio() setmode(fileno(stdin),O_BINARY),setmode(fileno(stdout),O_BINARY),setmode(fileno(stderr),O_BINARY);
#else
        #define initstdio()
        int filelength(int fd){ //constant phrase
                struct stat st;
                fstat(fd,&st);
                return st.st_size;
        }
#endif
