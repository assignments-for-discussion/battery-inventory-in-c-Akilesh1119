#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  //Rated capacity of a new battery in Ah
  int ratedCapacity=120;
  for(int i=0;i<nBatteries;i++){
    //Calculating the state of health(SoH) as a percentage
    float sohPercentage=((float)presentCapacities[i]/ratedCapacity)*100;
    //Classifying the battery based on the SoH valeu
    if(sohPercentage>80 && sohPercentage<=100)
    {
      counts.healthy++;
    }
    else if(sohPercentage>=62 && sohPercentage<=80)
    {
        counts.exchange++;
    }
    else
    {
      counts.failed++;
    }
  }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
