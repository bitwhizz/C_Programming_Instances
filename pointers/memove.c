#include<stdio.h>
void * _memmove(void* dest, const void* src, unsigned int n)
{
    char *pDest = (char *)dest;
    const char *pSrc =( const char*)src;
    //allocate memory for tmp array
    char *tmp  = (char *)malloc(sizeof(char ) * n);
    if(NULL == tmp)
    {
        return NULL;
    }
    else
    {
        unsigned int i = 0;
        // copy src to tmp array
        for(i =0; i < n ; ++i)
        {
            *(tmp + i) = *(pSrc + i);
        }
        //copy tmp to dest
        for(i =0 ; i < n ; ++i)
        {
            *(pDest + i) = *(tmp + i);
        }
        free(tmp); //free allocated memory
    }
    return dest;
}
int main()
{
    char cSrc[] = "Aticleworld";
    // The destination string size is 14.
    char cDest[16] = {0};
    // copying n bytes of cSrc into cDest
    //Using own _memcpy function
    _memmove(cDest, cSrc, 12);
    printf("Copied string: %s\n", cDest);
    int iSrc[] = {10, 20, 30, 40, 50};
    int n = sizeof(iSrc)/sizeof(iSrc[0]);
    int iDest[n], index = 0;
    // copying n bytes of iSrc into iDest
    //Using own my_memcpy function
    _memmove(iDest, iSrc, sizeof(iSrc));
    printf("\nCopied array is ");
    for (index=0; index<n; index++)
    {
        printf("%d ", iDest[index]);
    }
    return 0;
}
