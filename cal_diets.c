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

//[코드작성] 1.프로그램 시작과 함께 diet.txt로부터 식단관련 정보를 읽어와 diet_list[]라는 database 배열에 저장



// list of diets 
static Diet diet_list[MAX_DIETS]; //[코드작성] 1 - 식단 관련 정보를 담을 diet_list[]라는 database 
static int diet_list_size = 0;  


/*
    description : read the information in "diets.txt"
*/



// Project 응용 - 구조체화 3. 기존함수의 수정  
// 								 loadDiets(const char* DIETFILEPATH) 이용하기 


void loadDiets(const char* DIETFILEPATH) {
	
	char word[100];//[코드작성] 1 - 파일에서 읽어올 글자를 한글자씩 담는 일시적인 배열  
	int calories; //[코드작성] 1 - 파일에서 읽어올 글자를 한글자씩 담는 일시적인 변수  
	int cnt=0; // [코드작성] 1 - diet_list[]라는 database에 몇번째로 들어가는지 필요한 인덱스 개념 
	int i;
	
	
    FILE *file = fopen(DIETFILEPATH, "r"); //DIETFILEPATH == "diet.txt"
    
	//파일을 불러올 수 있게 코드를 짜야함 
    // * 참고한 실습 : week 11 [실습3], [실습6] 
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", word, &calories) != EOF) {
    	
        if (diet_list_size >= MAX_DIETS){ 
        	break;
		}
	
		strcpy(diet_list[cnt].food_name, word); //[코드작성] 1 -strcpy함수를 이용하여 일시적 배열에 담은 단어를 diet_list.food_name 구조제 database에 복사  
		diet_list[cnt].calories_intake = calories; //[코드작성] 1 -일시적 변수에 담은 칼로리 양을 diet_list.calories_intake 구조제 database에 복사 
				
		
		cnt++; //[코드작성] 1 - food_name과 calories_intake가 저장되었을 때마다 카운트 수 증가 
		
// Project 응용 - 구조체화 4. 파일로 부터 읽은 내용을 구조체 멤버 값에 대입
//								- 파일로 부터 데이터 읽는 함수 (fscanf, fgetc, fgets) 활용
//								- 구조체 멤버 접근 방법 활용   
    }
    
    diet_list_size = cnt; //[코드작성] 1 - 저장된 데이터 개수를 카운터 변수를 통해 업데이트 
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


//[코드작성]1 - diet_list가 static선언 되어있어서 main함수에서 프린트하기가 까다로움 따라서 print하는 함수를 추가
void print_diet_list(void)   
{
	int i;
	
	for(i=0;i<diet_list_size;i++)
	printf("%s %d kcal \n",diet_list[i].food_name,diet_list[i].calories_intake);
}

