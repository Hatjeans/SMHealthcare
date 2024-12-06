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

//[코드작성] 3. saveData함수에 변경된 exercise내용을 저장.
//[코드작성] 5. saveData함수에 변경된 diet내용을 저장 



void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
	int remaining_calories; //+ 추가설명: [코드작성] 6에서 remaining_calories백업을 위한 함수 
	 
    FILE* file = fopen(HEALTHFILEPATH, "w"); // HEALTHFILEPATH == "health_data.txt"
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

	//[코드작성] 3. saveData함수에 변경된 exercise내용을 저장.
    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    
    //[코드작성] 3- for문과 fprintf를 이용하여 이때까지 입력받은 exercise이름과 duration동안 소모한 총 칼로리를 health_data.txt파일에 저장
    for(i=0;i<health_data->exercise_count;i++){
    	
    	//@@fputc인가 뭐시기를 이용하여 단어 출력  
    	fprintf(file, " - %d kcal \n",health_data->exercises[i].calories_burned_per_minute); 

	}
	
	//[코드작성] 3 - 이때까지 소모한 총 칼로리를 health_data.txt 파일에 저장 
	fprintf(file,"Total calories burned - %d kcal \n",health_data->total_calories_burned);


    
    
    //[코드작성] 5. saveData함수에 변경된 diet내용을 저장 
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");

    //[코드작성] 5- for문과 fprintf를 이용하여 이때까지 입력받은 diet이름과 칼로리를 health_data.txt파일에 저장
    for(i=0;i<health_data->diet_count;i++){
    	
    	    	//@@fputc인가 뭐시기를 이용하여 단어 출력
    	fprintf(file, " - %d kcal \n",health_data->diet[i].calories_intake); 

	}

	//[코드작성] 5 - 이때까지 얻은 칼로리를 health_data.txt 파일에 저장 
	fprintf(file,"Total calories intaken - %d kcal \n",health_data->total_calories_intake);



    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    

    //[코드작성] 6. saveData함수에 total calories burned과 total calories intake, the remaining calories를 계산 
	fprintf(file,"Basal metabolic rate - %d kcal \n",BASAL_METABOLIC_RATE);
	//[코드작성] 6 - 남은 칼로리 (섭취 칼로리 - 기초 대사량 - 소모 칼로리) 계산 
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
