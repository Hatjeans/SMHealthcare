//
//  cal_healthdata.c
//  Diets for Calorie Diary
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


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

//[�ڵ��ۼ�] 3. saveData�Լ��� ����� exercise������ ����.
//[�ڵ��ۼ�] 5. saveData�Լ��� ����� diet������ ���� 



void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
	int remaining_calories; //+ �߰�����: [�ڵ��ۼ�] 6���� remaining_calories����� ���� �Լ� 
	 
    FILE* file = fopen(HEALTHFILEPATH, "w"); // HEALTHFILEPATH == "health_data.txt"
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

	//[�ڵ��ۼ�] 3. saveData�Լ��� ����� exercise������ ����.
    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    
    //[�ڵ��ۼ�] 3- for���� fprintf�� �̿��Ͽ� �̶����� �Է¹��� exercise�̸��� duration���� �Ҹ��� �� Į�θ��� health_data.txt���Ͽ� ����
    for(i=0;i<health_data->exercise_count;i++){
    	
    	//@@fputc�ΰ� ���ñ⸦ �̿��Ͽ� �ܾ� ���  
    	fprintf(file, " - %d kcal \n",health_data->exercises[i].calories_burned_per_minute); 

	}
	
	//[�ڵ��ۼ�] 3 - �̶����� �Ҹ��� �� Į�θ��� health_data.txt ���Ͽ� ���� 
	fprintf(file,"Total calories burned - %d kcal \n",health_data->total_calories_burned);


    
    
    //[�ڵ��ۼ�] 5. saveData�Լ��� ����� diet������ ���� 
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");

    //[�ڵ��ۼ�] 5- for���� fprintf�� �̿��Ͽ� �̶����� �Է¹��� diet�̸��� Į�θ��� health_data.txt���Ͽ� ����
    for(i=0;i<health_data->diet_count;i++){
    	
    	    	//@@fputc�ΰ� ���ñ⸦ �̿��Ͽ� �ܾ� ���
    	fprintf(file, " - %d kcal \n",health_data->diet[i].calories_intake); 

	}

	//[�ڵ��ۼ�] 5 - �̶����� ���� Į�θ��� health_data.txt ���Ͽ� ���� 
	fprintf(file,"Total calories intaken - %d kcal \n",health_data->total_calories_intake);



    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    

    //[�ڵ��ۼ�] 6. saveData�Լ��� total calories burned�� total calories intake, the remaining calories�� ��� 
	fprintf(file,"Basal metabolic rate - %d kcal \n",BASAL_METABOLIC_RATE);
	//[�ڵ��ۼ�] 6 - ���� Į�θ� (���� Į�θ� - ���� ��緮 - �Ҹ� Į�θ�) ��� 
	remaining_calories =  health_data->total_calories_intake - (BASAL_METABOLIC_RATE+health_data->total_calories_burned);
    
    
    fclose(file);
    
    printf("file writing done\n");
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
  
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	 printf("=======================================================================\n");
}
