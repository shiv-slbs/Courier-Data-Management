//importing used libraries
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//defining limitations of max customer & max parcels,so that it can be changed when needed. Just change here no need to change else where.
#define MAX_CUSTOMERS 1000
#define MAX_PARCELS 10000

//defining structures for storing informations of customer, parcel and thier adresses.
struct Customer {
    char customer_name[25];
    char email[25];
    long contact_num;
    bool isdeleted;
};

struct Address {
    char person_name[50];
    char area_colony[100];
    char city[15];
    char state[15];
    int pincode;
    long phone_num;
};

struct Parcel {
    char parcel_name[50];
    int customer_id;
    struct Address from_address;
    struct Address to_address;
    bool isdeleted;
};

struct Customer customer[MAX_CUSTOMERS] = {0}; // Initialize all elements to zero
struct Parcel parcel[MAX_PARCELS] = {0};

//This function check if the user has selected correct choice or not.
bool check_choice(const char s[]) {
    char yn;
    printf("You chose to %s [y/n]: ", s);
    scanf(" %c", &yn);
    if (yn == 'Y' || yn == 'y')
        return true;
    else if (yn == 'n' || yn == 'N') {
        printf("Returning to Main Menu.\n\n");
        return false;
    } else {
        printf("Enter available choices only 'y' or 'n'.\n");
        return check_choice(s);
    }
}

//These two functions check if the Customer Id & Parcel ID is already registered or not.
bool check_existing_cust(int cust_id) {
    return !customer[cust_id].isdeleted;
}

bool check_existing_parcel(int prcl_id) {
    return !parcel[prcl_id].isdeleted;
}

//Function for adding new customer
int add_new_customer() {
    if (check_choice("Add new customer")) {
        int cust_id;
        printf("Enter a customer ID [Integers only]: ");
        scanf("%d", &cust_id);
        if (!check_existing_cust(cust_id)) {
            printf("Enter name of customer: ");
            scanf("%s", customer[cust_id].customer_name);
            printf("Enter contact number: ");
            scanf("%ld", &customer[cust_id].contact_num);
            printf("Enter email: ");
            scanf("%s", customer[cust_id].email);
            customer[cust_id].isdeleted = false;
            printf("\nCustomer Saved!\n\n");
        } else {
            printf("\nCustomer ID already registered.\n");
        }
    }return 0;
}

//function for adding new parcel
int add_new_parcel(){
    if (check_choice("Add new parcel")){
        int prcl_id;
        printf("Enter a parcel ID [integers only]: ");
        scanf("%d",&prcl_id);
        if (!check_existing_parcel(prcl_id)) {
            printf("Enter customer ID of the customer :");
            scanf("%d",&parcel[prcl_id].customer_id);
            printf("Enter parcel name : ");
            scanf("%s", parcel[prcl_id].parcel_name);     
            //Accepting Sender's address
            printf("Enter Sender's address details : \n");
            printf("Sender's name : ");
            scanf("%s",parcel[prcl_id].from_address.person_name);
            printf("Area/colony or landmarks : ");
            scanf("%s",parcel[prcl_id].from_address.area_colony);
            printf("City : ");
            scanf("%s",parcel[prcl_id].from_address.city);
            printf("State : ");
            scanf("%s",parcel[prcl_id].from_address.state);
            printf("Pin Code : ");
            scanf("%d",&parcel[prcl_id].from_address.pincode);
            printf("Contact number : ");
            scanf("%ld",&parcel[prcl_id].from_address.phone_num);
            //Accepting receiver's address
            printf("Enter Reciver's address details : \n");
            printf("Receiver's name : ");
            scanf("%s",parcel[prcl_id].to_address.person_name);
            printf("Area/colony or landmarks : ");
            scanf("%s",parcel[prcl_id].to_address.area_colony);
            printf("City : ");
            scanf("%s",parcel[prcl_id].to_address.city);
            printf("State : ");
            scanf("%s",parcel[prcl_id].to_address.state);
            printf("Pin Code : ");
            scanf("%d",&parcel[prcl_id].to_address.pincode);
            printf("Contact number : ");
            scanf("%ld",&parcel[prcl_id].to_address.phone_num);
            parcel[prcl_id].isdeleted = false;
            printf("\n Parcel details saved!\n");
        }else{
            printf("Parcel ID already registered.\n");
        }
    }return 0;
}

