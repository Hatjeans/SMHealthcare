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
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/


// Project 응용 - 구조체화 3. 기존함수의 수정  
// 								  - loadExercises(const char* EXERCISEFILEPATH)  

 
void loadExercises(const char* EXERCISEFILEPATH) {
	
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    char word[100]; // 파일에서 읽어올 한 글자씩을 담는  
    
    
    
// 파일 복습  

// 파일 열기 
// - 파일에서 데이터 읽기/ 쓰기가 될 수 있도록 준비
// 		- mode - 읽기 혹은 쓰기 등 파일 열기에 대한 옵션 설정
// FILE *fopen(<파일경로이름>,<mode>);

// ex) FILE *fp;
//     fp = fopen("c:\text.txt". "w");

// 파일 닫기
// - 열었던 파일에서 데이터 읽기 / 쓰기를 종료하도록 stream을 마무리함
//  fclose(<파일 포인터>);

// ex) FILE *fp;
//     fp = fopen("c:\text.txt". "w"); 
// fclose(fp);

// 파일 입출력 함수 
// 문자단위 - 문자 단위로 입출력 - 입력 : int fgetc(FILE *fp) , 출력 : int fputc(int c, FILE *fp) 
// 문자열단위 - 문자열 단위로 입출력 - 입력  : char *fgets(char * str, int n, FILE *fp), 출력 : int fputs(const char *s, FILE *fp)
// 서식화된 입출력 - 형식지정 입출력 - 입력 : ㅑint fscanf(FILE *fp, ...), 출력 : int fprintf(FILE *fp) 
    
    
    
    
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file, "%s", )) {
    	
    	
        if (exercise_list_size >= MAX_EXERCISES){ 
		
		
// Project 응용 - 구조체화 4. 파일로 부터 읽은 내용을 구조체 멤버 값에 대입
//								- 파일로 부터 데이터 읽는 함수 (fscanf, fgetc, fgets) 활용
//								- 구조체 멤버 접근 방법 활용  

//파일 읽어오는 것을 짜야함  
        	break;
		}
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
