//
//  cal_healthdata.h
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//  수정할 필요 없음.  
//

#define cal_healthdata_h
#define cal_healthdata_h

#include "cal_exercise.h"
#include "cal_diets.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise
#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food
#define DAILY_CALORIE_GOAL 2000  	// Recommended daily calorie intake for adult women
#define BASAL_METABOLIC_RATE 1300 	// Basal metabolic rate of adult women


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


// 구조체 복습
// 구조체 포인터를 이용하여 구조체의 멤버 (구성요소)에 접근할 수 있다. 
// ex)  struct student *strPtr; 구조체 포인터 선언
//		struct student s = {10, "각자 이름", 4.3}
//		strPtr = &s;								 // 포인터를 구조체 s에 배정  
//		printf("ID : %d %d \n", s.ID, strPtr -> ID); //.연산자와 -> 연산자를 사용하여 각 멤버에 접근할 수 있다.  


// Typedef를 이용하여 사용자가 새로운 자료형을 정의 typedef (원래 자료형) (새로운 자료형 이름); 
// 현재 자료형 struct, 새로운 자료형 이름 Exercise -> 앞으로 Exercise만 써도 해당 구조체를 사용할 수 있음  
// 새로운 자료형 Exercise, Diet, HealthData 쓰는 방법 : Diet diet[]배열과 diet_count를 함께 적용하면 된다. ex)for(i=0;i<diet_count;i++) printf("%s", diet[i])등  




void saveData(const char* HEALTHFILEPATH,const HealthData* health_data);
void printHealthData(const HealthData* health_data);


#endif /* cal_diets_h */
