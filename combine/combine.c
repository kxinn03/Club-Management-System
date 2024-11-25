#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<windows.h>
#define MAX_RECORDS 100
#define cyan "\033[0;36m"
#define white "\033[0;37m"
#pragma warning(disable:4996)


//staff struct
typedef struct {
	char name[30], phoneNum[12];
} Details;

typedef struct {
	char staffID[10], position[20], gender, noIC[14];
	int password, recovery;
	Details details;
} Staff;


//member struct
struct Modify {
	char newModiID[20];
	char newModiName[30];
	char newModiGender;
	char newModiState[20];
	char newModiIC[20];
	char newModiPh[20];
	char newEmail[50];
	char confirm;
	int newModiYear;
};

typedef struct {
	char memberID[20], memberIC[20], memberEmail[50], state[20], memberName[30], memberPh[20];
	char gender;
	int yearJoin;
	struct Modify modify;
}Member;


// Facility Struct
typedef struct {
	int hours;
	int minutes;
}Time;

typedef struct {
	char facilityId[4];
	char types[30];
	char description[30];
	char venue[30];
	int maxallow;
	Time opentime;
	Time closetime;
	float charges;
}Facility;


//Booking Module
struct TodayDate {
	int todayDay;
	int todayMonth;
	int todayYear;
};

struct BookingDate {
	int bookingDay;
	int bookingMonth;
	int bookingYear;
};

struct BookingTime {
	int bookingStartHours;
	int bookingEndHours;
	int bookingStartMins;
	int bookingEndMins;
};

typedef struct {
	char bookingID[5];
	char memberID[6];
	char facilityID[6];
	char paymetMethod[20];
	struct TodayDate todayDate;
	struct BookingDate bookingDate;
	struct BookingTime bookingTime;
}Booking;


// Main page
void staffMainMenu();
void memberMenu();
void facilityMenu();
void bookingMenu();
void dash(int parameter);
void equalf(int parameter);
void dashf(int parameter);
void displaydash(int parameter);
void vbar(int parameter);
void cls(void);

void main() {
	int mainMenuChoice;
	do {
		printf("  _  __          _____   _____ _    _ _____ _   ___   _______ _   _      _____ _     _    _ ____  \n");
		printf(" | |/ /    /\\   |  __ \\ / ____| |  | |_   _| \\ | \\ \\ / /_   _| \\ | |    / ____| |   | |  | |  _ \ \n");
		printf(" | ' /    /  \\  | |__) | (___ | |__| | | | |  \\| |\\ V /  | | |  \\| |   | |    | |   | |  | | |_) |\n");
		printf(" |  <    / /\\ \\ |  _  / \\___ \\|  __  | | | | . ` | > <   | | | . ` |   | |    | |   | |  | |  _ < \n");
		printf(" | . \\  / ____ \\| | \\ \\ ____) | |  | |_| |_| |\\  |/ . \\ _| |_| |\\  |   | |____| |___| |__| | |_) |\n");
		printf(" |_|\\_\\/_/    \\_\\_|  \\_\\_____/|_|  |_|_____|_| \\_/_/ \\_\\_____|_| \\_|    \\_____|______\\____/|____/ \n");
		printf("\n\t  WELCOME TO KARSHINXIN CLUB!!!\t\n");
		dash(50);
		printf("\t\t 1. Staff Module\n");
		printf("\t\t 2. Member Module\n");
		printf("\t\t 3. Facility Module\n");
		printf("\t\t 4. Booking Module\n");
		printf("\t\t 5.Exit the program\n");
		printf("\tSelect a module by enter the number:");
		rewind(stdin);
		scanf("%d", &mainMenuChoice);
		while (mainMenuChoice < 1 || mainMenuChoice >5) {
			printf("  Invalid choice. Please enter again. [ 1-5 ]: ");
			rewind(stdin);
			scanf("%d", &mainMenuChoice);
		}
		if (mainMenuChoice == 1) {
			cls();
			staffMainMenu();
		}
		else if (mainMenuChoice == 2) {
			cls();
			memberMenu();
		}
		else if (mainMenuChoice == 3) {
			cls();
			facilityMenu();
		}
		else if (mainMenuChoice == 4) {
			cls();
			bookingMenu();
		}
		else if (mainMenuChoice == 5) {
			exit(-1);
		}
		else {
			printf("Invalid option!!! Please enter again: \n");
			rewind(stdin);
			scanf("%d", &mainMenuChoice);
			cls();
		}
	} while (mainMenuChoice >= 1 || mainMenuChoice <= 5);
	system("pause");
	system("cls");
}


//staff void function
void staffMenu();
void searchStaff();
void addStaff();
void displayStaff();
void modifyStaff();
void deleteStaff();
void reportStaff();
void printdash(int dash);

//staff main function
void staffMainMenu() {
	Staff staff;

	int choice;

	do {
		staffMenu();
		rewind(stdin);
		scanf("%d", &choice);
		while (choice < 1 || choice > 7) {
			printf("\n\n\tInvalid choice, please enter the valid number from menu (1-7)   ---> ");
			rewind(stdin);
			scanf("%d", &choice);
		}
		switch (choice)
		{
		case 1:system("cls"); addStaff(); break;
		case 2:	system("cls"); searchStaff(); break;
		case 3: system("cls"); modifyStaff(); break;
		case 4: system("cls"); displayStaff(); break;
		case 5: system("cls"); deleteStaff(); break;
		case 6: system("cls"); reportStaff(); break;
		case 7: system("cls"); break;
		default: printf("invalid choice");
		}

	} while (choice != 7);

}

void staffMenu() {
	system("cls");
	printf("   _____ _______       ______ ______   __  __  ____  _____  _    _ _      ______ \n");
	printf("  / ____|__   __|/\\   |  ____|  ____| |  \\/  |/ __ \\|  __ \\| |  | | |    |  ____|\n");
	printf(" | (___    | |  /  \\  | |__  | |__    | \\  / | |  | | |  | | |  | | |    | |__   \n");
	printf("  \\___ \\   | | / /\\ \\ |  __| |  __|   | |\\/| | |  | | |  | | |  | | |    |  __|  \n");
	printf("  ____) |  | |/ ____ \\| |    | |      | |  | | |__| | |__| | |__| | |____| |____ \n");
	printf(" |_____/   |_/_/    \\_\\_|    |_|      |_|  |_|\\____/|_____/ \\____/|______|______|\n\n");
	printf("\n\n%35s\n\n\n", "~~~WELCOME TO STAFF MODULE ~~~");

	printf("\t+----------------------+\n");
	printf("\t|      STAFF MENU      |\n");
	printf("\t+----------------------+\n");
	printf("\t| 1.Add Staff          |\n");
	printf("\t| 2.Search Staff       |\n");
	printf("\t| 3.Modify Staff       |\n");
	printf("\t| 4.Display Staff      |\n");
	printf("\t| 5.Delete Staff       |\n");
	printf("\t| 6.Report Staff       |\n");
	printf("\t| 7.Exit               |\n");
	printf("\t+----------------------+\n");
	printf("\tEnter your choice: ");
}

void addStaff() {
	FILE* addstaff, * recordFptr;
	Staff staff[MAX_RECORDS], add;
	int i;
	int index = 0;
	char choice;
	char conti;

	recordFptr = fopen("staff.dat", "rb");

	if (recordFptr == NULL) {
		printf("Error, unable to open file.\n");
		exit(-1);
	}

	while (fread(&staff[index], sizeof(Staff), 1, recordFptr) != 0) {
		index++;
	}
	fclose(recordFptr);

	do {
		printf("\n\tADD FUNCTION");
		printf("\n\t");
		printdash(12);
		printf("\n\tEnter Staff ID (eg. ST###): ");
		rewind(stdin);
		scanf("%s", &add.staffID);
		strupr(add.staffID);//strupr() = change string to uppercase
		while (add.staffID[0] != 'S' || add.staffID[1] != 'T' || add.staffID[2] != '0' && add.staffID[2] != '1' && add.staffID[2] != '2' && add.staffID[2] != '3' && add.staffID[2] != '4' && add.staffID[2] != '5' && add.staffID[2] != '6' && add.staffID[2] != '7' && add.staffID[2] != '8' && add.staffID[2] != '9' && add.staffID[3] != '0' && add.staffID[3] != '1' && add.staffID[3] != '2' && add.staffID[3] != '3' && add.staffID[3] != '4' && add.staffID[3] != '5' && add.staffID[3] != '6' && add.staffID[3] != '7' && add.staffID[3] != '8' && add.staffID[3] != '9' && add.staffID[4] != '0' && add.staffID[4] != '1' && add.staffID[4] != '2' && add.staffID[4] != '3' && add.staffID[4] != '4' && add.staffID[4] != '5' && add.staffID[4] != '6' && add.staffID[4] != '7' && add.staffID[4] != '8' && add.staffID[4] != '9') {
			printf("\n\t\tIncorrect format, please enter again");
			printf("\n\t\t   --->   ");
			scanf("%s", &add.staffID);
			strupr(add.staffID);
		}
		for (i = 0; i < index; i++) {
			while (strcmp(add.staffID, staff[i].staffID) == 0) {
				printf("\n\t\tSorry, this ID is used by others, please enter a new ID");
				printf("\n\t\t   --->   ");
				rewind(stdin);
				scanf("%s", &add.staffID);
				strupr(add.staffID);
				while (add.staffID[0] != 'S' || add.staffID[1] != 'T') {
					printf("\n\t\tIncorrect format, please enter again");
					printf("\n\t\t   --->   ");
					scanf("%s", &add.staffID);
					strupr(add.staffID);
				}
			}
		}
		printf("\n\tEnter Staff Name: ");
		rewind(stdin);
		scanf("%[^\n]", &add.details.name);
		strupr(add.details.name);
		printf("\n\tEnter Password(numbers only):");
		rewind(stdin);
		scanf("%d", &add.password);
		while (add.password < 0 || add.password > 9999999999) {
			printf("\n\t\tPlease enter only number");
			printf("\n\t\t   --->   ");
			rewind(stdin);
			scanf("%d", &add.password);
		}
		printf("\n\tEnter Password recovery(numbers only): ");
		rewind(stdin);
		scanf("%d", &add.recovery);
		while (add.recovery < 0 || add.recovery > 9999999999) {
			printf("\n\t\tPlease enter only number\n");
			printf("\n\t\t   --->   ");
			rewind(stdin);
			scanf("%d", &add.recovery);
		}
		printf("\n\tEnter Position: ");
		rewind(stdin);
		scanf("%[^\n]", &add.position);
		strupr(add.position);
		printf("\n\tEnter Phone Number(eg. XXX-XXXXXXXX): ");
		rewind(stdin);
		scanf("%s", &add.details.phoneNum);
		while (add.details.phoneNum[3] != '-')
		{
			printf("\n\t\tIncorrect format, please enter again");
			printf("\n\t\t   --->   ");
			rewind(stdin);
			scanf("%s", &add.details.phoneNum);
		}
		for (i = 0; i < index; i++) {
			while (strcmp(add.details.phoneNum, staff[i].details.phoneNum) == 0) {
				printf("\n\t\tSorry, this Phone Number is used by others, please enter again");
				printf("\n\t\t   --->   ");
				rewind(stdin);
				scanf("%s", &add.details.phoneNum);
				while (add.details.phoneNum[3] != '-')
				{
					printf("\n\t\tIncorrect format, please enter again");
					printf("\n\t\t   --->   ");
					rewind(stdin);
					scanf("%s", &add.details.phoneNum);
				}
			}
		}
		printf("\n\tEnter gender(Female=F,Male=M): ");
		rewind(stdin);
		scanf("%c", &add.gender);
		add.gender = toupper(add.gender);
		while (add.gender != 'F' && add.gender != 'M') {
			printf("\n\t\tPlease enter either F or M");
			printf("\n\t\t   --->   ");
			rewind(stdin);
			scanf("%c", &add.gender);
			add.gender = toupper(add.gender);
		}
		printf("\n\tEnter IC Number (with dash): ");
		rewind(stdin);
		scanf("%[^\n]", &add.noIC);
		while (add.noIC[6] != '-' || add.noIC[9] != '-') {
			printf("\n\t\tIncorrect format, please enter again");
			printf("\n\t\t   --->   ");
			rewind(stdin);
			scanf("%[^\n]", &add.noIC);
		}
		for (i = 0; i < index; i++) {
			while (strcmp(add.noIC, staff[i].noIC) == 0) {
				printf("\n\t\tSorry, this IC Number is registered, please enter a new IC Number");
				printf("\n\t\t   --->   ");
				rewind(stdin);
				scanf("%[^\n]", &add.noIC);
				while (add.noIC[6] != '-' || add.noIC[9] != '-') {
					printf("\n\t\tIncorrect format, please enter again");
					printf("\n\t\t   --->   ");
					rewind(stdin);
					scanf("%[^\n]", &add.noIC);
				}
			}
		}
		system("cls");
		printf("\n\n\t\t\t\t\tDetails of %s", add.staffID);
		printf("\n\t\t\t+-------------------------------------------------+");
		printf("\n\t\t\t| %-25s: %-20s |", "Staff ID", add.staffID);
		printf("\n\t\t\t| %-25s: %-20s |", "Staff Name", add.details.name);
		printf("\n\t\t\t| %-25s: %-20d |", "Staff login password", add.password);
		printf("\n\t\t\t| %-25s: %-20d |", "Staff password recovery", add.recovery);
		printf("\n\t\t\t| %-25s: %-20s |", "Staff Position", add.position);
		printf("\n\t\t\t| %-25s: %-20s |", "Staff phone number", add.details.phoneNum);
		printf("\n\t\t\t| %-25s: %-20c |", "Staff gender", add.gender);
		printf("\n\t\t\t| %-25s: %-20s |", "Staff IC number", add.noIC);
		printf("\n\t\t\t+-------------------------------------------------+");
		printf("\n\n\n\tSure to Add?(Yes='Y') : ");
		rewind(stdin);
		scanf("%c", &choice);
		if (toupper(choice) == 'Y') {
			staff[i] = add;
			addstaff = fopen("staff.dat", "ab");

			if (addstaff == NULL) {
				printf("Error, unable to open file.\n");
				exit(-1);
			}
			fwrite(&staff[i], sizeof(Staff), 1, addstaff);
			printf("\n\tYOUR RECORD HAVE BEEN SAVED   !!!");

			fclose(addstaff);
		}

		printf("\n\n\n\tDo You Want To Continue Add Staff?(Yes=Y)    ---> ");
		rewind(stdin);
		scanf("%c", &conti);
		system("cls");

	} while (toupper(conti) == 'Y');
}

void searchStaff() {
	Staff search, staff[MAX_RECORDS];
	int i = 0, choice = 0, searchStaff = 0;
	FILE* staffModule;
	char conti = 0;
	do {
		int index = 0;
		staffModule = fopen("staff.dat", "rb");
		if (staffModule == NULL) {
			printf("Error, unable to open file.\n");
			exit(-2);
		}
		while (fread(&staff[index], sizeof(Staff), 1, staffModule) != 0) {
			index++;
		}
		fclose(staffModule);

		if (index == 0)
			printf("\n\nNo record found.\n");
		else {
			printf("\n\t+-----------------------+");
			printf("\n\t|     SEARCH MENU       |");
			printf("\n\t+-----------------------+");
			printf("\n\t|1. Staff ID            |");
			printf("\n\t|2. Staff Name          |");
			printf("\n\t|3. Staff Position      |");
			printf("\n\t|4. Staff Phone Number  |");
			printf("\n\t|5. Staff Gender        |");
			printf("\n\t|6. Staff IC Number     |");
			printf("\n\t|7. Exit Search Function|");
			printf("\n\t+-----------------------+");
			printf("\n\tEnter your choice : ");
			rewind(stdin);
			scanf("%d", &choice);
			while (choice < 1 || choice> 7) {
				printf("\n\n\tInvalid choice, please enter the valid number from menu (1-7)   ---> ");
				scanf("%d", &choice);
			}
			system("cls");
			if (choice != 7) {
				searchStaff = 0; //to clear the data that search before
				if (choice == 1) {
					printf("\n\n\tEnter Staff ID : ");
					rewind(stdin);
					scanf("%[^\n]", &search.staffID);
					strupr(search.staffID);
					for (i = 0; i < index; i++) {
						if (strcmp(search.staffID, staff[i].staffID) == 0) {
							searchStaff++;
						}
					}
					if (searchStaff != 0) {
						printf("+=================================================================================================================================+\n");
						printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
						printf("+=================================================================================================================================+\n");
						for (i = 0; i < index; i++) {
							if (strcmp(search.staffID, staff[i].staffID) == 0) {
								printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
								printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
							}
						}
						printf("\n\n\t%d record found.\n", searchStaff);
					}

				}
				else if (choice == 2) {
					printf("\n\n\tEnter Staff Name : ");
					rewind(stdin);
					scanf("%[^\n]", &search.details.name);
					strupr(search.details.name);
					for (i = 0; i < index; i++) {
						if (strcmp(search.details.name, staff[i].details.name) == 0) {
							searchStaff++;
						}
					}
					if (searchStaff != 0) {
						printf("+=================================================================================================================================+\n");
						printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
						printf("+=================================================================================================================================+\n");
						for (i = 0; i < index; i++) {
							if (strcmp(search.details.name, staff[i].details.name) == 0) {
								printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
								printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
							}
						}
						printf("\n\n\t%d record found.\n", searchStaff);
					}

				}
				else if (choice == 3) {
					printf("\n\n\tEnter Staff Position : ");
					rewind(stdin);
					scanf("%[^\n]", &search.position);
					strupr(search.position);
					for (i = 0; i < index; i++) {
						if (strcmp(search.position, staff[i].position) == 0) {
							searchStaff++;
						}
					}
					if (searchStaff != 0) {
						printf("+=================================================================================================================================+\n");
						printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
						printf("+=================================================================================================================================+\n");
						for (i = 0; i < index; i++) {
							if (strcmp(search.position, staff[i].position) == 0) {
								printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
								printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");

							}
						}
						printf("\n\n\t%d record found.\n", searchStaff);
					}
				}
				else if (choice == 4) {
					printf("\n\n\tEnter Staff Phone Number : ");
					rewind(stdin);
					scanf("%[^\n]", &search.details.phoneNum);
					for (i = 0; i < index; i++) {
						if (strcmp(search.details.phoneNum, staff[i].details.phoneNum) == 0) {
							searchStaff++;
						}
					}
					if (searchStaff != 0) {
						printf("+=================================================================================================================================+\n");
						printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
						printf("+=================================================================================================================================+\n");
						for (i = 0; i < index; i++) {
							if (strcmp(search.details.phoneNum, staff[i].details.phoneNum) == 0) {
								printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
								printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
							}
						}
						printf("\n\n\t%d record found.\n", searchStaff);
					}

				}
				else if (choice == 5) {
					printf("\n\n\tEnter Staff Gender : ");
					rewind(stdin);
					scanf("%c", &search.gender);
					search.gender = toupper(search.gender);
					for (i = 0; i < index; i++) {
						if (staff[i].gender == search.gender) {
							searchStaff++;
						}
					}
					if (searchStaff != 0) {
						printf("+=================================================================================================================================+\n");
						printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
						printf("+=================================================================================================================================+\n");
						for (i = 0; i < index; i++) {
							if (staff[i].gender == search.gender) {
								printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
								printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");

							}
						}
						printf("\n\n\t%d record found.\n", searchStaff);
					}
				}
				else if (choice == 6) {
					printf("\n\n\tEnter Staff IC Number : ");
					rewind(stdin);
					scanf("%[^\n]", &search.noIC);
					for (i = 0; i < index; i++) {
						if (strcmp(search.noIC, staff[i].noIC) == 0) {
							searchStaff++;
						}
					}
					if (searchStaff != 0) {
						printf("+=================================================================================================================================+\n");
						printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
						printf("+=================================================================================================================================+\n");
						for (i = 0; i < index; i++) {
							if (strcmp(search.noIC, staff[i].noIC) == 0) {
								printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
								printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
							}
						}
						printf("\n\n\t%d record found.\n", searchStaff);
					}

				}
				if (searchStaff == 0) {
					printf("\n\n\tNo record according the data you enter.");
				}

				printf("\n\n\n\tDo You Want To Continue Search Staff?(Yes=Y)    ---> ");
				rewind(stdin);
				scanf("%c", &conti);
				system("cls");
			}

		}
	} while (toupper(conti) == 'Y' && choice < 7);

}

