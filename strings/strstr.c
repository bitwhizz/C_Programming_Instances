/*
strstr function is used to find the first occurance of a substring within another string.

*/


#include <stdio.h>
#include <string.h>


char *_strstr(const char *haystack, const char *needle)
{
	size_t len_haystack, len_needle;

	len_needle = strlen(needle);
	if (!len_needle)
		return NULL;

	len_haystack = strlen(haystack);
	while (len_haystack >= len_needle) {
		if (!memcmp(haystack, needle, len_needle))
			return (char *)haystack;
		haystack++;
		len_haystack--;
	}

	return NULL;
}

int main(void)
{
    const char *text = "Searching for a needle in a haystack.";
    const char *sub = "needle";
    char *result;

    result = _strstr(text,sub);

    if(result){
        printf("Substring found at : %s\n",result);
    }
    else{
        printf("Substring not found.\n");
    }

    return 0;
}
