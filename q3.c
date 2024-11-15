#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TEAMS 3       
#define SQUAD_SIZE 5      
typedef struct {
    char name[25];
    int kit_number;
    char club[20];
    struct {
        int day;
        int month;
        int year;
    } age;
    char position[20];
} player_t;
typedef struct {
    char name[20];
    player_t players[SQUAD_SIZE];
    int active_size;
} team_t;
void display_menu();
void enroll_club(team_t teams[], int *team_count);
void add_player(team_t teams[], int team_count);
void search_update(team_t teams[], int team_count);
void display_club_statistics(team_t teams[], int team_count);
void handle_error(const char *message);
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Search and Update Player\n");
    printf("4. Display Club Statistics\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}
void enroll_club(team_t teams[], int *team_count) {
    if (*team_count >= MAX_TEAMS) {
        handle_error("Maximum number of teams reached.");
        return;
    }
    printf("Enter club name: ");
    scanf("%s", teams[*team_count].name);
    teams[*team_count].active_size = 0;
    (*team_count)++;
    printf("Club enrolled successfully.\n");
}
void add_player(team_t teams[], int team_count) {
    if (team_count == 0) {
        handle_error("No clubs enrolled. Please enroll a club first.");
        return;
    }

    printf("Select a club:\n");
    for (int i = 0; i < team_count; i++) {
        printf("%d. %s\n", i + 1, teams[i].name);
    }
    int club_index;
    printf("Enter club number: ");
    scanf("%d", &club_index);
    club_index--;

    if (club_index < 0 || club_index >= team_count) {
        handle_error("Invalid club selection.");
        return;
    }

    if (teams[club_index].active_size >= SQUAD_SIZE) {
        handle_error("Squad size full.");
        return;
    }
     player_t new_player;
    printf("Enter player name: ");
    scanf("%s", new_player.name);
    printf("Enter kit number: ");
    scanf("%d", &new_player.kit_number);
    printf("Enter date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &new_player.age.day, &new_player.age.month, &new_player.age.year);
    printf("Enter position: ");
    scanf("%s", new_player.position);
    for (int i = 0; i < teams[club_index].active_size; i++) {
        if (strcmp(teams[club_index].players[i].name, new_player.name) == 0 || 
            teams[club_index].players[i].kit_number == new_player.kit_number) {
            handle_error("Duplicate player name or kit number.");
            return;
        }
    }
     teams[club_index].players[teams[club_index].active_size++] = new_player;
    printf("Player added successfully.\n");
}
