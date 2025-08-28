#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXCALL 100
//Helpers ----------------------------------------------------------------
bool static is_in_range(int start, int end, int number_checking)
{
	if (number_checking >= start && number_checking <= end) return true;
	return false;
}
int static get_max(int arr[], int size)
{
	if (arr == NULL) return -1;

	int max = arr[0];
	for (size_t i = 0; i < size; i++)
		if (max < arr[i]) max = arr[i];

	return max;
}
int static get_min(int arr[], int size)
{
	if (arr == NULL) return -1;

	int min = arr[0];
	for (size_t i = 0; i < size; i++)
		if (min > arr[i]) min = arr[i];

	return min;
}
int static get_number_from_user(char data_name[])
{
	int value = 0;
	printf("Please Enter The %s: ", data_name);
	scanf_s("%i", &value);
	return value;
}
//Helpers ----------------------------------------------------------------


int* get_specific_subject_for_specific_student_from_user(int two_dimintion_arr[][MAXCALL], int dimintion1_size, int dimintion2_size);
void print_menu_student_options();
void fill_arr(int two_dimition_arr[][MAXCALL], int d1_size, int d2_size, char d1_name[], char d2_name[]);
int* edit_subject(int two_dimition_arr[][MAXCALL], int d1_position, int d2_position, char d1_name[], char d2_name[]);
void display_specific(int two_dimition_arr[][MAXCALL], int d1_position, int d2_size, char d1_name[], char d2_name[]);
void display_all(int two_dimition_arr[][MAXCALL], int d1_size, int d2_size, char d1_name[], char d2_name[]);

int main()
{
	/// int subjects[5] = { 20,50,30,40,35 };
	/// printf("The Max Subject is %i \n", get_max(subjects, 5));
	/// printf("The Min Subject is %i \n", get_min(subjects, 5));

	///-------------------------------------------------------------------

	char c;
	do
	{
		print_menu_student_options();

		int operation_number = 0;
		scanf_s("%i", &operation_number);

		int students_subjects[3][5];
		int* ptr_temp;
		int number_temp;
		switch (operation_number)
		{
		case 1:
			system("cls");
			fill_arr(students_subjects, 3, 5, "Student", "Subject");
			break;
		case 2:
			system("cls");
			ptr_temp = get_specific_subject_for_specific_student_from_user(students_subjects, 3, 5);
			edit_subject(students_subjects, ptr_temp[0], ptr_temp[1], "Student", "Subject");
			break;
		case 3:
			system("cls");
			number_temp = get_number_from_user("Number of Student you want to display his Subjects");
			display_specific(students_subjects, number_temp, 5, "Student", "Subject");
			break;
		case 4:
			system("cls");
			display_all(students_subjects, 3, 5, "Student", "Subject");
			break;
		case 5:
			return 0;
		default:
			system("cls");
			printf("Your INPUT Was NOT VALID SO Try AGAIN");
		}

		printf("\n\nTo show menu again press any key ... ");
		while ((getchar()) != '\n'); // flush leftover newline
		c = getchar(); //

		//scanf_s(" %c", &c, 1);   // note the SPACE before %c -> skips \n, \t, etc.
	} while ((int)c != 27);
}

void print_menu_student_options()
{
	system("cls");
	printf("Please Enter The Number From the Menu: \n");

	printf("1. Add All\n");
	printf("2. Edit\n");
	printf("3. Display\n");
	printf("4. Display All\n");
	printf("5. Exit\n");
}

int* get_specific_subject_for_specific_student_from_user(int arr[][MAXCALL], int d1, int d2)
{
	int student_index = -1;
	int subject_index = -1;
	bool rlt_1 = false, rlt_2 = rlt_1;

	do
	{
		printf("Please Enter The Student Id `1 based`: ");
		scanf_s("%i", &student_index);

		printf("Please Enter The Subject Id `1 based`: ");
		scanf_s("%i", &subject_index);

		rlt_1 = is_in_range(0, d1, student_index);
		rlt_2 = is_in_range(0, d2, subject_index);

		if (!(rlt_1 || rlt_2))
		{
			printf("Not Valid Answer Please Try Again\n");
			system("cls");
		}
	} while (!(rlt_1 && rlt_2));

	int static result[2];
	result[0] = student_index - 1;
	result[1] = subject_index - 1;
	return result;
	//return arr[student_index, subject_index];
}

void fill_arr(int two_dimition_arr[][MAXCALL], int d1_size, int d2_size, char d1_name[], char d2_name[])
{
	if (d2_size > MAXCALL)
	{
		printf("The size of dimension 2 is out of range\n");
		exit(1);
	}
	for (size_t i = 0; i < d1_size; i++)
	{
		for (size_t j = 0; j < d2_size; j++)
		{
			printf("Please Enter %s %i of %s %i: ", d1_name, i + 1, d2_name, j + 1);
			scanf_s("%i", &two_dimition_arr[i][j]);
		}
	}
}

int* edit_subject(int two_dimition_arr[][MAXCALL], int d1_position, int d2_position, char d1_name[], char d2_name[])
{
	//printf("Please Enter %s of %s: ", d1_name, d2_name);
	printf("The %s %i in %s %i is: %i\n", d1_name, d1_position, d2_name, d2_position, two_dimition_arr[d1_position][d2_position]);
	printf("Enter the NEW value: ");
	scanf_s("%i", &two_dimition_arr[d1_position][d2_position]);

	system("cls");
	printf("EDINTING SUCCESS \n");
	printf("The %s %i in %s %i is: %i\n", d1_name, d1_position + 1, d2_name, d2_position + 1, two_dimition_arr[d1_position][d2_position]);

	return &two_dimition_arr[d1_position][d2_position];
}

void display_specific(int two_dimition_arr[][MAXCALL], int d1_position, int d2_size, char d1_name[], char d2_name[])
{
	if (d2_size > MAXCALL)
	{
		printf("The size of dimension 2 is out of range\n");
		exit(1);
	}
	for (size_t i = 0; i < d2_size; i++)
		printf("The Value to %s %i in %s %i is: %i\n", d1_name, d1_position + 1 , d2_name, i + 1, two_dimition_arr[d1_position][i]);
	//           the value to student 1 in Subje
}

void display_all(int two_dimition_arr[][MAXCALL], int d1_size, int d2_size, char d1_name[], char d2_name[])
{
	if (d2_size > MAXCALL)
	{
		printf("The size of dimension 2 is out of range\n");
		exit(1);
	}
	for (size_t i = 0; i < d1_size; i++)
	{
		for (size_t j = 0; j < d2_size; j++)
			printf("The Value to %s %i in %s %i is: %i\n", d1_name, i + 1, d2_name, j + 1, two_dimition_arr[i][j]);
	}
}