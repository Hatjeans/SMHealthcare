//
//  cal_healthdata.h
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//  수정할 필요 없음.  
//

#ifndef cal_healthdata_h
#define cal_healthdata_h

#include "cal_exercise.h"
#include "cal_diets.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise
#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food
#define DAILY_CALORIE_GOAL 2000  	// Recommended daily calorie intake for adult women
#define BASAL_METABOLIC_RATE 1300 	// Basal metabolic rate of adult women




// 
//
// HealthData my_health_data_history[MAX_HEALTH]; 구조체 정의를 위해 불가피하게 수정 
#define MAX_HEALTH 100
#define MAX_HEALTH_LEN 100


// Project 응용 - 구조체화 1. 구조체 형식 정의 - Typedef struct 문법 활용  
// Typedef를 이용하여 사용자가 새로운 자료형을 정의 typedef (원래 자료형) (새로운 자료형 이름); 
// 현재 자료형 struct, 새로운 자료형 이름 Exercise -> 앞으로 Exercise만 써도 해당 구조체를 사용할 수 있음  
// 새로운 자료형 Exercise, Diet, HealthData 쓰는 방법 : Diet diet[]배열과 diet_count를 함께 적용하면 된다. ex)for(i=0;i<diet_count;i++) printf("%s", diet[i])등  

//-----------------------------------------------------------------------------------------------------
// 구조체 복습
// 구조체 포인터를 이용하여 구조체의 멤버 (구성요소)에 접근할 수 있다. 
// ex)  struct student *strPtr; 구조체 포인터 선언
//		struct student s = {10, "각자 이름", 4.3}
//		strPtr = &s;								 // 포인터를 구조체 s에 배정  
//		printf("ID : %d %d \n", s.ID, strPtr -> ID); //.연산자와 -> 연산자를 사용하여 각 멤버에 접근할 수 있다.  

//----------------------------------------------------------------------------------------------------- 
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
//-----------------------------------------------------------------------------------------------------

// Project 응용 - 구조체화 2. 구조체 변수 선언 - 앞에서 정의한 구조체 자료형을 활용하여 구조체 변수 선언   

// excercise definition for linked list
typedef struct {
    char exercise_name[MAX_EXERCISE_NAME_LEN];	// the name of the exercise
    int calories_burned_per_minute;   			// calory burned per minute
} Exercise;



// diet definition for linked list
typedef struct {
    char food_name[MAX_FOOD_NAME_LEN]; 	// the name of food
    int calories_intake;   				// calorie intake
} Diet;
 


// health data  definition for linked list
typedef struct {
Exercise exercises[MAX_EXERCISES];  // exercise history 
// Typedef를 이용하여 exercises 구조체를 정의해서 주셨다. 
//exercise_count변수를 이용해서  운동을 했을때마다 순서가 매겨지는 것을 이용하면 좋을 것 같다.  
 
    Diet diet[MAX_DIETS];                // diet history
// Typedef를 이용하여 Diet 구조체를 정의해서 주셨다. 
//diet_count변수를 이용해서  운동을 했을때마다 순서가 매겨지는 것을 이용하면 좋을 것 같다.  
    
    int exercise_count;                  // number of exercises
    int diet_count;                      // number of diets
    int total_calories_burned;           // total calories burned
    int total_calories_intake;           // total calories intake
} HealthData; 



extern HealthData my_health_data_history;


void saveData(const char* HEALTHFILEPATH,const HealthData* health_data);
void printHealthData(const HealthData* health_data);


#endif /* cal_diets_h */
