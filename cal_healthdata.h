//
//  cal_healthdata.h
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//  ������ �ʿ� ����.  
//

#ifndef cal_healthdata_h
#define cal_healthdata_h

#include "cal_exercise.h"
#include "cal_diets.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise
#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food
#define DAILY_CALORIE_GOAL 2000  	// Recommended daily calorie intake for adult women
#define BASAL_METABOLIC_RATE 1300 	// Basal metabolic rate of adult women




// 
//
// HealthData my_health_data_history[MAX_HEALTH]; ����ü ���Ǹ� ���� �Ұ����ϰ� ���� 
#define MAX_HEALTH 100
#define MAX_HEALTH_LEN 100


// Project ���� - ����üȭ 1. ����ü ���� ���� - Typedef struct ���� Ȱ��  
// Typedef�� �̿��Ͽ� ����ڰ� ���ο� �ڷ����� ���� typedef (���� �ڷ���) (���ο� �ڷ��� �̸�); 
// ���� �ڷ��� struct, ���ο� �ڷ��� �̸� Exercise -> ������ Exercise�� �ᵵ �ش� ����ü�� ����� �� ����  
// ���ο� �ڷ��� Exercise, Diet, HealthData ���� ��� : Diet diet[]�迭�� diet_count�� �Բ� �����ϸ� �ȴ�. ex)for(i=0;i<diet_count;i++) printf("%s", diet[i])��  

//-----------------------------------------------------------------------------------------------------
// ����ü ����
// ����ü �����͸� �̿��Ͽ� ����ü�� ��� (�������)�� ������ �� �ִ�. 
// ex)  struct student *strPtr; ����ü ������ ����
//		struct student s = {10, "���� �̸�", 4.3}
//		strPtr = &s;								 // �����͸� ����ü s�� ����  
//		printf("ID : %d %d \n", s.ID, strPtr -> ID); //.�����ڿ� -> �����ڸ� ����Ͽ� �� ����� ������ �� �ִ�.  

//----------------------------------------------------------------------------------------------------- 
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
//-----------------------------------------------------------------------------------------------------

// Project ���� - ����üȭ 2. ����ü ���� ���� - �տ��� ������ ����ü �ڷ����� Ȱ���Ͽ� ����ü ���� ����   

// excercise definition for linked list
typedef struct {
    char exercise_name[MAX_EXERCISE_NAME_LEN];	// the name of the exercise
    int calories_burned_per_minute;   			// calory burned per minute
} Exercise;



// diet definition for linked list
typedef struct {
    char food_name[MAX_FOOD_NAME_LEN]; 	// the name of food
    int calories_intake;   				// calorie intake
} Diet;
 


// health data  definition for linked list
typedef struct {
Exercise exercises[MAX_EXERCISES];  // exercise history 
// Typedef�� �̿��Ͽ� exercises ����ü�� �����ؼ� �̴ּ�. 
//exercise_count������ �̿��ؼ�  ��� ���������� ������ �Ű����� ���� �̿��ϸ� ���� �� ����.  
 
    Diet diet[MAX_DIETS];                // diet history
// Typedef�� �̿��Ͽ� Diet ����ü�� �����ؼ� �̴ּ�. 
//diet_count������ �̿��ؼ�  ��� ���������� ������ �Ű����� ���� �̿��ϸ� ���� �� ����.  
    
    int exercise_count;                  // number of exercises
    int diet_count;                      // number of diets
    int total_calories_burned;           // total calories burned
    int total_calories_intake;           // total calories intake
} HealthData; 



extern HealthData my_health_data_history;


void saveData(const char* HEALTHFILEPATH,const HealthData* health_data);
void printHealthData(const HealthData* health_data);


#endif /* cal_diets_h */
