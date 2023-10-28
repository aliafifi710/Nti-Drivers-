/*
 * Name: Ali Muhammed Ali
 * Group: 7
 *
 *Discrebtion: school database using doubly linkde list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Config.h"
#include "school.h"

#include "stdint.h"


void Start_App() {


	setvbuf(stdout, NULL, _IONBF, 0);
	printf("======Welcome To Nti Student Data Base System ======\n");
	List_t studentList;
	ErrorState_t result = List_init(&studentList);

	if (result == SUCCESS) {
		printf("List initialized successfully.\n");

		while (1) {
			int choice;

			printf("\nMenu:\n");
			printf("1. Add a student\n");
			printf("2. Search for a student\n");
			printf("3. Delete a student\n");
			printf("4. Edit student information\n");
			printf("5. Update student scores\n");
			printf("6. Print the list\n");
			printf("7. Get list size\n");
			printf("8. Exit\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);


			ListEntry_t student;
			u8 searchID;
			u8 deleteID;
			u8 updateID;
			u8 editID;

			u32 size;
			switch (choice) {
			//               case 1:
				// Add a student
			case 1:
				printf("Enter student information:\n");

				printf("ID: ");
				scanf("%hhu", &student.ID);

				printf("Name: \n");
				scanf("%s", student.Name);  // Assuming no spaces in the name

				printf("Age: \n");
				scanf("%hhu", &student.age);

				printf("Phone: \n");
				scanf("%u", &student.data.phone);

				printf("Address: \n");
				scanf("%s", student.data.address);  // Assuming no spaces in the address

				printf("Math Degree: \n");
				scanf("%hhu", &student.degrees.math_deg);

				printf("English Degree: \n");
				scanf("%hhu", &student.degrees.english_deg);

				printf("Arabic Degree: \n");
				scanf("%hhu", &student.degrees.arabic_deg);

				ErrorState_t insertResult = List_insertStudent(&studentList, &student);

				if (insertResult == SUCCESS) {
					printf("Student added successfully.\n");
				} else {
					printf("Error adding the student.\n");
				}
				break;

			case 2:
				// Search for a student
				printf("Enter the ID to search for: ");
				scanf("%hhu", &searchID);
				ListNode_t* foundStudent;
				if (List_searchStudent(&studentList, searchID, &foundStudent) == SUCCESS) {
					// Print the found student
					printf("Student found: ID=%d, Name=%s\n", foundStudent->entry.ID, foundStudent->entry.Name);
				} else {
					printf("Student not found.\n");
				}
				break;
			case 3:
				// Delete a student
				printf("Enter the ID to delete: ");
				scanf("%hhu", &deleteID);
				if (List_deleteStudent(&studentList, deleteID) == SUCCESS) {
					printf("Student deleted.\n");
				} else {
					printf("Student not found.\n");
				}
				break;
			case 4:
				// Edit student information
//				printf("Enter the ID to edit: ");
//				scanf("%hhu", &editID);
			    editStudent(&studentList);

				// Implement the logic to edit the student's information
				break;
//			case 5:
//				// Update student scores
//				printf("Enter the ID to update scores: ");
//				scanf("%hhu", &updateID);
//				Subject_t newScores;
//				List_updateScore(&studentList, updateID, newScores) ;
//				// Implement the logic to update the student's scores

			case 5:
			    // Update student scores
			    printf("Enter the ID of the student to update scores: ");
			    scanf("%hhu", &updateID);

			    Subject_t newScores;
			    printf("Enter new math degree: ");
			    scanf("%hhu", &newScores.math_deg);
			    printf("Enter new English degree: ");
			    scanf("%hhu", &newScores.english_deg);
			    printf("Enter new Arabic degree: ");
			    scanf("%hhu", &newScores.arabic_deg);

			    ErrorState_t updateResult = List_updateScore(&studentList, updateID, newScores);

			    if (updateResult == SUCCESS) {
			        printf("Scores updated successfully.\n");
			    } else {
			        printf("Student not found.\n");
			    }
			    break;

				break;
			case 6:
				// Print the list
				List_printList(&studentList);
				break;
			case 7:
				// Get list size

				if (List_listSize(&studentList, &size) == SUCCESS) {
					printf("List size: %u\n", size);
				} else {
					printf("Error getting list size.\n");
				}
				break;
			case 8:
				// Exit the program
				List_freeList(&studentList);
				printf("Exiting the program.\n");
				exit(0);
			default:
				printf("Invalid choice. Please select a valid option.\n");
			}
		}
	} else {
		printf("Error initializing the list.\n");
	}

}
