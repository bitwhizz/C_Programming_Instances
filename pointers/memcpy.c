#include <stdio.h>
#include <string.h>


//error: conflicting types for ‘memcpy’
// In file included from memcpy.c:2:
// /usr/include/string.h:42:14: note: previous declaration of ‘memcpy’ was here
// extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
void * _memcpy(void* dst, const void* src,unsigned int cnt)
{
    char *pszDest = (char*)dst;
    const char *pszSource = (const char*)src;

    if((pszDest != NULL) && (pszSource != NULL))
    {
        while(cnt)
        {
            //copy byte by byte
            *(pszDest++) = *(pszSource++);
            --cnt;
        }
    }

    return dst;
}

int main()
{
    char src[20] = "How are you ?"; //Source String

    char dst[20] = {0}; //dst buffer

    _memcpy(dst,src,sizeof(src));

    printf("dst = %s \n",dst);

    return 0;
}