void modifyStaff() {
	Staff staff[MAX_RECORDS], modify, input;
	int sCount = 0;

	FILE* staffModule, * Modify;
	staffModule = fopen("staff.dat", "rb");
	if (staffModule == NULL) {
		printf("Error opening file.\n");
		exit(-3);
	}

	while (fread(&staff[sCount], sizeof(Staff), 1, staffModule) != 0) {
		sCount++;
	}
	fclose(staffModule);


	int i;
	char confirm, searchID[10];
	char conti = 0;
	int choice = 0;
	int modi = -1;
	do {
		printf("\n%65s\n", "LIST OF STAFF");
		printf("+=================================================================================================================================+\n");
		printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
		printf("+=================================================================================================================================+\n");
		for (i = 0; i < sCount; i++) {
			printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
			printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");

		}

		printf("Enter the staff ID to be modified > ");
		rewind(stdin);
		scanf("%s", searchID);
		strupr(searchID);
		system("cls");
		for (i = 0; i < sCount; i++) {

			if (strcmp(staff[i].staffID, searchID) == 0) {
				printf("\n\n\t\t\t\t\tDetails of %s", staff[i].staffID);
				printf("\n\t\t\t+-------------------------------------------------+");
				printf("\n\t\t\t| %-25s: %-20s |", "Staff ID", staff[i].staffID);
				printf("\n\t\t\t| %-25s: %-20s |", "Staff Name", staff[i].details.name);
				printf("\n\t\t\t| %-25s: %-20d |", "Staff login password", staff[i].password);
				printf("\n\t\t\t| %-25s: %-20d |", "Staff password recovery", staff[i].recovery);
				printf("\n\t\t\t| %-25s: %-20s |", "Staff Position", staff[i].position);
				printf("\n\t\t\t| %-25s: %-20s |", "Staff phone number", staff[i].details.phoneNum);
				printf("\n\t\t\t| %-25s: %-20c |", "Staff gender", staff[i].gender);
				printf("\n\t\t\t| %-25s: %-20s |", "Staff IC number", staff[i].noIC);
				printf("\n\t\t\t+-------------------------------------------------+");
				modify = staff[i];
				modi = i; //to store the index of modify
				printf("\n\t\t\t\t+--------------------------+");
				printf("\n\t\t\t\t|       MODIFY MENU        |");
				printf("\n\t\t\t\t+--------------------------+");
				printf("\n\t\t\t\t|1. Staff ID               |");
				printf("\n\t\t\t\t|2. Staff Name             |");
				printf("\n\t\t\t\t|3. Staff Password         |");
				printf("\n\t\t\t\t|4. Staff Password Recovery|");
				printf("\n\t\t\t\t|5. Staff Position         |");
				printf("\n\t\t\t\t|6. Staff Phone Number     |");
				printf("\n\t\t\t\t|7. Staff Gender           |");
				printf("\n\t\t\t\t|8. Staff IC Number        |");
				printf("\n\t\t\t\t|9. Exit                   |");
				printf("\n\t\t\t\t+--------------------------+");
				printf("\n\t\t\t\tEnter your choice : ");
				rewind(stdin);
				scanf("%d", &choice);
				if (choice < 1 || choice > 9) {
					printf("\n\n\tInvalid choice, please enter the valid number from menu (1-9)   ---> ");
					rewind(stdin);
					scanf("%d", &choice);
				}
				if (choice != 9) {
					if (choice == 1) {
						printf("\n\n\tEnter New Staff ID (eg. ST###) :   ");
						rewind(stdin);
						scanf("%[^\n]", &input.staffID);
						strupr(input.staffID);
						while (input.staffID[0] != 'S' || input.staffID[1] != 'T' || input.staffID[2] != '0' && input.staffID[2] != '1' && input.staffID[2] != '2' && input.staffID[2] != '3' && input.staffID[2] != '4' && input.staffID[2] != '5' && input.staffID[2] != '6' && input.staffID[2] != '7' && input.staffID[2] != '8' && input.staffID[2] != '9' && input.staffID[3] != '0' && input.staffID[3] != '1' && input.staffID[3] != '2' && input.staffID[3] != '3' && input.staffID[3] != '4' && input.staffID[3] != '5' && input.staffID[3] != '6' && input.staffID[3] != '7' && input.staffID[3] != '8' && input.staffID[3] != '9' && input.staffID[4] != '0' && input.staffID[4] != '1' && input.staffID[4] != '2' && input.staffID[4] != '3' && input.staffID[4] != '4' && input.staffID[4] != '5' && input.staffID[4] != '6' && input.staffID[4] != '7' && input.staffID[4] != '8' && input.staffID[4] != '9') {
							printf("\n\t\tIncorrect format, please enter again");
							printf("\n\t\t   --->   ");
							scanf("%s", &input.staffID);
							strupr(input.staffID);
						}
						for (i = 0; i < sCount; i++) {
							while (strcmp(input.staffID, staff[i].staffID) == 0) {
								printf("\n\t\tSorry, this ID is used by others, please enter a new ID");
								printf("\n\t\t   --->   ");
								rewind(stdin);
								scanf("%[^\n]", &input.staffID);
								strupr(input.staffID);
								while (input.staffID[0] != 'S' || input.staffID[1] != 'T') {
									printf("\n\t\tIncorrect format, please enter again");
									printf("\n\t\t   --->   ");
									scanf("%s", &input.staffID);
									strupr(input.staffID);
								}
							}
						}
						strcpy(modify.staffID, input.staffID);
					}
					if (choice == 2) {
						printf("\n\n\tEnter New Name :   ");
						rewind(stdin);
						scanf("%[^\n]", &input.details.name);
						strupr(input.details.name);
						strcpy(modify.details.name, input.details.name);
					}
					if (choice == 3) {
						printf("\n\n\tEnter New Password (numbers only):   ");
						rewind(stdin);
						scanf("%d", &input.password);
						while (input.password < 0 || input.password > 9999999999) {
							printf("\n\t\tPlease enter only number");
							printf("\n\t\t   --->   ");
							rewind(stdin);
							scanf("%d", &input.password);
						}
						modify.password = input.password;
					}
					if (choice == 4) {
						printf("\n\n\tEnter New Password Recovery (numbers only):   ");
						rewind(stdin);
						scanf("%d", &input.recovery);
						while (input.recovery < 0 || input.recovery > 9999999999) {
							printf("\n\t\tPlease enter only number");
							printf("\n\t\t   --->   ");
							rewind(stdin);
							scanf("%d", &input.recovery);
						}
						modify.recovery = input.recovery;
					}
					if (choice == 5) {
						printf("\n\n\tEnter New Position :   ");
						rewind(stdin);
						scanf("%[^\n]", &input.position);
						strupr(input.position);
						strcpy(modify.position, input.position);

					}
					if (choice == 6) {
						printf("\n\n\tEnter New Phone Number (eg. XXX-XXXXXXXX):   ");
						rewind(stdin);
						scanf("%s", &input.details.phoneNum);
						while (input.details.phoneNum[3] != '-')
						{
							printf("\n\t\tIncorrect format, please enter again");
							printf("\n\t\t   --->   ");
							rewind(stdin);
							scanf("%s", &input.details.phoneNum);
						}
						for (i = 0; i < sCount; i++) {
							while (strcmp(input.details.phoneNum, staff[i].details.phoneNum) == 0) {
								printf("\n\t\tSorry, this Phone Number is used by others, please enter again");
								printf("\n\t\t   --->   ");
								rewind(stdin);
								scanf("%s", &input.details.phoneNum);
								while (input.details.phoneNum[3] != '-')
								{
									printf("\n\t\tIncorrect format, please enter again");
									printf("\n\t\t   --->   ");
									rewind(stdin);
									scanf("%s", &input.details.phoneNum);
								}
							}
						}
						strcpy(modify.details.phoneNum, input.details.phoneNum);
					}
					if (choice == 7) {
						printf("\n\n\tEnter New Gender (Female=F,Male=M):   ");
						rewind(stdin);
						scanf("%c", &input.gender);
						input.gender = toupper(input.gender);
						while (input.gender != 'F' && input.gender != 'M') {
							printf("\n\t\tPlease enter either F or M");
							printf("\n\t\t   --->   ");
							rewind(stdin);
							scanf("%c", &input.gender);
							input.gender = toupper(input.gender);
						}
						modify.gender = input.gender;
					}
					if (choice == 8) {
						printf("\n\n\tEnter New IC Number (with dash):   ");
						rewind(stdin);
						scanf("%[^\n]", &input.noIC);
						while (input.noIC[6] != '-' || input.noIC[9] != '-') {
							printf("\n\t\tIncorrect format, please enter again");
							printf("\n\t\t   --->   ");
							rewind(stdin);
							scanf("%[^\n]", &input.noIC);
						}
						for (i = 0; i < sCount; i++) {
							while (strcmp(staff[i].noIC, input.noIC) == 0) {
								printf("\n\t\tSorry, this IC Number is registered, please enter a new IC Number");
								printf("\n\t\t   --->   ");
								rewind(stdin);
								scanf("%[^\n]", &input.noIC);
								while (input.noIC[6] != '-' || input.noIC[9] != '-') {
									printf("\n\t\tIncorrect format, please enter again");
									printf("\n\t\t   --->   ");
									rewind(stdin);
									scanf("%[^\n]", &input.noIC);
								}
							}
						}
						strcpy(modify.noIC, input.noIC);
					}
					printf("\n\n\n\tContinue to save(Yes=Y,No=N): ");
					rewind(stdin);
					scanf("%c", &confirm);
					if (toupper(confirm) == 'Y') {
						Modify = fopen("staff.dat", "wb");
						if (Modify == NULL) {
							printf("\n\nUnable to open staff.dat");
							exit(-3);
						}
						staff[modi] = modify;
						for (i = 0; i < sCount; i++) {
							fwrite(&staff[i], sizeof(Staff), 1, Modify);
						}
						fclose(Modify);
						system("cls");
						printf("%75s\n", "LIST OF STAFF(AFTER MODIFY)");
						printf("+=================================================================================================================================+\n");
						printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
						printf("+=================================================================================================================================+\n");
						for (i = 0; i < sCount; i++) {
							printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
							printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");

						}
					}

					else if (toupper(confirm) == 'N') {
						system("cls");
						printf("\n\t\t***The data will not be change***\n\n\n");
					}

					printf("\n\t\tContinue To Modify Staff? (Yes = Y, No = N)    --->");
					rewind(stdin);
					scanf("%c", &conti);
					system("cls");
				}

			}


		}


	} while (toupper(conti) != 'N' && choice < 9);
}

void displayStaff() {
	FILE* displaystaff;
	Staff staff[MAX_RECORDS];
	int i;
	int index = 0;
	char quit;

	displaystaff = fopen("staff.dat", "rb");
	if (displaystaff == NULL) {
		printf("Error, unable to open file.\n");
		exit(-4);
	}

	while (fread(&staff[index], sizeof(Staff), 1, displaystaff) != 0) {
		index++;
	}

	fclose(displaystaff);

	if (index == 0) {
		printf("\n\nNo record found\n");
	}

	else {
		printf("\n\n\n");
		printf("+=================================================================================================================================+\n");
		printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
		printf("+=================================================================================================================================+\n");
		for (i = 0; i < index; i++) {
			printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
			printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
		}
		printf("\n%d records found.\n", index);
		printf("\nPress any keys and enter to exit. ");
		rewind(stdin);
		scanf("%c", &quit);

		system("cls");
	}

}

void deleteStaff() {
	Staff delete, staff[MAX_RECORDS];
	FILE* deleteFptr, * staffModule;
	int choice = 0;
	int i = 0;
	int found;
	char conti = 0;

	do {
		found = -1;
		int index = 0;
		staffModule = fopen("staff.dat", "rb");
		if (staffModule == NULL) {
			printf("Unable to open staff.dat\n");
			exit(-5);
		}
		while (fread(&staff[index], sizeof(Staff), 1, staffModule) != 0) {
			index++;
		}
		fclose(staffModule);
		if (index == 0)
			printf("\n\nNo record found.\n");
		else {
			printf("+=================================================================================================================================+\n");
			printf("| %-8s | %-20s | %-8s | %-17s | %-20s | %-13s | %6s | %-14s |\n", "Staff ID", "Name", "Password", "Password Recovery", "Position", "Phone Number", "Gender", "IC Number");
			printf("+=================================================================================================================================+\n");
			for (i = 0; i < index; i++) {
				printf("| %-8s | %-20s | %-8d | %-17d | %-20s | %-13s | %-6c | %-14s |\n", staff[i].staffID, staff[i].details.name, staff[i].password, staff[i].recovery, staff[i].position, staff[i].details.phoneNum, staff[i].gender, staff[i].noIC);
				printf("+---------------------------------------------------------------------------------------------------------------------------------+\n");
			}
		}
		printf("\n\t+---------------------------------------+");
		printf("\n\t|         DELETE FUNCTION MENU          |");
		printf("\n\t+---------------------------------------+");
		printf("\n\t|1. Continue delete by enter Staff ID   |");
		printf("\n\t|2. Exit delete function                |");
		printf("\n\t+---------------------------------------+");
		printf("\n\tEnter your choice : ");
		rewind(stdin);
		scanf("%d", &choice);
		while (choice < 1 || choice>2) {
			printf("\n\n\tInvalid choice, please enter the valid number from menu (1 or 2)   ---> ");
			rewind(stdin);
			scanf("%d", &choice);
		}
		if (choice != 2) {
			if (choice == 1) {
				printf("\n\n\tEnter the Staff ID :  ");
				rewind(stdin);
				scanf("%[^\n]", &delete.staffID);
				strupr(delete.staffID);

				for (i = 0; i < index; i++) {

					if (strcmp(delete.staffID, staff[i].staffID) == 0) {
						system("cls");
						printf("\n\n\t\t\t\t\tDELETE FUNCTION");
						printf("\n\t\t\t\t\t-----------------");
						printf("\n\n\t\t\t\t\tDetails of %s", staff[i].staffID);
						printf("\n\t\t\t+-------------------------------------------------+");
						printf("\n\t\t\t| %-25s: %-20s |", "Staff ID", staff[i].staffID);
						printf("\n\t\t\t| %-25s: %-20s |", "Staff Name", staff[i].details.name);
						printf("\n\t\t\t| %-25s: %-20d |", "Staff login password", staff[i].password);
						printf("\n\t\t\t| %-25s: %-20d |", "Staff password recovery", staff[i].recovery);
						printf("\n\t\t\t| %-25s: %-20s |", "Staff Position", staff[i].position);
						printf("\n\t\t\t| %-25s: %-20s |", "Staff phone number", staff[i].details.phoneNum);
						printf("\n\t\t\t| %-25s: %-20c |", "Staff gender", staff[i].gender);
						printf("\n\t\t\t| %-25s: %-20s |", "Staff IC number", staff[i].noIC);
						printf("\n\t\t\t+-------------------------------------------------+");
						found = i;
					}
				}
				if (found == -1)
					printf("\n\n\t\tNo record according the data you enter");
				else {
					printf("\n\n\n\tContinue to delete(Yes='Y') : ");
					rewind(stdin);
					scanf("%c", &conti);
					if (toupper(conti) == 'Y') {
						index--;
						deleteFptr = fopen("staff.dat", "wb");
						if (deleteFptr == NULL) {
							printf("\nUnable to open staff.dat");
							exit(-5);
						}
						for (i = 0; i < index; i++) {
							if (i >= found)
								staff[i] = staff[i + 1];
						}
						for (i = 0; i < index; i++) {
							fwrite(&staff[i], sizeof(Staff), 1, deleteFptr);
						}
						printf("\n\t\t\t\t    SAVED   !!");
						fclose(deleteFptr);
					}
				}
			}
		}
		if (index == 0 || choice == 1) {
			printf("\n\n\tContinue to delete another staff?(Yes to Continue='Y')    ---> ");
			rewind(stdin);
			scanf("%c", &conti);
			system("cls");
		}
	} while (toupper(conti) == 'Y' && choice < 2);


}

void reportStaff() {
	Staff staff[MAX_RECORDS];
	int index = 0;
	int choice = 0;
	int i = 0;
	int female = 0;
	int male = 0;
	int conti = 0;
	index = 0;
	FILE* staffFptr;
	staffFptr = fopen("staff.dat", "rb");
	if (staffFptr == NULL) {
		printf("Unable to open staff.dat\n");
		exit(-6);
	}
	while (fread(&staff[index], sizeof(Staff), 1, staffFptr) != 0) {
		index++;
	}
	fclose(staffFptr);
	do {
		if (index == 0)
			printf("\n\nNo record found.\n");
		else {
			printf("\n\t+------------------------------------------+");
			printf("\n\t|          REPORT FUNCTION MENU            |");
			printf("\n\t+------------------------------------------+");
			printf("\n\t|1. Report of total number of staff        |");
			printf("\n\t|2. Report of total number of female staff |");
			printf("\n\t|3. Report of total number of male staff   |");
			printf("\n\t|4. Report of name list of staff           |");
			printf("\n\t|5. Exit report function                   |");
			printf("\n\t+------------------------------------------+");
			printf("\n\tEnter your choice : ");
			rewind(stdin);
			scanf("%d", &choice);
			while (choice < 1 || choice > 5) {
				printf("\n\n\tInvalid choice, please enter the valid number from menu (1-5)   ---> ");
				scanf("%d", &choice);
			}
			if (choice != 5) {
				if (choice == 1) {
					system("cls");
					printf("+----------------------------------------------------------------------+\n");
					printf("| %50s %19s\n", "Report of total number of staff", "|");
					printf("+----------------------------------------------------------------------+\n");
					printf("%-1s %71s", "|", "|\n");
					printf("| Total Number -----------> %02d %41s\n", index, "|");
					printf("%-1s %71s", "|", "|\n");
					printf("+----------------------------------------------------------------------+\n");
				}
				else if (choice == 2) {
					for (i = 0; i < index; i++) {
						if (staff[i].gender == 'F') {
							female++;
						}
					}
					system("cls");
					printf("+----------------------------------------------------------------------+\n");
					printf("| %50s %19s\n", "Report of total number of female staff", "|");
					printf("+----------------------------------------------------------------------+\n");
					printf("%-1s %71s", "|", "|\n");
					printf("| Total Number -----------> %02d %41s\n", female, "|");
					printf("%-1s %71s", "|", "|\n");
					printf("+----------------------------------------------------------------------+\n");
				}
				else if (choice == 3) {
					for (i = 0; i < index; i++) {
						if (staff[i].gender == 'M') {
							male++;
						}
					}
					system("cls");
					printf("+----------------------------------------------------------------------+\n");
					printf("| %50s %19s\n", "Report of total number of male staff", "|");
					printf("+----------------------------------------------------------------------+\n");
					printf("%-1s %71s", "|", "|\n");
					printf("| Total Number -----------> %02d %41s\n", male, "|");
					printf("%-1s %71s", "|", "|\n");
					printf("+----------------------------------------------------------------------+\n");
				}
				else if (choice == 4) {
					system("cls");
					printf("+----------------------------------------------------------------------+\n");
					printf("| %50s %19s\n", "Report of name list of staff", "|");
					printf("+----------------------------------------------------------------------+\n");
					for (i = 0; i < index; i++) {
						printf("| Staff No %02d: %-30s %26s\n", i + 1, staff[i].details.name, "|");
					}
					printf("+----------------------------------------------------------------------+\n");
				}
				printf("\n\n\n\tDo You Want To Continue?(Yes to Continue='Y')    ---> ");
				rewind(stdin);
				scanf("%c", &conti);
				system("cls");
			}
		}





	} while (toupper(conti) == 'Y' && choice < 5);

}

