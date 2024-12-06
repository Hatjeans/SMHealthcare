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

// [코드작성] 1.프로그램 시작과 함께 diet.txt로부터 식단관련 정보를 읽어와 diet_list[]라는 database 배열에 저장
// [코드작성] 4. choice가 2일때 diet_list를 출력 


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



// [코드작성] 4. choice가 2일때 diet_list를 출력  
void inputDiet(HealthData* health_data) {
    int choice, i;
    int cnt; // + 추가설명 : 하루에 3끼를 먹는것을 체크하기 위한 cnt변수 (0~2) 
    int calculation;//+추가설명 : 뒤line@@에섭취한 개별 칼로리를 저장할 변수를 설정. total_calories로 하려했으나 다른 파일에 비슷한 변수가 존재해 calculation으로 표현.  
    int calculation_so_far;//+추가설명 : 이때까지 구한 calculation을 합산한 결과.  비슷한 변수 충돌 및 헷갈림 방지를 위해 calculation_so_far로 표현
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    
    //[코드작성] 4 - [코드작성] 1에서 diet_list[] 배열에 저장한 식단 항목들을 불러와서 출력함. 

    
	for(i=0;i<diet_list_size;i++)
	printf("%d : %s %d kcal \n", i+1, diet_list[i].food_name,diet_list[i].calories_intake);
	// + 추가설명 : 인덱스를 1부터 시작하게끔 만들었음 
    
	// ToCode: to enter the diet to be chosen with exit option
	
	//[코드작성] 2 - 사용자가 리스트들을 보고 입력한 항목을 scanf로 잠시 담아두는 choice 변수에 저장 
	printf("\nEnter the option number of food you ate\n");
	printf("(If you want to go to the home menu, press -1)\n");
	printf(" : ");
	scanf("%d", &choice);
    
    //[코드작성] 4 - exit option으로 -1을 넣으면 exit하여 다시 [Healthcare Management Systems] 시스템에 돌아갈 수 있도록 함. 
	if (choice == -1) 
		return;
	
	//[코드작성] 4 - 아침 점심 저녁 중 어떤 식사를 하였는지 보여줌 입력한 항목과 얻은 칼로리양을 보여줌  
	printf("You earned < %d : %s  %d kcal> \n", choice, diet_list[choice-1].food_name,diet_list[choice-1].calories_intake);
    

    // ToCode: to enter the selected diet in the health data
    
    //[코드작성] 4 - health_data 포인터와 ->연산자를  사용하여 database구조체의 diet[]멤버에 접근
	//				이때 diet[]는 배열 멤버로 배열의 인덱스는 diet를 입력받는 횟수인 diet_count(0~2)를 사용함. 
	//				diet_count접근을 위해 healt_data 포인터와  -> 연산자를 활용! 
	// 
	//				database구조체 내 diet[]배열의 멤버는 calories_intake와 food_name임
	//				database 속 diet[]배열에 사용자가 선택한 음식의 이름과 입력받은 음식의 칼로리를 저장해야함
	//				health_data.diet[].food_name에 섭취한 음식의 이름을 넣고, health_data.diet[].calories_intake에 입력받은 음식의 칼로리를 넣으면됨.   
	  
	//(a) database 속 diet[]배열에 사용자가 선택한 음식의 이름을 입력한 순서대로 저장 
	strcpy(health_data->diet[health_data->diet_count].food_name,diet_list[choice-1].food_name);
	//+추가설명 : strcpy(a,b) 함수를 이용하여 사용자가 선택한 음식의 이름(b)를 복사하여 diet[].food_name에 입력받는 순서(diet_count)인덱스를 가지는 방에 저장 
	 
	 
	//(b) database 속 diet[]배열의 calories_burned_per_minute맴버에 섭취한 개별 칼로리를 입력한 순서대로 저장
	calculation = diet_list[choice-1].calories_intake;
	health_data->diet[health_data->diet_count].calories_intake = calculation;
	//+추가설명 (좌변) : 구조체 포인터 health_data와 -> 연산자를 이용하여 diet[].calories_intake에 접근   
	//          (우변) : 사용자가 입력한 음식의 칼로리양을 diet[]배열의 calories_intake멤버에 저장                              
	
	
	
    // ToCode: to enter the total calories intake in the health data
    //[코드작성] 2 - health_data 포인터와 -> 연산자를 이용하여 database구조체의 total_calories_burned에 접근후 값을 업데이트 	
	health_data->total_calories_intake += calculation;// health_data database의 total calories burned in the health data에 최종 값 calculation_so_far을 업데이트 	

	
	
	
	// @@database에 잘 저장되었는지 확인하기 위한 장치  
	printf("%d %s \n",	health_data->diet[health_data->diet_count].calories_intake,health_data->diet[health_data->diet_count].food_name);
	printf("%d \n",	health_data->total_calories_intake);
	
	
	
	//[코드작성] 2 - 입력할 때마다 순서를 늘려주어야 하므로 후위 연산자를 사용  
	health_data->diet_count++;
	
	
	// @@순서가 잘 증가하는지 확인하기 위한 장치  
	printf("%d\n",health_data->diet_count);

}


