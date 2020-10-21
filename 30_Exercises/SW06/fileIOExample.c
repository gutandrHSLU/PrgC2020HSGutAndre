#include<stdio.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("prgCfileIO.txt", "wb");  // überschreibt best. File!
    if( fp != NULL)
    {
	    printf("File open OK. Enter data...");
    	while( (ch = getchar()) != EOF) {  // getchar() von Console --> siehe unten
			// EOF = End Of File
			// EOF kann am terminal wie folgt erzeugt werden
			// 1. Daten eingeben
			// 2. Enter drücken
			// 3. Ctrl + Z drücken
    	    putc(ch, fp);
	    }
	    fclose(fp);
    	fp = fopen("prgCfileIO.txt", "r"); // öffnen im Lesemodus

		while( (ch = getc(fp)) != EOF)	{	// getchar(fp) vom File!
			printf("%c",ch);
		}
		// File schliessen
		fclose(fp);
	}
	else
	{
		printf("unable to open file\n");
	}
    return 0;
}
