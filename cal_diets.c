//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//  Developed by Haejin Lee
//


// NOTICE 
// �ش� ���ϰ� ������ �ڵ��ۼ� 
// [�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� diet.txt�κ��� �Ĵܰ��� ������ �о�� diet_list[]��� database �迭�� ����
// [�ڵ��ۼ�] 4. choice�� 2�϶� diet_list�� ��� 
// [�ڵ��ۼ�] 5. saveData�Լ��� ����� diet������ ���� 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS]; //[�ڵ��ۼ�] 1 - �Ĵ� ���� ������ ���� diet_list[]��� database.
static int diet_list_size = 0;  


/*
    description : read the information in "diets.txt"
*/

// [�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� diet.txt�κ��� �Ĵܰ��� ������ �о�� diet_list[]��� database �迭�� ����
	void loadDiets(const char* DIETFILEPATH) {
	
		int i;
	
		// + �߰����� : ���� �߰�  
		char word[100];//[�ڵ��ۼ�] 1 - ���Ͽ��� �о�� ���ڸ� �ѱ��ھ� ��� �Ͻ����� �迭  
		int calories; //[�ڵ��ۼ�] 1 - ���Ͽ��� �о�� ���ڸ� �ѱ��ھ� ��� �Ͻ����� ����  
		int cnt=0; // [�ڵ��ۼ�] 1 - diet_list[]��� database�� ���°�� ������ �ʿ��� �ε��� ���� 
	
    	FILE *file = fopen(DIETFILEPATH, "r");

    	if (file == NULL) {
        	printf("There is no file for diets! \n");
        	return;
    	}

    // ToCode: to read a list of the diets from the given file
    	while (fscanf(file, "%s %d", word, &calories) != EOF) {
    	
        	if (diet_list_size >= MAX_DIETS){ 
        		break;
			}
	
			strcpy(diet_list[cnt].food_name, word); //[�ڵ��ۼ�] 1 -strcpy�Լ��� �̿��Ͽ� �Ͻ��� �迭�� ���� �ܾ diet_list.food_name ������ database�� ����  
			diet_list[cnt].calories_intake = calories; //[�ڵ��ۼ�] 1 -�Ͻ��� ������ ���� Į�θ� ���� diet_list.calories_intake ������ database�� ���� 
				
		
			cnt++; //[�ڵ��ۼ�] 1 - food_name�� calories_intake�� ����Ǿ��� ������ ī��Ʈ �� ����    
    	}
    
    	diet_list_size = cnt; //[�ڵ��ۼ�] 1 - ����� ������ ������ ī���� ������ ���� ������Ʈ 
    	
    	fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

// [�ڵ��ۼ�] 4. choice�� 2�϶� diet_list�� ���  
	void inputDiet(HealthData* health_data) {
    	int choice, i;
    
    	//+ ���� �߰�  
    	int cnt; //+�߰����� : �Ϸ翡 3���� �Դ°��� üũ�ϱ� ���� cnt���� (0~2) 
    	int calculation;//+�߰����� : ��line127�� ������ ���� Į�θ��� ������ ������ ����. total_calories�� �Ϸ������� �ٸ� ���Ͽ� ����� ������ ������ calculation���� ǥ��.  
    	int calculation_so_far;//+�߰����� : �̶����� ���� calculation�� �ջ��� ���.  ����� ���� �浹 �� �򰥸� ������ ���� calculation_so_far�� ǥ��
    
    // ToCode: to provide the options for the diets to be selected
    	printf("The list of diets:\n");
    
    	//[�ڵ��ۼ�] 4 - [�ڵ��ۼ�] 1���� diet_list[] �迭�� ������ �Ĵ� �׸���� �ҷ��ͼ� �����. 
			for(i=0;i<diet_list_size;i++)
			printf("%d : %s %d kcal \n", i+1, diet_list[i].food_name,diet_list[i].calories_intake);
			// + �߰����� : �ε����� 1���� �����ϰԲ� ������� 
    
	// ToCode: to enter the diet to be chosen with exit option
		//[�ڵ��ۼ�] 5 - ����ڰ� ����Ʈ���� ���� �Է��� �׸��� scanf�� ��� ��Ƶδ� choice ������ ���� 
			printf("\nEnter the option number of food you ate\n");
			printf("(If you want to go to the home menu, press -1)\n");
			printf(" : ");
			scanf("%d", &choice);
    
    //[�ڵ��ۼ�] 5 - exit �ɼǰ� ��ȿ���� ���� ���ڸ� ���� if�� �ۼ�  
		if(0<choice&&choice<=diet_list_size){
			//[�ڵ��ۼ�] 5 - �Է��� �׸�� ���� Į�θ����� ������  
				printf("You earned < %d : %s  %d kcal> \n", choice, diet_list[choice-1].food_name,diet_list[choice-1].calories_intake);
    

   	// ToCode: to enter the selected diet in the health data
    	//[�ڵ��ۼ�] 5 - health_data �����Ϳ� ->�����ڸ�  ����Ͽ� database����ü�� diet[]����� ����
		//				�̶� diet[]�� �迭 ����� �迭�� �ε����� diet�� �Է¹޴� Ƚ���� diet_count(0~2)�� �����. 
		//				diet_count������ ���� healt_data �����Ϳ�  -> �����ڸ� Ȱ��! 
		// 
		//				database����ü �� diet[]�迭�� ����� calories_intake�� food_name��
		//				database �� diet[]�迭�� ����ڰ� ������ ������ �̸��� �Է¹��� ������ Į�θ��� �����ؾ���
		//				health_data.diet[].food_name�� ������ ������ �̸��� �ְ�, health_data.diet[].calories_intake�� �Է¹��� ������ Į�θ��� �������.   
	  
		//(a) ���� �̸� - database �� diet[]�迭�� ����ڰ� ������ ������ �̸��� �Է��� ������� ���� 
			strcpy(health_data->diet[health_data->diet_count].food_name,diet_list[choice-1].food_name);
			//+�߰����� : strcpy(a,b) �Լ��� �̿��Ͽ� ����ڰ� ������ ������ �̸�(b)�� �����Ͽ� diet[].food_name�� �Է¹޴� ����(diet_count)�ε����� ������ �濡 ���� 
	 
	 	//(b) ����Į�θ� - database �� diet[]�迭�� calories_burned_per_minute�ɹ��� ������ ���� Į�θ��� �Է��� ������� ����
			calculation = diet_list[choice-1].calories_intake;
			health_data->diet[health_data->diet_count].calories_intake = calculation;
			//+�߰����� (�º�) : ����ü ������ health_data�� -> �����ڸ� �̿��Ͽ� diet[].calories_intake�� ����   
			//          (�캯) : ����ڰ� �Է��� ������ Į�θ����� diet[]�迭�� calories_intake����� ����                              
	
	
	
   	// ToCode: to enter the total calories intake in the health data
    	//[�ڵ��ۼ�] 5 - health_data �����Ϳ� -> �����ڸ� �̿��Ͽ� database����ü�� total_calories_burned�� ������ ���� ������Ʈ 	
			health_data->total_calories_intake += calculation;
			//+ �߰����� : health_data database�� total calories burned in the health data�� ���� �� calculation_so_far�� ������Ʈ 	
	
		//[�ڵ��ۼ�] 5 - �Է��� ������ ������ �÷��־�� �ϹǷ� ���� ���� �����ڸ� ���  
			health_data->diet_count++;
	
	}
	
	else {
		
		//[�ڵ��ۼ�] 5 - exit option���� -1�� ������ exit�Ͽ� �ٽ� [Healthcare Management Systems] �ý��ۿ� ���ư� �� �ֵ��� ��. 
			if (choice == -1) {			
				printf("Return to the [Healthcare Management Systems] \n");
				return;
			}

		//[�ڵ��ۼ�] 5 - ��ȿ���� ���� ���� �ִٴ� ���� ǥ�� 
			else
				printf("[Error] Invalid option.\n");
	
	}

}