//function for viewing a single customer's details
int view_cust_details(){
    if (check_choice("view customer details")){
        int cust_id;
        printf("Enter Customer ID : ");
        scanf("%d",&cust_id);
        if (!customer[cust_id].isdeleted){
            printf("Customer name : %s; ",customer[cust_id].customer_name);
            printf("Contact number : %ld; ", customer[cust_id].contact_num);
            printf("Email : %s\n",customer[cust_id].email);
        }else{
            printf("Customer do not exist or has been deleted.\n");
        }
    }return 0;
}

//fumction for viewing a parcel details with taking Parcel ID as argument
void View_parcel_i(int prcl_id){
    printf("Parcel name : %s\n",parcel[prcl_id].parcel_name);
    printf("\nSender's address\nName : %s\n",parcel[prcl_id].from_address.person_name);
    printf("Area/colony or landmarks : %s\n",parcel[prcl_id].from_address.area_colony);
    printf("City : %s\n",parcel[prcl_id].from_address.city);
    printf("State : %s\n",parcel[prcl_id].from_address.state);
    printf("Conatact number : %ld\n",parcel[prcl_id].from_address.phone_num);
    printf("\nReceiver's address\nName : %s\n",parcel[prcl_id].to_address.person_name);
    printf("Pin Code : %d\n",parcel[prcl_id].from_address.pincode);
    printf("Area/colony or landmarks : %s\n",parcel[prcl_id].to_address.area_colony);
    printf("City : %s\n",parcel[prcl_id].to_address.city);
    printf("State : %s\n",parcel[prcl_id].to_address.state);
    printf("Pin Code : %d\n",parcel[prcl_id].to_address.pincode);
    printf("Conatact number : %ld\n",parcel[prcl_id].to_address.phone_num);
}

//function for viewing a single parcel's details
int view_parcel_details(){
    if (check_choice("view parcel details")){
        int prcl_id;
        printf("Enter parcel ID : ");
        scanf("%d",&prcl_id);
        if (!parcel[prcl_id].isdeleted ){
            printf("Customer Id : %d ;",parcel[prcl_id].customer_id);
            //complexity Alert!
            printf("Customer name : %s ;\n",customer[parcel[prcl_id].customer_id].customer_name);
            View_parcel_i(prcl_id);
        }else {
            printf("Parcel do not exits or has been deleted.\n");
        }
    }return 0;
}

//Function for viewing all the customer details with just one click.
int view_all_cust_details(){
    if(check_choice("view all customer details")){
        for (int i = 0 ; i<MAX_CUSTOMERS ; i++){
            if (!customer[i].isdeleted){
                printf("Customer Id : %d \n:",i);
                printf("Customer name : %s \n;",customer[i].customer_name);
                printf("Contact number : %ld \n;",customer[i].contact_num);
                printf("Email : %s ;\n",customer[i].email);
            }
            printf("\n");
        }
    }return 0;
}

//Function for viewing all the Parcel details with just one click.
int view_all_parcel_details(){
    if(check_choice("view all parcel details")){
        for (int i = 0 ; i<MAX_PARCELS ; i++){
            if (!parcel[i].isdeleted ){
                printf("Parcel Id : %d :",i);
                View_parcel_i(i);
                //sending existing parcel ID to a function which is dedicated to displaying a parcel details on demand.
                printf("\n");
            }
        }
    }return 0;
}

//function for deleting a customer infomation
int del_cust(){
    if (check_choice("delet a cutomer details")){
        int cust_id;
        printf("Enter Customer Id : ");
        scanf("%d",&cust_id);
        if (!customer[cust_id].isdeleted){
            customer[cust_id].isdeleted = true;
            printf("\nCustomer ID %d deleted.\n", cust_id);
        }else {
            printf("Customer ID %d not found!\n",cust_id);
        }
    }return 0;
}

//function for deleting a parcel information
int del_parcel(){
    if(check_choice("delet a parcel details")){
        int prcl_id;
        printf("Enter Parcel Id : ");
        scanf("%d",&prcl_id);
        if (!parcel[prcl_id].isdeleted){
            parcel[prcl_id].isdeleted = true;
            printf("\nParcel ID %d deleted.\n", prcl_id);
        }else {
            printf("Parcel ID %d not found!\n",prcl_id);
        }
    }return 0;
}

