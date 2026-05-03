#include<stdio.h>

int _memcmp(const void *s1, const void *s2, size_t n)
{
	size_t ofs = 0;
	int c1 = 0;

	while (ofs < n && !(c1 = ((unsigned char *)s1)[ofs] - ((unsigned char *)s2)[ofs])) {
		ofs++;
	}
	return c1;
}

int main()
{
    char cSrc[] = "Aticleworld";
    char cDest[] = "Aticleworld";

    int status = _memcmp(cDest, cSrc, sizeof(cSrc)/sizeof(cSrc[0]));

    if(status){
        printf("string not matcing\n");
    }
    else{
        printf("strings are same\n");
    }
    return 0;
}