//This is a racing game that prints out the victor randomly based on the least amount of time they complete the final lap.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures section
struct Race { 
    int numberOfLaps;
    int currentLap; 
    char firstPlaceDriverName[20];
    char firstPlaceRaceCarColor[20];
};

struct RaceCar {
    char driverName[20];
    char raceCarColor[20];
    int totalLapTime; 
};

// Print functions section
void printIntro() {
	printf("Welcome to the digital race!\n");
}

void printCountDown() {
	printf("Racers Ready! In...\n");
	for (int i = 5; i > 0; i--) {
		printf("%d...\n", i);
	}
	printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) { 
	printf("\nAfter lap number %d\n", race.currentLap);
	printf("First Place Is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
  	printf("\nCongrats to %s in the %s race car!! They've won!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap() { 
	int speed = (rand() % 3) + 1;
	int acceleration = (rand() % 3) + 1; 
	int nerves = (rand() % 3) + 1;

	int sum = speed + acceleration + nerves;
	return sum;
}

void updateRaceCar(struct RaceCar* raceCar) {
  	raceCar->totalLapTime = calculateTimeToCompleteLap(); 
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
	if(raceCar1->totalLapTime <= raceCar2->totalLapTime) { 
		strcpy(race->firstPlaceDriverName, raceCar1->driverName);
		strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
	} else { 
		strcpy(race->firstPlaceDriverName, raceCar2->driverName);
		strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
	}
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
	struct Race race;

	race.numberOfLaps = 5;
	race.currentLap = 1;

	strcpy(race.firstPlaceDriverName, "");
	strcpy(race.firstPlaceRaceCarColor, "");

	for(int i = 0; i < race.numberOfLaps; i++) { 
		updateRaceCar(raceCar1);
		updateRaceCar(raceCar2);

		updateFirstPlace(&race, raceCar1, raceCar2);
		printFirstPlaceAfterLap(race);

		race.currentLap++;
	}

	printCongratulation(race);
}

int main() {

	srand(time(0));

	struct RaceCar raceCar1 = {"George", "yellow", 0};
	struct RaceCar raceCar2 = {"Cosmo", "orange", 0};

	printIntro();
	printf("\n");
	printCountDown();

	startRace(&raceCar1, &raceCar2);

	return 0;  
};
