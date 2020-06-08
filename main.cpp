// * Katie Lee
// * CIS 7 Project Final
// * 15 May 2020

#include <iostream>
#include <string>

using namespace std;

string userPhrase;
string map_Key;


// * Intro to Encrypt & Decrypt *

void userPhrase_userKey() 
{
  string phrase;

  cout << endl; // Formatting

  cout << " * Please input a Word or Phrase and press Enter twice to confirm. ";

  cout << endl; // Formatting

  cout << endl; // Formatting

  getline(cin, phrase);

  cin.ignore();


  // * Change User Message To Caps *

  for (int i = 0; i < phrase.length(); i++) 
 
  {
    phrase[i] = toupper(phrase[i]);
  }

  string key;

  cout << endl; // Formatting

  cout << " * Now input a Key and press Enter twice to confirm.";

  cout << endl; // Formatting

  cout << endl; // Formatting

  getline(cin, key);

  cin.ignore();


  // * Change Key To Caps *
    
    for (int i = 0; i < key.length(); i++) 
    
    {
    key[i] = toupper(key[i]);
    }


  // * Begin Mapping *

  string key_Map = "";

  for (int i = 0, c = 0; i < phrase.length(); i++) 
  
  {
    if (phrase[i] == 32) 
    {
      key_Map += 32;
    }
  
    else 
    {

      if (c < key.length()) 
      {
        key_Map += key[c];

        c++;
      }
      
      else 
      {
        c = 0;

        key_Map += key[c];

        c++;
      }
    } 
  } 

  userPhrase = phrase;
  
  map_Key = key_Map;
}


// * Create & View Table*

int VigTable[26][26];

void viewVigTable()
  {
  
  for (int i = 0; i < 26; i++) 

  {
    for (int c = 0; c < 26; c++) 

    {
      int temp;

      if ((i + 65) + c > 90) 

      {
        temp = ((i + 65) + c) - 26;

        VigTable[i][c] = temp;
      }
      
      else 

      {
        temp = (i + 65) + c;

        VigTable[i][c] = temp;
      }
    }
  }

  for (int i = 0; i < 26; i++) 

  {
    
    for (int c = 0; c < 26; c++) 
    
    {
      
      cout << (char)VigTable[i][c] << " ";

    } 

      cout << endl; // Formatting Table
  }

  cout << endl; // Formatting

}

int tableArray[26][26];

void createVigTable()
 {

  for (int i = 0; i < 26; i++) 

  {
    for (int c = 0; c < 26; c++) 

    {
      int temp;

      if ((i + 65) + c > 90) 

      {
        temp = ((i + 65) + c) - 26;

        tableArray[i][c] = temp;
      }
      
      else 
      {
        temp = (i + 65) + c;

        tableArray[i][c] = temp;
      }
    }
  }
}

// * Encrypting *

void encryption(string userPhrase, string map_Key) 
{
  createVigTable();

  string encrypted = "";

  for (int i = 0; i < userPhrase.length(); i++) 
  {
    
    if (userPhrase[i] == 32 && map_Key[i] == 32) 

    {
      encrypted += "";
    }
    
    else 
    {
      int x = (int)userPhrase[i] - 65;

      int y = (int)map_Key[i] - 65;

      encrypted += (char)tableArray[x][y];
    }
  }

  // * Encrypted Text Output *

  cout << "Encrypted Text: " << encrypted;
  
   cout << endl; // Formatting

   cout << endl; // Formatting

  cout << "Thanks for using Lee's Cryption Services!";

   cout << endl; // Formatting

  cout << "To use the utilities again, Restart the program.";

   cout << endl; // Formatting

}



int count(int key, int phrase) 
{
  int counter = 0;

  string result = "";

  for (int i = 0; i < 26; i++) 
  {

    if (key + i > 90) 

    {
      result += (char)(key + (i - 26));
    }

    else 
    {
      result += (char)(key + i);
    }

  } 

  for (int i = 0; i < result.length(); i++) 
  {

    if (result[i] == phrase) 

    {
      break;
    }

    else 
    {
      counter++;
    }
  }

  return counter;
}

// * Decrypting * 

void decryption(string userPhrase, string map_Key) 
{
  
  string decrypted = "";

  for (int i = 0; i < userPhrase.length(); i++) 
  {
   
    if (userPhrase[i] == 32 && map_Key[i] == 32) 
    {
      decrypted += " ";
    }
    
    else 
    {
      int temp = count((int)map_Key[i], (int)userPhrase[i]);

      decrypted += (char)(65 + temp);
    }
  }

  // * Decrypted Text Output *

  cout << "Decrypted Text: " << decrypted;

   cout << endl; // Formatting

   cout << endl; // Formatting

  cout << "Thanks for using Lee's Cryption Services!";

   cout << endl; // Formatting

  cout << "To use the utilities again, Restart the program.";

   cout << endl; // Formatting

}


// *MAIN*

int main()
{

// * Welcome & Instructions *

  cout << endl; // Formatting

  cout << endl; // Formatting
  
  cout << "Welcome to Lee's Cipher Services!\n";
  
  cout << endl; // Formatting
  
  cout << "To use our Encryption and Decryption Services,\n";

  cout << "Please enter one of the following numbers & press Enter:\n";

  cout << endl; // Formatting

  cout << " * 1 for Encryption Services.\n";

  cout << " * 2 for Decryption Services.\n";

  cout << " * 3 for The Vigenère Table.\n";

  cout << " * 0 to Exit the program.\n";

  cout << endl; // Formatting


// * Get User Choice *

  int user_choice;
  
  cout << endl; // Formatting

  cin >> user_choice;

  cin.ignore();


  // * Choice #1 - Encrypting *

  if (user_choice == 1)


  {
    cout << endl; // Formatting

    cout << "Welcome To The Encryption Service.\n";

    userPhrase_userKey();
    
    encryption(userPhrase, map_Key);
  }


  // * Choice #2 - Decrypting *

  else if (user_choice == 2)

  {
    cout << endl; // Formatting

    cout << "Welcome To The Decryption Service.\n";

    userPhrase_userKey();
    
    decryption(userPhrase, map_Key);
  }


  // * Choice #3 - View Vigenère Table *

  else if (user_choice == 3)
  {
    cout << endl; // Formatting

    cout << " To view the table,";

    cout << " Please press 3 again to confirm.";

    cout << endl; // Formatting

    cout << endl; // Formatting

    cin >> user_choice;

    cout << endl; // Formatting

    if (user_choice == 3)

    {
      viewVigTable();
    }
  

  // * Choice #0 - Exit Program *

    else if (user_choice == 0)

  {
    cout << endl; // Formatting

    cout << "To exit the program,";

    cout << "Please press 0 again to confirm.";

    cout << endl; // Formatting

    cin >> user_choice;

    cout << endl; // Formatting

    if (user_choice == 0)

    {
      cout << "Goodbye, This program will now SELF-DESTRUCT.";

      _Exit;
      
    }

  }

  // * Incorrect Input Choice * 

  else 
  {
    cout << "ERROR: Choice not found.";

    cout << endl; // Formatting

    cout << "Please exit and retry the program again.";
  }

  return 0;
  }

}
