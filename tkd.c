#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG 0 // change to 1 for debugging
#define GR 0 // Change program language: 1 for Greek 0 for English
/* TKD v1.1*/

typedef struct node{
	int ID;
	char LastName[20];
	char FirstName[20];
	int apousies;
	struct node *next;
}Node;

Node * Node_ptr;
Node * List_ptr;

void MainMenu();
void AddStudent();
void Parousies();
void Create_List(Node** List, int poscounter, char* LastName, char* FirstName, int apousies);
void PrintList(Node* List);
void UpdateFile(Node* ListPointer,Node * AbsentList,int count, int SelectedClass);
void Help();

int main(void)
{

 		
 	puts("********************************************************************************");
 	puts("                         PROGRAM TKDv1.1 START");
 	puts("\n********************************************************************************");

	Help();
	
	while(1)
		MainMenu();
 	
  	puts("\n********************************************************************************");
 	puts("                              PROGRAM END");
 	puts("\n********************************************************************************");

}


void MainMenu()
{	
	puts("--------------------------------------------------------------------------------");
	puts(">>>>>>>>>>>>>>>>>>>>>       MAIN   MENU        ");
	puts("--------------------------------------------------------------------------------");
	if(GR)
	{
		puts(">>>>Eisagete katallilo noumero gia epilogi");
 		puts("--------------------------------------------------------------------------------");
 		puts("\n   1)Prosthiki Mathiti");
 		puts("\n   2)Parousies");
 		puts("\n   3)Erxetai syntoma");
 		puts("\n   4)Exodos\n");
  		puts("--------------------------------------------------------------------------------");
	}
 	else
 	{
 		puts(">>>>Type the number of your selected option");
 		puts("--------------------------------------------------------------------------------");
 		puts("\n   1)Add Student");
 		puts("\n   2)Attendances");
 		puts("\n   3)Coming Soon");
 		puts("\n   4)Exit\n");
  		puts("--------------------------------------------------------------------------------");
	}
	 	
 	int Select = 0;
 	
 	if(GR)
 		printf("Epilogi:");
 	else
 		printf("Option:");
 	
	if(!scanf("%d", &Select))
	{
		puts("\n");
		if(GR)
			puts("Sfalma eisodou, termatismos programmatos.");
		else
			puts("Bad input, program exits.");
		puts("\n********************************************************************************");
 		puts("                              PROGRAM END");
 		puts("\n********************************************************************************");
 		exit(0);
	}
		
 	
 	switch(Select)
 	{
 		case 1:
 			AddStudent();
 			break;
 		
 		case 2:
 			Parousies();
 			return;
 			break;
 		
 		case 3:
 			break;
 		case 4:
 			puts("\n********************************************************************************");
 			puts("                              PROGRAM END");
 			puts("\n********************************************************************************");
 			exit(0);
 			break;
 			
 		default:
 			if(GR)
 				puts("\n>>>>Mi egkyro noumero. Prospathiste pali.");
			else 
				puts("\n>>>>Bad input. Please try again.");
 			break;
	 }
 	
}

void AddStudent()
{
	puts("--------------------------------------------------------------------------------");
	puts(">>>>>>>>>>>>>>>>>>>>>       ADD STUDENT       ");
	puts("--------------------------------------------------------------------------------");
	int ID= 1;
	int Class;
	char LastName[20];
	char FirstName[20];
	FILE *fp;
	fp = fopen("students.txt", "a");
	
	puts("\n------------------------------------------");
	if(GR)
		puts(">>>>Prosthiki Mathiti");
	else
		puts(">>>>Add Student");
	puts("------------------------------------------");
	if(GR)
		puts("\n>Eisagete Tmima:");	
	else
		puts("\n>Insert Class:");	
			
	if(!scanf("%d", &Class))
	{
		puts("\n");
		if(GR)
			puts("Sfalma eisodou, termatismos programmatos.");
		else
			puts("Bad input, program exits.");
		puts("\n********************************************************************************");
 		puts("                              PROGRAM END");
 		puts("\n********************************************************************************");
 		exit(0);
	}
	if(GR)
		puts("\n>Eisagete Eponymo:");
	else
		puts("\n>Insert Last Name:");
	scanf("%s", LastName);
	if(GR)
		puts("\n>Eisagete Onoma:");
	else
		puts("\n>Insert First Name:");
	scanf("%s", FirstName);
	
	

	fputs("\n",fp);
	fprintf(fp, "%d",Class);
	fputs(" ", fp);
	fputs(LastName,fp);
	fputs(" ", fp);
	fputs(FirstName,fp);
	fputs(" 0",fp);
	


	
	

	fclose(fp);
	
	puts("------------------------------------------");
	printf("\nAdded: %s %s in Class:%d\n", LastName, FirstName, Class);
	puts("------------------------------------------\n\n");

	
}


