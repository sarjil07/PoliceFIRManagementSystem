#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void addRecord();
void editRecord();
void viewRecord();
void searchRecord();
void deleteRecord();
void login();
struct record
{
	char name[30];
	char id[10];
	char age[6];
	char gender[7];
	char weight[20];
	char height[20];
	char haircolour[10];
	char eyecolour[10];
	char crime[50];
	char details[100];
	char court[20];
	char act[20];
	char punishment[100];
	char address[40];
	char fir[20];
	char emergency1[30];
	char emergency2[30];
	char date[20];
	
	
}sample;

int main()
{
	login();
	int ch;
	printf("\n\n\t====================================\n");
	printf("\t   --GUJARAT POLICE DEPARTMENT--\n");
	printf("\t====================================\n");
	printf("\t   -POLICE FIR RECORD MANAGEMENT-\n");
	printf("\t====================================");


while(1)
{
	printf("\n\t\t\tMAIN MENU");
	printf("\n\t\t\t____ ____");
	printf("\n\t\t[1] ADD FIR RECORD");
	printf("\n\t\t[2] SEARCH FIR RECORD");
	printf("\n\t\t[3] EDIT FIR RECORD");
	printf("\n\t\t[4] VIEW FIR RECORD");
	printf("\n\t\t[5] DELETE FIR RECORD");
	printf("\n\t\t[6] EXIT(QUIT)");
	printf("\n\n\t\t ENTER YOUR CHOICE:");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			addRecord();
			break;
		
		case 2:
			searchRecord();
			break;
		
		case 3:
			editRecord();
			break;
		
		case 4:
			viewRecord();
			break;
		
		case 5:
			deleteRecord();
			break;
			
		case 6:
			system("cls");
			printf("\n\t\t\tTHANKS FOR USING OUR MANAGEMENT SYSTEM");
			printf("\n\t\t\tSEVA SURAKSHA SHANTI");
			printf("\n\t\t\t____ ________ ______");
			getch();
			exit(0);
			
		default:
			printf("\nENTER A VALID CHOICE FROM 1 TO 6");
			printf("\nPRESS ANY KEY TO TRY AGAIN");
			getch();
			break;
		}
		system("cls");
	}
	return 0;
}
void addRecord()
{
	system("cls");
	FILE *fp;
	char another='Y';
	char id[10];
	char filename[40];
	int choice;
	printf("\n\n\t\t====================================\n");
	printf("\n\t\t\t ADD FIR RECORDS");
	printf("\n\n\t\t====================================\n");
	printf("\n\n\tENTER FIRST NAME OF CONVICT:");
	fflush(stdin);
	gets(filename);
	fp=fopen("filename","ab+");
	if(fp==NULL)
	{
		fp=fopen("filename","wb+");
		if(fp==NULL)
		{
			printf("\nSYSTEM ERROR");
			printf("\nPRESS ANY KEY TO EXIT");
			getch();
			return;
			
		}
		
	}
	while ( another == 'Y'|| another=='y' )

    {
        choice=0;
        fflush(stdin);
        
		printf ( "\tENTER CONVICT CODE:");
        scanf("%s",id);
        
		rewind(fp);

        while(fread(&sample,sizeof(sample),1,fp)==1)
        {
            if(strcmp(sample.id,id)==0)
            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;

            }

        }

        if(choice==0)
        {

            strcpy(sample.id,id);

            printf("\n\tENTER NAME OF CONVICT:");
            fflush(stdin);
            gets(sample.name);
            
			printf("\tENTER SEX:");
            gets(sample.gender);
            fflush(stdin);

            printf("\tENTER AGE:");
            gets(sample.age);
            fflush(stdin);

            printf("\tENTER WEIGHT:");
            gets(sample.weight);
            fflush(stdin);
            
            printf("\tENTER HEIGHT(IN FEET):");
            gets(sample.height);
 			fflush(stdin);
           
            printf("\tENTER HAIRCOLOUR:");
            gets(sample.haircolour);
            fflush(stdin);
            
            printf("\tENTER EYECOLOUR:");
            gets(sample.eyecolour);
            fflush(stdin);
            
            printf("\tENTER FACE DETAILS:");
            gets(sample.details);
            fflush(stdin);
			
			
			printf("\tENTER CRIME:");
            gets(sample.crime);
            fflush(stdin);
            
            
            printf("\tENTER COURT:");
            gets(sample.court);
            fflush(stdin);
            
            printf("\tACT(UNDER WHICH CONVICTED):");
            gets(sample.act);
            fflush(stdin);
            
            printf("\tENTER CONVICTION:");
            gets(sample.punishment);
            fflush(stdin);
            
            printf("\tADDRESS OF POLICE STATION:");
            gets(sample.address);
            fflush(stdin);
            
            printf("\tENTER FIR NUMBER: ");
            gets(sample.fir);
            fflush(stdin);
            
            printf("\tENTER EMERGENCY CONTACT:");
            gets(sample.emergency1);
            fflush(stdin);
            
            printf("\tENTER RELATION OF EMERGENCY CONTACT WITH CONVICT:");
            gets(sample.emergency2);
            fflush(stdin);
            
            printf("\tENTER DATE OF ARREST:");
            gets(sample.date);
            
            fwrite ( &sample, sizeof ( sample ), 1, fp ) ;
            printf("\nYOUR RECORD IS ADDED!!!\n");

        }

        printf ( "\n\tADD ANOTHER RECORD(Y/N) \t" ) ;
        fflush (stdin) ;
        another = getch( ) ;

    }

    fclose (fp) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();
	
}
void searchRecord()
{
	system("cls");
    FILE *fp ;
	char id[10],choice,filename[15];
    int ch;
	printf("\n\n\t\t====================================\n");
    printf("\t\t\t SEARCH FIR RECORDS");
    printf("\n\n\t\t====================================\n");

    do
	{
        
		printf("\n\tENTER THE PRISONER NAME TO BE SEARCHED:");
        fflush(stdin);
        gets(filename);

        fp = fopen ( "filename", "rb" ) ;
			printf("\nENTER CONVICT CODE:");
            gets(id);
            system("cls");
            printf("\nTHE RECORD IS:");
 
            while ( fread ( &sample, sizeof (sample), 1, fp ) == 1 )

          //{
          if(strcmp(sample.id,id)==0)
               { printf("\n");
                printf("\nCONVICT'S NAME IS: %s",sample.name);
                printf("\nCONVICT'S GENDER IS: %s",sample.gender);
                printf("\nCONVICT'S AGE IS: %s",sample.age);
                printf("\nCONVICT'S WEIGHT IS: %s",sample.weight);
                printf("\nCONVICT'S HEIGHT IS: %s",sample.height);
                printf("\nCONVICT'S HAIRCOLOUR IS: %s",sample.haircolour);
				printf("\nCONVICT'S EYECOLOUR IS: %s",sample.eyecolour);
                printf("\nCONVICT'S CRIME IS: %s",sample.crime);
                printf("\nFACE DETAIL: %s",sample.details);
                printf("\nCOURT IS: %s",sample.court);
                printf("\nACT IS: %s",sample.act);
                printf("\nPRISONER'S CONVICTION IS: %s",sample.punishment);
                printf("\nADDRESS OF POLICE STATION: %s",sample.address);
                printf("\nFIR NUMBER IS: %s",sample.fir);
                printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",sample.emergency1);
                printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",sample.emergency2);
                printf("\nARRESTED DATE: %s",sample.date);
                printf("\n");
            }

           // }
            

        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING???(Y/N):");
        fflush(stdin);
		scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fp) ;
	getch();
    return ;
getch();
}
void editRecord()

