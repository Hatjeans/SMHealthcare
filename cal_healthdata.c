//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//  Developed by Haejin Lee
//


// NOTICE 
// 해당 파일과 관련한 코드작성
//[코드작성] 3. saveData함수에 변경된 exercise내용을 저장.
//[코드작성] 5. saveData함수에 변경된 diet내용을 저장 
//[코드작성] 6. saveData함수에 total calories burned과 total calories intake, the remaining calories를 계산 및 health_data.txt파일에 출력
//[코드작성] 7. show logged information 옵션 선택시, 현재까지 진행한 식사와 운동을 도스 창에 출력   
//[코드작성] 8. printHealthData() 함수에서 사용자에게 추천사항을 제공 


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

	// + 추가설명 : 변수 추가  
	int calculation_sofar_E; // + 추가설명: [코드작성] 3에서 총 소모한 칼로리를 계산하기 위한 변수  
	int calculation_sofar_D; // + 추가설명: [코드작성] 5에서 총 섭취한 칼로리를 계산하기 위한 변스  
	int remaining_calories; //  + 추가설명: [코드작성] 6에서 remaining_calories백업을 위한 변수
	
	
	
    FILE* file = fopen(HEALTHFILEPATH, "w"); 
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
		//[코드작성] 3 - saveData함수에 변경된 exercise내용을 health_data.txt파일에 백업  
    		fprintf(file, "[Exercises] \n");
    
    	//[코드작성] 3 - for문과 fprintf를 이용하여 이때까지 입력받은 exercise이름과 duration동안 소모한 총 칼로리를 health_data.txt파일에 저장
   			for(i=0;i<health_data->exercise_count;i++){
   				
    			fprintf(file, "%s",health_data->exercises[i].exercise_name);
    			//+ 추가설명: project_guide_pdf의 백업사항 [Example]처럼 출력하기 위해 작성 
    			fprintf(file, " - %d kcal \n", (health_data->exercises[i].calories_burned_per_minute)); 
    			//+ 추가설명: project_guide_pdf의 백업사항 [Example]처럼 출력하기 위해 작성  
    			
			}
	
		//[코드작성] 3 - 이때까지 소모한 총 칼로리를 fprintf를 이용하여 health_data.txt파일에 출력 
			fprintf(file,"Total calories burned - %d kcal \n",health_data->total_calories_burned);


	// ToCode: to save the chosen diet and total calories intake 
    	//[코드작성] 5 - saveData함수에 변경된 diet내용을 health_data.txt파일에 백업  
    		fprintf(file, "\n[Diets] \n");

    	//[코드작성] 5 - for문과 fprintf를 이용하여 이때까지 입력받은 diet이름과 칼로리를 health_data.txt파일에 저장
    		for(i=0;i<health_data->diet_count;i++){
    	
    			fprintf(file, "%s",health_data->diet[i].food_name);
				//+ 추가설명: project_guide_pdf의 백업사항 [Example]처럼 출력하기 위해 작성 
    			fprintf(file, " - %d kcal \n",health_data->diet[i].calories_intake);
    			//+ 추가설명: project_guide_pdf의 백업사항 [Example]처럼 출력하기 위해 작성 
		
			}

		//[코드작성] 5 - 이때까지 얻은 칼로리를 health_data.txt 파일에 저장 
			fprintf(file,"Total calories intaken - %d kcal \n",health_data->total_calories_intake);


    // ToCode: to save the total remaining calrories
    	//[코드작성] 6 - saveData함수에 변경된 total calroies 내용을 health_data.txt파일에 백업
    		fprintf(file, "\n[Total] \n");
    

    	//[코드작성] 6. saveData함수에 total calories burned과 total calories intake, the remaining calories를 계산 및 health_data.txt파일에 출력 
			fprintf(file,"Basal metabolic rate - %d kcal \n",BASAL_METABOLIC_RATE);
	
		//[코드작성] 6 - 남은 칼로리 (섭취 칼로리 - 기초 대사량 - 소모 칼로리) 계산 
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


//[코드작성] 7. show logged information 옵션 선택시, 현재까지 진행한 식사와 운동을 도스 창에 출력   
void printHealthData(const HealthData* health_data) {
	int i;
	
	//+ 추가설명 : 변수 추가  
	int remaining; //[코드작성] 7 - 남은칼로리 변수 정의 
	remaining = (health_data->total_calories_intake) - (BASAL_METABOLIC_RATE+(health_data->total_calories_burned));//[코드작성] 7 - 남은칼로리 변수 초기화 
	
	
	// ToCode: to print out the saved history of exercises
		printf("=========================== History of Exercise =======================\n");
	
    		for(i=0;i<health_data->exercise_count;i++){
    	
    			printf("Exercise : %s, ",health_data->exercises[i].exercise_name);
    			//+ 추가설명: database의 exercises[]배열의 exercise_name을 출력 
    			printf("Calories burned : %d kcal \n", (health_data->exercises[i].calories_burned_per_minute)); 
    			//+ 추가설명: database의 exercises[]배열의 duration동안 소모한 칼로리를 출력 
    
			}	
  
    	printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    	printf("============================= History of Diet =========================\n");

	    	for(i=0;i<health_data->diet_count;i++){
		    	
    		printf("Food : %s, ",health_data->diet[i].food_name);
    		//+ 추가설명: database의 diet[]배열의 food_name을 출력 
    		printf("Calories intake : %d kcal \n", (health_data->diet[i].calories_intake)); 
    		//+ 추가설명: database의 diet[]배열의 섭취한 칼로리를 출력 
    
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
