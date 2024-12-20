//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//  Developed by Haejin Lee (2413732 ������) 
//


// NOTICE 
// �ּ��� �������� �ּ��� ���� �ּ�'[�ڵ��ۼ�] (i)'�� '+�߰�����'���� �̷�����ֽ��ϴ�. 
// ���� �ּ��� �ѱ۰� ��� ȥ��Ǿ��־� �������� �ּ��� ���а����մϴ�!

// �ٽ� ������ �κ�@@���� ǥ��
 

// �ڵ��ۼ� ����  
//[�ڵ��ۼ�]  1. ���α׷� ���۰� �Բ� exercise.txt, diet.txt�κ��� ����� ������ �о�� exercise_list[], diet_list[] ��� database �迭�� ����
//[�ڵ��ۼ�]  2. choice�� 1�϶�, exercise_list ����� ����ü �����͸� �̿��Ͽ� health_data ����ü�� �Է¹��� ������ ���
//[�ڵ��ۼ�]  3. saveData�Լ��� ����� exercise������ ����.  
//[�ڵ��ۼ�]  4. choice�� 2�϶�, diet_list ����� ����ü �����͸� �̿��Ͽ�  health_data ����ü�� �Է¹��� ������ ���  
//[�ڵ��ۼ�]  5. saveData�Լ��� ����� diet������ ���� 
//[�ڵ��ۼ�]  6. saveData�Լ��� total calories burned�� total calories intake, the remaining calories�� ���� health_data.txt ���Ͽ� ���  
//[�ڵ��ۼ�]  7. show logged information �ɼ� ���ý�, ������� ������ �Ļ�� ��� ���� â�� ���   
//[�ڵ��ۼ�]  8. printHealthData() �Լ����� ����ڿ��� ��õ������ ���� 
//[�ڵ��ۼ�]  9. �ý��� ���� ���� ����  
//[�ڵ��ۼ�] 10. ���� �Դ� �� ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	
	int i;
	
	//+ ���� �߰� 
	int flag_end=0;//[�ڵ��ۼ�] 9 - ���� ������ ���� flag ���� ����  
	int remaining;//[�ڵ��ۼ�] 9 - ���� Į�θ� ����� ���� remaining ���� ���� 
	
	// To initialize the health data object
    	HealthData health_data = {0};
    
    	//[�ڵ��ۼ�] 9 - ���� Į�θ� ����� ���� remaining ���� �ʱ�ȭ  
    		remaining = health_data.total_calories_intake - (BASAL_METABOLIC_RATE+(health_data.total_calories_burned));
    		// + �߰����� :  ���� ���ǿ� �ʱ�ȭ�� �и��� ������ health_data ����ü�� �����Ǿ�� remaining���ʱ�ȭ �� �� �ֱ� ����  
    
    
    // Tocode: to read the list of the exercises and diets
    // ���α׷� ���۰� �Բ� 'diets.txt'���ϰ� 'exercise.txt'�κ��� �Ĵܰ� ����� ������ �о�ͼ� database�� ������.
	// ���۰� �Բ� ����ڰ� �/�Ĵ� ���ý�, �ش��������� ��µǾ����.
	
		//[�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� exercise.txt�κ��� ����� ������ �о�� exercise_list[]��� database �迭�� ����
			loadExercises(EXERCISEFILEPATH); 
	
		//[�ڵ��ۼ�] 1.���α׷� ���۰� �Բ� diet.txt�κ��� ����� ������ �о�� diet_list[]���  database �迭�� ����
			loadDiets(DIETFILEPATH); 
	
    
    // ToCode: to run the "Healthcare Management Systems" until 1. (all calories are used up) or 2. (the user wants to exit the system)
    // �ý��� �������� ���޽�, �ý��� ���� �� 'health_data.txt'��������.
    do {
    	
    	//[�ڵ��ۼ�] 9 - �ý��� ���� ���� �������� �� �ý��� ���Ḧ ���� if �Լ� 
		//[�ڵ��ۼ�] 10. ���� �Դ� �� ���� 
    		if ((health_data.diet_count>=3)&&(remaining==0)) { //[�ڵ��ۼ�] 10. 3�� �̻� �Ծ����� �����ִ� Į�θ��� 0�϶� ����, (�γ��� �԰� ��Ͽ� ����Į�θ��� 0�϶� �ý����� ����Ǵ� ���� ����)  

				saveData(HEALTHFILEPATH, &health_data);//[�ڵ��ۼ�] 9 -'health_data.txt'���� ����  
				printf("=======================================================================\n");//[�ڵ��ۼ�] 9 - ����Ʈ ������ �ٹ̱�, ������ ���� ��   
    	        printf("You have consumed all your calories for today! \n");
				printf("Exit the system.\n"); //[�ڵ��ۼ�] 9 - �ý����� �������� ����ڿ��� �˷���  
    			printf("=======================================================================\n");
        	    break;//[�ڵ��ۼ�] 9 - do while �ݺ����� Ż��, �ý��� ����  
                        
			} 
			else {
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
        	
        	
            case 1: 

				inputExercise(&health_data); //[�ڵ��ۼ�] 2. choice�� 1�϶� exercise_list�� ��� �� ����ü �����͸� �̿��Ͽ� ����ü�� �Է¹��� ������ ���
				saveData(HEALTHFILEPATH, &health_data); //[�ڵ��ۼ�] 3. saveData�Լ��� ����� Exercise ������ ����.
            	
                break;
            
            
            case 2:
            	
            	inputDiet(&health_data); //[�ڵ��ۼ�] 4. choice�� 2�϶� diet_list�� ��� �� ����ü �����͸� �̿��Ͽ� ����ü�� �Է¹��� ������ ���
				saveData(HEALTHFILEPATH, &health_data); //[�ڵ��ۼ�] 5. saveData�Լ��� ����� Diet ������ ����.
                break;
                
                
			case 3:
		
            	printHealthData(&health_data); //[�ڵ��ۼ�] 7. show logged information �ɼ� ���ý�, ������� ������ �Ļ�� ��� ���� â�� ���   
                break;
            
            
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
    			saveData(HEALTHFILEPATH, &health_data);
    			flag_end=1;//[�ڵ��ۼ�] 9 - do while �ݺ��� Ż���� ���� flag_end ���� ��ȭ  
                break;
                
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
        
        
    remaining = health_data.total_calories_intake - (BASAL_METABOLIC_RATE+(health_data.total_calories_burned));//[�ڵ��ۼ�] 9 - remaining ������ ������Ʈ 
    // + �߰����� : ���� ������Ʈ ���� ���� ��� ���� Į�θ��� 0�̾ do whlie�� ù��° if���� �Ǵ����� ���� 
    
    } while (flag_end==0);//[�ڵ��ۼ�] 9 - do while �� ���ǹ��� flag_end������ �Ǵ�.  
    
    return 0;
}