{

    system("cls");
    FILE *fp ;
    char id[10],choice,filename[14];
    int num,count=0;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- MODIFY RECORDS -");
    printf("\n\n\t\t====================================\n");

    do
    {

        printf("\n\tENTER CONVICT'S NAME TO BE EDITED:");
        fflush(stdin);
        gets(filename);

        printf("\n\tENTER ID:");
    	gets(id);
        fp = fopen ( "filename", "rb+" ) ;

        while ( fread ( &sample, sizeof (sample), 1, fp ) == 1 )
        {

            if(strcmp(sample.id,id)==0)
            {

                printf("\nYOUR OLD RECORD WAS AS:");
                printf("\nCONVICT'S NAME: %s",sample.name);
                printf("\nCONVICT'S SEX: %s",sample.gender);
                printf("\nCONVICT'S AGE: %s",sample.age);
                printf("\nCONVICT'S WEIGHT: %s",sample.weight);
                printf("\nCONVICT'S HEIGHT: %s",sample.height);
                printf("\nCONVICT'S HAIRCOLOUR: %s",sample.haircolour);
				printf("\nCONVICT'S EYECOLOUR: %s",sample.eyecolour);
                printf("\nCONVICT'S CRIME: %s",sample.crime);
                printf("\nFACE DETAILS: %s",sample.details);
                printf("\nCOURT: %s",sample.court);
                printf("\nCONVICT'S ACT: %s",sample.act);
                printf("\nCONVICT'S CONVICTION: %s",sample.punishment);
                printf("\nADDRESS OF POLICE STATION: %s",sample.address);
                printf("\nFIR NUMBER: %s",sample.fir);
                printf("\nCONVICT'S EMERGENCY CONTACT: %s",sample.emergency1);
                printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT: %s",sample.emergency2);
                printf("\nARRESTED DATE: %s",sample.date);
                
            
                
                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
                
                
                
                printf("\n1.NAME.");
                printf("\n2.SEX.");
                printf("\n3.AGE.");
                printf("\n4.WEIGHT.");
                printf("\n5.HEIGHT.");
                printf("\n6.HAIRCOLOR.");
                printf("\n7.EYECOLOR.");
                printf("\n8.CRIME.");
                printf("\n9.FACE DETAILS.");
                printf("\n10.COURT.");
                printf("\n11.ACT.");
                printf("\n12.CONVICTION.");
                printf("\n13.ADDRESS OF POLICE STATION.");
                printf("\n14.FIR NUMBER.");
                printf("\n15.EMERGENCY CONTACT.");
                printf("\n16.RELATION OF EMERGENCY CONTACT.");
                printf("\n17.ARRESTED DATE.");
                printf("\n18.WHOLE RECORD.");
                printf("\n19.GO BACK TO MAIN MENU.");
                
                do
                {

                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);
                    
                    switch(num)
                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNAME:");
                        gets(sample.name);
                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nSEX:");
                        gets(sample.gender);
                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nAGE:");
                        gets(sample.age);
                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nWEIGHT:");
                        gets(sample.weight);
                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHEIGHT:");
                        gets(sample.height);
                        break;

                    case 6:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHAIRCOLOUR:");
                        gets(sample.haircolour);
                        break;

                    case 7:
                        printf("ENTER THE NEW DATA:");
                        printf("\nEYECOLOUR:");
                        gets(sample.eyecolour);
                        break;

                    case 8:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCRIME:");
                        gets(sample.crime);
                        break;

                    case 9:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFACE DETAILS:");
                        gets(sample.details);
                        break;

                    case 10:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCOURT:");
                        gets(sample.court);
                        break;

                    case 11:
                        printf("ENTER THE NEW DATA:");
                        printf("\nACT:");
                        gets(sample.act);
                        break;

                    case 12:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCONVICTION:");
                        gets(sample.punishment);
                        break;

                    case 13:
                        printf("ENTER THE NEW DATA:");
                        printf("\nADDRESS OF POLICE STATION:");
                        gets(sample.address);
                        break;

                    case 14:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFIR NUMBER:");
                        gets(sample.fir);
                        break;

                    case 15:
                        printf("ENTER THE NEW DATA:");
                        printf("\nEMERGENCY CONTACT:");
                        gets(sample.emergency1);
                        break;

                    case 16:
                        printf("ENTER THE NEW DATA:");
                        printf("\nRELATION OF EMERGENCY CONTACT:");
                        gets(sample.emergency2);
                        break;

                    case 17:
                        printf("ENTER THE NEW DATA:");
                        printf("\nARRESTED DATE:");
                        gets(sample.date);
                        break;

                    case 18:
                    	printf("ENTER THE NEW DATA:");
                        printf("\tCONVICT'S NAME:");
			            gets(sample.name);		
						printf("\tSEX:");
			            gets(sample.gender);			
			            printf("\tAGE:");
			            gets(sample.age);
			            printf("\tWEIGHT:");
			            gets(sample.weight);
			            printf("\tHEIGHT:");
			            gets(sample.height);
			            printf("\tHAIRCOLOUR:");
			            gets(sample.haircolour);
			            printf("\tEYECOLOUR:");
			            gets(sample.eyecolour);
			            printf("\tCRIME:");
			            gets(sample.age);
			            printf("\tFACE DETAILS:");
			            gets(sample.details);
			            printf("\tCOURT:");
			            gets(sample.court);
			            printf("\tACT:");
			            gets(sample.act);
			            printf("\tCONVICTION:");
			            gets(sample.punishment);
			            printf("\tADDRESS OF POLICE STATION:");
			            gets(sample.address);
			            printf("\tFIR NUMBER:");
			            gets(sample.fir);
			            printf("\tEMERGENCY CONTACT:");
			            gets(sample.emergency1);
			            printf("\tRELATION OF EMERGENCY CONTACT WITH CONVICT:");
			            gets(sample.emergency2);
			            printf("\tARRESTED DATE:");
			            gets(sample.date);
                        break;

                    case 19:
                        printf("\nPRESS ANY KEY TO GO BACK\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\nINVALID...TRY AGAIN\n");
                        break;

                    }

                }
                while(num<1||num>20);

                fseek(fp,-sizeof(sample),SEEK_CUR);

                fwrite(&sample,sizeof(sample),1,fp);

                fseek(fp,-sizeof(sample),SEEK_CUR);

                fread(&sample,sizeof(sample),1,fp);

                choice=5;

                break;

            }
        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nCONVICT'S NAME IS: %s",sample.name);
            printf("\nCONVICT'S SEX IS: %s",sample.gender);
            printf("\nCONVICT'S AGE IS: %s",sample.age);
            printf("\nCONVICT'S WEIGHT IS: %s",sample.weight);
            printf("\nCONVICT'S HEIGHT IS: %s",sample.height);
            printf("\nCONVICT'S HAIRCOLOUR IS: %s",sample.haircolour);
			printf("\nCONVICT'S EYECOLOUR IS: %s",sample.eyecolour);
            printf("\nCONVICT'S CRIME IS: %s",sample.crime);
            printf("\nFACE DETAILS: %s",sample.details);
            printf("\nCOURT IS: %s",sample.court);
            printf("\nACT: %s",sample.act);
    		printf("\nCONVICT'S CONVICTION IS: %s",sample.punishment);
        	printf("\nADDRESS OF POLICE STATION: %s",sample.address);
            printf("\nFIR NUMBER: %s",sample.fir);
            printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",sample.emergency1);
            printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",sample.emergency2);
            printf("\nARRESTED DATE: %s",sample.date);

            fclose(fp);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD?(Y/N)");
            scanf("%c",&choice);
            count++;

        }
        else
        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN??(Y/N)");
        	scanf("%c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp ) ;
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();

}
void viewRecord()

