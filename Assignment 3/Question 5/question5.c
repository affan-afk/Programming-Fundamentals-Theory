#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char** speciesSupplies;
    char *name;
    int n_supplies;
} pet;

void add_supplies(int n_species, pet *pets) {
    for (int i = 0; i < n_species; i++) {
        printf("Enter number of supplies you want to add for %s: ", pets[i].name);
        scanf("%d", &(pets[i].n_supplies));
        pets[i].speciesSupplies = malloc(sizeof(char*) * pets[i].n_supplies);
        for (int j = 0; j < pets[i].n_supplies; j++) {
            pets[i].speciesSupplies[j] = malloc(30 * sizeof(char)); 
            printf("Enter supply %d: ", j + 1);
            scanf("%s", pets[i].speciesSupplies[j]);
        }
    }
}

void update_supplies(int n_species, pet *pets) { 
    int species_index, supplies_index;
    char tmp[30];
    for (int i = 0; i < n_species; i++) {
        printf("%d.%s\n", i + 1, pets[i].name);
    }
    printf("Enter Species to update: ");
    scanf("%d", &species_index);
    species_index -= 1;
    if (species_index < 0 || species_index >= n_species) {  
       printf("\nError! Invalid Species Index\n");
       return;      
    }
    
    for (int i = 0; i < pets[species_index].n_supplies; i++) {
        printf("%d.%s\n", i + 1, pets[species_index].speciesSupplies[i]);
    }
    printf("Enter Supply to update: ");
    scanf("%d", &supplies_index);
    supplies_index -= 1;
    if (supplies_index < 0 || supplies_index >= pets[species_index].n_supplies) {  
       printf("\nError! Invalid Supply Index\n");
       return;
    }
    printf("Enter New Supply: ");
    scanf("%s", tmp);
    strcpy(pets[species_index].speciesSupplies[supplies_index], tmp);
}

void remove_species(int *n_species, pet *pets) {
    int species_index;   
    for (int i = 0; i < *n_species; i++) {
        printf("%d.%s\n", i + 1, pets[i].name);
    }
    printf("Enter Species to remove: ");
    scanf("%d", &species_index);
    fflush(stdin);
    species_index -= 1;
    if (species_index < 0 || species_index >= *n_species) { 
       printf("\nError! Invalid Species Index\n");
       return;      
    }

    for (int i = 0; i < pets[species_index].n_supplies; i++) {
        free(pets[species_index].speciesSupplies[i]);
    }
    free(pets[species_index].speciesSupplies);
    free(pets[species_index].name);

    for (int i = species_index; i < *n_species - 1; i++) {
        pets[i] = pets[i + 1];
    }

    *n_species -= 1;
    pets = realloc(pets, *n_species * sizeof(pet));
}

void display_species(int n_species, pet *pets) {
    for (int i = 0; i < n_species; i++) {
        printf("\n%d. Species: %s\n", i + 1, pets[i].name);
        printf("Supplies: ");
        for (int j = 0; j < pets[i].n_supplies; j++) {
            printf("%d. %s ", j + 1, pets[i].speciesSupplies[j]);
        }
        printf("\n");
    }
}

int main() {
    int species = 0;
    printf("Enter number of species you want to add: ");
    scanf("%d", &species);
    fflush(stdin);
    pet *pets_in_heart = malloc(sizeof(pet) * species);

    for (int i = 0; i < species; i++) {
        pets_in_heart[i].name = malloc(sizeof(char) * 40);
        printf("Enter Species %d Name: ", i + 1);
        scanf("%s", pets_in_heart[i].name);
        pets_in_heart[i].speciesSupplies = NULL;
        pets_in_heart[i].n_supplies = 0;
    }

    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Species\n");
        printf("0. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                add_supplies(species, pets_in_heart);
                printf("Supplies Added\n");
                break;
            case 2:
                update_supplies(species, pets_in_heart);
                printf("Supplies Updated\n");
                break;
            case 3:
                remove_species(&species, pets_in_heart);
                printf("Species Removed\n");
                break;
            case 4:
                display_species(species, pets_in_heart);
                break;
            case 0:
                printf("GoodBye!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                return 0;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
}
