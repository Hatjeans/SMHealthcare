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



//[�ڵ��ۼ�] 1. ���α׷� ���۰� �Բ� exercise.txt�κ��� ����� ������ �о�� exercise_list[]��� database �迭�� ���� *�ַ� loadExercise�Լ��� ����  
//[�ڵ��ۼ�] 2. choice�� 1�϶� exercise_list�� ��� *�ַ� inputExercise�Լ��� ����  



// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES]; //[�ڵ��ۼ�] 1- � ���� ������ ���� exercise_list[]��� database 
int exercise_list_size = 0;






/*
    description : read the information in "excercises.txt"
*/


// Project ���� - ����üȭ 3. �����Լ��� ����  
// 								  - loadExercises(const char* EXERCISEFILEPATH)  

 
 //[�ڵ��ۼ�] 1. ���α׷� ���۰� �Բ� exercise.txt�κ��� ����� ������ �о�� exercise_list[]��� database �迭�� ���� *�ַ� loadExercise�Լ��� ����  
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
	
		strcpy(exercise_list[cnt].exercise_name, word); //[�ڵ��ۼ�] 1 - strcpy�Լ��� �̿��Ͽ� �Ͻ��� �迭�� ���� �ܾ diet_list.food_name ������ database�� ����  
		exercise_list[cnt].calories_burned_per_minute = calories; //[�ڵ��ۼ�] 1 - �Ͻ��� ������ ���� Į�θ� ���� diet_list.calories_intake ������ database�� ���� 
		
		
		
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






//[�ڵ��ۼ�] 2. choice�� 1�϶� exercise_list�� ��� *�ַ� inputExercise�Լ��� ����  
void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    int calculation;//+�߰����� : �ڿ� calories_per_minute�� duration�� ���� �� Į�θ��� ������ ������ ����. total_calories�� �Ϸ������� �ٸ� ���Ͽ� ����� ������ ������ calculation���� ǥ��.  
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    
    
    //[�ڵ��ۼ�] 2 - [�ڵ��ۼ�] 1���� exercise_list[] �迭�� ������ ��׸���� �ҷ��ͼ� �����. 
    
	for(i=0;i<exercise_list_size;i++)
		printf("%d : %s %d kcal per min \n",i+1,exercise_list[i].exercise_name,exercise_list[i].calories_burned_per_minute); 
		// + �߰����� : �ε����� 1���� �����ϰԲ� �������
		 


    // ToCode: to enter the exercise to be chosen with exit option
    //** exit option�� �Բ� �����ؾ��� 

    //[�ڵ��ۼ�] 2 - ����ڰ� ����Ʈ���� ���� �Է��� �׸��� scanf�� ��� ��Ƶδ� choice ������ ���� 
	printf("\nEnter the option number of exercise you've done\n");
	printf("(If you want to go to the home menu, press -1)\n");
	printf(" : ");
	scanf("%d", &choice);
	
	//[�ڵ��ۼ�] 2 - exit option���� -1�� ������ exit�Ͽ� �ٽ� [Healthcare Management Systems] �ý��ۿ� ���ư� �� �ֵ��� ��. 
	if (choice == -1) 
		return;


    // To enter the duration of the exercise
    //[�ڵ��ۼ�] 2 - �Է��� �׸��� ������  
    printf("You choose < %d : %s > \n", choice, exercise_list[choice-1].exercise_name);
    
    //[�ڵ��ۼ�] 2 - ��� �ð��� ���� �� �ִ� duration ������ �̿��Ͽ� scanf�� �ش� ���� ����.  
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    
    //[�ڵ��ۼ�] 2 - exercis_list�� duration�� ������ ������������ �Ҹ��� �� Į�θ�(calculation)�� ����ϰ� �� ���� ����ڿ��� ������  
    calculation =  (exercise_list[choice-1].calories_burned_per_minute)*duration;
    printf("You burned %d kcal total\n", calculation);
    
    
    
    // ToCode: to enter the selected exercise and total calcories burned in the health data

	//[�ڵ��ۼ�] 2 - health_data �����Ϳ� ->�����ڸ�  ����Ͽ� database����ü�� exercise[]����� ����
	//				�̶� exercise[]�� �迭 ����� �迭�� �ε����� exercise�� �Է¹޴� Ƚ���� exercise_count�� �����. 
	//				exercise_count������ ���� healt_data �����Ϳ�  -> �����ڸ� Ȱ��! 
	// 
	//				database����ü �� exercise[]�迭�� ����� calories_burned_per_minute�� exercise_name��
	//				�׷���, �츮�� database �� exercise[]�迭�� ����ڰ� ������ ��� �̸��� �Է¹��� duration ���� �Ҹ��� �� Į�θ��� �����ؾ���
	//				��� �̸��� exercise_name����� �����ϸ� �Ǿ� ������ ���� ������,
	//				duration���� �Ҹ��� �� Į�θ��� ������ ������ �������� ����. 
	//
	//				����ü�� ���� �����ϱ� ����Ƿ� ������ ����ü����� ������ �ִ��� Ȱ���ϱ� ���ؼ�
	//				calories_burned_per_minute��� ����� �׳� duration ���� �Ҹ��� �� Į�θ��� �����ϴ� �������� �����ϱ�� ��!!!!!
	//
	  
	//(a) database �� exercise[]�迭�� ����ڰ� ������ ��� �̸��� �Է��� ������� ���� 
	strcpy(health_data->exercises[health_data->exercise_count].exercise_name,exercise_list[choice-1].exercise_name);
	//+�߰����� : strcpy(a,b) �Լ��� �̿��Ͽ� ����ڰ� ������ ��� �̸�(b)�� �����Ͽ� exercise[]�迭�� ��̸��� �Է¹޴� ����(exercise_count)�� ���� ���� 
	 
	 
	//(b) database �� exercise[]�迭�� calories_burned_per_minute�ɹ��� duration���� �Ҹ��� �� Į�θ��� �Է��� ������� ����  
	health_data->exercises[health_data->exercise_count].calories_burned_per_minute = (exercise_list[choice-1].calories_burned_per_minute)*duration;
	//+�߰����� (�º�) : ����ü ������ health_data�� -> �����ڸ� �̿��Ͽ� duration ���� �Ҹ��� �� Į�θ��� �����ϴ� ������ (�̸��� per_minute��..) calories_burned_per_minute�� ������ 
	//          (�캯) : �տ��� ���� calculation�� exercise[]�迭�� calories_burned_per_minute����� ����                              
	
	
	
	// database�� �� ����Ǿ����� Ȯ���ϱ� ���� ��ġ  
	printf("%d %s \n",	health_data->exercises[health_data->exercise_count].calories_burned_per_minute,health_data->exercises[health_data->exercise_count].exercise_name );
	
	//[�ڵ��ۼ�] 2 - �Է��� ������ ������ �÷��־�� �ϹǷ� ���� �����ڸ� ���  
	health_data->exercise_count++;
	
	// ������ �� �����ϴ��� Ȯ���ϱ� ���� ��ġ  
	printf("%d\n",health_data->exercise_count);


	


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

