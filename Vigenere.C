// --------Vigenere Cipher--------
// This is a program to use Vigenere Cipher for encrypting and decrypting the text
// User can choose the option to Encrypt or Decrypt or Exit the program
// User has to enter the text to be encrypted and a key for the process of encryption
// User has to enter the encrypted text and the correct key for the process of decryption
// User also has the option to exit the program
// Once the process has been completed, the user will be prompted with the options similar to initial options
// Declaration of header files for the program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// Function to Remove all spaces from the entered String
int Remove_Spaces(char *str)
{
    int count = 0; // Variable to keep count of non-space characters
    // Traversing the Given String.
    for (int i=0; str [i]; i++)
    { 
        // If the character is not a space, then placing it at count position of string
        if( str[i] != ' ')
        {
             str[count] = str[i];
             count++;
        }
    } 
    str[count] = '\0';// Set last position of string to NULL character to denote end of string
    return 0;
}

//Function to convert the complete string to upper case
int ToUpper( char *str)
{
    int i=0; // Varibale to traverse the string
    // Traversing the string until NULL character is reached
    while(str[i])
    {
        str[i]= toupper(str[i]); // Replacing old characters with their respective upper case characters
        i++; // Incrementing value of i by 1
    }
    return 0;
}

// Function to Encrypt the input String with the input Key using Vigenere Cipher Algorithm
int Encrypt()
{
    char *passphrase,*key; //Passphrase and key string Declaration
    // Allocating memory to the variable passphrase and key
    passphrase = (char*) malloc(200*sizeof(char));
    key = (char*) malloc(20*sizeof(char));

    printf("Enter the Text to be encrypted: ");
    fgets(passphrase,500,stdin); // Taking input of string to be encrypted
    Remove_Spaces(passphrase); // Removing all the spaces from the string
    ToUpper(passphrase); // Changing all the characters of the string to Uppercase
    
    printf("Enter the Key for encryption: ");
    fgets(key,25,stdin);//Taking input of the string for the key
    Remove_Spaces(key); //Remvoing all the spaces from the string
    ToUpper(key); //Changing all the characters of the key to Upper case

    printf("Your Passphrase => %s",passphrase);
    printf("Your Key =>\t %s",key);
    
    // Displaying a note to remember the key as it would be required at the time of decryption
    printf("\n\t!!NOTE: Remember the key for the decryption of the message!!\n\n");
    int i =0, j=0; // Declaration of integer variable for traversing the strings for encryption
    char *encrypt; // Declaration of string to store encrypted string
    
    // Allocating memory same as of passphrase to the encrypt pointer
    encrypt = (char*)malloc(strlen(passphrase)*sizeof(char));
    
    // While loop block to encrypt the text and store it in the new string
    while(passphrase[i])
    { 
        // Using character 'A' for subtraction and addition with the algorithmm
        // to reset the value of character to start from 0 instead of their ASCII
        // value for easier calculations
        if(isalpha(passphrase[i])) // Encrypting the character if it is an alphabet
        {
            if(isalpha(key[j])) // Encrypting if the char of key is alphabet
                encrypt[i]=(passphrase[i] - 'A' + key[j] -'A') % 26 + 'A';
            else
                encrypt[i]=passphrase[i];
        }
        
        // Leaving text unchanged if it is number or punctuation
        if(ispunct(passphrase[i]) || isdigit(passphrase[i]))
        encrypt[i]=passphrase[i];
        // Incrementing the values of counter variables
        i++;
        j++;
    
        // Resetting the key's position back to start when end is reached
        if(j==strlen(key)-1)
        j=0;
    }
    
    // Displaying the encrypted text
    printf("Encrypted text =>\t");
    fputs(encrypt, stdout);
    
    //Freeing the allocated memory of variable pointers
    free(passphrase);
    free(key);
    free(encrypt);
    return 0;
}


// Function to Decrypt the input Cipherphrase with the input Key using Vigenere Cipher Algorithm
int Decrypt()
{
    char *cipherphrase,*key; // Cipherphrase and key string Declaration
    
    // Allocating memory to the varibales cipherphrase and key
    cipherphrase = (char*)malloc(200*sizeof(char));
    key = (char*)malloc(20*sizeof(char));
    
    printf("Enter the Text to be decrypted: ");
    fgets( cipherphrase,100, stdin);// Taking input of the string to be decrypted
    ToUpper(cipherphrase); // Changing all the characters of the string to Uppercase
    
    printf("Enter the Key for decryption: ");
    fgets( key,25, stdin);//Taking input of the string for the key
    Remove_Spaces(key); //Remvoing all the spaces from the string
    ToUpper(key); //Changing all the characters of the key to Upper case
    
    printf("Cipherphrase =>\t %s",cipherphrase);
    printf("Key =>\t\t %s",key);
    
    // Declaration of integer variable for traversing the strings for decryption
    int i =0, j=0;
    char *decrypt; // Declaration of string to store decrypted string
    
    // Allocating memory same as of cipherphrase to decrypt variable
    decrypt=(char*)malloc(strlen(cipherphrase)*sizeof(char));
    
    // While loop block to decrypt the text and store it in the new string
    while(cipherphrase[i])
    {
        //Using character 'A' for subtraction and addition with the algorithm
        //to reset the value of character to start from 0 instead of their ASCII
        //value for easier calculations
        if(isalpha(cipherphrase[i])) // Encrypting the text if it alphabet
            {
                if(isalpha(key[j])) // Encrypting if the char of key is alphabet
                    decrypt[i]=(((cipherphrase[i] -'A') - (key[j] - 'A'))+26) % 26 +'A';
                else
                    decrypt[i]=cipherphrase[i]
            }
                
        // Leaving the text unchanged if it is a number or punctuation
            if(ispunct(cipherphrase[i]) || isdigit(cipherphrase[i]))
                decrypt[i]=cipherphrase[i];
                
        // Incrementing the values of counter variables
        i++;
        j++;
                
        // Resetting the key's position to start once end is reached
        if(j==strlen(key)-1)
            j=0;
    }
    
    // Printing the Decrypted text
    printf("Decrypted text =>\t");
    fputs(decrypt, stdout);

    // Freeing the allocated memory of varaible pointers
    free(cipherphrase);
    free(key);
    free(decrypt);
    
    return 0;
}



int main() // Start of the Main Function
{
    char a[2]; //Declaration of a char variable for input
    int option; //Declaration of int variable

    // Running a while loop with always true condition to run the process of encryption and decryption multiple times
    // loop can only be exited once the Exit option has been chosen
    while(0==0)
    {
        printf("\nSelect an option:\n 1 - Encryption\n 2 - Decryption\n 3 - Exit\n=> ");
        fgets(a,4,stdin); // Taking input from the user to run the required function
        option = atoi(a); // Converting the input to string and storing it in option variable for later use
        
        // Checking the option chosen and running the required block of code corresponding to the slected option
        if(option == 3)
        { 
            printf("\n\t Thankyou for using the program \n");// Exiting the program with break keyword
            exit(0);
        }
        else if(option == 1)
            Encrypt(); // Calling the Encrypt function
        else if(option == 2)
            Decrypt(); // Calling the Decrypt function
        else
            printf("\t\t!! Invalid Option !!\n\n"); // Warning of Invalid option
    }
    return 0;
}
// ----------End Of Program----------------