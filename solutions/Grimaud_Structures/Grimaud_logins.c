#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100 
#define MAX_USERS 100    

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
} dates_s;

typedef struct {
  int nb_login;
  int uid;
  dates_s logged_on[MAX_LOG_ENTRIES];
} login_s;

typedef struct {
  char nickname[32];
  int uid;
  login_s *login;
} user_s;

dates_s now = {2024, 11, 13, 12, 0, 0};
user_s *users_array[MAX_USERS] = {NULL};

user_s *find_user(char *nickname) {
  for (int i = 0; i < MAX_USERS; i++) {
    if (users_array[i] != NULL &&
        strcmp(users_array[i]->nickname, nickname) == 0)
      return users_array[i];
  }
  return NULL;
}

void register_login(char *nickname) {
  user_s *user = find_user(nickname);
  if (user != NULL && user->login->nb_login < MAX_LOG_ENTRIES)
    user->login->logged_on[user->login->nb_login++] = now;
}

void delete_user(char *nickname) {
  for (int i = 0; i < MAX_USERS; i++) {
    if (users_array[i] != NULL &&
        strcmp(users_array[i]->nickname, nickname) == 0) {
      free(users_array[i]->login);
      free(users_array[i]);
      users_array[i] = NULL;
      break;
    }
  }
}

bool add_user(char *nickname, int uid) {
  int i;
  for (i = 0; i < MAX_USERS; i++)
    if (users_array[i] == NULL) break; 
  if(i>= MAX_USERS) return false;
  users_array[i] = (user_s *)malloc(sizeof(user_s));
  if (users_array[i] == NULL) return false; 
  int j=0;
  for(j=0;j<31 && nickname[j]!='\0';j++) 
    users_array[i]->nickname[j]=nickname[j]; 
  users_array[i]->nickname[j] = '\0'; 
  users_array[i]->uid = uid;
  users_array[i]->login = (login_s *)malloc(sizeof(login_s));
  if (users_array[i]->login == NULL) {
    free(users_array[i]);
    return false; 
  }
  users_array[i]->login->nb_login = 0;
  return true;
}

void print_user(user_s *u) {
  printf("nickname: %s, uid %d\n",u->nickname,u->uid);
  for(int i=0;i<u->login->nb_login;i++) {
    printf("\t log #%d: %d/%d/%d at %dh%dm%d\n",i,
	   u->login->logged_on[i].day,
	   u->login->logged_on[i].month,
	   u->login->logged_on[i].year,
	   u->login->logged_on[i].hour,
	   u->login->logged_on[i].minute,
	   u->login->logged_on[i].second);
  }
}

int main(int argc, char **argv) {
  // Adding some users
  printf("Adding users...\n");
  if (add_user("Alice", 101)) {
    printf("User Alice added.\n");
  } else {
    printf("Failed to add Alice.\n");
  }
  
  if (add_user("Bob", 102)) {
    printf("User Bob added.\n");
  } else {
    printf("Failed to add Bob.\n");
  }
  
  // Attempting to register a login for Alice
  printf("Registering login for Alice...\n");
  register_login("Alice");
  
  // Displaying information for Alice
  user_s *alice = find_user("Alice");
  if (alice != NULL) {
    printf("User Alice found:\n");
    print_user(alice);
  } else {
    printf("User Alice not found.\n");
  }
  
  // Attempting to register a login for a non-existent user
  printf("Registering login for Charlie (not added)...\n");
  register_login("Charlie");
  
  // Deleting a user
  printf("Deleting user Bob...\n");
  delete_user("Bob");
  
  // Verifying deletion of Bob
  user_s *bob = find_user("Bob");
  if (bob != NULL) {
    printf("User Bob still exists:\n");
    print_user(bob);
  } else {
    printf("User Bob successfully deleted.\n");
  }
  
  // Cleanup: deleting all remaining users
  printf("Cleaning up...\n");
  for (int i = 0; i < MAX_USERS; i++) {
    if (users_array[i] != NULL) {
      delete_user(users_array[i]->nickname);
    }
  }
  
  printf("All users cleaned up. Exiting...\n");
  return 0;
}