void printdash(int dash) {

	for (int i = 0; i < dash; i++)
		printf("-");
	printf("\n");
}


// member void function
void addMember();
void displayMember();
void searchMember();
void modifyMember();
void deleteMember();
void reportMember();
void singledash(int parameter);

// memberModule
void memberMenu() {
	printf("  __  __ ______ __  __ ____  ______ _____    __  __  ____  _____  _    _ _      ______ \n");
	printf(" |  \\/  |  ____|  \\/  |  _ \\|  ____|  __ \\  |  \\/  |/ __ \\|  __ \\| |  | | |    |  ____|\n");
	printf(" | \\  / | |__  | \\  / | |_) | |__  | |__) | | \\  / | |  | | |  | | |  | | |    | |__   \n");
	printf(" | |\\/| |  __| | |\\/| |  _ <|  __| |  _  /  | |\\/| | |  | | |  | | |  | | |    |  __|  \n");
	printf(" | |  | | |____| |  | | |_) | |____| | \\ \\  | |  | | |__| | |__| | |__| | |____| |____ \n");
	printf(" |_|  |_|______|_|  |_|____/|______|_|  \\_\\ |_|  |_|\\____/|_____/ \\____/|______|______|\n");
	int choice;

	do {
		printf("\n\n\tSelection Menu For Member Information\n");
		dash(50);
		printf("                                                 |\n");
		printf("\t\t1. Add Member                    |\n");
		printf("\t\t2. Display Member                |\n");
		printf("\t\t3. Search Member                 |\n");
		printf("\t\t4. Modify Member                 |\n");
		printf("\t\t5. Delete Member                 |\n");
		printf("\t\t6. Summary Report                |\n");
		printf("\t\t7. Exit                          |\n");
		printf("                                                 |\n");
		dash(50);
		printf("\t\tEnter your choice:");
		rewind(stdin);
		scanf("%d", &choice);
		while (choice < 1 || choice >7) {
			printf("Invalid choice. Please enter again. [ 1-7 ]: ");
			rewind(stdin);
			scanf("%d", &choice);
		}
		dash(50);
		printf("\n\n");
		switch (choice) {
		case 1: system("cls"); addMember();
			break;
		case 2: system("cls"); displayMember();
			break;
		case 3: system("cls"); searchMember();
			break;
		case 4:system("cls"); modifyMember();
			break;
		case 5: system("cls"); deleteMember();
			break;
		case 6: system("cls"); reportMember();
			break;
		default:
		case 7: system("cls"); main();
			break;
		}
		system("cls");
	} while (choice != 7);
}

void addMember() {
	Member info;
	Member check[MAX_RECORDS];
	Staff staff[MAX_RECORDS];
	int h = 0;
	int i = 0;
	int index = 0;
	char ans;
	char staffID[10];
	int staffPassword;

	FILE* fptr = fopen("addmember.dat", "ab");
	FILE* fp = fopen("addmember.dat", "rb");
	if (fptr == NULL) {
		printf("Error, can't open the data\n");
		exit(-1);
	}
	if (fp == NULL) {
		printf("Error, can't open the data\n");
		exit(-2);
	}

	// link staff module
	FILE* validStaff = fopen("staff.dat", "rb");
	if (validStaff == NULL) {
		printf("Error, can't open the data\n");
		exit(-3);
	}
	while (fread(&staff[index], sizeof(Staff), 1, validStaff) != 0) {
		index++;
	}
	fclose(validStaff);

	printf("\t\t\t  Member ID that are available.\n");
	while (fread(&check[h], sizeof(Member), 1, fp) != 0) {
		printf("\t\t\t\t\t%-6s\n", check[h].memberID);
		h++;
	}
	fclose(fp);
	printf("Before adding member, please login with your staff information below.\n");
	int searchID = 0, searchPas = 0;
	// member module add function
	do {
		do {
			printf("\nEnter your staff ID : ");
			rewind(stdin);
			scanf("%s", &staffID);
			strupr(staffID);
			for (int i = 0; i < index; i++)
			{
				if (strcmp(staff[i].staffID, staffID) == 0) {
					searchID = 1;
				}
			}
			if (searchID == 0) {
				printf("Invalid staff ID! \n");
			}
			printf("\nEnter your staff password: ");
			rewind(stdin);
			scanf("%d", &staffPassword);
			for (int i = 0; i < index; i++)
			{
				if (staff[i].password == staffPassword) {
					searchPas = 1;
				}
			}
			if (searchPas == 0) {
				printf("Invalid Password! \n");
			}
		} while (searchPas == 0);
		printf("Login Successfully! \n");

		printf("\nEnter the member's details below\n");
		printf("------------------------------------\n");
		printf("Member ID [eg. www**]: ");
		rewind(stdin);
		scanf("%s", &info.memberID);
		while (info.memberID[0] != 'w' || info.memberID[1] != 'w' || info.memberID[2] != 'w') {
			printf("Incorrect member format.\n");
			printf("Please enter the member ID again [eg. www**]: ");
			rewind(stdin);
			scanf("%s", &info.memberID);
			printf("\n");
		}
		for (int i = 0; i < h; i++)
		{
			while (strcmp(check[i].memberID, info.memberID) == 0)
			{
				printf("Member ID available, can't repeat. Please enter again: ");
				rewind(stdin);
				scanf("%s", &info.memberID);
				while (info.memberID[0] != 'w' || info.memberID[1] != 'w' || info.memberID[2] != 'w') {
					printf("Incorrect member format.\n");
					printf("Please enter the member ID again [eg. www**]: ");
					rewind(stdin);
					scanf("%s", &info.memberID);
					printf("\n");
				}
			}
		}
		printf("Member Name: ");
		rewind(stdin);
		gets(info.memberName);
		printf("\n");

		printf("Member Gender [ F=female / M=male ]: ");
		rewind(stdin);
		scanf("%c", &info.gender);
		printf("\n");
		while (toupper(info.gender) != 'F' && toupper(info.gender) != 'M') {
			printf("Invalid gender choice.\n");
			printf("Please enter your choice again [ F=female / M=male ]: ");
			rewind(stdin);
			scanf("%c", &info.gender);
			printf("\n\n");
		}

		printf("Year Join : ");
		rewind(stdin);
		scanf("%d", &info.yearJoin);
		printf("\n");
		while (info.yearJoin < 1922 || info.yearJoin > 2022) {
			printf("Invalid year.\n");
			printf("Please enter the year again [Only can enter year 1922 - 2022] : ");
			rewind(stdin);
			scanf("%d", &info.yearJoin);
			printf("\n\n");
		}

		printf("Member IC [eg. 010203-14-8900]: ");
		rewind(stdin);
		scanf("%s", &info.memberIC);
		printf("\n");
		while (info.memberIC[6] != '-' && info.memberIC[9] != '-')
		{
			printf("Incorrect IC format\n");
			printf("Please enter the member IC again [eg. 010203-14-8900]:");
			rewind(stdin);
			gets(info.memberIC);
			printf("\n\n");
		}
		printf("Member Contact Number [eg. 011-234567] : ");
		rewind(stdin);
		scanf("%s", &info.memberPh);
		printf("\n");
		while (info.memberPh[3] != '-')
		{
			printf("Incorrect Contact Number format\n");
			printf("Please enter the contact number again [eg. 011-234567] :");
			rewind(stdin);
			scanf("%s", &info.memberPh);
			printf("\n\n");
		}

		printf("Member Email: ");
		rewind(stdin);
		gets(info.memberEmail);
		printf("\n");

		printf("Place member stay [eg. Cheras]: ");
		rewind(stdin);
		gets(info.state);
		printf("\n");
		printf("Member Will Be Successfully Added After Aswering The Question Below.");
		printf("\nAdd more records? press y[Yes] or n[No] :");
		rewind(stdin);
		scanf("%c", &ans);
		while (toupper(ans) != 'N' && toupper(ans) != 'Y') {
			printf("Invalid Choice\n");
			printf("Enter new choice , y[Yes] or n[No]: ");
			rewind(stdin);
			scanf("%c\n", &ans);
		}
		fwrite(&info, sizeof(Member), 1, fptr);
		system("cls");
	} while (toupper(ans) != 'N'); {
		printf("End of adding member......\n");
		printf("You're now returning to the member selection menu\n\n\n\n\n");
	}
	fclose(fptr);
	system("cls");
}

void displayMember() {
	Member info;
	int i = 0;
	FILE* fptr2 = fopen("addmember.dat", "rb");
	if (fptr2 == NULL) {
		printf("Error, can't open the data\n");
		exit(-3);
	}

	int count = 0, one;
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\tMembers In KARSHINXIN CLUB\n");
	printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
	printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");

	while (fread(&info, sizeof(Member), 1, fptr2) != 0) {
		printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n", info.memberID, info.memberName, info.gender, "", info.state, info.yearJoin, "", info.memberIC, info.memberPh, "", info.memberEmail);
		count++;
	}
	printf("\n< There are %d members listed above >\n", count);
	do {
		printf("Press 1 to exit this file. ");
		rewind(stdin);
		scanf("%d", &one);
		if (one == 1) {
			printf("Exiting.........\n\n\n\n");
		}
		else {
			printf("Invalid choice. Please enter the correct number.\n\n");
		}
	} while (one != 1);
	fclose(fptr2);
	system("cls");
}

void searchMember() {
	Member info;
	Member search[MAX_RECORDS];
	int count = 0;

	FILE* fptr3 = fopen("addmember.dat", "rb");
	if (fptr3 == NULL) {
		printf("Error, can't open the data\n");
		exit(-4);
	}
	while (fread(&search[count], sizeof(Member), 1, fptr3) != 0) {
		count++;
	}
	fclose(fptr3);

	char searchName[20], ans;
	do {
		int checkName = 0;
		printf("\n\nEnter the member name you want to search: ");
		rewind(stdin);
		gets(searchName);

		for (int set = 0; set < count; set++) {
			if (strcmp(search[set].memberName, searchName) == 0)
			{
				checkName++;
				printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
				printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
				printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", search[set].memberID, search[set].memberName, search[set].gender, "", search[set].state, search[set].yearJoin, "", search[set].memberIC, search[set].memberPh, "", search[set].memberEmail);
				set++;
			}
		}
		if (checkName != 1) {
			printf("  //  No Record Found.  //  \n\n");
		}
		printf("Do you want to search for another time [ Y-Yes, N-No ]: ");
		rewind(stdin);
		scanf("%c", &ans);
		while (toupper(ans) != 'N' && toupper(ans) != 'Y') {
			printf("INVALID INPUT\n");
			printf("Please enter your choice again [ Y-Yes, N-No ]:");
			rewind(stdin);
			scanf("%c", &ans);
			printf("\n\n");
		}
	} while (toupper(ans) != 'N');
	printf("Going back to member menu selection list....\n\n\n\n");
	system("cls");
}