void Parousies()
{
	puts("--------------------------------------------------------------------------------");
	puts(">>>>>>>>>>>>>>>>>>>>>      PRESENT STUDENTS    ");
	puts("--------------------------------------------------------------------------------");
	int ID= 1;
	int Class;
	char LastName[20];
	char FirstName[20];
	FILE *fp;
	fp = fopen("students.txt", "a");
	
	if(GR)
	{
		puts("\n------------------------------------------");
		puts(">>>>Parousies");
		puts("------------------------------------------");
		puts("\n>Eisagete Tmima:");	
		puts("------------------------------------------");
		printf("\nTmima:");
	}
	else
	{
		puts("\n------------------------------------------");
		puts(">>>>Attendances");
		puts("------------------------------------------");
		puts("\n>Insert Class:");	
		puts("------------------------------------------");
		printf("\nClass:");
	}
	

	int scan;
	if(!scanf("%d", &scan))
	{
		
		puts("\n");
		if(GR)
			puts("Sfalma eisodou, termatismos programmatos.");
		else
			puts("Bad input, program exit");
		puts("\n********************************************************************************");
 		puts("                              PROGRAM END");
 		puts("\n********************************************************************************");
 		exit(0);
	}
	
	puts("------------------------------------------");
	char c;
	int count = 0;
	fp = fopen("students.txt", "r");
	
	for (c = getc(fp); c != EOF; c = getc(fp)) //Get file size
        if (c == '\n')
            count = count + 1;
	
	fclose(fp);

	int i=0;
	int apousies=0;
	int Poscounter=0;
	
	Node* List = NULL;
	
	fp = fopen("students.txt", "r");
	while(i<count+1)                     //Scan and create List
	{
	fscanf(fp,"%d", &Class); //Scan Class
	

	fscanf(fp,"%s", LastName); //Scan LastName
	
	
	fscanf(fp,"%s", FirstName); //Scan FirstName
	
	fscanf(fp,"%d", &apousies); //Scan apousies
	
	if(scan==Class)
	{	
		Create_List(&List, i+1, LastName, FirstName, apousies); //condition Class->  Add to List
	}

	
	
	i++;
	}
	
	
	fclose(fp);
	
	if(List==NULL)
	{
		if(GR)
			puts("Adeio tmima. Epistrofi sto menou.");
		else
			puts("Empry Class. Returning to Main Menu");
		return;
	}
	printf("ID LastName FirstName Cons.Absences\n");
	puts("------------------------------------------");
	PrintList(List);
	long int eisagwgh=0;
	

	int ChoseExit = 0;
	Node *PresentList =NULL;
	
	while(i>0 && !ChoseExit)                         // Get absent and Update file
	{
		
		puts("\n------------------------------------------");
		if(GR)
			puts(">>>>>Eisagete to ID tou parontos/ousas \n h eisagete -1 gia epistrofh sto Menu\n KAI apothikeush apousiwn. Gia akyrwsh \n kai kamia apo8hkeysh apla kleiste to programma.\nApofygete kakes eisodous gia apofygh aprosdokiths symperiforas");
		else
			puts(">>>>>Type the ID of attendee student or type -1 to return to Main Menu AND save absences. To cancel this option and not save just terminate the program.\nBad inputs also terminate but avoid them to prevent unpredictable behaviour");
		puts("------------------------------------------");
		printf("Tmima %d ID: ", scan);
		
		if(!scanf("%d", &eisagwgh))
	{
		puts("\n");
		if(GR)
			puts("Sfalma eisodou, termatismos programmatos xwris apo8hkeush.");
		else
			puts("Bad input, terminating without saving.");
		puts("\n********************************************************************************");
 		puts("                              PROGRAM END");
 		puts("\n********************************************************************************");
 		exit(0);
	}
		puts("------------------------------------------");
	
		Node *ListPointer = List;
	
		Node *Previous = ListPointer;
	
		Node *temp;
		
		
	
		while(ListPointer!= NULL && !ChoseExit)
		{
		if(eisagwgh == -1)
		{
			ChoseExit = 1;	
		}
		else if(ListPointer->ID == eisagwgh && List->next == NULL)
		{		
			Create_List(&PresentList, ListPointer->ID,ListPointer->LastName,ListPointer->FirstName, ListPointer->apousies);
		
			
			
			free(List);
			List = NULL;

		}		
		else if(ListPointer->ID == eisagwgh && ListPointer == List)
		{
			Create_List(&PresentList, ListPointer->ID,ListPointer->LastName,ListPointer->FirstName, ListPointer->apousies);

			
			
			temp = ListPointer;
			
			
			List = List->next;
			ListPointer = List;
			Previous = List;
			if(temp!=NULL)
				free(temp);
			
			
		}
		else if(ListPointer->ID == eisagwgh)
		{
			Create_List(&PresentList, ListPointer->ID,ListPointer->LastName,ListPointer->FirstName, ListPointer->apousies);
			
			
			Previous->next = ListPointer->next;
			
			temp = ListPointer;
			ListPointer= ListPointer->next;
			if(temp!=NULL)
				free(temp);

		}
		else
		{
			Previous = ListPointer;
			ListPointer= ListPointer->next;
		}	
		}
		printf("ID LastName FirstName Cons.Absences\n");
		puts("------------------------------------------");
		PrintList(List);

		i--;
;

		
	}
	puts("--------------------------------------------------------------------------------");
	UpdateFile(List,PresentList ,count, scan);
	puts("--------------------------------------------------------------------------------");
	if(GR)
		printf("Telos Tmima: %d\n", scan);
	else
		printf("Done Class: %d\n", scan);

}



