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


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES]; //[코드작성] 1- 
int exercise_list_size = 0;

/*
    description : read the information in "excercises.txt"
*/


// Project 응용 - 구조체화 3. 기존함수의 수정  
// 								  - loadExercises(const char* EXERCISEFILEPATH)  

 
void loadExercises(const char* EXERCISEFILEPATH) {
	
	
	
	char word[100]; // [코드작성] 1 - 파일에서 읽어올 글자를 한글자씩 담는 일시적인 캐릭터 배열  
	int calories;  // [코드작성] 1 - 파일에서 읽어올 칼로리숫자를 담는 일시적인 변수 
	
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file, "%s %d", word, &calories) != EOF) {
    	    	
        if (exercise_list_size >= MAX_EXERCISES){ 
			break;
		}
		
// Project 응용 - 구조체화 4. 파일로 부터 읽은 내용을 구조체 멤버 값에 대입
//								- 파일로 부터 데이터 읽는 함수 (fscanf, fgetc, fgets) 활용
//								- 구조체 멤버 접근 방법 활용  

//파일 읽어오는 것을 짜야함  





    }

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


void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    


    // ToCode: to enter the exercise to be chosen with exit option

 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    

}