void modifyMember() {
	Member info;
	Member modi[MAX_RECORDS];
	int mCount = 0;
	int choice = 0;
	int checkAvai = 0;
	char modiName[30];
	char confirm2;

	FILE* fptr4 = fopen("addmember.dat", "rb");


	if (fptr4 == NULL) {
		printf("Error cannot find the file \n");
		exit(-5);
	}

	while (fread(&modi[mCount], sizeof(Member), 1, fptr4) != 0) {
		mCount++;
	}
	fclose(fptr4);

	do {
		printf("\n");
		printf("\n\t\t\t\t\t\t\t\tModify For Members In KARSHINXIN CLUB\n");
		printf("\t\t\t\t\t\t\t\t  Member Name That Are Available\n");
		printf("\t\t\t\t\t\t\t\t  ================================\n");
		for (int i = 0; i < mCount; i++) {
			printf("\t\t\t\t\t\t\t\t\t\t%-15s\n", modi[i].memberName);
		}

		printf("\n\nEnter the member name that needed to be modified: ");
		rewind(stdin);
		scanf("%s", &modiName);
		for (int i = 0; i < mCount; i++) {
			if (strcmp(modi[i].memberName, modiName) == 0) {
				checkAvai++;
				printf("\t    . Member's details . \n");
				printf("--------------------------------------------\n");
				printf("\tMember ID   : %-13s\n", modi[i].memberID);
				printf("\tMember Name : %-15s\n", modi[i].memberName);
				printf("\tGender      : %-3c\n", modi[i].gender);
				printf("\tState       : %-20s\n", modi[i].state);
				printf("\tYear Join   : %-4d\n", modi[i].yearJoin);
				printf("\tMember IC   : %-18s\n", modi[i].memberIC);
				printf("\tMember PhNum: %-12s\n", modi[i].memberPh);
				printf("\tMember Email: %-50s\n\n", modi[i].memberEmail);
				printf(" 1. Edit member ID\n");
				printf(" 2. Edit name\n");
				printf(" 3. Edit gender\n");
				printf(" 4. Edit state\n");
				printf(" 5. Edit year join\n");
				printf(" 6. Edit IC\n");
				printf(" 7. Edit phone number\n");
				printf(" 8. Edit email\n");
				printf(" 9. Edit all \n");
				printf("\nEnter your choice [1 to 9 only] : ");
				rewind(stdin);
				scanf("%d", &choice);
				if (choice < 1 || choice > 9) {
					printf("Invalid choice. Please enter the valid number [ 1-8 ] :");
					rewind(stdin);
					scanf("%d", &choice);
				}
				if (choice != 10) {
					if (choice == 1) {
						printf("Enter the new ID number [eg. www**]: ");
						rewind(stdin);
						scanf("%s", &info.modify.newModiID);
						for (int i = 0; i < mCount; i++)
						{
							while (strcmp(modi[i].memberID, info.modify.newModiID) == 0 || info.modify.newModiID[0] != 'w' || info.modify.newModiID[1] != 'w' || info.modify.newModiID[2] != 'w')
							{
								if (strcmp(modi[i].memberID, info.modify.newModiID) == 0) {

									printf("Member ID available, can't repeat. Please enter again: ");
									rewind(stdin);
									scanf("%s", &info.modify.newModiID);
									i = 0;
								}

								else if (info.modify.newModiID[0] != 'w' || info.modify.newModiID[1] != 'w' || info.modify.newModiID[2] != 'w') {
									printf("Incorrect member format.\n");
									printf("Please enter the member ID again [eg. www**]: ");
									rewind(stdin);
									scanf("%s", &info.modify.newModiID);
								}
							}
						}
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							strcpy(modi[i].memberID, info.modify.newModiID);
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 2) {
						printf("Enter the new Name: ");
						rewind(stdin);
						gets(info.modify.newModiName);
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							strcpy(modi[i].memberName, info.modify.newModiName);
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 3) {
						printf("Enter the new Gender [ F=female / M=male ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.newModiGender);
						while (toupper(info.modify.newModiGender) != 'F' && toupper(info.modify.newModiGender) != 'M') {
							printf("Invalid gender choice.\n");
							printf("Please enter your choice again [ F=female / M=male ]: ");
							scanf("%c", &info.modify.newModiGender);
						}
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							modi[i].gender = info.modify.newModiGender;
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 4) {
						printf("Enter the new State: ");
						rewind(stdin);
						gets(info.modify.confirm);
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						gets(info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							gets(info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							strcpy(modi[i].memberName, info.modify.confirm);
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 5) {
						printf("Enter the new year join: ");
						rewind(stdin);
						scanf("%d", &info.modify.newModiYear);
						while (info.modify.newModiYear < 1922 || info.modify.newModiYear > 2022) {
							printf("Invalid year.\n");
							printf("Please enter the year again [Only can enter year 1922 - 2022]: ");
							scanf("%d", &info.modify.newModiYear);
						}
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							modi[i].yearJoin = info.modify.newModiYear;
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 6) {
						printf("Enter the new IC number [eg. 010203-14-8900]: ");
						rewind(stdin);
						scanf("%s", &info.modify.newModiIC);
						while (info.modify.newModiIC[6] != '-' && info.modify.newModiIC[9] != " ")
						{
							printf("Incorrect IC format\n");
							printf("Please enter the new member IC again [eg. 010203-14-8900]:");
							rewind(stdin);
							scanf("%s", &info.modify.newModiIC);
						}
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							strcpy(modi[i].memberIC, info.modify.newModiIC);
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 7) {
						printf("Enter the new Contact number [eg. 011-234567]: ");
						rewind(stdin);
						scanf("%s", &info.modify.newModiPh);
						while (info.modify.newModiPh[3] != '-')
						{
							printf("Incorrect Contact Number format\n");
							printf("Please enter the contact number again [eg. 011-234567]:");
							rewind(stdin);
							scanf("%s", &info.modify.newModiPh);
						}
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							strcpy(modi[i].memberPh, info.modify.newModiPh);
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 8) {
						printf("Enter new Email: ");
						rewind(stdin);
						gets(info.modify.newEmail);
						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							strcpy(modi[i].memberEmail, info.modify.newEmail);
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
					else if (choice == 9) {
						printf("Enter the new ID number [eg. www**]: ");
						rewind(stdin);
						gets(info.modify.newModiID);
						while (info.modify.newModiID[0] != 'w' || info.modify.newModiID[1] != 'w' || info.modify.newModiID[2] != 'w') {
							printf("Incorrect member format.\n");
							printf("Please enter the new member ID again [eg. www**]: ");
							gets(info.modify.newModiID);
						}

						printf("Enter the new Name: ");
						rewind(stdin);
						gets(info.modify.newModiName);

						printf("Enter the new Gender [ F=female / M=male ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.newModiGender);
						while (toupper(info.modify.newModiGender) != 'F' && toupper(info.modify.newModiGender) != 'M') {
							printf("Invalid gender choice.\n");
							printf("Please enter your choice again [ F=female / M=male ]: ");
							scanf("%c", &info.modify.newModiGender);
						}

						printf("Enter the new State: ");
						rewind(stdin);
						gets(info.modify.confirm);

						printf("Enter the new year join: ");
						rewind(stdin);
						scanf("%d", &info.modify.newModiYear);
						while (info.modify.newModiYear < 1922 || info.modify.newModiYear > 2022) {
							printf("Invalid year.\n");
							printf("Please enter the year again: ");
							scanf("%d", &info.modify.newModiYear);
						}

						printf("Enter the new IC number [eg. 010203-14-8900]: ");
						rewind(stdin);
						scanf("%s", &info.modify.newModiIC);
						while (info.modify.newModiIC[6] != '-' && info.modify.newModiIC[9] != '-')
						{
							printf("Incorrect IC format\n");
							printf("Please enter the new member IC again [eg. 010203-14-8900]: ");
							rewind(stdin);
							scanf("%s", &info.modify.newModiIC);
						}

						printf("Enter the new Contact number [eg. 011-234567]: ");
						rewind(stdin);
						scanf("%s", &info.modify.newModiPh);
						while (info.modify.newModiPh[3] != '-')
						{
							printf("Incorrect Contact Number format\n");
							printf("Please enter the contact number again [eg. 011-234567]:");
							rewind(stdin);
							scanf("%s", &info.modify.newModiPh);
						}

						printf("Enter new Email: ");
						rewind(stdin);
						gets(info.modify.newEmail);

						printf("Data will be change, are you sure to overwrite? [ Y=yes / N=no ]: ");
						rewind(stdin);
						scanf("%c", &info.modify.confirm);
						while (toupper(info.modify.confirm) != 'Y' && toupper(info.modify.confirm) != 'N') {
							printf("Invalid choice please enter again [ Y=yes / N=no ]: ");
							rewind(stdin);
							scanf("%c", &info.modify.confirm);
						}
						if (toupper(info.modify.confirm) == 'Y') {
							strcpy(modi[i].memberID, info.modify.newModiID);
							strcpy(modi[i].memberName, info.modify.newModiName);
							modi[i].gender = info.modify.newModiGender;
							strcpy(modi[i].state, info.modify.confirm);
							modi[i].yearJoin = info.modify.newModiYear;
							strcpy(modi[i].memberIC, info.modify.newModiIC);
							strcpy(modi[i].memberPh, info.modify.newModiPh);
							strcpy(modi[i].memberEmail, info.modify.newEmail);
							printf("-------------------------------------------------------------------------------MODIFIED---------------------------------------------------------------------------\n");
							printf("\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
							printf("\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
							printf("\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n\n", modi[i].memberID, modi[i].memberName, modi[i].gender, "", modi[i].state, modi[i].yearJoin, "", modi[i].memberIC, modi[i].memberPh, "", modi[i].memberEmail);
						}
					}
				}
			}
		}
		if (checkAvai == 0) {
			printf("No record found please try again \n");
		}
		printf("Do you want to continue modified member data [ Y=yes / N=no ]: ");
		rewind(stdin);
		scanf("%c", &confirm2);
		while (toupper(confirm2) != 'N' && toupper(confirm2) != 'Y') {
			printf("Invalid input. Please try again [ Y=yes / N=no ]: ");
			rewind(stdin);
			scanf("%c", &confirm2);
			printf("\n\n");
		}
	} while (toupper(confirm2) != 'N');
	printf("Going back to the member selection menu\n");


	FILE* newmodimember = fopen("addmember.dat", "wb");
	if (newmodimember == NULL)
	{
		printf("Error cannot find the file \n");
		exit(-7);
	}
	for (int i = 0; i < mCount; i++)
	{
		fwrite(&modi[i], sizeof(Member), 1, newmodimember);
	}
	fclose(newmodimember);
	system("cls");
}

void deleteMember() {
	Member info;
	Member delete[MAX_RECORDS];
	int memberDlt = 0;
	int member = 0;
	char dltName[25], choose;
	char sureAnot;

	FILE* fptr6 = fopen("addmember.dat", "rb");


	if (fptr6 == NULL) {
		printf("Error cannot find the file \n");
		exit(-8);
	}

	while (fread(&delete[memberDlt], sizeof(Member), 1, fptr6) != 0) {
		memberDlt++;
	}
	fclose(fptr6);

	do
	{
		printf("\n\t\t\t\t\t\t\t\t Delete Member In KARSHINXIN CLUB\n");
		printf("\t\t\t\t\t\t\t\t  Member Name That Are Available\n");
		printf("\t\t\t\t\t\t\t\t ==================================\n");
		for (int num = 0; num < memberDlt; num++) {
			printf("\t\t\t\t\t\t\t\t\t\t%-15s\n", delete[num].memberName);

		}

		int got = -1;
		printf("Enter member's name that you would want to delete: ");
		rewind(stdin);
		gets(dltName);

		for (int num = 0; num < memberDlt; num++) {
			if (strcmp(delete[num].memberName, dltName) == 0) {
				printf("\tThe record found: \n");
				printf("-----------------------------------\n");
				printf("\tMember ID    : %-13s\n", delete[num].memberID);
				printf("\tMember Name  : %-15s\n", delete[num].memberName);
				printf("\tGender       : %-3c\n", delete[num].gender);
				printf("\tYear Join    : %-4d\n", delete[num].yearJoin);
				printf("\tMember IC    : %-18s\n", delete[num].memberIC);
				printf("\tMember PhNum : %-12s\n", delete[num].memberPh);
				printf("\tMember Email : %-50s\n\n", delete[num].memberEmail);
				got = num;
				printf("\tAre you sure you want to delete? (Y=yes / N=no): ");
				rewind(stdin);
				scanf("\t%c", &sureAnot);
				while (toupper(sureAnot) != 'N' && toupper(sureAnot) != 'Y') {
					printf("Re-enter again >");
					rewind(stdin);
					scanf("\t%c", &sureAnot);
				}
				if (toupper(sureAnot) == 'Y') {
					memberDlt--;
					printf("Deleting...\n");
					printf("SUCCESSFULL. \n\n");

					for (num = 0; num < memberDlt; num++) {
						if (num >= got)
							delete[num] = delete[num + 1];
					}
				}
			}
		}
		if (got == -1) {
			printf("Unavailable member record.\n");
		}
		printf("Do you want to continue delete member data [Y=yes / N=no]: ");
		rewind(stdin);
		scanf("%c", &choose);
		printf("\n\n");
		while (toupper(choose) != 'N' && toupper(choose) != 'Y') {
			printf("Invalid input. Please try again [ Y=yes / N=no ]: ");
			rewind(stdin);
			scanf("\t%c", &choose);
		}
	} while (toupper(choose) == 'Y');


	FILE* fptr7 = fopen("addmember.dat", "wb");
	if (fptr7 == NULL) {
		printf("Error, can't open this file\n");
		exit(-8);
	}
	for (int num = 0; num < memberDlt; num++) {
		fwrite(&delete[num], sizeof(Member), 1, fptr7);
	}
	fclose(fptr7);
	system("cls");
}

void reportMember() {
	Member info;
	Member report[MAX_RECORDS];
	int num = 0;
	int year;
	char choose;

	FILE* fptr8 = fopen("addmember.dat", "rb");

	if (fptr8 == NULL) {
		printf("Error, can't open this file\n");
		exit(-9);
	}
	while (fread(&report[num], sizeof(Member), 1, fptr8) != 0) {
		num++;
	}

	printf("\t\t\t"); dash(150);
	printf("\t\t\t\t\t\t\t\t\t   FINAL REPORT FOR KARSHINXIN CLUB'S MEMBER \n");
	printf("\t\t\t"); dash(150);
	do {
		int ppl = 0;
		int check = 0;
		printf("\t\t\t\t\t\t\t\t\t  Enter summary report for which year: ");
		rewind(stdin);
		scanf("%d", &year);
		while (year < 1922 || year > 2022) {
			printf("Invalid year. Please enter again: ");
			scanf("%d", &year);
		}
		printf("\n\t\t\t\t\t\t\t\t\tBelow are the summary report for the year %d\n", year);
		printf("\t\t\t"); singledash(150);
		printf("\t\t\t\tMember ID    Member Name     Gender          State                Year Join          IC.Num             Phone.Num              Email\n");
		printf("\t\t\t\t=========    ===========     ======         =======               =========          ======             =========             ========\n");
		for (int r = 0; r < num; r++) {
			check++;
			if (report[r].yearJoin == year) {
				printf("\t\t\t\t%-15s %-15s %-6c %5s %-20s   %-4d %8s %-20s %-12s %5s %-40s\n", report[r].memberID, report[r].memberName, report[r].gender, "", report[r].state, report[r].yearJoin, "", report[r].memberIC, report[r].memberPh, "", report[r].memberEmail);
				ppl++;
			}
		}
		printf("\t\t\t\t\t\t\t\t\t# The total member record for the year %d is %d\n", year, ppl);
		printf("\t\t\t\t\t\t\t\t\t# The total member record for KAISHINXIN Club is %d\n", num);
		if (check == 0) {
			printf("\n\t\t\t\t\t\t\t\t\t[ NO SUMMARY REPORT FOR THE PARTICULAR YEAR! ]\n");
		}
		printf("\t\t\t"); singledash(150);
		printf("\t\t\t"); dash(150);
		printf("\t\t\t\t\t  lt Do you still want to view another year of KARSHINXIN's final report? [Y-Yes, N-No] :");
		rewind(stdin);
		scanf("%c", &choose);
		while (toupper(choose) != 'N' && toupper(choose) != 'Y') {
			printf("\t\t\t\t\tIncorrect choice. Please enter your choice again [Y-Yes, N-No]: ");
			rewind(stdin);
			scanf("%c", &choose);
		}
		printf("\n\n");
	} while (toupper(choose) != 'N');
	fclose(fptr8);
	system("pause");
	system("cls");
}

void dash(int parameter) {

	for (int i = 0; i < parameter; i++)
		printf("=");
	printf("\n");
}

void singledash(int parameter) {

	for (int i = 0; i < parameter; i++)
		printf("-");
	printf("\n");
}


//Facility void function
void addfacility();
void searchFacility();
void modifyFacility();
void displayFacility();
void deleteFacility();
void reportFacility();

//Facility Module
void facilityMenu() {
	int option;
	do {
		printf("\n\n");

		printf("%8s" "  _____          _ _ _ _           __  __           _       _      \n", " ");
		printf("%8s" " |  ___|_ _  ___(_) (_) |_ _   _  |  \\/  | ___   __| |_   _| | ___ \n", " ");
		printf("%8s" " | |_ / _` |/ __| | | | __| | | | | |\\/| |/ _ \\ / _` | | | | |/ _ \\\n", " ");
		printf("%8s" " |  _| (_| | (__| | | | |_| |_| | | |  | | (_) | (_| | |_| | |  __/\n", " ");
		printf("%8s" " |_|  \\__,_|\\___|_|_|_|\\__|\\__, | |_|  |_|\\___/ \\__,_|\\__,_|_|\\___|\n", " ");
		printf("%8s" "                           |___/                                   \n", " ");
		printf("%8s", "");
		dashf(65);
		printf("\n");
		printf("%8s|%24s1. Add Facility%24s|\n", "", "", "");
		printf("%8s|%24s2. Search Facility%21s|\n", "", "", "");
		printf("%8s|%24s3. Modify Facility%21s|\n", "", "", "");
		printf("%8s|%24s4. Display Facility%20s|\n", "", "", "");
		printf("%8s|%24s5. Delete Facility%21s|\n", "", "", "");
		printf("%8s|%24s6. Report%30s|\n", "", "", "");
		printf("%8s|%24s7. Exit%32s|\n", "", "", "");
		printf("%8s", "");
		dashf(65);
		printf("\n");

		printf("%8sEnter your option >", "");
		scanf("%d", &option);
		while (option < 1 || option > 7) {
			printf("\n\n\tInvalid choice. Please enter number (1-7) > ");
			rewind(stdin);
			scanf("%d", &option);
		}
		switch (option)
		{
		case 1:cls(); addfacility(); break;
		case 2:cls(); searchFacility(); break;
		case 3:cls(); modifyFacility(); break;
		case 4:cls(); displayFacility(); break;
		case 5:cls(); deleteFacility(); break;
		case 6:cls(); reportFacility(); break;
		case 7:printf("\n\tTHANK YOU, HAVE A NICE DAY!!\n\n"); system("pause"); cls();
			break;
		default:printf("%8sInvalid choice, Try again!\n\n", "");
		}

	} while (option != 7);
}

void addfacility() {
	Facility facility;
	Facility checkid[20];
	char addadd, confirm;
	int f = 0;
	FILE* addfacility, * addfacility2;
	addfacility = fopen("facilityinfor.txt", "a");
	addfacility2 = fopen("facilityinfor.txt", "r");
	if (addfacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}
	if (addfacility2 == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}
	while (fscanf(addfacility2, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &checkid[f].facilityId, &checkid[f].types, &checkid[f].description, &checkid[f].venue, &checkid[f].maxallow, &checkid[f].opentime.hours, &checkid[f].opentime.minutes, &checkid[f].closetime.hours, &checkid[f].closetime.minutes, &checkid[f].charges) != -1) {
		f++;

	}
	fclose(addfacility2);

	do {
		printf("\n\n%8s1. Add Facility\n", "");
		printf("%8s--------------------------------\n", "");
		printf("%8sEnter Facility ID >", "");
		rewind(stdin);
		scanf("%[^\n]", &facility.facilityId);


		for (int i = 0; i < f; i++)
		{
			while ((strcmp(facility.facilityId, checkid[i].facilityId) == 0) || (facility.facilityId[0] == '0' ||
				facility.facilityId[0] == '1' || facility.facilityId[0] == '2' || facility.facilityId[0] == '3' || facility.facilityId[0] == '4' || facility.facilityId[0] == '5' || facility.facilityId[0] == '6' || facility.facilityId[0] == '7' || facility.facilityId[0] == '8' || facility.facilityId[0] == '9') && (facility.facilityId[1] == '0' || facility.facilityId[1] == '1' || facility.facilityId[1] == '2' || facility.facilityId[1] == '3' || facility.facilityId[1] == '4' || facility.facilityId[1] == '5' || facility.facilityId[1] == '6' || facility.facilityId[1] == '7' || facility.facilityId[1] == '8' || facility.facilityId[1] == '9') || (facility.facilityId[2] != '0' && facility.facilityId[2] != '1' && facility.facilityId[2] != '2' && facility.facilityId[2] != '3' && facility.facilityId[2] != '4' && facility.facilityId[2] != '5' && facility.facilityId[2] != '6' && facility.facilityId[2] != '7' && facility.facilityId[2] != '8' && facility.facilityId[2] != '9') || (strlen(facility.facilityId) != 3))
			{
				if (strcmp(facility.facilityId, checkid[i].facilityId) == 0) {
					printf("\n");
					printf("%8s%s have been used. Please enter a new Facility ID >", "", checkid[i].facilityId);
					scanf("%s", &facility.facilityId);
					rewind(stdin);
					i = 0;
				}
				else if ((facility.facilityId[0] == '0') ||
					(facility.facilityId[0] == '0' ||
						facility.facilityId[0] == '1' || facility.facilityId[0] == '2' || facility.facilityId[0] == '3' || facility.facilityId[0] == '4' || facility.facilityId[0] == '5' || facility.facilityId[0] == '6' || facility.facilityId[0] == '7' || facility.facilityId[0] == '8' || facility.facilityId[0] == '9') && (facility.facilityId[1] == '0' || facility.facilityId[1] == '1' || facility.facilityId[1] == '2' || facility.facilityId[1] == '3' || facility.facilityId[1] == '4' || facility.facilityId[1] == '5' || facility.facilityId[1] == '6' || facility.facilityId[1] == '7' || facility.facilityId[1] == '8' || facility.facilityId[1] == '9') || (facility.facilityId[2] != '0' && facility.facilityId[2] != '1' && facility.facilityId[2] != '2' && facility.facilityId[2] != '3' && facility.facilityId[2] != '4' && facility.facilityId[2] != '5' && facility.facilityId[2] != '6' && facility.facilityId[2] != '7' && facility.facilityId[2] != '8' && facility.facilityId[2] != '9') || (strlen(facility.facilityId) != 3)) {
					printf("\n");
					printf("%8sInvalid Facility ID. Please enter correct Facility ID (Eg. SQ1) >", "", checkid[i].facilityId);
					scanf("%s", &facility.facilityId);
					rewind(stdin);
					i = 0;
				}

			}

		}
		printf("\n");
		printf("%8sEnter Facility types >", "");
		rewind(stdin);
		scanf("%[^\n]", &facility.types);
		printf("\n");
		printf("%8sEnter Facility description >", "");
		rewind(stdin);
		scanf("%[^\n]", &facility.description);
		printf("\n");
		printf("%8sEnter Facility's venue > ", "");
		rewind(stdin);
		scanf("%[^\n]", &facility.venue);
		printf("\n");
		do {
			printf("%8sMaximum amount of allowable users (1-4)>", "");
			rewind(stdin);
			scanf("%d", &facility.maxallow);
			if (facility.maxallow <= 0 || facility.maxallow > 4) {
				printf("%8sInvalid amount of users. Please type again.\n", "");
			}
		} while (facility.maxallow <= 0 || facility.maxallow > 4);
		printf("\n");

		do {
			printf("%8sVenue open time (24-hour system. Eg: 21 00)>", "");
			rewind(stdin);
			scanf("%d %d", &facility.opentime.hours, &facility.opentime.minutes);
			if (facility.opentime.hours < 0 || facility.opentime.hours>24 || facility.opentime.minutes < 0 || facility.opentime.minutes>59) {
				printf("%8sInvalid open time. Please type again.\n", "");
			}

		} while (facility.opentime.hours < 0 || facility.opentime.hours>24 || facility.opentime.minutes < 0 || facility.opentime.minutes>59);
		printf("\n");
		do {
			printf("%8sVenue close time (24-hour system. Eg: 21 00)> ", "");
			rewind(stdin);
			scanf("%d %d", &facility.closetime.hours, &facility.closetime.minutes);
			if (facility.closetime.hours < 0 || facility.closetime.hours>24 || facility.closetime.minutes < 0 || facility.closetime.minutes>59) {
				printf("%8sInvalid close time. Please type again.\n", "");
			}
		} while (facility.closetime.hours < 0 || facility.closetime.hours>24 || facility.closetime.minutes < 0 || facility.closetime.minutes>59);
		printf("\n");
		do {
			printf("%8sFees charged per hour > RM ", "");
			rewind(stdin);
			scanf("%f", &facility.charges);
			if (facility.charges <= 0) {
				printf("%8sIncvalid fees charged. Please type again.\n", "");
			}
		} while (facility.charges <= 0);
		printf("\n");
		printf("%8sDO YOU SURE TO ADD THIS FACILITY? (Y/N) > ", "");
		rewind(stdin);
		scanf("%c", &confirm);

		if (confirm == 'Y') {
			fprintf(addfacility, "%s|%s|%s|%s|%d|%.2d %.2d|%.2d %.2d|%.2f\n", facility.facilityId, facility.types, facility.description, facility.venue, facility.maxallow, facility.opentime.hours, facility.opentime.minutes, facility.closetime.hours, facility.closetime.minutes, facility.charges);
			printf("%8sAdd Facility Successfully.\n", "");
			fclose(addfacility);
		}
		else if (confirm == 'N') {
			printf("%8sAdd Facility failed.\n", "");
		}
		else {
			printf("%8sInvalid option. Please type again.\n", "");
		}

		do {
			printf("%8sContinue to add facility? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &addadd);
			if (toupper(addadd) != 'Y' && toupper(addadd) != 'N') {
				printf("%8sInvalid option. Please type again.\n", "");
			}
		} while (toupper(addadd) != 'Y' && toupper(addadd) != 'N');

	} while (toupper(addadd) == 'Y');
	fclose(addfacility);


	cls();
}

void searchFacility() {
	Facility facilitysearch[20];
	char searchtype[10];
	char addadd;
	int f = 0;
	FILE* searchFacility;
	searchFacility = fopen("facilityinfor.txt", "r");
	if (searchFacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}

	printf("\n");
	printf("%8s2.Search Facility\n", "");
	printf("%8s", "");
	dashf(55);
	printf("\n");

	while (fscanf(searchFacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &facilitysearch[f].facilityId, &facilitysearch[f].types, &facilitysearch[f].description, &facilitysearch[f].venue, &facilitysearch[f].maxallow, &facilitysearch[f].opentime.hours, &facilitysearch[f].opentime.minutes, &facilitysearch[f].closetime.hours, &facilitysearch[f].closetime.minutes, &facilitysearch[f].charges) != -1) {

		f++;
	}
	do {
		printf("\n");
		printf("%-8s", "");
		equalf(33);
		printf("\n");
		printf("%-8s|%-11sFacility ID%-9s|\n", "", "", "");
		printf("%-8s", "");
		vbar(1);
		dashf(31);
		vbar(1);
		printf("\n");
		for (int p = 0; p < f; p++) {
			printf("%-8s|%18s%-13s|\n", "", facilitysearch[p].facilityId, "");

		}
		printf("%-8s", "");
		equalf(33);
		printf("\n");


		int found = 0;
		printf("\n");
		printf("%8sSearch by Facility ID > ", "");
		rewind(stdin);
		scanf("%[^\n]", &searchtype);
		printf("\n\n");
		for (int i = 0; i < f; i++) {
			if (strcmp(searchtype, facilitysearch[i].facilityId) == 0) {
				printf("%24sFacility Information\n", "");
				printf("%8s", "");
				equalf(65);
				printf("\n");
				printf("%24sFacility ID%-13s: %s%-40s\n", "", "", facilitysearch[i].facilityId, "");
				printf("%24sFacility type%-11s: %s%-32s\n", "", "", facilitysearch[i].types, "");
				printf("%24sFacility Description%-4s: %s%-32s\n", "", "", facilitysearch[i].description, "");
				printf("%24sVenue%-19s: %s%-32s\n", "", "", facilitysearch[i].venue, "");
				printf("%24sMaximum Allowable Users	: %d%-28s\n", "", facilitysearch[i].maxallow, "");
				printf("%24sVenue Open Time%-9s: %.2d %.2d%-31s\n", "", "", facilitysearch[i].opentime.hours, facilitysearch[i].opentime.minutes, "");
				printf("%24sVenue Close Time%-8s: %.2d %.2d%-30s\n", "", "", facilitysearch[i].closetime.hours, facilitysearch[i].closetime.minutes, "");
				printf("%24sFees charged per hour%-3s: RM %.2f\n", "", "", facilitysearch[i].charges);
				printf("%8s", "");
				equalf(65);
				printf("\n");
				found++;
			}
		}
		if (found == 0) {
			printf("\n");
			printf("%8sNo Record Found.\n\n", "");
		}
		do {
			printf("\n");
			printf("%8sContinue to search facility? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &addadd);
			cls();
			if (toupper(addadd) != 'Y' && toupper(addadd) != 'N') {
				printf("\n");
				printf("%8sInvalid option. Please type again.\n", "");
			}
		} while (toupper(addadd) != 'Y' && toupper(addadd) != 'N');

	} while (toupper(addadd) == 'Y');
	fclose(searchFacility);
	cls();
}

void modifyFacility() {
	Facility facilitymodify[20];
	Facility newfacility;
	Facility checkid[20];

	char addadd, modifyID[4];
	int f = 0, found = 0;
	FILE* modifyfacility;
	modifyfacility = fopen("facilityinfor.txt", "r");
	if (modifyfacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}

	printf("\n");
	printf("%-8s 3. Modify Facility\n", "");
	printf("%-8s", "");
	dashf(55);
	printf("\n");
	while (fscanf(modifyfacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &facilitymodify[f].facilityId, &facilitymodify[f].types, &facilitymodify[f].description, &facilitymodify[f].venue, &facilitymodify[f].maxallow, &facilitymodify[f].opentime.hours, &facilitymodify[f].opentime.minutes, &facilitymodify[f].closetime.hours, &facilitymodify[f].closetime.minutes, &facilitymodify[f].charges) != -1) {

		f++;
	}
	fclose(modifyfacility);
	do {
		printf("%-8s", "");
		equalf(33);
		printf("\n");
		printf("%-8s|%-11sFacility ID%-9s|\n", "", "", "");
		printf("%-8s", "");
		vbar(1);
		dashf(31);
		vbar(1);
		printf("\n");
		for (int p = 0; p < f; p++) {
			printf("%-8s|%18s%-13s|\n", "", facilitymodify[p].facilityId, "");

		}
		printf("%-8s", "");
		equalf(33);
		printf("\n");
		printf("\n");
		printf("%-8sChoose the Facility ID that want to modify >", "");
		rewind(stdin);
		scanf("%[^\n]", &modifyID);
		for (int i = 0; i < f; i++) {
			if (strcmp(modifyID, facilitymodify[i].facilityId) == 0) {
				printf("\n");
				printf("%-8sEnter new Facility ID >", "");
				rewind(stdin);
				scanf("%[^\n]", &newfacility.facilityId);

				for (int i = 0; i < f; i++)
				{
					while (strcmp(newfacility.facilityId, checkid[i].facilityId) == 0 || newfacility.facilityId[0] == '0' ||
						newfacility.facilityId[0] == '1' || newfacility.facilityId[0] == '2' || newfacility.facilityId[0] == '3' || newfacility.facilityId[0] == '4' || newfacility.facilityId[0] == '5' || newfacility.facilityId[0] == '6' || newfacility.facilityId[0] == '7' || newfacility.facilityId[0] == '8' || newfacility.facilityId[0] == '9' && newfacility.facilityId[1] == '0' || newfacility.facilityId[1] == '1' || newfacility.facilityId[1] == '2' || newfacility.facilityId[1] == '3' || newfacility.facilityId[1] == '4' || newfacility.facilityId[1] == '5' || newfacility.facilityId[1] == '6' || newfacility.facilityId[1] == '7' || newfacility.facilityId[1] == '8' || newfacility.facilityId[1] == '9' || newfacility.facilityId[2] != '0' && newfacility.facilityId[2] != '1' && newfacility.facilityId[2] != '2' && newfacility.facilityId[2] != '3' && newfacility.facilityId[2] != '4' && newfacility.facilityId[2] != '5' && newfacility.facilityId[2] != '6' && newfacility.facilityId[2] != '7' && newfacility.facilityId[2] != '8' && newfacility.facilityId[2] != '9' || strlen(newfacility.facilityId) != 3)
					{
						if (strcmp(newfacility.facilityId, checkid[i].facilityId) == 0) {
							printf("\n");
							printf("%8s%s have been used. Please enter a new Facility ID >", "", checkid[i].facilityId);
							scanf("%s", &newfacility.facilityId);
							rewind(stdin);
							i = 0;
						}
						else if (newfacility.facilityId[0] == '0' ||
							newfacility.facilityId[0] == '1' || newfacility.facilityId[0] == '2' || newfacility.facilityId[0] == '3' || newfacility.facilityId[0] == '4' || newfacility.facilityId[0] == '5' || newfacility.facilityId[0] == '6' || newfacility.facilityId[0] == '7' || newfacility.facilityId[0] == '8' || newfacility.facilityId[0] == '9' && newfacility.facilityId[1] == '0' || newfacility.facilityId[1] == '1' || newfacility.facilityId[1] == '2' || newfacility.facilityId[1] == '3' || newfacility.facilityId[1] == '4' || newfacility.facilityId[1] == '5' || newfacility.facilityId[1] == '6' || newfacility.facilityId[1] == '7' || newfacility.facilityId[1] == '8' || newfacility.facilityId[1] == '9' || newfacility.facilityId[2] != '0' && newfacility.facilityId[2] != '1' && newfacility.facilityId[2] != '2' && newfacility.facilityId[2] != '3' && newfacility.facilityId[2] != '4' && newfacility.facilityId[2] != '5' && newfacility.facilityId[2] != '6' && newfacility.facilityId[2] != '7' && newfacility.facilityId[2] != '8' && newfacility.facilityId[2] != '9' || strlen(newfacility.facilityId) != 3) {
							printf("\n");
							printf("%8sInvalid Facility ID. Please enter correct Facility ID (Eg. SQ1) >", "", checkid[i].facilityId);
							scanf("%s", &newfacility.facilityId);
							rewind(stdin);
							i = 0;
						}

					}

				}
				printf("\n");
				printf("%-8sEnter the types >", "");
				rewind(stdin);
				scanf("%[^\n]", &newfacility.types);
				printf("\n");
				printf("%-8sEnter the description >", "");
				rewind(stdin);
				scanf("%[^\n]", &newfacility.description);
				printf("\n");
				printf("%-8sEnter the venue >", "");
				rewind(stdin);
				scanf("%[^\n]", &newfacility.venue);
				printf("\n");
				do {
					printf("%8sMaximum amount of allowable users (1-4)>", "");
					rewind(stdin);
					scanf("%d", &newfacility.maxallow);
					if (newfacility.maxallow <= 0 || newfacility.maxallow > 4) {
						printf("%8sInvalid amount of users. Please type again.\n", "");
					}
				} while (newfacility.maxallow <= 0 || newfacility.maxallow > 4);
				printf("\n");
				do {
					printf("%8sVenue open time (24-hour system. Eg: 21 00)>", "");
					rewind(stdin);
					scanf("%d %d", &newfacility.opentime.hours, &newfacility.opentime.minutes);
					if (newfacility.opentime.hours < 0 || newfacility.opentime.hours>24 || newfacility.opentime.minutes < 0 || newfacility.opentime.minutes>59) {
						printf("%8sInvalid open time. Please type again.\n", "");
					}

				} while (newfacility.opentime.hours < 0 || newfacility.opentime.hours>24 || newfacility.opentime.minutes < 0 || newfacility.opentime.minutes>59);
				printf("\n");
				do {
					printf("%8sVenue close time (24-hour system. Eg: 21 00)> ", "");
					rewind(stdin);
					scanf("%d %d", &newfacility.closetime.hours, &newfacility.closetime.minutes);
					if (newfacility.closetime.hours < 0 || newfacility.closetime.hours>24 || newfacility.closetime.minutes < 0 || newfacility.closetime.minutes>59) {
						printf("%8sInvalid close time. Please type again.\n", "");
					}
				} while (newfacility.closetime.hours < 0 || newfacility.closetime.hours>24 || newfacility.closetime.minutes < 0 || newfacility.closetime.minutes>59);
				printf("\n");
				do {
					printf("%8sFees charged per hour > RM ", "");
					rewind(stdin);
					scanf("%f", &newfacility.charges);
					if (newfacility.charges <= 0) {
						printf("%8sIncvalid fees charged. Please type again.\n", "");
					}
				} while (newfacility.charges <= 0);
				printf("\n");
				strcpy(facilitymodify[i].facilityId, newfacility.facilityId);
				strcpy(facilitymodify[i].types, newfacility.types);
				strcpy(facilitymodify[i].description, newfacility.description);
				strcpy(facilitymodify[i].venue, newfacility.venue);
				facilitymodify[i].maxallow = newfacility.maxallow;
				facilitymodify[i].opentime.hours = newfacility.opentime.hours;
				facilitymodify[i].opentime.minutes = newfacility.opentime.minutes;
				facilitymodify[i].closetime.hours = newfacility.closetime.hours;
				facilitymodify[i].closetime.minutes = newfacility.closetime.minutes;
				facilitymodify[i].charges = newfacility.charges;
				found++;
			}
		}
		if (found == 1) {
			printf("%-8sModify Successfully.\n", "");
		}
		if (found == 0) {
			printf("%-8sModify Failed.\n", "");
		}
		do {
			printf("\n");
			printf("%-8sContinue to modify facility? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &addadd);
			cls();
			if (toupper(addadd) != 'Y' && toupper(addadd) != 'N') {
				printf("%-8sInvalid option. Please type again.\n", "");
			}
		} while (toupper(addadd) != 'Y' && toupper(addadd) != 'N');
	} while (toupper(addadd) == 'Y');
	FILE* writemodify;
	writemodify = fopen("facilityinfor.txt", "w");
	if (writemodify == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}
	for (int i = 0; i < f; i++) {
		fprintf(writemodify, "%s|%s|%s|%s|%d|%.2d %.2d|%.2d %.2d|%.2f\n", facilitymodify[i].facilityId, facilitymodify[i].types, facilitymodify[i].description, facilitymodify[i].venue, facilitymodify[i].maxallow, facilitymodify[i].opentime.hours, facilitymodify[i].opentime.minutes, facilitymodify[i].closetime.hours, facilitymodify[i].closetime.minutes, facilitymodify[i].charges);
	}
	fclose(writemodify);
	cls();
}

void displayFacility() {
	Facility facilitydisplay[20];
	char addadd;
	int f = 0;
	FILE* displayfacility;
	displayfacility = fopen("facilityinfor.txt", "r");
	if (displayfacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}
	printf("\n\n");
	printf("%-8s4.Display Facility\n", "");
	printf("%-5s", "");
	dashf(55);
	printf("\n");
	printf(" ");
	equalf(119);
	printf("\n");
	printf(" | Facility ID |%3sTypes%-9s|%2sDescription%-6s|%2sVenue%-10s| Maximum user | Open Time | Close Time | Fees  |\n", "", "", "", "", "", "");
	while (fscanf(displayfacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &facilitydisplay[f].facilityId, &facilitydisplay[f].types, &facilitydisplay[f].description, &facilitydisplay[f].venue, &facilitydisplay[f].maxallow, &facilitydisplay[f].opentime.hours, &facilitydisplay[f].opentime.minutes, &facilitydisplay[f].closetime.hours, &facilitydisplay[f].closetime.minutes, &facilitydisplay[f].charges) != -1) {
		displaydash(1);

		printf(" |%8s%-5s|%3s%-14s|%2s%-17s|%2s%-15s|%7s%-7d|%3s%.2d %.2d%3s|%3s%.2d %.2d%4s| %-5.2f |", facilitydisplay[f].facilityId, "", "", facilitydisplay[f].types, "", facilitydisplay[f].description, "", facilitydisplay[f].venue, "", facilitydisplay[f].maxallow, "", facilitydisplay[f].opentime.hours, facilitydisplay[f].opentime.minutes, "", "", facilitydisplay[f].closetime.hours, facilitydisplay[f].closetime.minutes, "", facilitydisplay[f].charges);
		printf("\n");
		f++;
	}
	printf(" ");
	equalf(119);
	printf("\n");
	printf("%47s>> Total %d records <<\n\n", "", f);
	fclose(displayfacility);
	system("pause");
	cls();
}

void deleteFacility() {
	Facility facilitydelete[20];
	char defacilityId[4];
	char addadd, confirm;
	int f = 0, d = 0;
	FILE* deletefacility;
	deletefacility = fopen("facilityinfor.txt", "r");
	if (deletefacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}

	printf("\n\n");
	printf("%8s5.Delete Facility\n", "");
	printf("%8s", "");
	dashf(55);
	printf("\n\n");

	while (fscanf(deletefacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &facilitydelete[f].facilityId, &facilitydelete[f].types, &facilitydelete[f].description, &facilitydelete[f].venue, &facilitydelete[f].maxallow, &facilitydelete[f].opentime.hours, &facilitydelete[f].opentime.minutes, &facilitydelete[f].closetime.hours, &facilitydelete[f].closetime.minutes, &facilitydelete[f].charges) != -1) {

		f++;
	}
	fclose(deletefacility);

	do {
		printf("\n");
		printf("%-8s", "");
		equalf(33);
		printf("\n");
		printf("%-8s|%-11sFacility ID%-9s|\n", "", "", "");
		printf("%-8s", "");
		vbar(1);
		dashf(31);
		vbar(1);
		printf("\n");
		for (int p = 0; p < f; p++) {
			printf("%-8s|%18s%-13s|\n", "", facilitydelete[p].facilityId, "");

		}
		printf("%-8s", "");
		equalf(33);
		printf("\n");
		printf("%8sChoose Facility ID to Delete >", "");
		rewind(stdin);
		scanf("%[^\n]", &defacilityId);
		int found = 0;
		for (int i = 0; i < f; i++) {
			if (strcmp(facilitydelete[i].facilityId, defacilityId) == 0) {
				do {
					printf("\n");
					printf("%24sFacility Information\n", "");
					printf("%8s", "");
					equalf(65);
					printf("\n");
					printf("%24sFacility ID%-13s: %s%-40s\n", "", "", facilitydelete[i].facilityId, "");
					printf("%24sFacility type%-11s: %s%-32s\n", "", "", facilitydelete[i].types, "");
					printf("%24sFacility Description%-4s: %s%-32s\n", "", "", facilitydelete[i].description, "");
					printf("%24sVenue%-19s: %s%-34s\n", "", "", facilitydelete[i].venue, "");
					printf("%24sMaximum Allowable Users	: %d%-28s\n", "", facilitydelete[i].maxallow, "");
					printf("%24sVenue Open Time%-9s: %.2d %.2d%-31s\n", "", "", facilitydelete[i].opentime.hours, facilitydelete[i].opentime.minutes, "");
					printf("%24sVenue Close Time%-8s: %.2d %.2d%-30s\n", "", "", facilitydelete[i].closetime.hours, facilitydelete[i].closetime.minutes, "");
					printf("%24sFees charged per hour%-3s: RM %.2f\n", "", "", facilitydelete[i].charges);
					printf("%8s", "");
					equalf(65);
					printf("\n");
					printf("\n");
					printf("%8sDO YOU SURE TO DELETE THIS FACILITY? (Y/N) >", "");
					rewind(stdin);
					scanf("%c", &confirm);
					if (toupper(confirm) != 'Y' && toupper(confirm) != 'N') {
						printf("%8sInvalid option. Please type again.\n", "");
					}
				} while (toupper(confirm) != 'Y' && toupper(confirm) != 'N');

				if (toupper(confirm) == 'Y') {
					//facilitydelete[i] = facilitydelete[i + 1];
					f--;//9
					found++;//1

					for (d = i; d < f; d++) {//d=0,0<9,d++
						facilitydelete[d] = facilitydelete[d + 1];
					}
				}
				else if (toupper(confirm) == 'N') {
					break;
				}
			}
		}
		if (found == 1) {
			printf("%8sDelete Successfully.\n", "");
		}
		if (found == 0) {
			printf("%8sDelete Failed.\n", "");
		}
		do {
			printf("%8sContinue to delete facility? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &addadd);
			cls();
			if (toupper(addadd) != 'Y' && toupper(addadd) != 'N') {
				printf("%8sInvalid option. Please type again.\n", "");
			}
		} while (toupper(addadd) != 'Y' && toupper(addadd) != 'N');
	} while (toupper(addadd) == 'Y');

	cls();
	FILE* dewriteFacility;
	dewriteFacility = fopen("facilityinfor.txt", "w");
	if (dewriteFacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}
	for (int i = 0; i < f; i++) {
		fprintf(dewriteFacility, "%s|%s|%s|%s|%d|%.2d %.2d|%.2d %.2d|%.2f\n", facilitydelete[i].facilityId, facilitydelete[i].types, facilitydelete[i].description, facilitydelete[i].venue, facilitydelete[i].maxallow, facilitydelete[i].opentime.hours, facilitydelete[i].opentime.minutes, facilitydelete[i].closetime.hours, facilitydelete[i].closetime.minutes, facilitydelete[i].charges);
	}
	fclose(dewriteFacility);

	cls();
}

void reportFacility() {
	Facility facilityreport[20];
	char addadd, view, view1, view2;
	int f = 0; int totalcharges = 0, option;
	int countuser = 0, countuser1 = 0, countuser2 = 0, countuser3 = 0;

	FILE* reportfacility;
	reportfacility = fopen("facilityinfor.txt", "r");
	if (reportfacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}
	printf("\n\n");
	printf("%8s6.Report\n", "");
	printf("%8s", "");
	dashf(55);
	printf("\n\n");
	while (fscanf(reportfacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &facilityreport[f].facilityId, &facilityreport[f].types, &facilityreport[f].description, &facilityreport[f].venue, &facilityreport[f].maxallow, &facilityreport[f].opentime.hours, &facilityreport[f].opentime.minutes, &facilityreport[f].closetime.hours, &facilityreport[f].closetime.minutes, &facilityreport[f].charges) != -1) {
		if (facilityreport[f].charges != 0) {
			totalcharges++;
		}
		if (facilityreport[f].maxallow == 4) {
			countuser++;
		}
		if (facilityreport[f].maxallow == 3) {
			countuser1++;
		}
		if (facilityreport[f].maxallow == 2) {
			countuser2++;
		}
		if (facilityreport[f].maxallow == 1) {
			countuser++;
		}
		f++;
	}
	do {
		printf("%8sCHOOSE THE REPORT YOU WANT TO VIEW.\n", "");
		printf("%8s", "");
		dashf(55);
		printf("\n");
		printf("%8s| 1. Total Facility%35s|\n", "", "");
		printf("%8s| 2. Total Facility That Charge Fees%18s|\n", "", "");
		printf("%8s| 3. All The Facility Maximum Allowable User%10s|\n", "", "");
		printf("%8s", "");
		dashf(55);
		printf("\n");
		printf("%8sChoose the report that want to view >", "");
		rewind(stdin);
		scanf("%d", &option);
		printf("\n");
		if (option == 1) {
			printf("%8s", "");
			equalf(70);
			printf("\n");
			printf("%8s| TOTAL FACILITY >>> %d %45s|\n", "", f, "");
			printf("%8s", "");
			equalf(70);
			printf("\n\n");
			printf("%8sDO YOU WANT TO VIEW ALL FACILITY ? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &view);
			if (toupper(view == 'Y')) {
				printf("\n%-8s", "");
				dashf(70);
				printf("\n");
				printf("%-8s|%-10sFacility ID%-8s|%-10sFacility Description%-8s|\n", "", "", "", "", "");
				printf("%-8s", "");
				vbar(1); dashf(29); vbar(1); dashf(38); vbar(1);
				printf("\n");
				for (int i = 0; i < f; i++) {
					printf("%-8s|%-13s %s%-12s|%12s%-17s%-9s|\n", "", "", facilityreport[i].facilityId, "", "", facilityreport[i].description, "");
					printf("%8s", "");
					vbar(1); dashf(29); vbar(1); dashf(38); vbar(1);
					printf("\n");
				}
			}
			printf("\n");
		}
		else if (option == 2) {
			printf("%8s", "");
			equalf(70);
			printf("\n");
			printf("%8s| TOTAL FACILITY THAT CHARGE FEES >>> %2d %28s|\n", "", totalcharges, "");
			printf("%8s", "");
			equalf(70);
			printf("\n");
			printf("%8sVIEW ALL THE FACILITY FEES CHARGED ? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &view1);
			if (toupper(view1 == 'Y')) {
				printf("\n%-8s", "");
				dashf(70);
				printf("\n");
				printf("%-8s|%-10sFacility ID%-8s|%-10sFees charged per hour%-7s|\n", "", "", "", "", "");
				printf("%-8s", "");
				vbar(1); dashf(29); vbar(1); dashf(38); vbar(1);
				printf("\n");
				for (int i = 0; i < f; i++) {
					printf("%-8s|%-13s %s%-12s|%16sRM %6.2f%-13s|\n", "", "", facilityreport[i].facilityId, "", "", facilityreport[i].charges, "");
					printf("%8s", "");
					dashf(70);
					printf("\n");
				}
			}
		}
		else if (option == 3) {
			printf("\n");
			printf("%8s", "");
			equalf(70);
			printf("\n");
			printf("%8s| TOTAL FACILITY MAXIMUM ALLOWABLE 4 USER >>> %d%22s|\n", "", countuser, "");
			printf("%8s| TOTAL FACILITY MAXIMUM ALLOWABLE 3 USER >>> %d%22s|\n", "", countuser1, "");
			printf("%8s| TOTAL FACILITY MAXIMUM ALLOWABLE 2 USER >>> %d%22s|\n", "", countuser2, "");
			printf("%8s| TOTAL FACILITY MAXIMUM ALLOWABLE 1 USER >>> %d%22s|\n", "", countuser3, "");
			printf("%8s", "");
			equalf(70);
			printf("\n\n");
			printf("%8sVIEW ALL THE FACILITY MAXIMUM ALLOWABLE USER ? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &view2);
			if (toupper(view2 == 'Y')) {
				printf("\n%-8s", "");
				dashf(70);
				printf("\n");
				printf("%-8s|%-10sFacility ID%-8s|%-10sMaximum Allowable User%-6s|\n", "", "", "", "", "");
				printf("%-8s", "");
				vbar(1); dashf(29); vbar(1); dashf(38); vbar(1);
				printf("\n");
				for (int i = 0; i < f; i++) {
					printf("%-8s|%-13s %s%-12s|%16s%d%-21s|\n", "", "", facilityreport[i].facilityId, "", "", facilityreport[i].maxallow, "");
					printf("%8s", "");
					vbar(1); dashf(29); vbar(1); dashf(38); vbar(1);
					printf("\n");
				}
			}
			printf("\n");
		}
		do {
			printf("%8sDO YOU WANT TO VIEW ANOTHER REPORT? (Y/N) >", "");
			rewind(stdin);
			scanf("%c", &addadd);
			if (toupper(addadd) != 'Y' && toupper(addadd) != 'N') {
				printf("%8sInvalid option. Please type again.\n", "");
			}
		} while (toupper(addadd) != 'Y' && toupper(addadd) != 'N');

		fclose(reportfacility);
		cls();
	} while (toupper(addadd) == 'Y');

}

void equalf(int parameter) {
	for (int i = 0; i < parameter; i++)
		printf("=");
}

void dashf(int parameter) {
	for (int i = 0; i < parameter; i++)
		printf("-");
}

void displaydash(int parameter) {
	for (int i = 0; i < parameter; i++)
		printf(" |-------------|-----------------|-------------------|-----------------|--------------|-----------|------------|-------|\n");
}

void vbar(int parameter) {
	for (int i = 0; i < parameter; i++)
		printf("|");
}


//Booking void function
void addBookingFunction();
void modifyBookingFunction();
void searchBookingFunction();
void displayBookingFunction();
void reportBookingFunction();
void deleteBookingFunction();
void printEqual(int parameter);
void printDash(int parameter);
void paymentMethodName();

//Booking Module

void bookingMenu() {
	char blank = ' ';
	int num;

	printEqual(172);
	printf("\n");
	printDash(172);
	printf("\n");
	printEqual(172);
	printf("\n\n");

	do {
		printf(white "%50c" "  ____              _    _               __  __           _       _ \n", blank);
		printf("%50c" " | __ )  ___   ___ | | _(_)_ __   __ _  |  \\/  | ___   __| |_   _| |\n", blank);
		printf("%50c" " |  _ \\ / _ \\ / _ \\| |/ / | '_ \\ / _` | | |\\/| |/ _ \\ / _` | | | | |\n", blank);
		printf("%50c" " | |_) | (_) | (_) |   <| | | | | (_| | | |  | | (_) | (_| | |_| | |\n", blank);
		printf("%50c" " |____/ \\___/ \\___/|_|\\_\\_|_| |_|\\__, | |_|  |_|\\___/ \\__,_|\\__,_|_|\n", blank);
		printf("%50c" "                                 |___/                              \n\n\n", blank);
		printf("%65c" "-----------------------------------------\n", blank);
		printf("%65c" "|                Menu                   |\n", blank);
		printf("%65c" "|   1. Add Booking                      |\n", blank);
		printf("%65c" "|   2. Search Booking                   |\n", blank);
		printf("%65c" "|   3. Modify Booking                   |\n", blank);
		printf("%65c" "|   4. Display Booking                  |\n", blank);
		printf("%65c" "|   5. Report Booking                   |\n", blank);
		printf("%65c" "|   6. Delete Booking                   |\n", blank);
		printf("%65c" "|   7. Back To Main Page                |\n", blank);
		printf("%65c" "-----------------------------------------\n\n", blank);
		printf("%65c" "Enter your selection: ", blank);
		rewind(stdin);
		scanf("%d", &num);
		cls();

		if (num == 1)
			addBookingFunction();

		else if (num == 2)
			searchBookingFunction();
		else if (num == 3)
			modifyBookingFunction();

		else if (num == 4)
			displayBookingFunction();

		else if (num == 5)
			reportBookingFunction();

		else if (num == 6)
			deleteBookingFunction();
	} while (num != 7);

}

void addBookingFunction() {
	FILE* booking01;
	FILE* checkBookingID;
	FILE* datafacility;
	SYSTEMTIME time;
	char yesNo, confirm, blank = ' ';
	Booking bookingInfor, checkBookingId[100];
	int facilityId, f = 0, payment, c = 0;
	Facility addfacility[20];

	booking01 = fopen("Booking_File.txt", "a");
	if (booking01 == NULL) {
		printf("Error cannot find the file");
		exit(-1);
	}

	checkBookingID = fopen("Booking_File.txt", "r");
	if (checkBookingID == NULL) {
		printf("Error cannot find the file");
		exit(-2);
	}

	datafacility = fopen("facilityinfor.txt", "r");
	if (datafacility == NULL) {
		printf("Error in opening facility file.\n");
		exit(-3);
	}

	while (fscanf(booking01, "%[^|]|%d/%d/%d|%d/%d/%d|%[^|]|%[^|]|%[^|]|%d %d|%d %d\n", &bookingInfor.bookingID, &bookingInfor.todayDate.todayDay, &bookingInfor.todayDate.todayMonth, &bookingInfor.todayDate.todayYear, &bookingInfor.bookingDate.bookingDay, &bookingInfor.bookingDate.bookingMonth, &bookingInfor.bookingDate.bookingYear, &bookingInfor.memberID, &bookingInfor.facilityID, &bookingInfor.paymetMethod, &bookingInfor.bookingTime.bookingStartHours, &bookingInfor.bookingTime.bookingStartMins, &bookingInfor.bookingTime.bookingEndHours, &bookingInfor.bookingTime.bookingEndMins) != -1) {
		rewind(stdin);
	}

	while (fscanf(checkBookingID, "%[^|]|%d/%d/%d|%d/%d/%d|%[^|]|%[^|]|%[^|]|%d %d|%d %d\n", &checkBookingId[c].bookingID, &checkBookingId[c].todayDate.todayDay, &checkBookingId[c].todayDate.todayMonth, &checkBookingId[c].todayDate.todayYear, &checkBookingId[c].bookingDate.bookingDay, &checkBookingId[c].bookingDate.bookingMonth, &checkBookingId[c].bookingDate.bookingYear, &checkBookingId[c].memberID, &checkBookingId[c].facilityID, &checkBookingId[c].paymetMethod, &checkBookingId[c].bookingTime.bookingStartHours, &checkBookingId[c].bookingTime.bookingStartMins, &checkBookingId[c].bookingTime.bookingEndHours, &checkBookingId[c].bookingTime.bookingEndMins) != -1) {
		c++;
	}

	do {
		printEqual(172);
		printf("\n");
		printDash(172);
		printf("\n");
		printEqual(172);
		printf("\n\n");

		GetLocalTime(&time);
		bookingInfor.todayDate.todayDay = time.wDay;
		bookingInfor.todayDate.todayMonth = time.wMonth;
		bookingInfor.todayDate.todayYear = time.wYear;

		printf(white "1. Add Booking Information\n\n");
		printf("Your enter time ( Hour , Minute, Second ) is %d : %d : %d \n\n", time.wHour, time.wMinute, time.wSecond);
		printf("Your enter day ( Day , Month , Year ) is %d - %d - %d \n\n", bookingInfor.todayDate.todayDay, bookingInfor.todayDate.todayMonth, bookingInfor.todayDate.todayYear);

		do {
			printf("Enter your booking ID (A105) : ");
			rewind(stdin);
			scanf("%[^\n]", &bookingInfor.bookingID);

			if (bookingInfor.bookingID[0] == '0' || bookingInfor.bookingID[0] == '1' || bookingInfor.bookingID[0] == '2' || bookingInfor.bookingID[0] == '3' || bookingInfor.bookingID[0] == '4' || bookingInfor.bookingID[0] == '5' || bookingInfor.bookingID[0] == '6' || bookingInfor.bookingID[0] == '7' || bookingInfor.bookingID[0] == '8' || bookingInfor.bookingID[0] == '9' || bookingInfor.bookingID[1] != '0' && bookingInfor.bookingID[1] != '1' && bookingInfor.bookingID[1] != '2' && bookingInfor.bookingID[1] != '3' && bookingInfor.bookingID[1] != '4' && bookingInfor.bookingID[1] != '5' && bookingInfor.bookingID[1] != '6' && bookingInfor.bookingID[1] != '7' && bookingInfor.bookingID[1] != '8' && bookingInfor.bookingID[1] != '9' && bookingInfor.bookingID[2] != '0' && bookingInfor.bookingID[2] != '1' && bookingInfor.bookingID[2] != '2' && bookingInfor.bookingID[2] != '3' && bookingInfor.bookingID[2] != '4' && bookingInfor.bookingID[2] != '5' && bookingInfor.bookingID[2] != '6' && bookingInfor.bookingID[2] != '7' && bookingInfor.bookingID[2] != '8' && bookingInfor.bookingID[2] != '9' && bookingInfor.bookingID[3] != '0' && bookingInfor.bookingID[3] != '1' && bookingInfor.bookingID[3] != '2' && bookingInfor.bookingID[3] != '3' && bookingInfor.bookingID[3] != '4' && bookingInfor.bookingID[3] != '5' && bookingInfor.bookingID[3] != '6' && bookingInfor.bookingID[3] != '7' && bookingInfor.bookingID[3] != '8' && bookingInfor.bookingID[3] != '9' || strlen(bookingInfor.bookingID) != 4) {
				printf("Invalid ID. Please type again.\n\n");
			}
		} while (bookingInfor.bookingID[0] == '0' || bookingInfor.bookingID[0] == '1' || bookingInfor.bookingID[0] == '2' || bookingInfor.bookingID[0] == '3' || bookingInfor.bookingID[0] == '4' || bookingInfor.bookingID[0] == '5' || bookingInfor.bookingID[0] == '6' || bookingInfor.bookingID[0] == '7' || bookingInfor.bookingID[0] == '8' || bookingInfor.bookingID[0] == '9' || bookingInfor.bookingID[1] != '0' && bookingInfor.bookingID[1] != '1' && bookingInfor.bookingID[1] != '2' && bookingInfor.bookingID[1] != '3' && bookingInfor.bookingID[1] != '4' && bookingInfor.bookingID[1] != '5' && bookingInfor.bookingID[1] != '6' && bookingInfor.bookingID[1] != '7' && bookingInfor.bookingID[1] != '8' && bookingInfor.bookingID[1] != '9' && bookingInfor.bookingID[2] != '0' && bookingInfor.bookingID[2] != '1' && bookingInfor.bookingID[2] != '2' && bookingInfor.bookingID[2] != '3' && bookingInfor.bookingID[2] != '4' && bookingInfor.bookingID[2] != '5' && bookingInfor.bookingID[2] != '6' && bookingInfor.bookingID[2] != '7' && bookingInfor.bookingID[2] != '8' && bookingInfor.bookingID[2] != '9' && bookingInfor.bookingID[3] != '0' && bookingInfor.bookingID[3] != '1' && bookingInfor.bookingID[3] != '2' && bookingInfor.bookingID[3] != '3' && bookingInfor.bookingID[3] != '4' && bookingInfor.bookingID[3] != '5' && bookingInfor.bookingID[3] != '6' && bookingInfor.bookingID[3] != '7' && bookingInfor.bookingID[3] != '8' && bookingInfor.bookingID[3] != '9' || strlen(bookingInfor.bookingID) != 4);

		for (int x = 0; x < c; x++)
		{
			while (strcmp(bookingInfor.bookingID, checkBookingId[x].bookingID) == 0)
			{
				do {
					printf("\n");
					printf("This booking ID already added or Invalid ID. \n\nPlease enter a new booking ID (A105) : ");
					scanf("%s", &bookingInfor.bookingID);
					rewind(stdin);

					if (bookingInfor.bookingID[0] == '0' || bookingInfor.bookingID[0] == '1' || bookingInfor.bookingID[0] == '2' || bookingInfor.bookingID[0] == '3' || bookingInfor.bookingID[0] == '4' || bookingInfor.bookingID[0] == '5' || bookingInfor.bookingID[0] == '6' || bookingInfor.bookingID[0] == '7' || bookingInfor.bookingID[0] == '8' || bookingInfor.bookingID[0] == '9' || bookingInfor.bookingID[1] != '0' && bookingInfor.bookingID[1] != '1' && bookingInfor.bookingID[1] != '2' && bookingInfor.bookingID[1] != '3' && bookingInfor.bookingID[1] != '4' && bookingInfor.bookingID[1] != '5' && bookingInfor.bookingID[1] != '6' && bookingInfor.bookingID[1] != '7' && bookingInfor.bookingID[1] != '8' && bookingInfor.bookingID[1] != '9' && bookingInfor.bookingID[2] != '0' && bookingInfor.bookingID[2] != '1' && bookingInfor.bookingID[2] != '2' && bookingInfor.bookingID[2] != '3' && bookingInfor.bookingID[2] != '4' && bookingInfor.bookingID[2] != '5' && bookingInfor.bookingID[2] != '6' && bookingInfor.bookingID[2] != '7' && bookingInfor.bookingID[2] != '8' && bookingInfor.bookingID[2] != '9' && bookingInfor.bookingID[3] != '0' && bookingInfor.bookingID[3] != '1' && bookingInfor.bookingID[3] != '2' && bookingInfor.bookingID[3] != '3' && bookingInfor.bookingID[3] != '4' && bookingInfor.bookingID[3] != '5' && bookingInfor.bookingID[3] != '6' && bookingInfor.bookingID[3] != '7' && bookingInfor.bookingID[3] != '8' && bookingInfor.bookingID[3] != '9' || strlen(bookingInfor.bookingID) != 4) {
					}

					x = 0;
				} while (bookingInfor.bookingID[0] == '0' || bookingInfor.bookingID[0] == '1' || bookingInfor.bookingID[0] == '2' || bookingInfor.bookingID[0] == '3' || bookingInfor.bookingID[0] == '4' || bookingInfor.bookingID[0] == '5' || bookingInfor.bookingID[0] == '6' || bookingInfor.bookingID[0] == '7' || bookingInfor.bookingID[0] == '8' || bookingInfor.bookingID[0] == '9' || bookingInfor.bookingID[1] != '0' && bookingInfor.bookingID[1] != '1' && bookingInfor.bookingID[1] != '2' && bookingInfor.bookingID[1] != '3' && bookingInfor.bookingID[1] != '4' && bookingInfor.bookingID[1] != '5' && bookingInfor.bookingID[1] != '6' && bookingInfor.bookingID[1] != '7' && bookingInfor.bookingID[1] != '8' && bookingInfor.bookingID[1] != '9' && bookingInfor.bookingID[2] != '0' && bookingInfor.bookingID[2] != '1' && bookingInfor.bookingID[2] != '2' && bookingInfor.bookingID[2] != '3' && bookingInfor.bookingID[2] != '4' && bookingInfor.bookingID[2] != '5' && bookingInfor.bookingID[2] != '6' && bookingInfor.bookingID[2] != '7' && bookingInfor.bookingID[2] != '8' && bookingInfor.bookingID[2] != '9' && bookingInfor.bookingID[3] != '0' && bookingInfor.bookingID[3] != '1' && bookingInfor.bookingID[3] != '2' && bookingInfor.bookingID[3] != '3' && bookingInfor.bookingID[3] != '4' && bookingInfor.bookingID[3] != '5' && bookingInfor.bookingID[3] != '6' && bookingInfor.bookingID[3] != '7' && bookingInfor.bookingID[3] != '8' && bookingInfor.bookingID[3] != '9' || strlen(bookingInfor.bookingID) != 4);
			}

		}

		printf("\n");
		printf("Today date is %d - %d - %d\n\n", bookingInfor.todayDate.todayDay, bookingInfor.todayDate.todayMonth, bookingInfor.todayDate.todayYear);

		do {
			printf("Enter your booking date (YYYY MM DD) : ");
			rewind(stdin);
			scanf("%d %d %d", &bookingInfor.bookingDate.bookingYear, &bookingInfor.bookingDate.bookingMonth, &bookingInfor.bookingDate.bookingDay);

			if ((bookingInfor.bookingDate.bookingYear < bookingInfor.todayDate.todayYear) || (bookingInfor.bookingDate.bookingMonth < bookingInfor.todayDate.todayMonth))
			{

				printf("\nError Booking Date!\n\n");

			}
			if (bookingInfor.bookingDate.bookingMonth == bookingInfor.todayDate.todayMonth && bookingInfor.bookingDate.bookingDay < bookingInfor.todayDate.todayDay)
			{
				printf("\nError Booking Date!\n\n");
			}


		} while ((bookingInfor.bookingDate.bookingYear < bookingInfor.todayDate.todayYear) || (bookingInfor.bookingDate.bookingMonth < bookingInfor.todayDate.todayMonth) || (bookingInfor.bookingDate.bookingMonth == bookingInfor.todayDate.todayMonth && bookingInfor.bookingDate.bookingDay < bookingInfor.todayDate.todayDay));

		printf("\n");

		Member informember[100];
		FILE* datamember;
		datamember = fopen("addmember.dat", "rb");
		if (datamember == NULL) {
			printf("Error cannot find the file");
			exit(-4);
		}

		int m = 0, i = 0;
		printf("%5s| Member ID |\n", "");

		while (fread(&informember[m], sizeof(Member), 1, datamember) != 0) {
			m++;
		}
		fclose(datamember);

		int status = 0;
		do {
			for (int i = 0; i < m; i++) {
				printf("%14s\n", informember[i].memberID);
			}

			printf("\nEnter your member ID : ");
			rewind(stdin);
			scanf("%[^\n]", &bookingInfor.memberID);

			for (int i = 0; i < m; i++) {
				if (strcmp(bookingInfor.memberID, informember[i].memberID) == 0) {
					printf("Continue Booking.\n");
					status++;
					break;
				}
			}
		} while (status == 0);

		printf("\n");

		printf("%5s %12s %6s %16s %4s", "Facility ID |", "Types", "|", "Description", "|");
		while (fscanf(datafacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &addfacility[f].facilityId, &addfacility[f].types, &addfacility[f].description, &addfacility[f].venue, &addfacility[f].maxallow, &addfacility[f].opentime.hours, &addfacility[f].opentime.minutes, &addfacility[f].closetime.hours, &addfacility[f].closetime.minutes, &addfacility[f].charges) != -1) {
			rewind(stdin);
			f++;
		}

		int found = 0;
		printf("\n");
		do {
			for (int i = 0; i < f; i++) {
				printf("%8s %3s|%16s %2s|%18s %2s|\n", addfacility[i].facilityId, "", addfacility[i].types, "", addfacility[i].description, "");
			}
			printf("\nEnter Facility ID : ");
			rewind(stdin);
			scanf("%[^\n]", &bookingInfor.facilityID);
			for (int a = 0; a < f; a++) {
				if (strcmp(bookingInfor.facilityID, addfacility[a].facilityId) == 0) {
					printf("\nFacility type : %s \n", addfacility[a].types);
					printf("\nFacility Description : %s \n", addfacility[a].description);
					printf("\nOpen Time : %.2d %.2d\n", addfacility[a].opentime.hours, addfacility[a].opentime.minutes);
					printf("\nEnd Time : %.2d %.2d \n", addfacility[a].closetime.hours, addfacility[a].closetime.minutes);

					int FacilityOpenHours = addfacility[a].opentime.hours * 60;
					int FacilityCloseHours = addfacility[a].closetime.hours * 60;
					int totalFacilityOpenMins = FacilityOpenHours + addfacility[a].opentime.minutes;
					int totalFacilityCloseMins = FacilityCloseHours + addfacility[a].closetime.minutes;

					int BookingStartHour, BookingEndHours, totalBookingMins, totalEndMins;
					do {
						printf("\nEnter your start time (24 Hours System ) (HH MM - 15 30) : ");
						rewind(stdin);
						scanf("%d  %d", &bookingInfor.bookingTime.bookingStartHours, &bookingInfor.bookingTime.bookingStartMins);

						BookingStartHour = bookingInfor.bookingTime.bookingStartHours * 60;
						totalBookingMins = BookingStartHour + bookingInfor.bookingTime.bookingStartMins;

						if (totalBookingMins < totalFacilityOpenMins || totalBookingMins > totalFacilityCloseMins) {
							printf("Error Time\n");
						}
					} while (totalBookingMins < totalFacilityOpenMins || totalBookingMins > totalFacilityCloseMins);

					do {
						printf("\nEnter your end time (24 Hours System ) (HH MM - 15 30) : ");
						rewind(stdin);
						scanf("%d  %d", &bookingInfor.bookingTime.bookingEndHours, &bookingInfor.bookingTime.bookingEndMins);

						BookingEndHours = bookingInfor.bookingTime.bookingEndHours * 60;
						totalEndMins = BookingEndHours + bookingInfor.bookingTime.bookingEndMins;

						if (totalEndMins > totalFacilityCloseMins || totalEndMins < totalBookingMins) {
							printf("Error Time\n");
						}

					} while (totalEndMins > totalFacilityCloseMins || totalEndMins < totalBookingMins);

					found++;
				}
			}
			if (found == 1) {
				printf("Continue booking.\n");
			}
			else
			{
				printf("Invalid data. Please try again.\n\n");
			}
		} while (found == 0);

		printf("\n");

		do {
			paymentMethodName();
			printf("\nEnter your payment method (1) : ");
			rewind(stdin);
			scanf("%d", &payment);

			if (payment == 1) {
				strcpy(bookingInfor.paymetMethod, "Maybank");
			}

			else if (payment == 2) {
				strcpy(bookingInfor.paymetMethod, "Public Bank");
			}

			else if (payment == 3) {
				strcpy(bookingInfor.paymetMethod, "CIMB Bank");
			}

			else if (payment == 4) {
				strcpy(bookingInfor.paymetMethod, "Touch 'n Go");
			}

			else {
				printf("\nInvalid data.\nPlease enter again.\n");
			}

		} while (payment < 0 || payment > 4);

		cls();
		printf("\n\n");
		printEqual(172);
		printf(white "\n%75c" "This is booking information", blank);
		printf("\n\n\n");
		printf("%8c" "Booking ID", blank);
		printf("%8c" "Today's Date", blank);
		printf("%8c" "Booking Date", blank);
		printf("%8c" "Member ID", blank);
		printf("%8c" "Facility ID", blank);
		printf("%8c" "Payment Method", blank);
		printf("%8c" "Booking Start Time", blank);
		printf("%8c" "Booking End Time\n", blank);
		printEqual(172);
		printf(white "\n\n %14s %13d/%d/%d %12d/%d/%d %16s %16s %23s %17.2d %.2d %21.2d %.2d\n", bookingInfor.bookingID, bookingInfor.todayDate.todayDay, bookingInfor.todayDate.todayMonth, bookingInfor.todayDate.todayYear, bookingInfor.bookingDate.bookingDay, bookingInfor.bookingDate.bookingMonth, bookingInfor.bookingDate.bookingYear, bookingInfor.memberID, bookingInfor.facilityID, bookingInfor.paymetMethod, bookingInfor.bookingTime.bookingStartHours, bookingInfor.bookingTime.bookingStartMins, bookingInfor.bookingTime.bookingEndHours, bookingInfor.bookingTime.bookingEndMins);
		printEqual(172);

		printf(white "\n\nConfirm to book? (Y or N) : ");
		rewind(stdin);
		scanf("%c", &confirm);
		while (confirm != 'Y' && confirm != 'N') {
			printf("\nInvalid input. \nPlease enter again (Y / N) : ");
			rewind(stdin);
			scanf("%c", &confirm);
		}

		if (confirm == 'Y') {
			fprintf(booking01, "%s|%d/%d/%d|%d/%d/%d|%s|%s|%s|%.2d %.2d|%.2d %.2d\n", bookingInfor.bookingID, bookingInfor.todayDate.todayDay, bookingInfor.todayDate.todayMonth, bookingInfor.todayDate.todayYear, bookingInfor.bookingDate.bookingDay, bookingInfor.bookingDate.bookingMonth, bookingInfor.bookingDate.bookingYear, bookingInfor.memberID, bookingInfor.facilityID, bookingInfor.paymetMethod, bookingInfor.bookingTime.bookingStartHours, bookingInfor.bookingTime.bookingStartMins, bookingInfor.bookingTime.bookingEndHours, bookingInfor.bookingTime.bookingEndMins);
		}

		else {
			printf("No booking record to add. \n");
		}

		printf("\nStill want to booking? (Y or N) >");
		rewind(stdin);
		scanf("%c", &yesNo);
		while (yesNo != 'Y' && yesNo != 'N') {
			printf("\nInvalid input. \nPlease enter again (Y / N) : ");
			rewind(stdin);
			scanf("%c", &yesNo);
		}
		printf("\n");
		cls();
	} while (yesNo == 'Y' || yesNo != 'N');

	fclose(booking01);
	fclose(datafacility);
	fclose(checkBookingID);
	system("pause");
	cls();
}

void searchBookingFunction() {
	Booking bookingSearch[100];
	char searchBookingId[5], searchMemberId[10], blank = ' ', select;
	int  num = 0;

	FILE* searchBooking;
	searchBooking = fopen("Booking_File.txt", "r");
	if (searchBooking == NULL) {
		printf("Error cannot find the file");
		exit(-1);
	}

	while (fscanf(searchBooking, "%[^|]|%d/%d/%d|%d/%d/%d|%[^|]|%[^|]|%[^|]|%d %d|%d %d\n", &bookingSearch[num].bookingID, &bookingSearch[num].todayDate.todayDay, &bookingSearch[num].todayDate.todayMonth, &bookingSearch[num].todayDate.todayYear, &bookingSearch[num].bookingDate.bookingDay, &bookingSearch[num].bookingDate.bookingMonth, &bookingSearch[num].bookingDate.bookingYear, &bookingSearch[num].memberID, &bookingSearch[num].facilityID, &bookingSearch[num].paymetMethod, &bookingSearch[num].bookingTime.bookingStartHours, &bookingSearch[num].bookingTime.bookingStartMins, &bookingSearch[num].bookingTime.bookingEndHours, &bookingSearch[num].bookingTime.bookingEndMins) != -1) {
		num++;
	}
	printEqual(172);
	printf("\n");
	printDash(172);
	printf("\n");
	printEqual(172);
	printf("\n\n");

	do {
		int  found = 0, found1 = 0;
		printf(white"\n\n2. Search Booking Information\n\n");
		printf("Which method you want to choose?\n");
		printf("A. Booking ID\n\n");
		printf("B. Member ID\n\n");
		printf("C. Exit\n\n");

		printf("What is your selection : ");
		rewind(stdin);
		scanf("%c", &select);

		while (select != 'A' && select != 'B' && select != 'C') {
			printf("\nInvalid input. \nPlease enter again (A / B / C) : ");
			rewind(stdin);
			scanf("%c", &select);
		}

		printf("\n\n");

		if (select == 'A') {
			printf("Booking ID : \n");
			for (int i = 0; i < num; i++) {
				printf(white "%5s\n", bookingSearch[i].bookingID);
			}

			printf("\nEnter your booking ID (A105) : ");
			rewind(stdin);
			scanf("%[^\n]", &searchBookingId);
			cls();
			printf("\n\n");

			for (int i = 0; i < num; i++) {
				if (strcmp(searchBookingId, bookingSearch[i].bookingID) == 0) {
					printEqual(172);
					printf(white "%64c" "This is the search booking ID result of the %s", blank, bookingSearch[i].bookingID);
					printf("\n\n\n");
					printf("%8c" "Booking ID", blank);
					printf("%8c" "Today's Date", blank);
					printf("%8c" "Booking Date", blank);
					printf("%8c" "Member ID", blank);
					printf("%8c" "Facility ID", blank);
					printf("%8c" "Payment Method", blank);
					printf("%8c" "Booking Start Time", blank);
					printf("%8c" "Booking End Time\n", blank);
					printEqual(172);
					printf(white "\n\n%15s %13d/%d/%d %13d/%d/%d %16s %16s %23s %17.2d %.2d %21.2d %.2d\n", bookingSearch[i].bookingID, bookingSearch[i].todayDate.todayDay, bookingSearch[i].todayDate.todayMonth, bookingSearch[i].todayDate.todayYear, bookingSearch[i].bookingDate.bookingDay, bookingSearch[i].bookingDate.bookingMonth, bookingSearch[i].bookingDate.bookingYear, bookingSearch[i].memberID, bookingSearch[i].facilityID, bookingSearch[i].paymetMethod, bookingSearch[i].bookingTime.bookingStartHours, bookingSearch[i].bookingTime.bookingStartMins, bookingSearch[i].bookingTime.bookingEndHours, bookingSearch[i].bookingTime.bookingEndMins);
					printEqual(172);
					found++;
				}
			}
			if (found == 0) {
				printf(white "Invalid data. Please enter again.\n");
			}
		}

		else if (select == 'B') {

			printf("Member ID : \n");
			for (int i = 0; i < num; i++) {
				printf(white "%5s\n", bookingSearch[i].memberID);
			}

			printf("\nEnter your member ID : ");
			rewind(stdin);
			scanf("%[^\n]", searchMemberId);
			cls();

			for (int i = 0; i < num; i++) {
				if (strcmp(searchMemberId, bookingSearch[i].memberID) == 0) {
					printf("\n\n");
					printEqual(172);
					printf(white "%64c" "This is the search member ID result of the %s", blank, bookingSearch[i].memberID);
					printf("\n\n\n");
					printf("%8c" "Booking ID", blank);
					printf("%8c" "Today's Date", blank);
					printf("%8c" "Booking Date", blank);
					printf("%8c" "Member ID", blank);
					printf("%8c" "Facility ID", blank);
					printf("%8c" "Payment Method", blank);
					printf("%8c" "Booking Start Time", blank);
					printf("%8c" "Booking End Time\n", blank);
					printEqual(172);
					printf(white "\n\n%15s %13d/%d/%d %13d/%d/%d %16s %16s %23s %17.2d %.2d %21.2d %.2d\n", bookingSearch[i].bookingID, bookingSearch[i].todayDate.todayDay, bookingSearch[i].todayDate.todayMonth, bookingSearch[i].todayDate.todayYear, bookingSearch[i].bookingDate.bookingDay, bookingSearch[i].bookingDate.bookingMonth, bookingSearch[i].bookingDate.bookingYear, bookingSearch[i].memberID, bookingSearch[i].facilityID, bookingSearch[i].paymetMethod, bookingSearch[i].bookingTime.bookingStartHours, bookingSearch[i].bookingTime.bookingStartMins, bookingSearch[i].bookingTime.bookingEndHours, bookingSearch[i].bookingTime.bookingEndMins);
					printEqual(172);
					found1++;
				}
			}


			if (found1 == 0) {
				printf(white "\nInvalid data. Please enter again.\n");
			}
		}

		else if (select == 'C') {
			printf("Exit\n");
		}

		else {
			printf("\nInvalid data. Please enter again.\n");
		}
		fclose(searchBooking);
	} while (select != 'C');
	system("pause");
	cls();
}

void modifyBookingFunction() {
	SYSTEMTIME time;
	Booking bookingModify[100], checkModifyBookingId[100];
	int  num = 0, payment;
	char bookingnewid[10], continueOrno, confirm;

	FILE* datamodifyfacility;
	int facilityId, f = 0, found = 0, c = 0;
	Facility addmodifyfacility[20];

	FILE* modifyBooking;
	modifyBooking = fopen("Booking_File.txt", "r");
	if (modifyBooking == NULL) {
		printf("Error cannot find the file");
		exit(-1);
	}

	datamodifyfacility = fopen("facilityinfor.txt", "r");
	if (datamodifyfacility == NULL) {
		printf("%8sError in opening facility file.\n", "");
		exit(-1);
	}

	while (fscanf(modifyBooking, "%[^|]|%d/%d/%d|%d/%d/%d|%[^|]|%[^|]|%[^|]|%d %d|%d %d\n", &bookingModify[num].bookingID, &bookingModify[num].todayDate.todayDay, &bookingModify[num].todayDate.todayMonth, &bookingModify[num].todayDate.todayYear, &bookingModify[num].bookingDate.bookingDay, &bookingModify[num].bookingDate.bookingMonth, &bookingModify[num].bookingDate.bookingYear, &bookingModify[num].memberID, &bookingModify[num].facilityID, &bookingModify[num].paymetMethod, &bookingModify[num].bookingTime.bookingStartHours, &bookingModify[num].bookingTime.bookingStartMins, &bookingModify[num].bookingTime.bookingEndHours, &bookingModify[num].bookingTime.bookingEndMins) != -1) {
		rewind(stdin);
		num++;
	}
	fclose(modifyBooking);

	do {
		printEqual(172);
		printf("\n");
		printDash(172);
		printf("\n");
		printEqual(172);
		printf("\n\n");

		GetLocalTime(&time);
		bookingModify[num].todayDate.todayDay = time.wDay;
		bookingModify[num].todayDate.todayMonth = time.wMonth;
		bookingModify[num].todayDate.todayYear = time.wYear;

		printf(white "3. Modify Booking Information\n\n");
		printf("Booking Id : \n");
		for (int i = 0; i < num; i++) {
			printf("%s\n", bookingModify[i].bookingID);
		}

		printf("\nEnter your booking ID : ");
		rewind(stdin);
		scanf("%[^\n]", &bookingnewid);

		for (int i = 0; i < num; i++) {
			if (strcmp(bookingnewid, bookingModify[i].bookingID) == 0) {
				printf("\nToday date is : %d : %d : %d \n\n", bookingModify[i].todayDate.todayDay, bookingModify[i].todayDate.todayMonth, bookingModify[i].todayDate.todayYear);

				printf("\n");

				printf("%5s %12s %6s %16s %4s", "Facility ID |", "Types", "|", "Description", "|");
				while (fscanf(datamodifyfacility, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d %d|%d %d|%f\n", &addmodifyfacility[f].facilityId, &addmodifyfacility[f].types, &addmodifyfacility[f].description, &addmodifyfacility[f].venue, &addmodifyfacility[f].maxallow, &addmodifyfacility[f].opentime.hours, &addmodifyfacility[f].opentime.minutes, &addmodifyfacility[f].closetime.hours, &addmodifyfacility[f].closetime.minutes, &addmodifyfacility[f].charges) != -1) {
					rewind(stdin);
					f++;
				}
				fclose(datamodifyfacility);
				do {
					int found = 0;
					printf("\n");
					do {
						for (int i = 0; i < f; i++) {
							printf("%8s %3s|%16s %2s|%18s %2s|\n", addmodifyfacility[i].facilityId, "", addmodifyfacility[i].types, "", addmodifyfacility[i].description, "");
						}
						printf("\nEnter Facility ID : ");
						rewind(stdin);
						scanf("%[^\n]", &bookingModify[i].facilityID);
						for (int a = 0; a < f; a++) {
							if (strcmp(bookingModify[i].facilityID, addmodifyfacility[a].facilityId) == 0) {
								printf("\nFacility type : %s \n", addmodifyfacility[a].types);
								printf("\nFacility Description : %s \n", addmodifyfacility[a].description);
								printf("\nOpen Time : %.2d %.2d\n", addmodifyfacility[a].opentime.hours, addmodifyfacility[a].opentime.minutes);
								printf("\nEnd Time : %.2d %.2d \n", addmodifyfacility[a].closetime.hours, addmodifyfacility[a].closetime.minutes);

								int FacilityOpenHours = addmodifyfacility[a].opentime.hours * 60;
								int FacilityCloseHours = addmodifyfacility[a].closetime.hours * 60;
								int totalFacilityOpenMins = FacilityOpenHours + addmodifyfacility[a].opentime.minutes;
								int totalFacilityCloseMins = FacilityCloseHours + addmodifyfacility[a].closetime.minutes;

								int BookingStartHour, BookingEndHours, totalBookingMins, totalEndMins;
								do {
									printf("\nEnter your start time (24 Hours System ) (HH MM - 15 30) : ");
									rewind(stdin);
									scanf("%d %d", &bookingModify[i].bookingTime.bookingStartHours, &bookingModify[i].bookingTime.bookingStartMins);

									BookingStartHour = bookingModify[i].bookingTime.bookingStartHours * 60;
									totalBookingMins = BookingStartHour + bookingModify[i].bookingTime.bookingStartMins;

									if (totalBookingMins < totalFacilityOpenMins || totalBookingMins > totalFacilityCloseMins) {
										printf("Error Time\n");
									}
								} while (totalBookingMins < totalFacilityOpenMins || totalBookingMins > totalFacilityCloseMins);

								do {
									printf("\nEnter your end time (24 Hours System ) (HH MM - 15 30) : ");
									rewind(stdin);
									scanf("%d %d", &bookingModify[i].bookingTime.bookingEndHours, &bookingModify[i].bookingTime.bookingEndMins);

									BookingEndHours = bookingModify[i].bookingTime.bookingEndHours * 60;
									totalEndMins = BookingEndHours + bookingModify[i].bookingTime.bookingEndMins;

									if (totalEndMins > totalFacilityCloseMins || totalEndMins < totalBookingMins) {
										printf("Error Time\n");
									}

								} while (totalEndMins > totalFacilityCloseMins || totalEndMins < totalBookingMins);

								found++;
							}
						}
						if (found == 1) {
							printf("Continue booking.\n\n");
						}
						else
						{
							printf("Invalid data. \nPlease enter again.\n\n");
						}
					} while (found == 0);

					do {
						paymentMethodName();
						printf("\nEnter your payment method (1) : ");
						rewind(stdin);
						scanf("%d", &payment);

						if (payment == 1) {
							strcpy(bookingModify[i].paymetMethod, "Maybank");
						}

						else if (payment == 2) {
							strcpy(bookingModify[i].paymetMethod, "Public Bank");
						}

						else if (payment == 3) {
							strcpy(bookingModify[i].paymetMethod, "CIMB Bank");
						}

						else if (payment == 4) {
							strcpy(bookingModify[i].paymetMethod, "Touch 'n Go");
						}

						else {
							printf("\nInvalid data.\nPlease enter again.\n");
						}

					} while (payment < 0 || payment > 4);

					do {
						printf("\nEnter your booking date (YYYY MM DD) : ");
						rewind(stdin);
						scanf("%d %d %d", &bookingModify[i].bookingDate.bookingYear, &bookingModify[i].bookingDate.bookingMonth, &bookingModify[i].bookingDate.bookingDay);

						if ((bookingModify[i].bookingDate.bookingYear < bookingModify[i].todayDate.todayYear) || (bookingModify[i].bookingDate.bookingMonth < bookingModify[i].todayDate.todayMonth))
						{

							printf("\nError Booking Date!\n\n");

						}
						if (bookingModify[i].bookingDate.bookingMonth == bookingModify[i].todayDate.todayMonth && bookingModify[i].bookingDate.bookingDay < bookingModify[i].todayDate.todayDay)
						{
							printf("\nError Booking Date!\n\n");
						}


					} while ((bookingModify[i].bookingDate.bookingYear < bookingModify[i].todayDate.todayYear) || (bookingModify[i].bookingDate.bookingMonth < bookingModify[i].todayDate.todayMonth) || (bookingModify[i].bookingDate.bookingMonth == bookingModify[i].todayDate.todayMonth && bookingModify[i].bookingDate.bookingDay < bookingModify[i].todayDate.todayDay));

					printf("\nYour member ID is : %s\n", bookingModify[i].memberID);

					printf("\nConfirm modify this record (Y or N) : ");
					rewind(stdin);
					scanf("%c", &confirm);
					while (confirm != 'Y' && confirm != 'N') {
						printf("\nInvalid input. \nPlease enter again (Y / N) : ");
						rewind(stdin);
						scanf("%c", &confirm);
					}

					if (confirm == 'Y') {
						FILE* modifyBookingWrite;
						modifyBookingWrite = fopen("Booking_File.txt", "w");
						if (modifyBookingWrite == NULL) {
							printf("Error cannot find the file");
							exit(-1);
						}

						for (int i = 0; i < num; i++) {
							fprintf(modifyBookingWrite, "%s|%d/%d/%d|%d/%d/%d|%s|%s|%s|%.2d %.2d|%.2d %.2d\n", bookingModify[i].bookingID, bookingModify[i].todayDate.todayDay, bookingModify[i].todayDate.todayMonth, bookingModify[i].todayDate.todayYear, bookingModify[i].bookingDate.bookingDay, bookingModify[i].bookingDate.bookingMonth, bookingModify[i].bookingDate.bookingYear, bookingModify[i].memberID, bookingModify[i].facilityID, bookingModify[i].paymetMethod, bookingModify[i].bookingTime.bookingStartHours, bookingModify[i].bookingTime.bookingStartMins, bookingModify[i].bookingTime.bookingEndHours, bookingModify[i].bookingTime.bookingEndMins);
						}
						fclose(modifyBookingWrite);
					}

					else {
						printf("\nNo booking record to add. \n");
					}

				} while (strcmp(bookingModify[i].facilityID, addmodifyfacility[f].facilityId) == 0);

			}
		}

		printf("\nDo you want to continue modify? (Y or N) :");
		rewind(stdin);
		scanf("%c", &continueOrno);
		while (continueOrno != 'Y' && continueOrno != 'N') {
			printf("\nInvalid input. \nPlease enter again (Y / N) : ");
			rewind(stdin);
			scanf("%c", &continueOrno);
		}

		cls();
	} while (continueOrno == 'Y' || continueOrno != 'N');
	system("pause");
	cls();
}

void displayBookingFunction() {
	Booking bookingDisplay[100];

	int  num = 0;
	char blank = ' ';

	FILE* displayBooking;

	displayBooking = fopen("Booking_File.txt", "r");
	if (displayBooking == NULL) {
		printf("Error cannot find the file");
		exit(-1);
	}

	printEqual(172);
	printf("\n");
	printDash(172);
	printf("\n");
	printEqual(172);
	printf("\n\n");

	printf(white "%5c" "4. Display Booking Information\n\n", blank);
	printf("%8c" "Booking ID", blank);
	printf("%6c" "Today's Date", blank);
	printf("%6c" "Booking Date", blank);
	printf("%6c" "Member ID", blank);
	printf("%6c" "Facility ID", blank);
	printf("%6c" "Payment Method", blank);
	printf("%6c" "Booking Start Time", blank);
	printf("%6c" "Booking End Time\n", blank);

	while (fscanf(displayBooking, "%[^|]|%d/%d/%d|%d/%d/%d|%[^|]|%[^|]|%[^|]|%d %d|%d %d\n", &bookingDisplay[num].bookingID, &bookingDisplay[num].todayDate.todayDay, &bookingDisplay[num].todayDate.todayMonth, &bookingDisplay[num].todayDate.todayYear, &bookingDisplay[num].bookingDate.bookingDay, &bookingDisplay[num].bookingDate.bookingMonth, &bookingDisplay[num].bookingDate.bookingYear, &bookingDisplay[num].memberID, &bookingDisplay[num].facilityID, &bookingDisplay[num].paymetMethod, &bookingDisplay[num].bookingTime.bookingStartHours, &bookingDisplay[num].bookingTime.bookingStartMins, &bookingDisplay[num].bookingTime.bookingEndHours, &bookingDisplay[num].bookingTime.bookingEndMins) != -1) {
		rewind(stdin);
		num++;
	}

	for (int i = 0; i < num; i++) {
		printEqual(172);
		printf(white "%3d %11s %12d/%d/%d %10d/%d/%d %13s %14s %22s %15.2d %.2d %18.2d %.2d\n", i + 1, bookingDisplay[i].bookingID, bookingDisplay[i].todayDate.todayDay, bookingDisplay[i].todayDate.todayMonth, bookingDisplay[i].todayDate.todayYear, bookingDisplay[i].bookingDate.bookingDay, bookingDisplay[i].bookingDate.bookingMonth, bookingDisplay[i].bookingDate.bookingYear, bookingDisplay[i].memberID, bookingDisplay[i].facilityID, bookingDisplay[i].paymetMethod, bookingDisplay[i].bookingTime.bookingStartHours, bookingDisplay[i].bookingTime.bookingStartMins, bookingDisplay[i].bookingTime.bookingEndHours, bookingDisplay[i].bookingTime.bookingEndMins);
		printEqual(172);
		printf("\n\n");
	}

	printf(white "<< Total record is %d >>\n\n", num);

	fclose(displayBooking);
	system("pause");
	cls();
}

void reportBookingFunction() {
	Booking bookingReport[100];
	int  num = 0, day1, month1, year1, found = 0;
	char blank = ' ', yesNo;

	FILE* reportBooking;
	reportBooking = fopen("Booking_File.txt", "r");
	if (reportBooking == NULL) {
		printf("Error cannot find the file");
		exit(-1);
	}

	while (fscanf(reportBooking, "%[^|]|%d/%d/%d|%d/%d/%d|%[^|]|%[^|]|%[^|]|%d %d|%d %d\n", &bookingReport[num].bookingID, &bookingReport[num].todayDate.todayDay, &bookingReport[num].todayDate.todayMonth, &bookingReport[num].todayDate.todayYear, &bookingReport[num].bookingDate.bookingDay, &bookingReport[num].bookingDate.bookingMonth, &bookingReport[num].bookingDate.bookingYear, &bookingReport[num].memberID, &bookingReport[num].facilityID, &bookingReport[num].paymetMethod, &bookingReport[num].bookingTime.bookingStartHours, &bookingReport[num].bookingTime.bookingStartMins, &bookingReport[num].bookingTime.bookingEndHours, &bookingReport[num].bookingTime.bookingEndMins) != -1) {
		rewind(stdin);
		num++;
	}
	fclose(reportBooking);

	do {
		printEqual(172);
		printf("\n");
		printDash(172);
		printf("\n");
		printEqual(172);
		printf("\n\n");

		printf(white "5. Report Booking Information\n\n");

		printf("Enter summary report of booking day (YYYY MM DD) : ");
		rewind(stdin);
		scanf("%d %d %d", &year1, &month1, &day1);

		cls();

		printf("\n\n");
		printEqual(172);
		printf(white "%55c" "This is the summary report of the %d - %d - %d", blank, day1, month1, year1);
		printf("\n\n\n");
		printf("%8c" "Member ID", blank);
		printf("%8c" "Booking ID", blank);
		printf("%8c" "Facility ID", blank);
		printf("%8c" "Payment Method", blank);
		printf("%8c" "Booking Date", blank);
		printf("%8c" "Booking Start Time", blank);
		printf("%8c" "Booking End Time\n", blank);
		printEqual(172);
		printf("\n\n");

		for (int i = 0; i < num; i++) {
			if (year1 == bookingReport[i].bookingDate.bookingYear && month1 == bookingReport[i].bookingDate.bookingMonth && day1 == bookingReport[i].bookingDate.bookingDay) {
				printf(white "%3d %10s %17s %17s %24s %12d/%d/%d %17.2d %.2d %21.2d %.2d \n\n", i + 1, bookingReport[i].memberID, bookingReport[i].bookingID, bookingReport[i].facilityID, bookingReport[i].paymetMethod, bookingReport[i].bookingDate.bookingDay, bookingReport[i].bookingDate.bookingMonth, bookingReport[i].bookingDate.bookingYear, bookingReport[i].bookingTime.bookingStartHours, bookingReport[i].bookingTime.bookingStartMins, bookingReport[i].bookingTime.bookingEndHours, bookingReport[i].bookingTime.bookingEndMins);
				found++;
				num++;
			}
		}

		if (found == 0) {
			printf(white "\nInvalid data.\n");
		}

		printf(white "\n\nDo you want to view other summary report? (Y / N) : ");
		rewind(stdin);
		scanf("%c", &yesNo);

		while (yesNo != 'Y' && yesNo != 'N') {
			printf("\nInvalid input. \nPlease enter again (Y / N) : ");
			rewind(stdin);
			scanf("%c", &yesNo);
		}

		cls();
	} while (yesNo == 'Y' || yesNo != 'N');
	system("pause");
	cls();
}

void deleteBookingFunction() {
	Booking bookingDelete[100];
	int  num = 0, temp, found = 0;
	char blank = ' ', bookingid1[10], confirm, delbook;

	FILE* deleteBooking;
	deleteBooking = fopen("Booking_File.txt", "r");
	if (deleteBooking == NULL) {
		printf("Error cannot find the file");
		exit(-1);
	}

	while (fscanf(deleteBooking, "%[^|]|%d/%d/%d|%d/%d/%d|%[^|]|%[^|]|%[^|]|%d %d|%d %d\n", &bookingDelete[num].bookingID, &bookingDelete[num].todayDate.todayDay, &bookingDelete[num].todayDate.todayMonth, &bookingDelete[num].todayDate.todayYear, &bookingDelete[num].bookingDate.bookingDay, &bookingDelete[num].bookingDate.bookingMonth, &bookingDelete[num].bookingDate.bookingYear, &bookingDelete[num].memberID, &bookingDelete[num].facilityID, &bookingDelete[num].paymetMethod, &bookingDelete[num].bookingTime.bookingStartHours, &bookingDelete[num].bookingTime.bookingStartMins, &bookingDelete[num].bookingTime.bookingEndHours, &bookingDelete[num].bookingTime.bookingEndMins) != -1) {
		num++;
	}
	fclose(deleteBooking);

	do {
		printEqual(172);
		printf("\n");
		printDash(172);
		printf("\n");
		printEqual(172);
		printf("\n\n");

		printf(white"6. Delete Booking Information\n\n");

		printf("Booking ID : \n");

		for (int i = 0; i < num; i++) {
			printf("%3s\n", bookingDelete[i].bookingID);
		}

		printf("\nEnter you want to delete the booking ID : ");
		rewind(stdin);
		scanf("%[^\n]", &bookingid1);
		cls();

		for (int i = 0; i < num; i++) {
			if (strcmp(bookingid1, bookingDelete[i].bookingID) == 0) {
				printf("\n\n");
				printEqual(172);
				printf(white "%55c" "This is the search booking ID result of the %s", blank, bookingDelete[i].bookingID);
				printf("\n\n\n");
				printf("%5c" "Booking ID", blank);
				printf("%8c" "Booking That Day", blank);
				printf("%8c" "Booking Date", blank);
				printf("%8c" "Booking Start Time", blank);
				printf("%8c" "Booking End Time", blank);
				printf("%8c" "Member ID", blank);
				printf("%8c" "Facility ID", blank);
				printf("%8c" "Payment Method\n", blank);
				printEqual(172);
				printf(white "\n\n%12s %15d/%d/%d %15d/%d/%d %17.2d %.2d %21.2d %.2d %19s %16s %24s\n", bookingDelete[i].bookingID, bookingDelete[i].todayDate.todayDay, bookingDelete[i].todayDate.todayMonth, bookingDelete[i].todayDate.todayYear, bookingDelete[i].bookingDate.bookingDay, bookingDelete[i].bookingDate.bookingMonth, bookingDelete[i].bookingDate.bookingYear, bookingDelete[i].bookingTime.bookingStartHours, bookingDelete[i].bookingTime.bookingStartMins, bookingDelete[i].bookingTime.bookingEndHours, bookingDelete[i].bookingTime.bookingEndMins, bookingDelete[i].memberID, bookingDelete[i].facilityID, bookingDelete[i].paymetMethod);
				printEqual(172);
				printf("\n\n");
				found++;

				printf(white "\n\nConfirm to delete this booking ? (Y or N) : ");
				rewind(stdin);
				scanf("%c", &confirm);
				while (confirm != 'Y' && confirm != 'N') {
					printf("\nInvalid input. \nPlease enter again (Y / N) : ");
					rewind(stdin);
					scanf("%c", &confirm);
				}


				if (confirm == 'Y') {
					for (int i = 0; i < num; i++) {
						if (strcmp(bookingid1, bookingDelete[i].bookingID) == 0) {
							temp = i;
							for (int b = i; b < num; b++, i++) {
								bookingDelete[i] = bookingDelete[i + 1];
							}
							num--;
							i = temp - 1;
						}
					}
				}

				else
					printf("\nNo booking record delete.\n");
			}
		}

		if (found == 0) {
			printf("\nInvalid data\n");
		}

		printf(white "\n<< Total record is %d >>\n", num);

		printf("\nDo you want to delete another booking record? (Y / N) : ");
		rewind(stdin);
		scanf("%c", &delbook);

		while (delbook != 'Y' && delbook != 'N') {
			printf("\nInvalid input. \nPlease enter again (Y / N) : ");
			rewind(stdin);
			scanf("%c", &delbook);
		}

		cls();
	} while (delbook == 'Y' || delbook != 'N');

	FILE* deleteBookingWrite;
	deleteBookingWrite = fopen("Booking_File.txt", "w");
	if (deleteBookingWrite == NULL) {
		printf("Error cannot find the file");
		exit(-1);
	}

	for (int i = 0; i < num; i++) {
		fprintf(deleteBookingWrite, "%s|%d/%d/%d|%d/%d/%d|%s|%s|%s|%.2d %.2d|%.2d %.2d\n", bookingDelete[i].bookingID, bookingDelete[i].todayDate.todayDay, bookingDelete[i].todayDate.todayMonth, bookingDelete[i].todayDate.todayYear, bookingDelete[i].bookingDate.bookingDay, bookingDelete[i].bookingDate.bookingMonth, bookingDelete[i].bookingDate.bookingYear, bookingDelete[i].memberID, bookingDelete[i].facilityID, bookingDelete[i].paymetMethod, bookingDelete[i].bookingTime.bookingStartHours, bookingDelete[i].bookingTime.bookingStartMins, bookingDelete[i].bookingTime.bookingEndHours, bookingDelete[i].bookingTime.bookingEndMins);

	}

	fclose(deleteBookingWrite);
	system("pause");
	cls();
}

void paymentMethodName() {
	printf("Our Payment method : \n");
	printf("1. Maybank\n");
	printf("2. Public Bank\n");
	printf("3. CIMB Bank\n");
	printf("4. Touch 'n Go\n");
}

void printEqual(int parameter) {
	for (int i = 0; i < parameter; i++)
		printf(cyan "=");
}

void printDash(int parameter) {
	for (int i = 0; i < parameter; i++)
		printf(cyan "-");
}

void cls(void) {
	system("cls");
}