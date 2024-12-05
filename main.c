//
//  main.c
//  Calorie Diary
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

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"



//[코드작성] 1.프로그램 시작과 함께 exercise.txt, diet.txt로부터 운동관련 정보를 읽어와 exercise_list[], diet_list[] 라는 database 배열에 저장
//[코드작성] 2. choice가 1일때 exercise_list를 출력 



static int choice;

int main() {
	
	int i;
	
	// To initialize the health data object
    HealthData health_data = {0};
    
    
    // Tocode: to read the list of the exercises and diets
    // 프로그램 시작과 함께 'diets.txt'파일과 'exercise.txt'로부터 식단과 운동관련 정보를 읽어와서 database에 저장함.
	// 시작과 함께 사용자가 운동/식단 선택시, 해당정보들이 출력되어야함.
	
	loadExercises(EXERCISEFILEPATH); //[코드작성] 1.프로그램 시작과 함께 exercise.txt로부터 운동관련 정보를 읽어와 exercise_list[]라는 database 배열에 저장
	loadDiets(DIETFILEPATH); //[코드작성] 1.프로그램 시작과 함께 diet.txt로부터 운동관련 정보를 읽어와 diet_list[]라는  database 배열에 저장
	
    
    // ToCode: to run the "Healthcare Management Systems" until 1. (all calories are used up) or 2. (the user wants to exit the system)
    // 시스템 종료조건 도달시, 시스템 종료 및 'health_data.txt'파일저장. 

    do {
    	if ( 0 ){ // if 조건안에 1. 모든 칼로리가 소모되었을 때를 표현 (남은 칼로리 =0) //**나중에 수정요망 
    	        // 시스템 종료조건 도달시, 시스템 종료 및 'health_data.txt'파일저장. 
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
        	
        	// 운동 옵션 선택시, 저장된 모든 운동 후보 출력(모든 정보 항목에 대해 출력) & 해당 운동을 진행할 시간 입력 가능  
        	// 운동의 후보군은 'exercise.txt' 파일로부터 읽어와서 저장하며, 아래와 같은 형식으로 저장하고 있음.
			// (사용자가 선택한 운동)*(운동시간 [min]) = (총 소모 칼로리 [kcal]) 
			
			
            case 1: 
            
				inputExercise(health_data);
            	saveData(HEALTHFILEPATH, &health_data);
            	
                break;
            
            
            // 식사 옵션 선택시, 저장된 모든 식단  후보 출력(모든 정보 항목에 대해 출력)
			// 식단의 후보군은 'diets.txt' 파일로부터 읽어와서 저장하며, 아래와 같은 형식으로 저장하고있음. 
			// (식단) (해당 식단 섭취 시 얻게되는 kcal)
			// + 건강한 칼로리 섭취를 위해, 하루에 3끼를 먹음
			// +일일 권장 섭취 칼로리는 2000kcal. 
			 
            case 2:
            	

				 
            
            	
                break;
                
                
            //'Show logged information'옵션 선택시, 현재까지 진행한 식사와 운동을 기준으로 아래와 같이 출력
			// [History of Exercise] 현재까지 진행한 운동과 해당 운동을 통해 소모된 칼로리 출력
			// [History of Diet] 현재까지 먹은 식사 종류와 해당 식사를 통해 섭취한 칼로리 출력
			// [Total Calories] 기초대사량(고정,1300kacl), 현재까지 소모된 칼로리, 현재까지 섭취된 칼로리, 남은칼로리 (섭취-기초대사량-소모)출력 
			// 사용자에게 추천사항 제공 
			// 남은 칼로리 0 : "You have consumed all your calories for today"
			// 					시스템 종료
			// 남은 칼로리<0 : "[Warning] Too rew calories!" 
			//					1. 섭취 칼로리가 일일 권장 칼로리에 도달한 경우 "Your total Calorie intake for today has reached your goal!"
			//					2. 섭취 칼로리가 일일 권장 칼로리보다 적은 경우 "Your total calorie intake for today has not reached your goal, remember to eat more!!"
			//					3. 섭취 칼로리가 일일 권장 칼로리보다 많은 경우 "You have eaten more calories than planned today, but you have exercised too much!!"
			// 남은 칼로리>0 : "Please exercise for your health"
			//					1. 섭취 칼로리가 일일 권장 칼로리에 도달한 경우 "Your total Calorie intake for today has reached your goal!"
			//					2. 섭취 칼로리가 일일 권장 칼로리보다 적은 경우 "Your total Calorie intake for today has not reached your goal, remeber to eat more!!"
            case 3:
            	
                break;
                
                
                
            // 시스템 종료조건 도달시, 시스템 종료 및 'health_data.txt'파일저장. 
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while ( 1 );

    return 0;
}

