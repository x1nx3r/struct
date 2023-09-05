#include <stdio.h>

// Struct for your own profile
struct character {
    char name[50];
    char gender[12];
    float height;
    float weight;
    float hp;
    int lvl;
};

void display_main_menu(){
    printf("------Character Creation Window------\n");
    printf("1. Create characters\n");
    printf("2. Display already created characters\n");
}

void display_char_menu(){
    printf("------Character Selection Menu------\n");
    printf("1. Char 1\n");
    printf("2. Char 2\n");
    printf("3. Char 3\n");  
}



int main() {
    struct character char1 = {"-", "-", 0, 0, 0, 0};
    struct character char2 = {"-", "-", 0, 0, 0, 0};
    struct character char3 = {"-", "-", 0, 0, 0, 0};

    while(1){
        int choice=0;
        display_main_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            choice = 0;
            display_char_menu();
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Input your character name ");
                scanf("%s", char1.name);
                printf("Input your character gender (Male/Female/Up to your hearts desire) ");
                scanf("%s", char1.gender);
                printf("Input your character height ");
                scanf("%f", &char1.height);
                printf("Input your character weight ");
                scanf("%f", &char1.weight);
                char1.hp = 1000;
                char1.lvl = 1;
                break;
            case 2:
                printf("Input your character name ");
                scanf("%s", char2.name);
                printf("Input your character gender (Male/Female/Up to your hearts desire) ");
                scanf("%s", char2.gender);
                printf("Input your character height ");
                scanf("%f", &char2.height);
                printf("Input your character weight ");
                scanf("%f", &char2.weight);
                char1.hp = 1000;
                char1.lvl = 1;
                break;
            case 3:
                printf("Input your character name ");
                scanf("%s", char3.name);
                printf("Input your character gender (Male/Female/Up to your hearts desire)");
                scanf("%s", char3.gender);
                printf("Input your character height ");
                scanf("%f", &char3.height);
                printf("Input your character weight ");
                scanf("%f", &char3.weight);
                char1.hp = 1000;
                char1.lvl = 1;
                break;
            default:
                break;
            }

            break;
        case 2:
            choice = 0;
            int brick;
            display_char_menu();
            scanf("%d", &choice);
            switch (choice)
            {
            case 1 :
                printf("Name:   %s \n", char1.name);
                printf("Gender: %s \n", char1.gender);
                printf("Height: %.1f \n", char1.height);
                printf("weight: %.1f \n", char1.weight);
                printf("Health: %.1f \n", char1.hp);
                printf("Level:  %d \n", char1.lvl);
            case 2 :
                printf("Name:   %s \n", char2.name);
                printf("Gender: %s \n", char2.gender);
                printf("Height: %.1f \n", char2.height);
                printf("weight: %.1f \n", char2.weight);
                printf("Health: %.1f \n", char2.hp);
                printf("Level:  %d \n", char2.lvl);
            case 3 :
                printf("Name:   %s \n", char3.name);
                printf("Gender: %s \n", char3.gender);
                printf("Height: %.1f \n", char3.height);
                printf("weight: %.1f \n", char3.weight);
                printf("Health: %.1f \n", char3.hp);
                printf("Level:  %d \n", char3.lvl);    
            default:
                break;
            }
            break;
        default:
            printf("Error occurs, quitting program");
            break;
        }
    }


    return 0;
}


/*
    // Declare and initialize a struct variable
    struct warrior warrior = {"Alice", "Female", 154, 49, 1000, 1};

    // Access and display the information
    printf("Name : %s\n", warrior.name);
    printf("Gender: %s\n", warrior.gender);
    printf("Height : %.2f\n", warrior.height);
    printf("Weight : %.2f\n", warrior.weight);
    printf("Curent HP : %.2f\n", warrior.hp);
    printf("Current level : %d\n", warrior.lvl);
*/