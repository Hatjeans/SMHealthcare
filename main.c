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



//[�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� exercise.txt, diet.txt�κ��� ����� ������ �о�� exercise_list[], diet_list[] ��� database �迭�� ����
//[�ڵ��ۼ�] 2. choice�� 1�϶� exercise_list�� ��� 



static int choice;

int main() {
	
	int i;
	
	// To initialize the health data object
    HealthData health_data = {0};
    
    
    // Tocode: to read the list of the exercises and diets
    // ���α׷� ���۰� �Բ� 'diets.txt'���ϰ� 'exercise.txt'�κ��� �Ĵܰ� ����� ������ �о�ͼ� database�� ������.
	// ���۰� �Բ� ����ڰ� �/�Ĵ� ���ý�, �ش��������� ��µǾ����.
	
	loadExercises(EXERCISEFILEPATH); //[�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� exercise.txt�κ��� ����� ������ �о�� exercise_list[]��� database �迭�� ����
	loadDiets(DIETFILEPATH); //[�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� diet.txt�κ��� ����� ������ �о�� diet_list[]���  database �迭�� ����
	
    
    // ToCode: to run the "Healthcare Management Systems" until 1. (all calories are used up) or 2. (the user wants to exit the system)
    // �ý��� �������� ���޽�, �ý��� ���� �� 'health_data.txt'��������. 

    do {
    	if ( 0 ){ // if ���Ǿȿ� 1. ��� Į�θ��� �Ҹ�Ǿ��� ���� ǥ�� (���� Į�θ� =0) //**���߿� ������� 
    	        // �ý��� �������� ���޽�, �ý��� ���� �� 'health_data.txt'��������. 
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
        	
        	// � �ɼ� ���ý�, ����� ��� � �ĺ� ���(��� ���� �׸� ���� ���) & �ش� ��� ������ �ð� �Է� ����  
        	// ��� �ĺ����� 'exercise.txt' ���Ϸκ��� �о�ͼ� �����ϸ�, �Ʒ��� ���� �������� �����ϰ� ����.
			// (����ڰ� ������ �)*(��ð� [min]) = (�� �Ҹ� Į�θ� [kcal]) 
			
			
            case 1: 
            
				inputExercise(health_data);
            	saveData(HEALTHFILEPATH, &health_data);
            	
                break;
            
            
            // �Ļ� �ɼ� ���ý�, ����� ��� �Ĵ�  �ĺ� ���(��� ���� �׸� ���� ���)
			// �Ĵ��� �ĺ����� 'diets.txt' ���Ϸκ��� �о�ͼ� �����ϸ�, �Ʒ��� ���� �������� �����ϰ�����. 
			// (�Ĵ�) (�ش� �Ĵ� ���� �� ��ԵǴ� kcal)
			// + �ǰ��� Į�θ� ���븦 ����, �Ϸ翡 3���� ����
			// +���� ���� ���� Į�θ��� 2000kcal. 
			 
            case 2:
            	

				 
            
            	
                break;
                
                
            //'Show logged information'�ɼ� ���ý�, ������� ������ �Ļ�� ��� �������� �Ʒ��� ���� ���
			// [History of Exercise] ������� ������ ��� �ش� ��� ���� �Ҹ�� Į�θ� ���
			// [History of Diet] ������� ���� �Ļ� ������ �ش� �Ļ縦 ���� ������ Į�θ� ���
			// [Total Calories] ���ʴ�緮(����,1300kacl), ������� �Ҹ�� Į�θ�, ������� ����� Į�θ�, ����Į�θ� (����-���ʴ�緮-�Ҹ�)��� 
			// ����ڿ��� ��õ���� ���� 
			// ���� Į�θ� 0 : "You have consumed all your calories for today"
			// 					�ý��� ����
			// ���� Į�θ�<0 : "[Warning] Too rew calories!" 
			//					1. ���� Į�θ��� ���� ���� Į�θ��� ������ ��� "Your total Calorie intake for today has reached your goal!"
			//					2. ���� Į�θ��� ���� ���� Į�θ����� ���� ��� "Your total calorie intake for today has not reached your goal, remember to eat more!!"
			//					3. ���� Į�θ��� ���� ���� Į�θ����� ���� ��� "You have eaten more calories than planned today, but you have exercised too much!!"
			// ���� Į�θ�>0 : "Please exercise for your health"
			//					1. ���� Į�θ��� ���� ���� Į�θ��� ������ ��� "Your total Calorie intake for today has reached your goal!"
			//					2. ���� Į�θ��� ���� ���� Į�θ����� ���� ��� "Your total Calorie intake for today has not reached your goal, remeber to eat more!!"
            case 3:
            	
                break;
                
                
                
            // �ý��� �������� ���޽�, �ý��� ���� �� 'health_data.txt'��������. 
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

