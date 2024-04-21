#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Vehicle {
  char name[50];
  int cost;
  float mileage;
};

void printVehicle(struct Vehicle *v)
{
  printf("Name:%s\n", v->name);
  printf("Cost:%d\n",v->cost);
  printf("Mileage:%.2f\n",v->mileage);
}

int main()
{
  struct Vehicle *Veh1;
  Veh1 = (struct Vehicle *)malloc(sizeof(struct Vehicle));
  if(Veh1 == NULL)
  {
    printf("Mem-allocation failed.\n");
    return 1;
  }
  
  strncpy(Veh1->name, "Vish", 50);
  Veh1->name[49] = '\0';
  Veh1->cost = 500000;
  Veh1->mileage = 12.5;
  printf("Vehicle-1 information: \n");
  printVehicle(Veh1);
  free(Veh1);
  return 0;
}
