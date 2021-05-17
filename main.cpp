#include <iostream>
#include <fstream>
using namespace std;

struct Recipe{
	    int numOfComponents;
	    string c_List[20];
	    string c_Measurement;  
};
	    
struct Menu{
	    string menuName;
	    int itemCode;
	    float itemPrice;
	    int preparationTime;
	    Recipe itemRecipe;
}menuX[10];
		    
struct Order{
	    string orderedBy;
	    Menu menuItems[5];
}userX[3];

// prototyping a function
void initialize();
void showMenuList();
int VatCalculator();


// a global variable
int numOfMenuItems;
int davesno;

int main(){
	string again;
	
	
	
	cout<<"                          Welcome To Our Customer-Ordering-System..."<<endl;
	cout<<" "<<endl;
	cout<<"	You Can Make Three Separate Orders, And One Order Can Have Five Items"<<endl;
	int i=0;
	do{
	    int item;
	    showMenuList();
	    cout<<" "<<endl;
		cout<<"Order Number "<<i+1<<endl;
		cout<<"	Write Your Name, For Your Order "<<endl;
		cin>>userX[0].orderedBy;
		cout<<" "<<endl;
		cout<<"	You Can Order By Choosing Item Number  Eg. 01/1 for Beyaynet "<<endl;
		for(int j=0;j<5;j++){
			cout<<"Your Number "<<j+1<<" Item Is:"<<endl;
			while(!(cin>>item && item>=1 && item<=10)){
				cout<<" "<<endl;
				cout<<"	Your Input Must Be A Number From 1 - 10, Only Number"<<endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
		}
		
		if(i<2){
		    cout<<" "<<endl;
			cout<<"Do You Want To Continue Ordering? (Use Y/y For \"Yes\" and Use N/n for \"No\")"<<endl;
			cin>>again;
			if(again!="Y"||again!="y"){
			    cout<<" "<<endl;
			    cout<<"Thank You For Order          ..........Bye"<<endl;
			}
		}else{
			  cout<<" "<<endl;
			  cout<<"		You Can't Not Order More Than 3 Orders"<<endl;
			  cout<<"	Thank You For Using Our Customer Ordering System..."<<endl;
			  again = "n";
		}
		i++;
	}while(again=="Y" || again=="y");
	
	if(again=="n" && i<=2){
		cout<<"Thank You For Order          ..........Bye"<<endl;
	}
	
	return 0;
}

// a function to calulate the total amount of the food price including VAT %
int VatCalculator()
{
	for(int index = 0; index <5; index++)
	{	
		float Vat = 115.0;
		float incVat; //price including VAT
		float itemVat; //VAT per item
		
		itemVat = menuX[index].itemPrice/Vat;
		
		int totalVat = itemVat * (100 - Vat);
		
		int newPrice = menuX[index].itemPrice + totalVat;
		
		return(newPrice);
		
	}
}



void showMenuList (){
	ofstream menuList("menuTable.txt");
	
	menuList<<"    ****************************** MENU LIST ***********************************"<<endl;
 	menuList<<" "<<endl;
    menuList<<"                Daily-food                         Fast-Food    "<<endl;                        
    menuList<<"                **********                         *********    "<<endl;                       
    menuList<<"              01. Beyaynet                       06. Burger     "<<endl;                     
    menuList<<"              02. Shiro                          07. Pizza      "<<endl;                 
    menuList<<"              03. Kitfo                          08. Chicken    "<<endl;                      
    menuList<<"              04. Doro-wat                       09. Sandwich   "<<endl;                         
    menuList<<"              05. Kita-fir-fir                   10. Tacos      "<<endl;                       
	menuList.close();
	
	string itemLine;
	ifstream readFile("menuTable.txt");
	while(getline(readFile, itemLine)){
		cout<<itemLine<<endl;
	}
	readFile.close();
	
}



void initialize(){
	
	// Initializing the first menu Item
	menuX[0].menuName = "Beyaynet";
	menuX[0].itemCode = 1;
	menuX[0].itemPrice = 35.5;
	menuX[0].preparationTime = 30;
	menuX[0].itemRecipe.numOfComponents = 3;
	menuX[0].itemRecipe.c_List[0] = " ";
	menuX[0].itemRecipe.c_List[1] = " ";
	menuX[0].itemRecipe.c_List[2] = " ";
	menuX[0].itemRecipe.c_Measurement = "Gram";
	
	menuX[1].menuName = "Shiro";
	menuX[1].itemCode = 2;
	menuX[1].itemPrice = 40.7;
	menuX[1].preparationTime = 25;
	menuX[1].itemRecipe.numOfComponents = 3;
	menuX[1].itemRecipe.c_List[0] = " ";
	menuX[1].itemRecipe.c_List[1] = " ";
	menuX[1].itemRecipe.c_List[2] = " ";
	menuX[1].itemRecipe.c_Measurement = "liter";
	
	menuX[2].menuName = "Kitfo";
	menuX[2].itemCode = 3;
	menuX[2].itemPrice = 145;
	menuX[2].preparationTime = 55;
	menuX[2].itemRecipe.numOfComponents = 2;
	menuX[2].itemRecipe.c_List[0] = " ";
	menuX[2].itemRecipe.c_List[1] = " ";
	menuX[2].itemRecipe.c_Measurement = "Gram";
	
	menuX[3].menuName = "Doro-wat";
	menuX[3].itemCode = 4;
	menuX[3].itemPrice = 125.8;
	menuX[3].preparationTime = 35;
	menuX[3].itemRecipe.numOfComponents = 4;
	menuX[3].itemRecipe.c_List[0] = " ";
	menuX[3].itemRecipe.c_List[1] = " ";
	menuX[3].itemRecipe.c_List[2] = " ";
	menuX[3].itemRecipe.c_List[3] = " ";
	menuX[3].itemRecipe.c_Measurement = "liter";
	
	menuX[4].menuName = "Kita-fir-fir";
	menuX[4].itemCode = 5;
	menuX[4].itemPrice = 55.8;
	menuX[4].preparationTime = 60;
	menuX[4].itemRecipe.numOfComponents = 2;
	menuX[4].itemRecipe.c_List[0] = "Kita";
	menuX[4].itemRecipe.c_List[1] = "Butter";
	menuX[4].itemRecipe.c_Measurement = "Gram ";
	
	menuX[5].menuName = "Burger";
	menuX[5].itemCode = 6;
	menuX[5].itemPrice = 85;
	menuX[5].preparationTime = 40;
	menuX[5].itemRecipe.numOfComponents = 4;
	menuX[5].itemRecipe.c_List[0] = "Bread";
	menuX[5].itemRecipe.c_List[1] = "Meat";
	menuX[5].itemRecipe.c_List[2] = "Vegetable";
	menuX[5].itemRecipe.c_List[3] = " ";
	menuX[5].itemRecipe.c_Measurement = "Gram";
	
	menuX[6].menuName = "Pizza";
	menuX[6].itemCode = 7;
	menuX[6].itemPrice = 99;
	menuX[6].preparationTime = 30;
	menuX[6].itemRecipe.numOfComponents = 3;
	menuX[6].itemRecipe.c_List[0] = "";
	menuX[6].itemRecipe.c_List[1] = "";
	menuX[6].itemRecipe.c_List[2] = "Vegetable";
	menuX[6].itemRecipe.c_Measurement = "Gram";

    menuX[7].menuName = "Chicken";
	menuX[7].itemCode = 8;
	menuX[7].itemPrice = 99;
	menuX[7].preparationTime = 30;
	menuX[7].itemRecipe.numOfComponents = 3;
	menuX[7].itemRecipe.c_List[0] = "";
	menuX[7].itemRecipe.c_List[1] = "";
	menuX[7].itemRecipe.c_List[2] = "Vegetable";
	menuX[7].itemRecipe.c_Measurement = "Gram";
	
	menuX[8].menuName = "Sandwich";
	menuX[8].itemCode = 9;
	menuX[8].itemPrice = 50.5;
	menuX[8].preparationTime = 30;
	menuX[8].itemRecipe.numOfComponents = 3;
	menuX[8].itemRecipe.c_List[0] = "";
	menuX[8].itemRecipe.c_List[1] = "";
	menuX[8].itemRecipe.c_List[2] = "Vegetable";
	menuX[8].itemRecipe.c_Measurement = "Gram";
	
 	menuX[9].menuName = "Tacos";
	menuX[9].itemCode = 10;
	menuX[9].itemPrice = 99;
	menuX[9].preparationTime = 30;
	menuX[9].itemRecipe.numOfComponents = 3;
	menuX[9].itemRecipe.c_List[0] = "";
	menuX[9].itemRecipe.c_List[1] = "";
	menuX[9].itemRecipe.c_List[2] = "Vegetable";
	menuX[9].itemRecipe.c_Measurement = "Gram";
	
}






