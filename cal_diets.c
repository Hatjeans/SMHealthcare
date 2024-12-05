//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/



// Project 응용 - 구조체화 3. 기존함수의 수정  
// 								 loadDiets(const char* DIETFILEPATH) 이용하기 


void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    
	//파일을 불러올 수 있게 코드를 짜야함 
    // * 참고할 실습 : week 11 [실습3], [실습6] 
    
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while () {
    	
        if (diet_list_size >= MAX_DIETS){ 

		
// Project 응용 - 구조체화 4. 파일로 부터 읽은 내용을 구조체 멤버 값에 대입
//								- 파일로 부터 데이터 읽는 함수 (fscanf, fgetc, fgets) 활용
//								- 구조체 멤버 접근 방법 활용   



        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    
    
	// ToCode: to enter the diet to be chosen with exit option
    

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data


}