{
    system("cls");
    FILE *fp;
    char filename[30];
    
    printf("\n\n\t\t====================================\n");
    printf("\t\t\t LIST RECORDS ");
    printf("\n\n\t\t====================================\n");
    
    fp=fopen("filename","rb");
    rewind(fp);
    while((fread(&sample,sizeof(sample),1,fp))==1)
    {
        printf("\n\n\t\tPRESS ENTER TO VIEW MORE RECORDS!!\n");
        printf("\nCONVICT'S NAME IS: %s",sample.name);
        printf("\nCONVICT'S SEX IS: %s",sample.gender);
        printf("\nCONVICT'S AGE IS: %s",sample.age);
        printf("\nCONVICT'S WEIGHT IS: %s",sample.weight);
        printf("\nCONVICT'S HEIGHT IS: %s",sample.height);
        printf("\nCONVICT'S HAIRCOLOUR IS: %s",sample.haircolour);
		printf("\nCONVICT'S EYECOLOUR IS: %s",sample.eyecolour);
        printf("\nCONVICT'S CRIME IS: %s",sample.crime);
        printf("\nFACE DETAILS: %s",sample.details);
        printf("\nCOURT IS: %s",sample.court);
        printf("\nACT: %s",sample.act);
        printf("\nCONVICT'S CONVICTION IS: %s",sample.punishment);
        printf("\nADDRESS OF POLICE STATION: %s",sample.address);
        printf("\nFIR NUMBER: %s",sample.fir);
        printf("\nCONVICT'S EMERGENCY CONTACT IS: %s",sample.emergency1);
        printf("\nRELATION OF EMERGENCY CONTACT WITH CONVICT IS: %s",sample.emergency2);
        printf("\nARRESTED DATE: %s",sample.date);
        getch();
        
    }
    fclose(fp);
	getch();
	
}