//function for deleting all the exiting customer at once.
int del_all_cust(){
    if(check_choice("delet all customer details")){
        char yn;
        printf("Please Confirm! you really want to delet all Customer details [y/n] : ");
        scanf(" %c",&yn);
        if (yn == 'Y' || yn == 'y'){
            for (int i = 0 ; i<MAX_CUSTOMERS ; i++){
                if (customer[i].isdeleted == false){
                    customer[i].isdeleted = true;
                }
            }
        printf("\nAll Customers details has been deleted.\n");
        } else if (yn == 'N' || yn == 'n') {
            printf("Returning to Main Menu.\n\n");
        }else {
            printf("Enter available choices only (y/n)\n\n");
            del_all_cust();
        }
    }return 0;
}

//Function for deleting all the existing parcel at once
int del_all_parcel(){
    if(check_choice("delet all parcel details")){
        char yn;
        printf("Please Confirm! you really want to delet all Parcel details [y/n] : ");
        scanf(" %c",&yn);
        if (yn == 'Y' || yn == 'y'){
            for (int i = 0 ; i<MAX_PARCELS ; i++){
                if (parcel[i].isdeleted == false){
                    parcel[i].isdeleted = true;
                }
            }
        printf("\nAll Parcel details has been deleted.\n");
        } else if (yn == 'N' || yn == 'n') {
            printf("Returning to Main Menu.\n\n");
        }else {
            printf("Enter available choices only (y/n)\n\n");
            del_all_parcel();
        }
    }return 0;
}

// Function to save data to files
void save_data_to_files() {
    FILE *client_file = fopen("client_data.txt", "w");
    FILE *parcel_file = fopen("parcel_data.txt", "w");

    if (client_file == NULL || parcel_file == NULL) {
        printf("Error opening files for writing.\n");
        return;
    }

    // Save customer data
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (!customer[i].isdeleted) {
            fprintf(client_file, "%d %s %ld %s\n", i, customer[i].customer_name, customer[i].contact_num, customer[i].email);
        }
    }

    // Save parcel data
    for (int i = 0; i < MAX_PARCELS; i++) {
        if (!parcel[i].isdeleted) {
            fprintf(parcel_file, "%d %s %d %s %s %s %d %ld %s %s %s %d %ld\n", i, parcel[i].parcel_name,
                    parcel[i].customer_id, parcel[i].from_address.person_name, parcel[i].from_address.area_colony,
                    parcel[i].from_address.city, parcel[i].from_address.pincode, parcel[i].from_address.phone_num,
                    parcel[i].to_address.person_name, parcel[i].to_address.area_colony, parcel[i].to_address.city,
                    parcel[i].to_address.pincode, parcel[i].to_address.phone_num);
        }
    }

    fclose(client_file);
    fclose(parcel_file);
    printf("Data saved to files successfully!\n");
}

int main() {
    int ch;

    //marking all the fields of customer and parcel as deleted so it can be filled.
    for (int  i = 0 ; i<MAX_CUSTOMERS ; i++){
        customer[i].isdeleted = true;
    }
    for (int  i = 0 ; i<MAX_PARCELS ; i++){
        parcel[i].isdeleted = true;
    }

    //Using while instead of recusrion of main function as AI suggested "It would be a better practice".
    while (true) {
        printf("\n------**MAIN MENU**------\n");
        printf("1. Add a new customer\n2. Add a new parcel\n");
        printf("3. View a customer details\n4. View a parcel details\n");
        printf("5. View all customers details\n6. View all the parcel details\n");
        printf("7. Delete a customer profile\n8. Delete a parcel details\n");
        printf("9. Delete all the customer details\n10. Delete all the parcel details\n");
        printf("11. Export all the data\n0. Exit from the programme\n");
        printf("\nEnter a number according to operation you would like to perform : ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                add_new_customer();
                break;
            case 2:
                add_new_parcel();
                break;
            case 3:
                view_cust_details();
                break;
            case 4: 
                view_parcel_details();
                break;
            case 5:
                view_all_cust_details();
                break;
            case 6:
                view_all_parcel_details();
                break;
            case 7:
                del_cust();
                break;
            case 8:
                del_parcel();
                break;
            case 9:
                del_all_cust();
                break;
            case 10:
                del_all_parcel();
                break;
            case 11:
                save_data_to_files();
                break;
            case 0:
                save_data_to_files();
                printf("Data automatically saved if any.");
                exit(1);
            default:
                printf("\nEnter correct number \n\n ");
                break;
        }
    }
    return 0;
}