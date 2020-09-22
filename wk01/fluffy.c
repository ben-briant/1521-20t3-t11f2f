#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 256
#define MAX_BREED_LENGTH 64

struct pet {
    char name[MAX_NAME_LENGTH];
    char breed[MAX_BREED_LENGTH];
    int age;
    int weight;
};

void age_fluffy(struct pet *my_pet);
struct pet *new_pet(char *name, char *breed, int age, int weight);

int main(int argc, char *argv[]) {
    // 1. create Fluffy
    // 2. age Fluffy
    // 3. create a new pet using command line args
    // 4. Write the new_pet() function
    //    - what's the difference to creating a pet inside main?

    struct pet fluffy;
    strcpy(fluffy.name, "Fluffy");
    strcpy(fluffy.breed, "Dog");
    fluffy.age = 5;
    fluffy.weight = 17;

    // Since age_fluffy() takes a pointer to a struct pet,
    // we can pass in the address of our 'fluffy' struct.
    // This allows age_fluffy to change the actual struct,
    // rather than creating a copy of it.
    age_fluffy(&fluffy);

    // Now, using command line arguments:
    // Assume that order of arguments is name, breed, age, weight.
    struct pet *command_line_pet = new_pet(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));
    
    // Now, since command_line_pet is already a pointer to a struct pet,
    // we can pass it into the 'age_fluffy' function directly.
    age_fluffy(command_line_pet);

    return 0;
}

// Increase a pet's age by one, and
// its weight by the fraction its age has increased by.
void age_fluffy(struct pet *my_pet) {
    double old_age = my_pet->age;
    my_pet->age += 1;
    double weight_fraction = my_pet->age / old_age;
    my_pet->weight *= weight_fraction;
}

// Malloc a new struct pet, and fill its fields with the given values.
struct pet *new_pet(char *name, char *breed, int age, int weight) {
    struct pet *new = malloc(sizeof(struct pet));

    strcpy(new->name, name);
    strcpy(new->breed, breed);
    new->age = age;
    new->weight = weight;

    return new;
}
