//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//  Developed by Haejin Lee
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/


// Project ���� - ����üȭ 3. �����Լ��� ����  
// 								  - loadExercises(const char* EXERCISEFILEPATH)  

 
void loadExercises(const char* EXERCISEFILEPATH) {
	
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    char word[100]; // ���Ͽ��� �о�� �� ���ھ��� ���  
    
    
    
// ���� ����  

// ���� ���� 
// - ���Ͽ��� ������ �б�/ ���Ⱑ �� �� �ֵ��� �غ�
// 		- mode - �б� Ȥ�� ���� �� ���� ���⿡ ���� �ɼ� ����
// FILE *fopen(<���ϰ���̸�>,<mode>);

// ex) FILE *fp;
//     fp = fopen("c:\text.txt". "w");

// ���� �ݱ�
// - ������ ���Ͽ��� ������ �б� / ���⸦ �����ϵ��� stream�� ��������
//  fclose(<���� ������>);

// ex) FILE *fp;
//     fp = fopen("c:\text.txt". "w"); 
// fclose(fp);

// ���� ����� �Լ� 
// ���ڴ��� - ���� ������ ����� - �Է� : int fgetc(FILE *fp) , ��� : int fputc(int c, FILE *fp) 
// ���ڿ����� - ���ڿ� ������ ����� - �Է�  : char *fgets(char * str, int n, FILE *fp), ��� : int fputs(const char *s, FILE *fp)
// ����ȭ�� ����� - �������� ����� - �Է� : ��int fscanf(FILE *fp, ...), ��� : int fprintf(FILE *fp) 
    
    
    
    
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file, "%s", )) {
    	
    	
        if (exercise_list_size >= MAX_EXERCISES){ 
		
		
// Project ���� - ����üȭ 4. ���Ϸ� ���� ���� ������ ����ü ��� ���� ����
//								- ���Ϸ� ���� ������ �д� �Լ� (fscanf, fgetc, fgets) Ȱ��
//								- ����ü ��� ���� ��� Ȱ��  

//���� �о���� ���� ¥����  
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/


void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    


    // ToCode: to enter the exercise to be chosen with exit option

 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    

}
