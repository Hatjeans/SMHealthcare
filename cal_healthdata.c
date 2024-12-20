//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//  Developed by Haejin Lee
//


// NOTICE 
// �ش� ���ϰ� ������ �ڵ��ۼ�
//[�ڵ��ۼ�] 3. saveData�Լ��� ����� exercise������ ����.
//[�ڵ��ۼ�] 5. saveData�Լ��� ����� diet������ ���� 
//[�ڵ��ۼ�] 6. saveData�Լ��� total calories burned�� total calories intake, the remaining calories�� ��� �� health_data.txt���Ͽ� ���
//[�ڵ��ۼ�] 7. show logged information �ɼ� ���ý�, ������� ������ �Ļ�� ��� ���� â�� ���   
//[�ڵ��ۼ�] 8. printHealthData() �Լ����� ����ڿ��� ��õ������ ���� 


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


void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {  
	int i;

	// + �߰����� : ���� �߰�  
	int calculation_sofar_E; // + �߰�����: [�ڵ��ۼ�] 3���� �� �Ҹ��� Į�θ��� ����ϱ� ���� ����  
	int calculation_sofar_D; // + �߰�����: [�ڵ��ۼ�] 5���� �� ������ Į�θ��� ����ϱ� ���� ����  
	int remaining_calories; //  + �߰�����: [�ڵ��ۼ�] 6���� remaining_calories����� ���� ����
	
	
	
    FILE* file = fopen(HEALTHFILEPATH, "w"); 
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
		//[�ڵ��ۼ�] 3 - saveData�Լ��� ����� exercise������ health_data.txt���Ͽ� ���  
    		fprintf(file, "[Exercises] \n");
    
    	//[�ڵ��ۼ�] 3 - for���� fprintf�� �̿��Ͽ� �̶����� �Է¹��� exercise�̸��� duration���� �Ҹ��� �� Į�θ��� health_data.txt���Ͽ� ����
   			for(i=0;i<health_data->exercise_count;i++){
   				
    			fprintf(file, "%s",health_data->exercises[i].exercise_name);
    			//+ �߰�����: project_guide_pdf�� ������� [Example]ó�� ����ϱ� ���� �ۼ� 
    			fprintf(file, " - %d kcal \n", (health_data->exercises[i].calories_burned_per_minute)); 
    			//+ �߰�����: project_guide_pdf�� ������� [Example]ó�� ����ϱ� ���� �ۼ�  
    			
			}
	
		//[�ڵ��ۼ�] 3 - �̶����� �Ҹ��� �� Į�θ��� fprintf�� �̿��Ͽ� health_data.txt���Ͽ� ��� 
			fprintf(file,"Total calories burned - %d kcal \n",health_data->total_calories_burned);


	// ToCode: to save the chosen diet and total calories intake 
    	//[�ڵ��ۼ�] 5 - saveData�Լ��� ����� diet������ health_data.txt���Ͽ� ���  
    		fprintf(file, "\n[Diets] \n");

    	//[�ڵ��ۼ�] 5 - for���� fprintf�� �̿��Ͽ� �̶����� �Է¹��� diet�̸��� Į�θ��� health_data.txt���Ͽ� ����
    		for(i=0;i<health_data->diet_count;i++){
    	
    			fprintf(file, "%s",health_data->diet[i].food_name);
				//+ �߰�����: project_guide_pdf�� ������� [Example]ó�� ����ϱ� ���� �ۼ� 
    			fprintf(file, " - %d kcal \n",health_data->diet[i].calories_intake);
    			//+ �߰�����: project_guide_pdf�� ������� [Example]ó�� ����ϱ� ���� �ۼ� 
		
			}

		//[�ڵ��ۼ�] 5 - �̶����� ���� Į�θ��� health_data.txt ���Ͽ� ���� 
			fprintf(file,"Total calories intaken - %d kcal \n",health_data->total_calories_intake);


    // ToCode: to save the total remaining calrories
    	//[�ڵ��ۼ�] 6 - saveData�Լ��� ����� total calroies ������ health_data.txt���Ͽ� ���
    		fprintf(file, "\n[Total] \n");
    

    	//[�ڵ��ۼ�] 6. saveData�Լ��� total calories burned�� total calories intake, the remaining calories�� ��� �� health_data.txt���Ͽ� ��� 
			fprintf(file,"Basal metabolic rate - %d kcal \n",BASAL_METABOLIC_RATE);
	
		//[�ڵ��ۼ�] 6 - ���� Į�θ� (���� Į�θ� - ���� ��緮 - �Ҹ� Į�θ�) ��� 
			remaining_calories = (health_data->total_calories_intake) - (BASAL_METABOLIC_RATE+(health_data->total_calories_burned));
    		fprintf(file,"The remaining calories - %d kcal \n",remaining_calories);
    
    
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


//[�ڵ��ۼ�] 7. show logged information �ɼ� ���ý�, ������� ������ �Ļ�� ��� ���� â�� ���   
void printHealthData(const HealthData* health_data) {
	int i;
	
	//+ �߰����� : ���� �߰�  
	int remaining; //[�ڵ��ۼ�] 7 - ����Į�θ� ���� ���� 
	remaining = (health_data->total_calories_intake) - (BASAL_METABOLIC_RATE+(health_data->total_calories_burned));//[�ڵ��ۼ�] 7 - ����Į�θ� ���� �ʱ�ȭ 
	
	
	// ToCode: to print out the saved history of exercises
		printf("=========================== History of Exercise =======================\n");
	
    		for(i=0;i<health_data->exercise_count;i++){
    	
    			printf("Exercise : %s, ",health_data->exercises[i].exercise_name);
    			//+ �߰�����: database�� exercises[]�迭�� exercise_name�� ��� 
    			printf("Calories burned : %d kcal \n", (health_data->exercises[i].calories_burned_per_minute)); 
    			//+ �߰�����: database�� exercises[]�迭�� duration���� �Ҹ��� Į�θ��� ��� 
    
			}	
  
    	printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    	printf("============================= History of Diet =========================\n");

	    	for(i=0;i<health_data->diet_count;i++){
		    	
    		printf("Food : %s, ",health_data->diet[i].food_name);
    		//+ �߰�����: database�� diet[]�迭�� food_name�� ��� 
    		printf("Calories intake : %d kcal \n", (health_data->diet[i].calories_intake)); 
    		//+ �߰�����: database�� diet[]�迭�� ������ Į�θ��� ��� 
    
			}

    	printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
		printf("============================== Total Calories =========================\n");
 	
			printf("Basal Metabolic Rate   : %d\n",BASAL_METABOLIC_RATE);
			printf("Total calories burned  : %d\n",(health_data->total_calories_burned));
			printf("Total calories intake  : %d\n",(health_data->total_calories_intake));
			printf("The remaining calories : %d\n",remaining);
 
 		printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    	if (remaining==0)
			printf("You have consumed all your calories for today\n");
		
		
		if (remaining<0){
		
			printf("[Warning] Too few calories! \n");
		
			if(health_data->total_calories_intake==DAILY_CALORIE_GOAL)
				printf("Your total calories intake for today has reached your goal!\n");
		
			if(health_data->total_calories_intake<DAILY_CALORIE_GOAL)
				printf("Your total calories intake for today has not reached your goal!, remember to eat more!!\n");
		
			if(health_data->total_calories_intake>DAILY_CALORIE_GOAL)
				printf("You have eaten more calories than you planned today, but you have exercised too much!\n");
		
		}	
	
		if (remaining>0){
		
			printf("Please exercise for your health! \n");
		
			if(health_data->total_calories_intake==DAILY_CALORIE_GOAL)
				printf("Your total calories intake for today has reached your goal!\n");
		
			if(health_data->total_calories_intake<DAILY_CALORIE_GOAL)
				printf("Your total calories intake for today has not reached your goal!, remember to eat more!!\n");
		
		}
	 
    
		printf("=======================================================================\n");
}
