#include <stdio.h>

int main()
{
	char s[]="WELCOME";
	int i;

	for(i=0 ; s[i]!='\0' ; i++)
	{
		s[i] = s[i] + 32;
	}

	printf("%d\n", i);
	printf("%s\n", s);

	return 0;
}
