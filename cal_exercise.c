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
static Exercise exercise_list[MAX_EXERCISES]; //[�ڵ��ۼ�] 1- �  ���� ������ ���� exercise_list[]��� database 
int exercise_list_size = 0;






/*
    description : read the information in "excercises.txt"
*/


// Project ���� - ����üȭ 3. �����Լ��� ����  
// 								  - loadExercises(const char* EXERCISEFILEPATH)  

 
void loadExercises(const char* EXERCISEFILEPATH) {
	
	
	char word[100];//[�ڵ��ۼ�] 1 - ���Ͽ��� �о�� ���ڸ� �ѱ��ھ� ��� �Ͻ����� �迭  
	int calories; //[�ڵ��ۼ�] 1 - ���Ͽ��� �о�� ���ڸ� �ѱ��ھ� ��� �Ͻ����� ����  
	int cnt=0; // [�ڵ��ۼ�] 1 - diet_list[]��� database�� ���°�� ������ �ʿ��� �ε��� ���� 
	int i;
	
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    // ��� �ĺ����� 'exercise.txt' ���Ϸκ��� �о�ͼ� �����ϸ�, �Ʒ��� ���� �������� �����ϰ� ����.
	// (����ڰ� ������ �)*(��ð� [min]) = (�� �Ҹ� Į�θ� [kcal]) 
			
    while (fscanf(file, "%s %d", word, &calories) != EOF) {
    	
        if (exercise_list_size >= MAX_EXERCISES){ 
        	break;
		}
	
		strcpy(exercise_list[cnt].exercise_name, word); //strcpy�Լ��� �̿��Ͽ� �Ͻ��� �迭�� ���� �ܾ diet_list.food_name ������ database�� ����  
		exercise_list[cnt].calories_burned_per_minute = calories; // �Ͻ��� ������ ���� Į�θ� ���� diet_list.calories_intake ������ database�� ���� 
		
		
		
		cnt++; //[�ڵ��ۼ�] 1 - exercise_name�� calories_burned_per_minute�� ����Ǿ��� ������ ī��Ʈ �� ���� 
// Project ���� - ����üȭ 4. ���Ϸ� ���� ���� ������ ����ü ��� ���� ����
//								- ���Ϸ� ���� ������ �д� �Լ� (fscanf, fgetc, fgets) Ȱ��
//								- ����ü ��� ���� ��� Ȱ��   
    }
    exercise_list_size = cnt; //[�ڵ��ۼ�] 1 - ����� ������ ������ ī���� ������ ���� ������Ʈ 
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
    
    int cnt; // ī��Ʈ�� ���� �߰�  
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
	for(i=0;i<exercise_list_size;i++)
		printf("%d : %s %d kcal per min \n",i+1,exercise_list[i].exercise_name,exercise_list[i].calories_burned_per_minute);


    // ToCode: to enter the exercise to be chosen with exit option
    //** exit option�� �Բ� �����ؾ��� 
	printf("\nEnter the option number of exercise you've done\n");
	printf("(If you want to go to the home menu, press -1)\n");
	printf(" : ");
	scanf("%d", &choice);
	
	if (choice == -1) 
		return;


    // To enter the duration of the exercise
    printf("You choose < %d : %s > \n", choice, exercise_list[choice-1].exercise_name);
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    
    printf("You burned %d kcal total", (exercise_list[choice-1].calories_burned_per_minute)*duration);
    
    
    
    // ToCode: to enter the selected exercise and total calcories burned in the health data
	my_health_data_history[cnt].total_calories_burned = (exercise_list[choice-1].calories_burned_per_minute)*duration;


	cnt++;
	


/*
Exercise exercises[MAX_EXERCISES];  // exercise history 
// Typedef�� �̿��Ͽ� exercises ����ü�� �����ؼ� �̴ּ�. 
//exercise_count������ �̿��ؼ�  ��� ���������� ������ �Ű����� ���� �̿��ϸ� ���� �� ����.  
 
    Diet diet[MAX_DIETS];                // diet history
// Typedef�� �̿��Ͽ� Diet ����ü�� �����ؼ� �̴ּ�. 
//diet_count������ �̿��ؼ�  ��� ���������� ������ �Ű����� ���� �̿��ϸ� ���� �� ����.  
    
    int exercise_count;                  // number of exercises
    int diet_count;                      // number of diets
    int total_calories_burned;   
    
    
    
    exercise_name[MAX_EXERCISE_NAME_LEN];	// the name of the exercise
    int calories_burned_per_minute
*/
}




//[�ڵ��ۼ�]1 - exercise_list�� static���� �Ǿ��־ main�Լ����� ����Ʈ�ϱⰡ ��ٷο� ���� print�ϴ� �Լ��� �߰�
void print_exercise_list(void) 
{
	int i;
	
	for(i=0;i<exercise_list_size;i++)
	printf("%s %d kcal per min \n",exercise_list[i].exercise_name,exercise_list[i].calories_burned_per_minute);
}

