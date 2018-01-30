#include "math.h"
#include<stdio.h>
#include "user.h"
#include <string.h>

int main(int argc, char const *argv[]) {

  User user;
  user.age = 10;
  strcpy(user.name, "ahmet");

  int a = 4;
  int b = 2;

  int res1 = carp(a,b);
  int res2 = bol(a,b);
  int res3 = topla(a,b);
  userEkle(user);
  printf("topla: %d, bol: %d, carpma: %d \n", res3,res2,res1);
  return 0;
}

int carp(int a, int b){
  return a * b;
}

int bol(int a, int b){
  return a / b;
}

int topla(int a, int b){
  return a + b;
}

void userEkle(User user){
  printf("user %s\n", user.name);
}
