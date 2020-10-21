#include <stdio.h>
#include <stdlib.h>


struct data {
  int nummer;
  int daten;
};

int main (void)
{
  FILE *datei = fopen ("text.bin","rb");


  struct data Daten[3];
  unsigned int ret = 0;

  Daten[0].nummer = 0;
  Daten[1].nummer = 0;
  Daten[2].nummer = 0;
  Daten[0].daten = 1;
  Daten[1].daten = 1;
  Daten[2].daten = 1;

  ret = fread (Daten, sizeof(struct data), 3, datei);

  printf("%d\n", ret);
  if (ret != 3)
    printf ("Hupps, ein Fehler...\n");
  else
    printf ("Erfolgreich gelesen!\n");

  fclose (datei);
  return EXIT_SUCCESS;
}