void deleteRecord( )

{

    system("cls");
    FILE *fp,*ft ;
    struct record file ;
    char filename[15],another ='Y',id[16];;
    int choice,check;
    int j=0;
    char pwd[8];

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t DELETE RECORDS ");
    printf("\n\n\t\t====================================\n");
    
    printf("\nENTER PASSWORD\n");
    int i;
    for(  i=0;i<4;i++)
    {
    	pwd[i]=getch();
    	printf("*");
	}
	if (strcmpi(pwd,"guest")==0)
	{
	
     printf("\n\t\t*ACCESS GRANTED*\n\n");
   while ( another == 'Y' || another == 'y' )

    {
       
    	printf("\n\tENTER THE NAME OF CONVICT TO BE DELETED:");
		fflush(stdin);
        gets(filename);
        fp = fopen ("filename", "rb" ) ;
        if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft=fopen("temp","wb");
				
				if(ft==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\n\tENTER THE ID OF RECORD TO BE DELETED:");
                fflush(stdin);
                gets(id);

        		while(fread(&file,sizeof(file),1,fp)==1)

                {

                    if(strcmp(file.id,id)!=0)

                        fwrite(&file,sizeof(file),1,ft);

                }
        fclose(ft);
        fclose(fp);
        remove("filename");
        rename("temp","filename");
        printf("\nDELETED SUCCESFULLY...");
        getch();

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);

    }
   

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();
}
	else
	{
		printf("\nSORRY! INVALID PASSWORD\n");
		exit(0);
	}

}

void login()
{
	int sample=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="guest";
    char pwd[10]="guest";
    do
{
	printf("\n  ====================== GUJARAT POLICE  ======================  \n");
    printf("\n  ==================== LOGIN IN INTO SYSTEM  ======================  \n");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"guest")==0 && strcmp(pword,"guest")==0)
	{
	printf("  \n\n\n  WELCOME TO POLICE FIR RECORD MANAGEMENT SYSTEM !! \nYOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\tPRESS ANY KEY TO CONTINUE...");
	getch();
	break;
	}
	else
	{
		printf("\n SORRY !!!!  LOGIN IS UNSUCESSFUL");
		sample++;
		getch();
		system("cls");
		
	}
}
	while(sample<=100);
	if (sample>100)
	{
		printf("\nSORRY YOU HAVE ENTERED WRONG PASSWORD!!");
		
		getch();
		
		}
		system("cls");	
}

		
			
	




