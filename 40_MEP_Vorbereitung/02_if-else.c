#include <stdio.h>

int main(void){
  int o = 1; //True
  int x = 0; //False

  if (o){ //Alles was nicht 0 ist, ist "True"
    printf("o ist True\n"); //o ist True
  }

  if (x){
    printf("Das wird nicht gedruckt\n");//Hier passiert nichts
  }

  if (o == x){
    printf("Das wird nicht gedruckt\n");//Hier passiert auch nichts
  } else{
    printf("o ist nicht gleich x\n"); //o ist nicht gleich x
  }

  int a = 1;
  int b = 10;

  if (a > b){
    printf("Das stimmt sicher nicht!\n");//Hier passiert wieder nichts
  } else if (a == b){
    printf("Das stimmt sicher auch nicht!\n");//Hier passiert auch nichts
  } else{
    printf("Alles was oben dran ist falsch\n");//Alles oben dran ist falsch
  }

  //========== Kombination mit ||(oder) und &&(und) ===========
  if (b > 9 && o != x){
    printf("Das stimmt!\n");//Das stimmt!
  }

  if (b > 11 || o){
    printf("Das wird geruckt!\n");//Das wird geruckt!
  }



}
