# Courier-Services-in-C
This programme is totaly teerminal based and menu programme written in C language which stores and manage data of Customers and Parcels of  a courier company

# Parcel Management System

This program is a simple parcel management system written in C. It allows you to manage customers and parcels.

## Features

1. Add a new customer
2. Add a new parcel
3. View a customer's details
4. View a parcel's details
5. View all customers' details
6. View all parcels' details
7. Delete a customer profile
8. Delete a parcel's details
9. Delete all customer details
10. Delete all parcel details
11. Export all data

## Structures

The program uses three structures:

1. `Customer`: Stores information about customers, including name, email, contact number, and a deletion flag.
2. `Address`: Stores address details, including the person's name, area/colony, city, state, pin code, and phone number.
3. `Parcel`: Stores information about parcels, including the parcel name, customer ID, sender's address, receiver's address, and a deletion flag.

## Functions

The program includes several functions to manage customers and parcels, check choices, and check if a customer or parcel already exists. It also includes functions to delete customers and parcels, either individually or all at once.

## Data Storage

The program stores customer and parcel data in arrays. The maximum number of customers and parcels can be adjusted by changing the `MAX_CUSTOMERS` and `MAX_PARCELS` constants.

## Data Export

The program can export all customer and parcel data to text files (`client_data.txt` and `parcel_data.txt`). This function is called when the user chooses to export all data or exits the program.

## Usage

To use the program, run it and follow the prompts in the console. You can perform various operations by entering the corresponding number from the main menu.