void Create_List(Node** List, int poscounter, char* LastName, char* FirstName, int apousies)
{
	
	Node* newnode = malloc(sizeof(Node));  //create Node
	newnode->ID = poscounter;
	strcpy(newnode->LastName, LastName);
	strcpy(newnode->FirstName, FirstName);
	newnode->apousies = apousies;
	newnode->next = NULL;
	
	if((*List)==NULL)                 //if List is Null Point List to NewNode
	{
		(*List) = newnode;                
		
	}
	else                               // Else Add NewNode to end of List
	{                                     
		
		Node* LastNode = (*List);
		while( LastNode->next != NULL )
			LastNode = LastNode->next;
		
	
		LastNode->next = newnode;
	}
	
	
	
}

void PrintList(Node* List)
{
	Node * ListPointer = List;
	while(ListPointer!=NULL)//ListPointer->next
	{
		printf("%d) %s %s %d\n\n", ListPointer->ID, ListPointer->LastName, ListPointer->FirstName, ListPointer->apousies);
		ListPointer = ListPointer->next;
	}
		
}

void UpdateFile(Node* ListPointer,Node * PresentList ,int count, int SelectedClass)
{
			FILE * fp_t1;
			FILE *fp;
			fp = fopen("students.txt", "r");
			fp_t1 = fopen("temp1.txt","w");
			int i;
			int Class;
			char LastName[20];
			char FirstName[20];
			int apousies;
			for(i=0;i<count+1;i++)   // COPY to temp1
			{
					
				fscanf(fp,"%d", &Class);
				fscanf(fp,"%s", LastName);
				fscanf(fp,"%s", FirstName);
				fscanf(fp,"%d", &apousies);
				
				if(Class!=SelectedClass)  // Copy other classes AS ARE
				{
					if(DEBUG)  //debug
						puts("Debug:Other");
						
					fprintf(fp_t1,"%d",Class);
					fputs(" ", fp_t1);
					fputs(LastName,fp_t1);
					fputs(" ", fp_t1);
					fputs(FirstName,fp_t1);
					fputs(" ",fp_t1);
					fprintf(fp_t1,"%d\n",apousies);
				}
				else if(PresentList!=NULL) // Copy Present Students
				{
					if(DEBUG) //debug
						puts("Debug:Present");
						
					fprintf(fp_t1,"%d",Class);
					fputs(" ", fp_t1);
					fputs(PresentList->LastName,fp_t1);
					fputs(" ", fp_t1);
					fputs(PresentList->FirstName,fp_t1);
					fputs(" ",fp_t1);
					fprintf(fp_t1,"%d\n",0);
					PresentList = PresentList->next;
				}
				else // Copy Absent Students
				{
					if(DEBUG) //debug
						puts("Debug:Absent");
					
					fprintf(fp_t1,"%d",Class);
					fputs(" ", fp_t1);
					fputs(ListPointer->LastName,fp_t1);
					fputs(" ", fp_t1);
					fputs(ListPointer->FirstName,fp_t1);
					fputs(" ",fp_t1);
					fprintf(fp_t1,"%d\n",(ListPointer->apousies)+1);
					if(((ListPointer->apousies)+1)>=7)
					{
						if(GR)
							printf("Mathitis/tria: %s %s apo Tmima: %d leipei %d synexomenes meres.\n\n",ListPointer->LastName, ListPointer->FirstName,SelectedClass,((ListPointer->apousies)+1) );
						else
							printf("Student: %s %s from Class: %d is absent for %d consequative days.\n\n",ListPointer->LastName, ListPointer->FirstName,SelectedClass,((ListPointer->apousies)+1) );
					}
						
					ListPointer = ListPointer->next;
				}
			
			}
			fclose(fp);
			fclose(fp_t1);
	
			fp = fopen("students.txt", "w"); //copy back to students.txt
			fp_t1 = fopen("temp1.txt","r");
	
				fscanf(fp_t1,"%d", &Class); //first line
				fscanf(fp_t1,"%s", LastName);
				fscanf(fp_t1,"%s", FirstName);
				fscanf(fp_t1,"%d", &apousies);
		
				fprintf(fp,"%d",Class);
				fputs(" ", fp);
				fputs(LastName,fp);
				fputs(" ", fp);
				fputs(FirstName,fp);
				fputs(" ",fp);
				fprintf(fp,"%d",apousies);
			for(i=0;i<count;i++)  // rest lines
			{
				fscanf(fp_t1,"%d", &Class);
				fscanf(fp_t1,"%s", LastName);
				fscanf(fp_t1,"%s", FirstName);
				fscanf(fp_t1,"%d", &apousies);
		
				fprintf(fp,"\n%d",Class);
				fputs(" ", fp);
				fputs(LastName,fp);
				fputs(" ", fp);
				fputs(FirstName,fp);
				fputs(" ",fp);
				fprintf(fp,"%d",apousies);
			}
			fclose(fp);
			fclose(fp_t1);
			remove("temp1.txt");
}



void Help()
{
	FILE *fp ;
 	char B[10000] ;
 	if(GR)
 		fp = fopen( "READMEGR.txt", "rb" ) ;
 	else
 		fp = fopen( "READMEEN.txt", "rb" ) ;
 	while(fread(B,1,10000,fp))
 	;
 	fclose(fp);
 	puts(B);
	
}





